# -*- coding: utf-8 -*-
"""
Created on Fri Sep 16 19:08:01 2022

@author: Hammad Hassan
"""

given_file=open(file='values.txt',mode='r')
lines=given_file.read()
values=[]
arr=lines.split()
for s in arr:
    num=int(s)
    values.append(num)


import funcs as f
import time as t

for i in range(len(values)):
    #Check the time for process 
    start_time=t.time() #Time Start
    randomArray=f.RandomArray(values[i])
    f.InsertionSort(randomArray,0,len(randomArray)-1)
    end_time=t.time() #Time End
    run_time=end_time-start_time #Calculate run time
    print(run_time)