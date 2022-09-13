# -*- coding: utf-8 -*-
"""
Created on Wed Sep  7 13:19:37 2022

@author: Hammad Hassan
"""
# Read Data from File
#given_file=open(file='test.txt',mode='r')
#lines=given_file.read()
#numbers=[]
#arr=lines.split()
#for s in arr:
#    num=int(s)
#    numbers.append(num)
#print(numbers)
arr=['Hello World','UET']
f=open(file="test.txt",mode="w")
for i in arr:
    f.write(i+"\n")
