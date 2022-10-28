# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 13:24:37 2022

@author: Hammad Hassan
"""
import random
#Problem1
def RandomArray(size):
    arr=[]
    for i in range(size):
        arr.append(random.randint(0, size))
    return arr
#Problem2
def InsertionSort(array,start,end):
    for i in range(start,end):
        key=array[i]
        j=i-1
        while(key<array[j] and j>=start):
            array[j+1]=array[j]
            j=j-1
        array[j+1]=key
    return array
#Problem3
import numpy as np
#A=array p=start r=end q=mid
def Merge(array,start,mid,end):
    n1=mid-start+1
    n2=end-mid
    L=[0]*(n1+1)
    R=[0]*(n2+1)
    for i in range(n1):
        L[i]=array[start+i]
    for j in range(n2):
        R[j]=array[mid+j+1]
    L[len(L)-1]=np.inf
    R[len(R)-1]=np.inf
    i=j=0
    for s in range(start,end+1):
        if(L[i]<=R[j]):
            array[s]=L[i]
            i+=1
        else:
            array[s]=R[j]
            j=j+1
def MergeSort(array, start, end):
    if(start!=end):     
        mid=start+(end-start)//2
        MergeSort(array, start, mid)
        MergeSort(array, mid+1, end)
        Merge(array, start, mid, end)
    else:
        return
#Problem4
def HybrideMergeSort(array,start,end):
    n=end-start
    if(n<43):
        InsertionSort(array, start, 43)
        MergeSort(array, 43, end)
    else:
        MergeSort(array, start, end)
#Problem5
def BubbleSort(array,start,end):
    for i in range(start,end):
        for j in range(0, end-i-1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    return array
#Problem6
def SelectionSort(array,start,end):
    for i in range(start,end):
        min_index = i
        for j in range(i+1, end):
            if array[j] < array[min_index]:
                min_index = j
        (array[i], array[min_index]) = (array[min_index], array[i])
    return array
#Poblem8
def ShuffleArray(array,start,end):
    for i in range(end-1,0,-1):
          j = random.randint(0,i+1)
          array[i],array[j] = array[j],array[i]
          return array