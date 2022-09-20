# -*- coding: utf-8 -*-
"""
Created on Tue Sep 20 13:48:19 2022

@author: Hammad Hassan
"""
arr1=[]
arr2=[]
sum=[]

def parMult(a,b):
    if(a<9 or b<9):
        arr1.append(a%10)
        arr2.append(b%10)
    else:
        arr1.append(a%10)
        a=a//10
        arr2.append(b%10)
        b=b//10
        return(parMult(a,b))
    carry=0
    toadd1=""
    for i in range(len(arr2)):
        for j in range(len(arr1)):
            mul=arr2[i]*arr1[j]
            if(mul>=10):
              carry=mul//10
              if(carry>=1 and j<len(arr2)-1):
                  mul+=carry
                  toadd=str(mul%10)
              else:
                  toadd+=str(mul)
                  sum.append(toadd) 
                  
            else:
                if(j<len(arr2)-1):
                    toadd1+=str(mul)+"0"                 
                else:
                    sum.append(str(mul)+toadd1)
    total=0
    for i in range(len(sum)):
        total=total+int(sum[i])
    print(sum)
    print(total)
    
parMult(22,45)