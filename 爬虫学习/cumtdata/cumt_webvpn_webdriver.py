#生成登录cumt的webvpn的webdriver
import requests
from selenium import webdriver
from selenium.webdriver.common import by, options
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from selenium.webdriver import ChromeOptions
from webdriver_manager.chrome import ChromeDriverManager
import shutil
import os
import time
from test_code import get_code_text
from selenium.common.exceptions import NoSuchElementException
from requests.exceptions import MissingSchema

def login_vpn(bro,username,password):
    #登录web vpn
    bro.get(r'https://authserver-cumt-edu-cn-s.webvpn.cumt.edu.cn:8118/authserver/login?service=https%3A%2F%2Fwebvpn.cumt.edu.cn%2Fauth%2Fcas_validate%3Fentry_id%3D1')

    u=bro.find_element(by=by.By.ID,value='username')
    p=bro.find_element(by=by.By.ID,value='password')
    u.send_keys(username)
    p.send_keys(password)

    switcher_plogin=bro.find_element(by=by.By.ID,value='login_submit')
    switcher_plogin.click()
    
    #验证码处理
    try:
        img_element = bro.find_element(by=by.By.ID, value='captchaImg')
        img_element.screenshot('a.jpg')
        # 获取验证码图片
        
        test_code=get_code_text('a.jpg')
        os.remove('a.jpg')
        
        captcha=bro.find_element(by=by.By.ID,value='captcha')
        captcha.send_keys(test_code)
        
        switcher_plogin=bro.find_element(by=by.By.ID,value='login_submit')
        switcher_plogin.click()
        
    except NoSuchElementException:
        pass
    except MissingSchema:
        pass

def get_webvpn_webdriver(username,password,download_folder):
    """配置浏览网页ChromeDriver"""
    option=ChromeOptions()
    option.add_experimental_option('excludeSwitches', ['enable-logging'])
    #忽略证书错误
    option.add_argument('--ignore-certificate-errors')
    #实现无头
    #option.add_argument('--headless')
    #规避检测
    option.add_experimental_option('excludeSwitches',['enable-automation'])
    #设置代理
    # proxy = "192.168.173.101:9128"
    # option.add_argument('--proxy-server=%s' % proxy)
    #自动下载PDF文件
    option.add_experimental_option('prefs', {
    "download.default_directory":  download_folder,
    "download.prompt_for_download": False,  # 不提示下载窗口
    "download.directory_upgrade": True,
    "plugins.always_open_pdf_externally": True  # 自动下载pdf
    })
    #自动下载jpg文件     
       
    # 指定驱动目标位置
    folder_path = os.path.dirname(os.path.abspath(__file__))
    file_path = os.path.join(folder_path, 'chromedriver.exe')
    # 使用ChromeDriverManager安装ChromeDriver，并获取驱动程序的路径
    download_driver_path = ChromeDriverManager().install()
    # 复制文件到目标位置
    shutil.copy(download_driver_path, file_path)
    service=Service(file_path)
    bro = webdriver.Chrome(service=service,options=option)
    #登录webvpn
    login_vpn(bro,username,username)
    
    return bro