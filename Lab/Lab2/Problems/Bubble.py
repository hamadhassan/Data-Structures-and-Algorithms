# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 15:13:32 2022

@author: Hammad Hassan
"""
import funcs as f
import time as t
#Check the time for process 
start_time=t.time() #Time Start
randomArray=f.RandomArray(30000)
sortedArray=f.BubbleSort(randomArray, 0,len(randomArray))
end_time=t.time() #Time End
run_time=end_time-start_time #Calculate run time
print(run_time)
#Write sorted array into file
f=open(file=r"D:\COMPUTER SCIENCE\3rd Semester\Data Structures and Algorithms-DSA\Labs\Lab2\Problems\SortedBubbleSort.csv",mode="w")
for i in range(len(sortedArray)):
    f.write(str(sortedArray[i])+",")
    f.write("\n")
