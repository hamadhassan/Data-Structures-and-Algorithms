# -*- coding: utf-8 -*-
"""
Created on Wed Oct 19 13:18:01 2022

@author: Hammad Hassan
"""

import math 
def InsertionSort(array):
    for i in range(len(array)):
        key=array[i]
        j=i-1
        while(key<array[j]):
            array[j+1]=array[j]
            j=j-1
        array[j+1]=key
    return array

def bucketSort(arr,n):
    bucket = []*(n-1)
    for i in range(n):
        bucket.append([])
    for i in arr:
        j = math.floor(n * i)
        bucket[j].append(i)  
    bucket=InsertionSort(bucket)
    k = 0
    for i in range(n):
        for j in range(len(bucket[i])):
            arr[k] = bucket[i][j]
            k += 1
    return arr


arr = [.897, .565, .657, .1234, .665, .3434]
print(bucketSort(arr,6))