# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html


# useful for handling different item types with a single interface
from itemadapter import ItemAdapter


class QiubaiProPipeline:
    fp=None
    def open_spider(self,spider):
        print('开始爬虫...')
        self.fp=open('D:/_code/爬虫/temp/qiubai.txt','w',encoding='utf-8')
        
    def process_item(self,item,spider):
        name=item['name']
        content=item['content']
        self.fp.write('***'+name.strip('\n')+'***'+'\n'+content.strip('\n')+'\n')
        return item

    def close_spider(self,spider):
        self.fp.close()
        print('爬虫结束！')

#setting中启用管道