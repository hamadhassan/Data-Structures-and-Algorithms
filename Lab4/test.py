# -*- coding: utf-8 -*-
"""
Created on Thu Sep 29 07:11:24 2022

@author: Hammad Hassan
"""
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.by import By
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