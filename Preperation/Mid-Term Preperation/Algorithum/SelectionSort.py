# -*- coding: utf-8 -*-
"""
Created on Mon Oct 24 17:40:06 2022

@author: Hammad Hassan
"""

def SelectionSort(array,start,end):
    for i in range(start,end):
        min_index = i
        for j in range(i+1, end):
            if array[j] < array[min_index]:
                min_index = j
        (array[i], array[min_index]) = (array[min_index], array[i])
    return array
print(SelectionSort([5,4,3,2],0,4))