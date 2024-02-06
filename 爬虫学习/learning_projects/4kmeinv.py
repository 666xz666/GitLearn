#xpath爬取4k美女图片
import requests
from lxml import etree
import os

if not os.path.exists('./4kmeinv'):
    os.mkdir('./4kmeinv')

page_url='https://pic.netbian.com/4kmeinv/index'
index_num=input('enter index number(1~n):')
if index_num=='1':
    page_url='https://pic.netbian.com/4kmeinv/index.html'
else:
    page_url=page_url+'_'+index_num+'.html'
    
headers={
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36 Edg/120.0.0.0'
}

response=requests.get(page_url,headers=headers)
#设置响应的编码方式
response.encoding='gbk'
page_text=response.text
tree=etree.HTML(page_text)
li_list=tree.xpath('//div[@class="slist"]//li')

for li in li_list:
    img_name=li.xpath('.//text()')[0]
    #img_name.encode('iso-8859-1').decode('gbk')
    img_url='https://pic.netbian.com'+li.xpath('.//@src')[0]
    img_data=requests.get(url=img_url,headers=headers).content
    file_name='./4kmeinv/'+img_name+'.jpg'
    with open(file_name,'wb') as fp:
        fp.write(img_data)
        print(img_name+'.jpg'+'保存成功!')
    

