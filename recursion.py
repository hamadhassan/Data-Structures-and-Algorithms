# -*- coding: utf-8 -*-
"""
Created on Wed Sep  7 14:41:24 2022

@author: Hammad Hassan
"""
def sum(n):
    if(n==0):
        return n
    else:
        print(n+sum(n-1))
        return n+sum(n-1)
   
print(sum(10))
