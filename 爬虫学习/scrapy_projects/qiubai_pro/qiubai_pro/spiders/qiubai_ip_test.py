import scrapy


class QiubaiIpTestSpider(scrapy.Spider):
    name = "qiubai_ip_test"
    #allowed_domains = ["www.xxx.com"]
    start_urls = ["https://ip.900cha.com/"]

    def parse(self, response):
        ip_text=response.xpath('/html/body/div/div/div/div[1]/div[1]/ul/li[3]/text()')[0].extract()
        print('ip'+ip_text)