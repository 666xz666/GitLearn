#线程池实现异步爬虫
import requests
from bs4 import BeautifulSoup
import random
import pandas as pd
from multiprocessing.dummy import Pool


def get_video(dic):
    headers = {
        'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/106.0.0.0 Safari/537.36 Edg/106.0.1370.47'
    }
    video_data = requests.get(url=dic['url'], headers=headers).content
    print(dic['name'] + '开始下载')

    path = "./" + dic['name']

    with open(path, 'wb') as fp:
        fp.write(video_data)
    print(dic['name'] + '下载成功')

if __name__ == '__main__':
    url = "https://www.pearvideo.com/category_1"
    base_url = "https://www.pearvideo.com/"
    headers = {
        'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/106.0.0.0 Safari/537.36 Edg/106.0.1370.47'
    }
    session = requests.Session()
    person_page = session.get(url=url,headers=headers).text
    # print(person_page)
    # 使用BeautifulSoup解析这一页
    bs = BeautifulSoup(person_page, 'html.parser')
    # 使用选择器进行定位
    ## 找到a标签
    person_a = bs.select(".vervideo-bd .vervideo-lilink")
    ## 找到a标签下视频的简介
    person_content = bs.select(".vervideo-bd .vervideo-lilink .vervideo-title")
    # 保存到一个列表当中
    links = []
    conent = []
    a_size = len(person_a)
    real_videos = []
    real_urls = []
    for i in range(a_size):
        links.append(base_url + person_a[i]['href'])
        conent.append(person_content[i].string + ".mp4")
        # 获得视频的id,之后有用
        contId = person_a[i]['href'].split("_")[1]
        mrd = random.random()
        # 这个我们进入到视频界面后进行抓包可以发现需要这两个参数
        # 抓包发现的网址为:https://www.pearvideo.com/videoStatus.jsp
        # 向它发起请求会得到视频的假地址
        params = {
            "contId":contId,
            "mrd":mrd
        }
        video_url = "https://www.pearvideo.com/videoStatus.jsp"
        # 如果使用该语句会发现"视频已下线"
        # video_response = session.get(url=video_url,headers=headers,data=data).json()
        # 解决办法:往header里面加一个Referer就好
        headers["Referer"] = links[i]
        video_response = session.get(url=video_url, headers=headers, params = params).json()
        # 这是一个假的视频地址
        # 真地址其实可以在前面一个网页中找到,为:https://video.pearvideo.com/mp4/adshort/20190324/cont-1534025-13728370_adpkg-ad_hd.mp4
        # 而假地址为:https://video.pearvideo.com/mp4/adshort/20190324/1668071072522-13728370_adpkg-ad_hd.mp4
        # 通过观察可以发现后面的cont-1534025替换为了1668071072522,cont-1534025其实就是cont-videoId,则我们将假地址错误的部分替换即可
        fake_video_url = video_response['videoInfo']['videos']['srcUrl']
        ss = fake_video_url.split("/")
        end_string = ss[-1].split("-")
        end_fix = ""
        for s in range(1,len(end_string)):
            end_fix = end_fix + "-" + end_string[s]
        start_fix = ""
        for s in range(len(ss)-1):
            start_fix = start_fix + ss[s] + "/"
        real_video_url = start_fix + "cont-" + str(contId) + end_fix
        dic = {
            "url":real_video_url,
            "name":conent[i]
        }
        real_videos.append(dic)
        real_urls.append(real_video_url)
	# 下载视频
    # pool = Pool(4)
    # pool.map(get_video,real_videos)
    # pool.close()
    # pool.join()
    # 存在excel表里面
    data = pd.DataFrame({"视频简介":conent,"视频地址":real_urls})
    data.to_excel("视频信息.xlsx", sheet_name='Sheet1', index=False)
