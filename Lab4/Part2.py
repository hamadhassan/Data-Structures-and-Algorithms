# -*- coding: utf-8 -*-
"""
Created on Sat Oct  1 16:52:25 2022

@author: Hammad Hassan
"""

##----------------------- libraries ----------------------------##
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
##----------------------- (1) ----------------------------##
df=pd.read_csv('Train.csv')
##----------------------- (2) ----------------------------##
# df.groupby(['TYPE'])['COUGH']
# label=df.loc[:,"TYPE"]
# symptoms=["COUGH","MUSCLE_ACHES","TIREDNESS","SORE_THROAT","RUNNY_NOSE","STUFFY_NOSE","FEVER"
#           ,"NAUSEA","VOMITING","DIARRHEA","SHORTNESS_OF_BREATH","DIFFICULTY_BREATHING","LOSS_OF_SMELL","ITCHY_NOSE","ITCHY_MOUTH"
#           ,"ITCHY_INNER_EAR","SNEEZING","PINK_EYE"]
# for i in range(len(symptoms)):
#     symptom=df.loc[:,symptoms[i]]
#     plt.scatter(label,symptom)
#     plt.xlabel("Label") #x label
#     plt.ylabel("Symptom of "+symptoms[i]) #y label
#     plt.show()
    
##----------------------- (3) ----------------------------##
dfS=pd.read_csv('Test.csv') # df: dataframe s: small test data dfS: dataframe of test data
dfB=df.loc[:, df.columns != 'TYPE'] # Get the symptom without label column
label=df.loc[:,"TYPE"]
point1=np.array(dfS.iloc[0]) # Small data row
point2=np.array(dfB.iloc[0]) # Big data row
finalDistance = np.linalg.norm(point1 - point2)
labelIndex=0
for i in range(1,len(dfS)):
    point1=np.array(dfS.iloc[i])
    for j in range(1,len(dfB)):
        point2=np.array(dfB.iloc[j])
        dist=np.linalg.norm(point1 - point2)
        if(dist<finalDistance):
            finalDistance=dist
##----------------------- (4) ----------------------------##
            labelIndex=j
    print("Patient",i,"has symptom of ",label[labelIndex])



















