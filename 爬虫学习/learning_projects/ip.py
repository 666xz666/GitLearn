#代理ip
import requests
from lxml import etree

headers={
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36 Edg/120.0.0.0'
}

page_url='https://ip.900cha.com'
#
page_text=requests.get(url=page_url,headers=headers,proxies={'https':'https://117.30.214.224'}).text

"""
    with open('./temp/ip.html','w',encoding='utf-8') as fp:
    fp.write(page_text)
"""
tree=etree.HTML(page_text)
ip_text=tree.xpath('/html/body/div/div/div/div[1]/div[1]/ul/li[3]/text()')[0]
print('ip:'+ip_text)