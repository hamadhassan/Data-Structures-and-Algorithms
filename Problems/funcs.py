# -*- coding: utf-8 -*-
"""
Created on Fri Sep  9 5:45:15 2022

@author: Hammad Hassan
"""
#Prob1
def SearchA(Arr,x):
    searchArr=[]
    for i in range(len(Arr)):
        if(x==Arr[i]):
            searchArr.append(i)
    return searchArr
#Prob2
def SearchA(Arr,x):
    searchArr=[]
    for i in range(len(Arr)):
        if(x==Arr[i]):
            searchArr.append(i)
    return searchArr
#Prob3
def Minimum(Arr,starting,ending):
    minNum=Arr[starting]
    index=starting;
    for starting in range(ending+1):
        if(Arr[starting]<minNum):
            minNum=Arr[starting]
            index=starting;
    return index
