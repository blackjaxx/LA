#!/usr/bin/env python

import os
from distutils.log import warn as printf
import re

with os.popen('who', 'r') as f:
    for eachLine in f:
        printf(re.split('\s\s+|\t', eachLine.rstrip()))

#通用版本在python2和python3中都能运行

