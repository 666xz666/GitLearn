#梨视频mp4
import requests


url='https://video.pearvideo.com/mp4/short/20230421/cont-1781504-15972096-hd.mp4'

headers={
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36 Edg/120.0.0.0'
    
}

response=requests.get(url=url,headers=headers)

with open('video.mp4','wb') as fp:
    fp.write(response.content)
    
print('over')