# -*- coding: utf-8 -*-
"""
Created on Mon Oct 24 17:09:07 2022

@author: Hammad Hassan
"""

def SearchA(Arr, x):
    num=[]
    for i in range(len(Arr)):
        if(Arr[i]==2):
            num.append(i)
    return num
X = [22,2,1,7,11,13,5,2,9]
print(SearchA(X,2))
            