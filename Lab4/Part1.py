# -*- coding: utf-8 -*-
"""
Created on Tue Sep 27 13:28:18 2022

@author: Hammad Hassan
"""
import matplotlib.pyplot as plt
import pandas as pd
#(1)
#df=pd.read_csv('dailyActivity_merged.csv')#Read the data  df: data frames pd: pandas
#df.groupby(['ActivityDate'])['TotalSteps'].sum().plot()
#(2)
#df.groupby(['ActivityDate'])['TrackerDistance'].sum().plot.bar(x='ActivityDate',y='TrackerDistance',rot=0)
#(3)
df1=pd.read_csv('sleepDay_merged.csv')
#df1.plot.scatter(x = 'SleepDay', y = 'TotalTimeInBed', s = 100);
#df1.groupby(['SleepDay'])['TotalTimeInBed'].sum().plot.scatter(x=df1['SleepDay'],y=df1['TotalTimeInBed'])
#(4)

