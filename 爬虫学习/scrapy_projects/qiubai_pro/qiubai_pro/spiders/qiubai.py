import scrapy
from qiubai_pro.items import QiubaiProItem

class QiubaiSpider(scrapy.Spider):
    name = "qiubai"
    #allowed_domains = ["www.xxx.com"]
    start_urls = ["https://xiaohua.zol.com.cn/lengxiaohua/"]

    def parse(self, response):
        li_list=response.xpath('//ul[@class="article-list"]/li')
        
        for li in li_list:
            name=li.xpath('./span[2]/a/text()')[0].extract()
            content=li.xpath('./div[2]/text()').extract()
            content=''.join(content)
            
            item=QiubaiProItem()
            item['name']=name
            item['content']=content
            
            #将item送入管道
            yield item 
