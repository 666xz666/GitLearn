from pdfminer.high_level import extract_text
import re

def pdf_to_text(pdf_path,txt_path):
    # 使用 extract_text 函数提取 PDF 文件的文本内容
    content = extract_text(pdf_path)
    
    # 使用正则表达式替换特殊字符
    # content = re.sub(r'[^\w\s\n]', ' ', content)
    
    with open(txt_path,'w',encoding='utf-8') as fp:
        fp.write(content)

# 使用函数
pdf_path = r'D:\_code\爬虫\temp\50E9CDB7DC98C9A51948E05EA2D_321FA463_38E26.pdf'  # 你的 PDF 文件路径
txt_path='./temp/xiaogui.txt'
text = pdf_to_text(pdf_path,txt_path)

