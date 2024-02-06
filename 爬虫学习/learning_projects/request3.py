#破解百度翻译（未完成）
import requests

import json

from requests.api import request

from requests.models import Response

post_url='https://fanyi.baidu.com/v2transapi?from=en&to=zh'

#UA伪装
headers={
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36 Edg/120.0.0.0'
}

kw=input('enter a word:')

#参数处理
params={
    'from': 'en',
    'to': 'zh',
    'query': kw,
    'transtype': 'realtime',
    'simple_means_flag': '3',
    'sign': '871501.634748',
    'token': 'ae328f05906e9be05a0d328962cb54d5',
    'domain': 'common',
    'ts': '1705296859033'
    }

response=requests.post(url=post_url,headers=headers,params=params)

dic_obj=response.json()

file_name=kw+'.json'

with open(file_name,'w',encoding='utf-8') as fp:
    json.dump(obj=dic_obj,fp=fp,ensure_ascii=False)

print('over!!!')

