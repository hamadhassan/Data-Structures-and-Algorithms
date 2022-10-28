# -*- coding: utf-8 -*-
"""
Created on Fri Sep 16 14:10:06 2022

@author: Hammad Hassan
"""
#Import the function 
import funcs as f
import time as t

#Check the time for process 
start_time=t.time() #Time Start
randomArray=f.RandomArray(30000)
f.MergeSort(randomArray,0,len(randomArray)-1)
end_time=t.time() #Time End
run_time=end_time-start_time #Calculate run time
print(run_time)
#Write sorted array into file
f=open(file="SortedMergeSort.csv",mode="w")
for i in range((len(randomArray))):
    f.write(str(randomArray[i])+",")
    f.write("\n")