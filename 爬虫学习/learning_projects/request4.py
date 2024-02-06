#豆瓣喜剧排行榜
import requests

import json

url='https://movie.douban.com/j/chart/top_list'

headers={
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36 Edg/120.0.0.0'

}

param={
   'type':'24',
   'interval_id':'100:90',
   'action':'',
   'start':'0',
   'limit':'20'
}

response=requests.get(url=url,params=param,headers=headers)

dic_obj=response.json()

file_name='./douban.json'

with open(file_name,'w',encoding='utf-8') as fp:
    json.dump(obj=dic_obj,fp=fp,ensure_ascii=False)

print('over!!!')

