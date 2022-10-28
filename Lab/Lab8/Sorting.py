
"""
Created on Mon Oct 24 17:37:01 2022

@author: Hammad Hassan
"""

def InsertionSort(array,start,end):
    for i in range(start,end):
        key=array[i]
        j=i-1
        while(key<array[j] and j>=start):
            array[j+1]=array[j]
            j=j-1
        array[j+1]=key
    return array