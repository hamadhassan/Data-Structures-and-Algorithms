# -*- coding: utf-8 -*-
"""
Created on Thu Sep 29 06:58:35 2022

@author: Hammad Hassan
"""
from helium import *
from bs4 import BeautifulSoup
url='http://eduko.spikotech.com/Course/Details/2049'
browser=start_chrome(url,headless=True)
soup=BeautifulSoup(browser.page_source,'html.parser')
code=soup.find(id='CourseCode')
print(code)
# from selenium import webdriver
# from bs4 import BeautifulSoup
# from selenium.webdriver.common.by import By
# import pandas as pd

# url='http://eduko.spikotech.com/Course/Details/2049'
# driver = webdriver.Chrome()
# driver.get(url)
# code = driver.find_elements(By.XPATH, './/*[@id="CourseBooks"]')
# print(code)
# df = pd.DataFrame({'Product Name':products,'Price':prices,'Rating':ratings})
# df.to_csv('products.csv', index=False, encoding='utf-8')