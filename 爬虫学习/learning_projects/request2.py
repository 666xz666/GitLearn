#制作简易网页采集器

import requests


if __name__=='__main__':
    #UA伪装（反反爬）
    headers={
        'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36 Edg/120.0.0.0'
    }

    url='https://sogou.com/web'

    kw=input('enter a word:')

    param={
        'query':kw
    }

    response=requests.get(url=url,params=param,headers=headers)

    page_text=response.text

    file_name=kw+'.html'

    with open(file_name,'w',encoding='utf-8') as fp:
        fp.write(page_text)
        print(kw+'保存成功')
   
        
        

