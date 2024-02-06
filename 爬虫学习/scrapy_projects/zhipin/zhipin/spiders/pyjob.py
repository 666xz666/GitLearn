import scrapy


class PyjobSpider(scrapy.Spider):
    name = "pyjob"
    #allowed_domains = ["www.xxx.com"]
    start_urls = ["https://www.zhipin.com/web/geek/job?query=&city=101240700&position=100109"]
    def parse_detail(self, response):
        detail_text=response.xpath('//*[@id="main"]/div[3]/div/div[2]/div[1]/div[2]/text()').extract()
        print(detail_text)
        
    def parse(self, response):
        
        
        li_list=response.xpath('//*[@id="wrap"]/div[2]/div[2]/div/div[1]/div[2]/ul/li')
        print('爬虫开始...')
        print(li_list)
        
        with open(r'D:\_code\爬虫\temp\page.html','w',encoding='utf-8') as fp:
            fp.write(response.body.decode('utf-8'))
        
        for li in li_list:
            job_name=li.xpath('./div[1]/a/div[1]/span[1]').extract_first()
            job_addr=li.xpath('./div[1]/a/div[1]/span[2]/span/text()').extract_first()
            detail_url='https://www.zhipin.com/'+li.xpath('./div[1]/a/@href').extract()
            print(job_name,job_addr)
            scrapy.Request(url=detail_url,callback=self.parse_detail)
            
        print('爬虫结束！')
            
