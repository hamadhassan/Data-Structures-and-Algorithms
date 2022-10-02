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
df.groupby(['TYPE'])['COUGH']
label=df.loc[:,"TYPE"]
symptoms=["COUGH","MUSCLE_ACHES","TIREDNESS","SORE_THROAT","RUNNY_NOSE","STUFFY_NOSE","FEVER"
          ,"NAUSEA","VOMITING","DIARRHEA","SHORTNESS_OF_BREATH","DIFFICULTY_BREATHING","LOSS_OF_SMELL","ITCHY_NOSE","ITCHY_MOUTH"
          ,"ITCHY_INNER_EAR","SNEEZING","PINK_EYE"]
for i in range(len(symptoms)):
    symptom=df.loc[:,symptoms[i]]
    plt.scatter(label,symptom)
    plt.xlabel("Label") #x label
    plt.ylabel("Symptom of "+symptoms[i]) #y label
    plt.show()
    




















