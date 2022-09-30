# -*- coding: utf-8 -*-
"""
Created on Wed Sep 28 19:13:57 2022

@author: Hammad Hassan
"""
#(1)
def printMatrix(A,starting_index,rows,columns):
    for i in range(len(A)):
        for j in range(len(A)+1):
            print(A[i][j],end = " ")
        print()
A=[[3,4,5],[2,5,7]]
printMatrix (A,1,2,3) 
#(2)
def MatAdd(A,B):
    C=[[0]*len(A)]*len(B)
    print("",len(C))
    for i in range(len(A)):
        for j in range(len(B)):
            for k in range(len(A)):
             C[i][j]=C[i][j]+(A[i][k]*B[k][j])
    print(C)
A=[[3,4,5],[3,4,5]]
B=[[2,5,5],[2,5,5]]
MatAdd(A,B)   
    