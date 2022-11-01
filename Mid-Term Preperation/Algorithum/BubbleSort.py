# -*- coding: utf-8 -*-
"""
Created on Mon Oct 24 17:39:30 2022

@author: Hammad Hassan
"""

def BubbleSort(array,start,end):
    for i in range(start,end):
        for j in range(end-i-1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    return array
print(BubbleSort([5,4,3,2],0,4))