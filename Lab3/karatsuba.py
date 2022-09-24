# -*- coding: utf-8 -*-
"""
Created on Tue Sep 20 13:48:19 2022

@author: Hammad Hassan
"""
#(i)
from math import ceil, floor
def Multiply_integer(a,b):
    if a < 10 and b< 10: # in other words, if x and y are single digits
        return a*b
    x=str(a)
    y=str(b)
    result=[]
    isReminder=True
    rowResult=""
    t=0
    o=0
    sum=0
    for i in  reversed(range(len(y))):
        for z in range(t):
            rowResult=rowResult+"0"
        for j in reversed(range(len(x))):
            rowMul=int(y[i])*int(x[j])
            if(rowMul>9):
                reminder=rowMul%10
                carry=rowMul//10
                if(isReminder):
                    rowResult=rowResult+str(reminder)
                    isReminder=False
                else:
                    rowMul=rowMul+carry
                    rowResult=str(rowMul)+rowResult
                    if(j==0):
                        result.append(int(rowResult))
                        rowResult=""
                        t+=1
            else:
                rowResult=str(rowMul)+rowResult
                o+=1
                if(j==0):
                    result.append(int(rowResult))
                    rowResult=""
                    t+=1
    for i in range(len(result)):
        sum+=result[i]
    return sum                               
print(Multiply_integer(22,45))
#(ii)
def Multiply_string(a,b):
    if int(a) < 10 and int(b)< 10: # in other words, if x and y are single digits
        return a*b
    result=[]
    isReminder=True
    rowResult=""
    t=0
    o=0
    sum=0
    for i in  reversed(range(len(b))):
        for z in range(t):
            rowResult=rowResult+"0"
        for j in reversed(range(len(a))):
            rowMul=int(b[i])*int(a[j])
            if(rowMul>9):
                reminder=rowMul%10
                carry=rowMul//10
                if(isReminder):
                    rowResult=rowResult+str(reminder)
                    isReminder=False
                else:
                    rowMul=rowMul+carry
                    rowResult=str(rowMul)+rowResult
                    if(j==0):
                        result.append(int(rowResult))
                        rowResult=""
                        t+=1
            else:
                rowResult=str(rowMul)+rowResult
                o+=1
                if(j==0):
                    result.append(int(rowResult))
                    rowResult=""
                    t+=1
    for i in range(len(result)):
        sum+=result[i]
    return sum                               
print(Multiply_string("22","45"))

    
 


