#查询附近肯德基门店

import requests
import json

post_url='http://www.kfc.com.cn/kfccda/ashx/GetStoreList.ashx?op=keyword'

headers={
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.107 Safari/537.36 Edg/92.0.902.55'
    
}

kw=input('enter a keyword:')

params={
'cname':'',
'pid':'',
'keyword':kw,
'pageIndex':'1',
'pageSize':'10'
}



response=requests.post(url=post_url,params=params,headers=headers)

text=response.text

print(text)

file_name=kw+'kfc.txt'

with open(file_name,'a',encoding='utf-8') as fp:
    fp.write(text)
    print("over!!!")