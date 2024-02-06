from selenium import webdriver
from selenium.webdriver.edge.service import Service
from lxml import etree
import time

service=Service(r"C:\Users\xuzha\AppData\Local\Google\Chrome\Application\chromedriver.exe")
bro = webdriver.Chrome(service=service)

bro.get('https://www.pearvideo.com/video_1167944')
page_text=bro.page_source

tree=etree.HTML(page_text)
video_url=tree.xpath('//*[@id="JprismPlayer"]/video/@src')
print(video_url)

time.sleep(10)
