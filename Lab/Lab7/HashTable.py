# -*- coding: utf-8 -*-
"""
Created on Tue Oct 18 13:24:29 2022

@author: Hammad Hassan
"""

class KeyNode():
    value=0
    key=""
    def __init__(self,value,key):
        self.value=value         
        self.key=key
##-------------------------------()--------------------------------------##
class MyHashTable():
    def __init__(self,Size):
        self.hashTableSize=Size
        self.arrayObject=[None]*self.hashTableSize
    
    def GetHashTableSize(self):
        return self.hashTableSize
    
    def GetNumberOfKeys(self):
        return len(self.arrayObject)
    
    def HashFunction(self, key):
        return key % self.hashTableSize
    
    def UpdateKey(self, value, key):
        h = self.HashFunction(key)
        self.arrayObject[h] = value 
        
    def SearchKey(self,key):
        h = self.HashFunction(key)
        return self.arrayObject[h]
    def Insert(self, value, key):
        h = self.HashFunction(key)
        self.arrayObject[h] = value   
                
    def Rehash(self):
        temp=self.arrayObject
        newObjectarry=[None]*(self.arrayObject+self.arrayObject)
       
t=MyHashTable(128)
obj=KeyNode("cat",2)
t.Insert(obj.value, obj.key)
obj=KeyNode("hat",4)
t.Insert(obj.value, obj.key)
obj=KeyNode("green",12)
t.Insert(obj.value, obj.key)
obj=KeyNode("eggs",3)
t.Insert(obj.value, obj.key)
obj=KeyNode("ham",5)
t.Insert(obj.value, obj.key)
obj=KeyNode("algorithmic",14)
t.Insert(obj.value, obj.key)
obj=KeyNode("deoxyribonucleic",3)
t.Insert(obj.value, obj.key)
obj=KeyNode("dedecahedron",400)
t.Insert(obj.value, obj.key)

print(t.arrayObject)
        
    
    
    