from urllib.request import urlopen
from bs4 import BeautifulSoup
import ssl


ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input('Enter - ')
if len(url) < 1 : url = 'http://py4e-data.dr-chuck.net/comments_736153.html'
html = urlopen(url, context=ctx).read()
soup = BeautifulSoup(html, "html.parser")

count = 0
total = 0 

tags = soup('span')

for tag in tags:
	total = total + int(tag.contents[0])
	count = count + 1
print('Count:', count)
print('Sum:', total)