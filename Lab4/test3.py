# -*- coding: utf-8 -*-
"""
Created on Fri Sep 30 6:30:00 2022

@author: Hammad Hassan
"""
##----------------------- libraries ----------------------------##

##----------------------- (1) ----------------------------##
def printMatrix(A,starting_Index,row,colums):
    for i in range(starting_Index[0],row):
        for j in range(starting_Index[1],colums):
            print(A[i][j],end=(" "))
        print()
A=[[3,4,5],[2,5,7]]
starting_index=(0,0)
row=2 #Number of row wants to print
column=3 #Number of Column wants to print
printMatrix(A,starting_index,row,column) 
##----------------------- (2) ----------------------------##
