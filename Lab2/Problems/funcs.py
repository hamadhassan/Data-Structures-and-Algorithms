# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 13:24:37 2022

@author: Hammad Hassan
"""
import random as r
#Problem1
def RandomArray(size):
    arr=[]
    for i in range(size):
        arr.append(r.randint(0, size))
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
#Problem5
def BubbleSort(array,start,end):
    for i in range(start,end):
        for j in range(0, end-i-1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    return array