# -*- coding: utf-8 -*-
"""
Created on Thu Sep 29 06:58:35 2022

@author: Hammad Hassan
"""
from helium import *
from bs4 import BeautifulSoup
# url='http://eduko.spikotech.com/Course/Details/2049'
# browser=start_chrome(url,headless=True)
# soup=BeautifulSoup(browser.page_source,'html.parser')
# code=soup.find(id='CourseCode')
# print(code)
# from selenium import webdriver
# from bs4 import BeautifulSoup
# from selenium.webdriver.common.by import By
# import pandas as pd

url='http://eduko.spikotech.com/Course/Details/2049'
driver = webdriver.Chrome()
driver.get(url)
code = driver.find_elements(By.XPATH, './/*[@id="CourseBooks"]')
print(code)
df = pd.DataFrame({'Product Name':products,'Price':prices,'Rating':ratings})
df.to_csv('products.csv', index=False, encoding='utf-8')
##------------------------ Scrap the Content --------------------------------- ##

##------------------------ Decelerar the data variables --------------------------------- ##
# products=[] 
# ratings=[]
# prices=[] 
##------------------------ Extract the required data --------------------------------- ##
# for a in soup.findAll('div',attrs={'class':'_37K3-p'}):
#     name=a.find('a', attrs={'class':'s1Q9rs'})
#     price=a.find('div',attrs={'class':'_30jeq3'})
#     rating=a.find('div',attrs={'class':'_3LWZlK'})
#     products.append(name.text)
#     prices.append(price.text)
#     ratings.append(rating.text)
##------------------------ Store in file --------------------------------- ##
# df = pd.DataFrame({'Product Name':products,'Price':prices,'Rating':ratings})
# df.to_csv('products.csv', index=False, encoding='utf-8')

##------------------------ Scrap the Content --------------------------------- ##

# driver = webdriver.Chrome()
# driver.get('https://www.youtube.com/channel/UC7RWnITwDurFDiXLbl51D0A/videos')
# content=driver.page_source
# soup = BeautifulSoup(content, 'lxml')
# ##------------------------ Find desire content through soup  ------------------ ##
# title=soup.find(class_='yt-simple-endpoint style-scope ytd-grid-video-renderer')
# print(title).split.text()
# driver.quit()