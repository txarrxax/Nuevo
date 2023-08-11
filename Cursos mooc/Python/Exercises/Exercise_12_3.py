import urllib.request, urllib.parse, urllib.error
from bs4 import BeautifulSoup
import ssl

ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input('Enter URL: ')
if len(url) < 1 : url='http://py4e-data.dr-chuck.net/known_by_Simonne.html'
count = int(input('Enter count: '))
pos = int(input('Enter position: '))

print('Retrieving:', url)

while count > 0 :
	html = urllib.request.urlopen(url, context=ctx).read()
	soup = BeautifulSoup(html, 'html.parser')

	links = list()

	tags = soup('a')

	for tag in tags:
		link = tag.get('href', None)
		links.append(link)
	url = links[pos-1]
	print('Retrieving:', url)
	count = count - 1