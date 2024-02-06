import shutil
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
import os

# 指定驱动目标位置
folder_path = os.path.dirname(os.path.abspath(__file__))
file_path = os.path.join(folder_path, 'chromedriver.exe')

# 使用ChromeDriverManager安装ChromeDriver，并获取驱动程序的路径
download_driver_path = ChromeDriverManager().install()

# 复制文件到目标位置
shutil.copy(download_driver_path, file_path)

# 创建Chrome WebDriver，并指定驱动路径
driver = webdriver.Chrome(service=Service(file_path))

# 打开百度网页
driver.get("https://www.baidu.com")
