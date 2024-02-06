#糗事网gif动图
import requests
import re
import os

if not os.path.exists('./qiushi_gifs'):
    os.mkdir('./qiushi_gifs')

f_page_url='https://xiaohua.zol.com.cn/qutu/qiushi/%d.html'

headers={
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36 Edg/120.0.0.0'
    
}

page_num=0

for page_num in range(1,36):
    folder_name=format('./qiushi_gifs/page%d'%page_num)
    
    if not os.path.exists(folder_name):
        os.mkdir(folder_name)
    
    page_url=format(f_page_url%page_num)
    
    page_text=requests.get(url=page_url,headers=headers).text

    ex='<div class="summary-text">.*?<img src="(.*?)" alt.*?</div>'

    img_src_list=re.findall(ex,page_text,re.S)

    print(img_src_list)

    for src in img_src_list:
        try:
            gif_data=requests.get(src,headers=headers).content
            gif_path=folder_name+'/'+src.split('/')[-1]
            with open(gif_path,'wb') as fp:
                fp.write(gif_data)
                print(src.split('/')[-1]+'保存完毕！')
        except OSError:
            print('OSError!')
            continue