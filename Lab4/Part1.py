# -*- coding: utf-8 -*-
"""
Created on Tue Sep 27 13:28:18 2022

@author: Hammad Hassan
"""
##----------------------- libraries ----------------------------##
import matplotlib.pyplot as plt
import pandas as pd
##----------------------- (1) ----------------------------##
# df=pd.read_csv('dailyActivity_merged.csv')#Read the data  df: data frames pd: pandas
# df.groupby(['ActivityDate'])['TotalSteps'].sum().plot()
##----------------------- (2) ----------------------------##
# df.groupby(['ActivityDate'])['TrackerDistance'].sum().plot.bar(x='ActivityDate',y='TrackerDistance',rot=0)
##----------------------- (3) ----------------------------##
df1=pd.read_csv('sleepDay_merged.csv')
df1.groupby(['SleepDay'])['TotalTimeInBed'].sum()
list1=df1.loc[:,"SleepDay"]
list2=df1.loc[:,"TotalTimeInBed"]
print(list1,list2)
plt.scatter(list1, list2)
plt.show()
##----------------------- (4) ----------------------------##
# df2=pd.read_csv('dailySteps_merged.csv')
# df2.groupby(['ActivityDay'])['StepTotal'].sum()
# day=df2.loc[:,"ActivityDay"]
# steps=df2.loc[:,"StepTotal"]
# specificDateSteps=[]
# for i in range(len(day)):
#     if(day[i]=="4/12/2016"):
#         specificDateSteps.append(steps[i])
# plt.pie(specificDateSteps)
# plt.show()   
