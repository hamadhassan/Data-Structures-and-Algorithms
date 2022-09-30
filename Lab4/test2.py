# -*- coding: utf-8 -*-
"""
Created on Fri Sep 30 10:11:20 2022

@author: Hammad Hassan
"""

from bs4 import BeautifulSoup
from selenium import webdriver

##------------------------ Scrap the Content --------------------------------- ##

driver = webdriver.Chrome()
driver.get('https://www.youtube.com/channel/UC7RWnITwDurFDiXLbl51D0A/videos')
content=driver.page_source
soup = BeautifulSoup(content, 'lxml')
##------------------------ Find desire content through soup  ------------------ ##
title=soup.find(class_='yt-simple-endpoint style-scope ytd-grid-video-renderer')
print(title).split.text()
driver.quit()