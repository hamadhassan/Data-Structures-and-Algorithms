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
#Prob4
def Sort4(Arr):
    minIndex=Minimum(Arr,0,len(Arr)-1)
    minValue=Arr[minIndex]
    temp=Arr[0]
    Arr[0]=minValue
    Arr[minIndex]=temp
    for i in range (len(Arr)):
        for j in range(i + 1, len(Arr)):
            if(Arr[i] > Arr[j]):
                temp = Arr[i]
                Arr[i] = Arr[j]
                Arr[j] = temp
    return Arr
