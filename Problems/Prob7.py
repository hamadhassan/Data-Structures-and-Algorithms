# -*- coding: utf-8 -*-
"""
Created on Fri Sep  9 09:49:42 2022

@author: Hammad Hassan
"""
import funcs  
A=[[1,13,13],[5,11,6],[4,4,9]]
#Row sum
print("Row-Wise",funcs.RowWiseSum(A))
#Column sum 
print("Column-Wise:",funcs.ColumnWisSum(A))