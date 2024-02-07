#爬取cumt官网规章制度页面数据
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

from pdf_to_txt import pdf_to_text
from cumt_webvpn_webdriver import get_webvpn_webdriver

class CumtRules:
    def __init__(self,download_folder):
        #下载位置
        self.download_folder = download_folder
        
    def download_rules(self,bro,page_url):
        """下载详情页中的pdf文件"""
        bro.get(page_url)
        
        #获取文件名
        new_pdf_name=bro.find_element(by=by.By.XPATH,value='/html/body/div[4]/div/div[2]/div[2]/form/h1').text
        new_file_name = new_pdf_name + '.pdf'
        print(new_file_name+' downloading...')
        
        #下载pdf
        pdf_url=bro.find_element(by=by.By.XPATH,value='//*[@id="vsb_content"]/div/ul/li[4]/p/a').get_attribute('href')
        pdf_url = pdf_url.replace('https://rules.cumt.edu.cn', 'https://rules-cumt-edu-cn-s.webvpn.cumt.edu.cn:8118')
        bro.get(pdf_url)
        
        #修改文件名
        time.sleep(3)
        pdf_name = pdf_url.split('/')[-1]
        downloaded_file = os.path.join(self.download_folder, pdf_name)
        os.rename(os.path.join(self.download_folder, downloaded_file), os.path.join(self.download_folder, new_file_name))
        
        #将pdf转换为txt
        pdf_to_text(os.path.join(self.download_folder, new_file_name))
        
        bro.back()
        

    def get_all_rules(self):
        #清空屏幕
        os.system('cls')
        
        #清空下载文件夹
        for file in os.listdir(self.download_folder):
            os.remove(os.path.join(self.download_folder,file))
        
        print('输入融合门户账号')
        username=input('username:>')
        password=input('password:>')
        
        #获取webdriver
        bro=get_webvpn_webdriver(username,password,self.download_folder)
        
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
                
                #获取文件名
                new_pdf_name=bro.find_element(by=by.By.XPATH,value='/html/body/div[4]/div/div[2]/div[2]/h1').text
                new_file_name = new_pdf_name + '.pdf'
                print(new_file_name+' downloading...')
                
                #下载pdf
                pdf_url=bro.find_element(by=by.By.XPATH,value='//*[@id="vsb_content"]/ul/li[4]/p/a').get_attribute('href')
                pdf_url = pdf_url.replace('https://rules.cumt.edu.cn', 'https://rules-cumt-edu-cn-s.webvpn.cumt.edu.cn:8118')
                bro.get(pdf_url)
                
                #修改文件名
                time.sleep(3)
                pdf_name = pdf_url.split('/')[-1]
                self.download_folder = "D:\\_code\\GitLearn\\GitLearn\\爬虫学习\\cumtdata\\temp\\kd_rules"
                downloaded_file = os.path.join(self.download_folder, pdf_name)
                os.rename(os.path.join(self.download_folder, downloaded_file), os.path.join(self.download_folder, new_file_name))
        
                #将pdf转换为txt
                pdf_to_text(os.path.join(self.download_folder, new_file_name))
                
                bro.back()
            else:
                class_btn_list=bro.find_elements(by=by.By.XPATH,value='/html/body/div[4]/div/div[1]/dl/dd/a')
                if class_btn_list==[]:
                    while True:
                        a_list=bro.find_elements(by=by.By.XPATH,value='/html/body/div[4]/div/div[2]/div[2]/ul/li/a')
                        for a in a_list:
                            page_url=a.get_attribute('href')
                            page_url=page_url.replace('https://rules.cumt.edu.cn', 'https://rules-cumt-edu-cn-s.webvpn.cumt.edu.cn:8118')
                            self.download_rules(bro,page_url) 
                        
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
                                self.download_rules(bro,page_url)
                            
                            next_page_btn=bro.find_elements(by=by.By.XPATH,value='/html/body/div[4]/div/div[2]/div[2]/div/div/span/span[5]/a')
                            if next_page_btn==[]:
                                break
                            next_page_btn[0].click()
                            print('page changed')
                            
                    bro.get('https://rules-cumt-edu-cn.webvpn.cumt.edu.cn:8118/')
        
        print('结束！')        
        time.sleep(10)
   
    def get_new_rules(self):
        """获取最新规章制度"""
        
        #清空屏幕
        os.system('cls')
        
        #清空下载文件夹
        for file in os.listdir(self.download_folder):
            os.remove(os.path.join(self.download_folder,file))
        
        print('输入融合门户账号')
        username=input('username:>')
        password=input('password:>')
        
        #获取webdriver
        bro=get_webvpn_webdriver(username,password,self.download_folder)
        
        #进入中国矿业大学官网规章制度页面
        bro.get('https://rules-cumt-edu-cn.webvpn.cumt.edu.cn:8118/')
        
        #获取PDF文件
        a_list=bro.find_elements(by=by.By.XPATH,value='/html/body/div[5]/div[1]/div[2]/ul/li/a')
        for a in a_list:
            page_url=a.get_attribute('href')
            page_url=page_url.replace('https://rules.cumt.edu.cn', 'https://rules-cumt-edu-cn-s.webvpn.cumt.edu.cn:8118')
            self.download_rules(bro,page_url) 
        
    
      
# test  
if __name__ == '__main__':
    cumt_rules = CumtRules("D:\\_code\\GitLearn\\GitLearn\\爬虫学习\\cumtdata\\temp\\kd_rules")
    cumt_rules.get_all_rules()


