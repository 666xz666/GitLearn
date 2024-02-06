#获取古诗文网站的验证码图片并识别，模拟登录
import requests
from lxml import etree
from requests.models import Response

from test_code import get_code_text

headers={
        'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36 Edg/120.0.0.0'
    }

page_url='https://so.gushiwen.cn/user/login.aspx'
page_text=requests.get(url=page_url,headers=headers).text
tree=etree.HTML(page_text)

img_url=tree.xpath('//*[@id="imgCode"]/@src')[0]
img_url='https://so.gushiwen.cn'+img_url

img_data=requests.get(url=img_url,headers=headers).content
with open('./temp/test_code.jpg','wb') as fp:
    fp.write(img_data)
    

code_text=get_code_text('.//temp//test_code.jpg')
print('code_text:'+code_text)

login_url='https://so.gushiwen.cn/user/login.aspx'
data={
'__VIEWSTATE': 'qsnl3FG6rcc/R7iMPhLVjLCz3bkspkh/TaWP7lI7nQqiIxayYCR5hs13pScEtY5XFKePhVI7Gi0mV8r6PbKgi6DW71ceibrlz4PHIN9WY38ztijWWFROUmg5A0KYSgWCcoPVJ32Z210z3fOxJ3e0nQc1XDA=',
'__VIEWSTATEGENERATOR': 'C93BE1AE',
'from': 'http://so.gushiwen.cn/user/collect.aspx?type=s',
'email': '15505193862',
'pwd': '985211Xz',
'code': code_text,
'denglu': '登录'
}

s = requests.Session()#保存cookie
response=s.post(url=login_url,headers=headers,data=data,allow_redirects=True)
print('status_code:'+str(response.status_code))     

response = s.get('https://so.gushiwen.cn/user/collect.aspx')
login_page_text=response.text

with open('./temp/test.html','w',encoding='utf-8') as fp:
    fp.write(login_page_text)
#login_page_tree=etree.HTML(login_page_text)

#print(login_page_tree.xpath('//*[@id="mainSearch"]/div[2]/img'))
"""
test_img_url=login_page_tree.xpath('//*[@id="mainSearch"]/div[2]/img/@src')
test_img_url='https://so.gushiwen.cn/user/'+test_img_url
test_img_data=s.get(test_img_url).content

with open('./temp/test_img.jpg','wb') as fp:
    fp.write(test_img_data)
     
"""

    
    
    
    





