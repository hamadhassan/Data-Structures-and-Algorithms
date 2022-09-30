# -*- coding: utf-8 -*-
"""
Created on Fri Sep 30 6:30:00 2022

@author: Hammad Hassan
"""

from selenium import webdriver
from bs4 import BeautifulSoup
import pandas as pd
##------------------------ Scrap the Content --------------------------------- ##
driver = webdriver.Chrome()
driver.get("https://www.youtube.com/c/SandeepSeminars/videos")
content = driver.page_source
soup = BeautifulSoup(content)
print(soup.prettify())
driver.quit()
