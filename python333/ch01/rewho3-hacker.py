#!/usr/bin/env python
"hacker's corner version of rewho3.py"

from os import popen
from re import split

with popen('who', 'r') as f:
    [print(split('\s\s+|\t', eachLine.strip())) for eachLine in f]
#通过使用with语句，此处io对象会自动调用f.close()
#注意who命令仅能在POSIX系统中使用，除非wimdows支持
