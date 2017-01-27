"""Currently, dumping place for all analysis routines."""
from . import data as wdata
from .utils.multiprocessing_mapreduce import SimpleMapReduce
import logging
import os
import pandas as pd
import glob
import numpy as np
import itertools

logger = logging.getLogger(__name__)

default_group_params_coltimes = ['linear_distance']
def map_mean_coltimes(sim_dir, group_params=default_group_params_coltimes):
    sim = wdata.Sim(sim_dir)
    try:
        for param in group_params:
            if param not in sim.coltimes.columns:
                sim.coltimes[param] = sim.params[param]
        gb_coltimes = sim.coltimes.groupby(group_params, as_index=True).coltime
    except OSError:
        # no coltimes in this simulation dir
        return []
    means = gb_coltimes.mean()
    nan_counts = gb_coltimes.agg(lambda x: np.sum(np.isnan(x)))
    total_counts = gb_coltimes.size()
    df = pd.concat([means, nan_counts, total_counts], axis=1,
                   keys=['mean_coltime', 'coltime_nan_count', 'coltime_count'])
    # this will flatten a multi-index if it exists, else no-op
    df.index = df.index.values
    # with a flattened multiindex, we can transpose to get out the three values
    # as a Series
    return list(df.T.items())

class MapMeanColtimes:
    """Function object, allows the same-named method to be passed to
    Pool.map"""
    def __init__(self, group_params):
        self.group_params = group_params
    def __call__(self, sim_dir):
        return map_mean_coltimes(sim_dir, self.group_params)


def reduce_mean_coltimes(item):
    param_vals, coltime_stats = item
    # concat will put the param_vals as the column (then .T to row) names
    df = pd.concat(coltime_stats, axis=1).T
    # all indexes will match (== param_vals), so we will get one row at end
    row = df.groupby(df.index).agg({'mean_coltime': np.mean,
                                    'coltime_nan_count': np.sum,
                                    'coltime_count': np.sum})
    # the key of the single row is param_vals, so we can just
    # return next(row.T.items())
    # but honestly, keeping it in tuple form is annoying, since we will
    # just concatenate all the reduced results afterwards anyway, so we just
    return row

def reduce_rigid_mean_coltimes(item):
    param_vals, coltime_stats = item
    # concat will put the param_vals as the column (then .T to row) names
    df = pd.concat(coltime_stats, axis=1).T
    # all indexes will match (== param_vals), so we will get one row at end
    df = df[df['nan_counts'] == 0]
    row = df.groupby(df.index).agg({'mean_coltime': np.mean,
                                    'coltime_nan_count': np.sum,
                                    'coltime_count': np.sum})
    # the key of the single row is param_vals, so we can just
    # return next(row.T.items())
    # but honestly, keeping it in tuple form is annoying, since we will
    # just concatenate all the reduced results afterwards anyway, so we just
    return row

def striding_map_mean_coltimes(sim_dir, idx_gap=0,
                               group_params=['linear_distance']):
    """Not yet implemented. In the future, this should calculate the mean
    for a particular simulation of all the beads of each separation possible,
    without overlapping looped sections. Gah. Don't feel like typing that
    better."""
    pass

def map_reduce_mean_coltimes(run_dir, num_workers=None,
                             group_params=default_group_params_coltimes,
                             be_rigid=False, pool_type='process'):
    # write necessary csv files if not already there
    wdata.write_coltimes_csvs(run_dir)
    # get list of simulation directories to map over
    sim_dirs = wdata.Scan(run_dir).sim_paths
    # construct the MapReduce-r
    map_func = MapMeanColtimes(group_params)
    if be_rigid:
        reduce_func = reduce_rigid_mean_coltimes
    else:
        reduce_func = reduce_mean_coltimes
    mapper = SimpleMapReduce(map_func, reduce_func, num_workers=num_workers)
    # return a dataframe containing all the stats calculated
    df = pd.concat(mapper(sim_dirs), axis=0)
    df.index = pd.MultiIndex.from_tuples(df.index, names=group_params)
    return df


def map_cdf_coltimes(sim_dir, dt, group_params=default_group_params_coltimes):
    """TODO: actually implement"""
    sim = wdata.Sim(sim_dir)
    try:
        for param in group_params:
            if param not in sim.coltimes.columns:
                sim.coltimes[param] = sim.params[param]
        gb_coltimes = sim.coltimes.groupby(group_params, as_index=True).coltime
    except OSError:
        # no coltimes in this simulation dir
        return []

    df = pd.concat([], axis=1,
                   keys=['mean_coltime', 'coltime_nan_count', 'coltime_count'])
    # this will flatten a multi-index if it exists, else no-op
    df.index = df.index.values
    return list(df.T.items())

# non map-reduced version. Get's pretty bogged down by disk speed already
# based on watching it in htop.
def get_com_msd(run_dir):
    sim_dirs = wdata.Scan(run_dir).sim_paths
    num_sims = len(sim_dirs)
    sim0 = wdata.Sim(sim_dirs[0])
    num_time_points, ndims, num_polymers, num_beads = sim0.r.shape
    msd_com = np.zeros((num_time_points, ndims, num_polymers))
    for i,sim_dir in enumerate(sim_dirs):
        sim = wdata.Sim(sim_dir)
        msd_com += np.power(sim.center_of_mass - sim.center_of_mass[0,:,:], 2)
        print('Progress: {:2.1%}'.format(float(i)/num_sims), end='\r')
    msd_com = msd_com/len(sim_dirs)
    return msd_com

def fraction_collided_from_csv(csv_file):
    with open(csv_file) as f:
        # first establish the correct column identities
        column_names = next(f).rstrip().split(',')
        col_i = None
        i_i = None
        j_i = None
        nb_i = None
        for i,name in enumerate(column_names):
            if name.upper() == 'COLTIME':
                col_i = i
            elif name.upper() == 'I':
                i_i = i
            elif name.upper() == 'J':
                j_i = i
            elif name.upper() == 'NB' or name.upper() == 'N':
                nb_i = i
        if col_i is None or i_i is None or j_i is None or nb_i is None:
            raise ValueError(csv_file + "does not contain coltime,i,j,nb columns.")
        # peek at first line to get number of beads per polymer
        try:
            data = next(f).rstrip().split(',')
        except StopIteration:
            raise ValueError(csv_file + "has no data")
        nB = int(data[nb_i])
        num_uncollided = np.zeros((nB))
        num_precollided = np.zeros((nB))
        num_total = np.zeros((nB))
        # loop and a half, since we peeked the first line
        coltime = float(data[col_i])
        i = int(round(float(data[i_i])))
        j = int(round(float(data[j_i])))
        linear_distance = i - j
        num_total[linear_distance] += 1
        if coltime == 0.0:
            num_precollided[linear_distance] += 1
        elif coltime < 0.0:
            num_uncollided[linear_distance] += 1
        for line in f:
            data = line.rstrip().split(',')
            coltime = float(data[col_i])
            i = int(round(float(data[i_i])))
            j = int(round(float(data[j_i])))
            linear_distance = i - j
            num_total[linear_distance] += 1
            if coltime == 0.0:
                num_precollided[linear_distance] += 1
            elif coltime < 0.0:
                num_uncollided[linear_distance] += 1
    return num_uncollided, num_precollided, num_total

def get_coltimes_by_pos(scan_dir, linear_distance):
    """Get all coltimes that happened at a fixed linear distance as a
    function of their position on the polymer"""
    scan = wdata.Scan(scan_dir)
    c_fixed_dist = pd.DataFrame(columns=['coltime', 'i', 'j',
                                'linear_distance'])
    for sim_dir in scan.sim_dirs:
        s = wdata.Sim(os.path.join(scan.scan_dir, sim_dir))
        try:
            c = s.coltimes
        except FileNotFoundError:
            continue
        c_fixed_dist = c_fixed_dist.append(
            c.loc[c['linear_distance'] == linear_distance]
        )
    return c_fixed_dist
