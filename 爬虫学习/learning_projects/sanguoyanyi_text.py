#bs4爬取《三国演义》
import requests
from bs4 import BeautifulSoup
import os
headers={
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36 Edg/120.0.0.0'
}

folder_path='./sanguo'
if not os.path.exists(folder_path):
    os.mkdir(folder_path)

page_url='https://www.shicimingju.com/book/sanguoyanyi.html'
page_text=requests.get(url=page_url,headers=headers).text

soup=BeautifulSoup(page_text,'lxml')
li_list=soup.select('.book-mulu > ul > li')

for li in li_list:
    
    detail_url=li.a['href']
    detail_url='https://www.shicimingju.com'+detail_url
    
    detail_page_text=requests.get(url=detail_url,headers=headers).text
    detail_soup=BeautifulSoup(detail_page_text,'lxml')
    
    div_tag=detail_soup.find('div',class_='card bookmark-list')
    content=div_tag.text
    title=div_tag.h1.text
    
    file_name=folder_path+'/'+title+'.txt'
    with open(file_name,'w',encoding='utf-8') as fp:
        fp.write(content)
        print(file_name+'保存成功！')
