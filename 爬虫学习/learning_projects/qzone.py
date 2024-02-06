#selenium模拟qq空间登录
from types import FrameType
from selenium import webdriver
from selenium.webdriver.common import by, options
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from selenium.webdriver import ChromeOptions

from lxml import etree
import time


option=ChromeOptions()
#规避检测
option.add_experimental_option('excludeSwitches',['enable-automation'])
#实现无头
option.add_argument('--headless')



#驱动文件位置
service=Service(r"C:\Users\xuzha\AppData\Local\Google\Chrome\Application\chromedriver.exe")

bro = webdriver.Chrome(service=service,options=option)

bro.get('https://qzone.qq.com/')
page_text=bro.page_source

bro.switch_to.frame('login_frame')
switcher_plogin=bro.find_element(by=by.By.ID,value='switcher_plogin')
# print(switcher_plogin.text)
switcher_plogin.click()

u=bro.find_element(by=by.By.ID,value='u')
p=bro.find_element(by=by.By.ID,value='p')
u.send_keys('username')
p.send_keys('password')

login_button=bro.find_element(by=by.By.ID,value='login_button')
login_button.click()

time.sleep(5)



