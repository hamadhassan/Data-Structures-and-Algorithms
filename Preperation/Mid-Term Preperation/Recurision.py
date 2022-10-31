# -*- coding: utf-8 -*-
"""
Created on Mon Oct 24 11:34:10 2022

@author: Hammad Hassan
"""
##---------------------(Printing)----------------------##
# def Iprint(arr,start,end):
#     for i in range(start,end):
#         print(arr[i])
# arr=[0,1,2,3,4,5,6,7,8,9]
# Iprint(arr,0,10)
# def Rprint(arr,start,end):
#     if(start==end):
#         return
#     else:
#         print(arr[start])
#         Rprint(arr,start+1,end)
# arr=[0,1,2,3,4,5,6,7,8,9]
# Rprint(arr,0,10)
##---------------------(Power function)-----------------##
def IPower(base,power):
    result=1
    for i in range(power):
        result=result*base
        print(result)
IPower(2,5)
def RPower(base,power):
    if(power==1):
        return base
    else:
        
        return base  * RPower(base,power-1)

print(RPower(2,5))






