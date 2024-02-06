#爬取cumt官网规章制度页面数据
from types import FrameType
from selenium import webdriver
from selenium.webdriver.common import by, options
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from selenium.webdriver import ChromeOptions
from webdriver_manager.chrome import ChromeDriverManager
import shutil
from lxml import etree
import time
import os

def login_vpn(bro,username,password):
    #登录web vpn
    bro.get(r'https://authserver-cumt-edu-cn-s.webvpn.cumt.edu.cn:8118/authserver/login?service=https%3A%2F%2Fwebvpn.cumt.edu.cn%2Fauth%2Fcas_validate%3Fentry_id%3D1')

    u=bro.find_element(by=by.By.ID,value='username')
    p=bro.find_element(by=by.By.ID,value='password')
    u.send_keys(username)
    p.send_keys(password)

    switcher_plogin=bro.find_element(by=by.By.ID,value='login_submit')
    switcher_plogin.click()
    
def download_pdf(bro,page_url):
    """下载详情页中的pdf文件"""
    bro.get(page_url)
    pdf_url=bro.find_element(by=by.By.XPATH,value='//*[@id="vsb_content"]/div/ul/li[4]/p/a').get_attribute('href')
    pdf_url = pdf_url.replace('https://rules.cumt.edu.cn', 'https://rules-cumt-edu-cn-s.webvpn.cumt.edu.cn:8118')
    print(pdf_url+' downloading...')
    #bro.get(pdf_url)
    bro.back()

if __name__=='__main__':
    print('输入融合门户账号')
    username=input('username:>')
    password=input('password:>')
    
    """配置浏览网页ChromeDriver"""
    option=ChromeOptions()
    option.add_experimental_option('excludeSwitches', ['enable-logging'])
    #忽略证书错误
    option.add_argument('--ignore-certificate-errors')
    #实现无头
    #option.add_argument('--headless')
    #规避检测
    option.add_experimental_option('excludeSwitches',['enable-automation'])
    #自动下载PDF文件
    option.add_experimental_option('prefs', {
    "download.default_directory":  "D:\\_code\\爬虫\\temp",
    "download.prompt_for_download": False,  # 不提示下载窗口
    "download.directory_upgrade": True,
    "plugins.always_open_pdf_externally": True  # 自动下载pdf
    })
    # 指定驱动目标位置
    folder_path = os.path.dirname(os.path.abspath(__file__))
    file_path = os.path.join(folder_path, 'chromedriver.exe')
    # 使用ChromeDriverManager安装ChromeDriver，并获取驱动程序的路径
    download_driver_path = ChromeDriverManager().install()
    # 复制文件到目标位置
    shutil.copy(download_driver_path, file_path)
    service=Service(file_path)
    bro = webdriver.Chrome(service=service,options=option)
    login_vpn(bro,username,password)
    
    #进入中国矿业大学官网规章制度页面
    bro.get('https://rules-cumt-edu-cn.webvpn.cumt.edu.cn:8118/')
    
    #获取PDF文件
    xpath='/html/body/div[3]/div/ul/li[%d]/a'
    for index in range(1,10):
        btn=bro.find_element(by=by.By.XPATH,value=xpath%index)
        btn.click()
        part_name=bro.find_element(by=by.By.XPATH,value='/html/body/div[4]/div/div[1]/div')
        part_name_text=part_name.text
        print(part_name_text)
        
        if index==1:
            """获取矿大章程"""
            pdf_url=bro.find_element(by=by.By.XPATH,value='//*[@id="vsb_content"]/ul/li[4]/p/a').get_attribute('href')
            pdf_url = pdf_url.replace('https://rules.cumt.edu.cn', 'https://rules-cumt-edu-cn-s.webvpn.cumt.edu.cn:8118')
            # 访问PDF链接
            print(pdf_url+' downloading...')
            #下载
            #bro.get(pdf_url)
            bro.back()
        else:
            class_btn_list=bro.find_elements(by=by.By.XPATH,value='/html/body/div[4]/div/div[1]/dl/dd/a')
            if class_btn_list==[]:
                while True:
                    a_list=bro.find_elements(by=by.By.XPATH,value='/html/body/div[4]/div/div[2]/div[2]/ul/li/a')
                    for a in a_list:
                        page_url=a.get_attribute('href')
                        page_url=page_url.replace('https://rules.cumt.edu.cn', 'https://rules-cumt-edu-cn-s.webvpn.cumt.edu.cn:8118')
                        download_pdf(bro,page_url) 
                    
                    next_page_btn=bro.find_elements(by=by.By.XPATH,value='/html/body/div[4]/div/div[2]/div[2]/div/div/span/span[5]/a')
                    if next_page_btn==[]:
                        break
                    next_page_btn[0].click()
                    print('page changed')
                    
                bro.back()    
            else:
                for i in range(len(class_btn_list)):
                    class_btn = bro.find_elements(by=by.By.XPATH,value='/html/body/div[4]/div/div[1]/dl/dd/a')[i]
                    print('*'+class_btn.text)
                    class_btn.click()
                    while True:
                        a_list=bro.find_elements(by=by.By.XPATH,value='/html/body/div[4]/div/div[2]/div[2]/ul/li/a')
                        for a in a_list:
                            page_url=a.get_attribute('href')
                            page_url=page_url.replace('https://rules.cumt.edu.cn', 'https://rules-cumt-edu-cn-s.webvpn.cumt.edu.cn:8118')
                            download_pdf(bro,page_url)
                        
                        next_page_btn=bro.find_elements(by=by.By.XPATH,value='/html/body/div[4]/div/div[2]/div[2]/div/div/span/span[5]/a')
                        if next_page_btn==[]:
                            break
                        next_page_btn[0].click()
                        print('page changed')
                        
                bro.get('https://rules-cumt-edu-cn.webvpn.cumt.edu.cn:8118/')
    
    print('结束！')        
    time.sleep(10)


