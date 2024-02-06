import scrapy


class PicnameSpider(scrapy.Spider):
    name = "picname"
    #allowed_domains = ["www.xxx.com"]
    start_urls = ["https://pic.netbian.com/4kmeinv/index.html"]
    page_num=1
    def parse(self, response):
        if self.page_num==1:
            print('开始爬虫...')
        li_list=response.xpath('//*[@id="main"]/div[3]/ul/li')
        for li in li_list:
            pic_name=li.xpath('./a/b/text()').extract_first()
            print(pic_name)
         
        if self.page_num<=10:   
            new_url='https://pic.netbian.com/4kmeinv/index_%d.html'
            self.page_num+=1
            new_url=format(new_url%self.page_num)
            yield scrapy.Request(url=new_url,callback=self.parse)
        
        else:
            print('爬虫结束！')
