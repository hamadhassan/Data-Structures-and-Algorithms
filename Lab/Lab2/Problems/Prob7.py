# -*- coding: utf-8 -*-
"""
Created on Fri Sep 16 19:49:46 2022

@author: Hammad Hassan
"""

given_file=open(file='Nvalues.txt',mode='r')
lines=given_file.read()
values=[]
arr=lines.split()
for s in arr:
    num=int(s)
    values.append(num)
import funcs as f
import time as t
ins=[]
m=[]
h=[]
s=[]
b=[]
#Inseration Sort 
for i in range(len(values)):
    #Check the time for process 
    start_time=t.time() #Time Start
    randomArray=f.RandomArray(values[i])
    f.InsertionSort(randomArray,0,len(randomArray))
    end_time=t.time() #Time End
    run_time=end_time-start_time #Calculate run time
    ins.append(run_time)
    print("Insertion Sort",ins)

#Merge Sort
for i in range(len(values)):
    #Check the time for process 
    start_time=t.time() #Time Start
    randomArray=f.RandomArray(values[i])
    f.MergeSort(randomArray,0,len(randomArray)-1)
    end_time=t.time() #Time End
    run_time=end_time-start_time #Calculate run time
    m.append(run_time)
    print("Merge Sort",m)

#Hybrid Merge sort
for i in range(len(values)):
    #Check the time for process 
    start_time=t.time() #Time Start
    randomArray=f.RandomArray(values[i])
    f.HybrideMergeSort(randomArray,0,len(randomArray)-1)
    end_time=t.time() #Time End
    run_time=end_time-start_time #Calculate run time
    h.append(run_time)
    print("Hybrid Merge sort",h)

#Selection Sort 
for i in range(len(values)):
    #Check the time for process 
    start_time=t.time() #Time Start
    randomArray=f.RandomArray(values[i])
    sortedArray=f.SelectionSort(randomArray, 0,len(randomArray))
    end_time=t.time() #Time End
    run_time=end_time-start_time #Calculate run time
    s.append(run_time)
    print("Selection Sort ",s)
#Bubble Sort 
for i in range(len(values)):
    #Check the time for process 
    start_time=t.time() #Time Start
    randomArray=f.RandomArray(values[i])
    sortedArray=f.BubbleSort(randomArray, 0,len(randomArray))
    end_time=t.time() #Time End
    run_time=end_time-start_time #Calculate run time
    b.append(run_time)
    print("Bubble Sort ",b)



print(ins)
f=open(file="RunTime.csv",mode="w")
for (i,m,h,s,b) in zip(ins,m,h,s,b):
    print("I=",i,"M=",m,"H=",h,"S=",s,"B=",b)
    f.write(f"{ins},{m},{h},{s},{b}\n")
