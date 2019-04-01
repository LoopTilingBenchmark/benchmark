#!/usr/bin/env python
from __future__ import print_function
import re
import os
import sys
import time
import json
import math
import os
import argparse
import numpy as np

sys.path.insert(0, '/home/vinu/workspace/surf/surf-ytopt/plopper')
from plopper import Plopper

from numpy import abs, cos, exp, mean, pi, prod, sin, sqrt, sum
seed = 12345

def create_parser():
    'command line parser'
    
    parser = argparse.ArgumentParser(add_help=True)
    group = parser.add_argument_group('required arguments')

    for id in range(0, 3):
        parser.add_argument('--p%d'%id, action='store', dest='p%d'%id,
                            nargs='?', const=2, type=str, default='a',
                            help='parameter p%d value'%id)
    return(parser)

parser = create_parser()
cmdline_args = parser.parse_args()
param_dict = vars(cmdline_args)

p0 = param_dict['p0']
p1 = param_dict['p1']
p2 = param_dict['p2']

x=[p0,p1,p2]

p0_dict = {'a': "None", 'b': "#pragma omp parallel for", 'c': "#pragma omp parallel for schedule(static)"}
p1_dict = {'a': "None", 'b': "#pragma omp parallel for", 'c': "#pragma omp parallel for num_threads(2)"}
p2_dict = {'a': "None", 'b': "#pragma omp parallel for", 'c': "#pragma omp simd"}

obj = Plopper()
def plopper_func(x):
    result = float('inf')
    
    value = [p0_dict[x[0]], p1_dict[x[1]], p2_dict[x[2]]]
    params = ["LOOP1", "LOOP2", "LOOP3"]

    retVal = obj.validate(value)
    
    if retVal:
        result = obj.findRuntime(value, params)

    return result

pval = plopper_func(x)
print('OUTPUT:%1.3f'%pval)
