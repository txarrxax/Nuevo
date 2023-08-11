import urllib.request, urllib.parse, urllib.error
import xml.etree.ElementTree as ET
import ssl

api_key = False

if api_key is False:
    api_key = 42
    serviceurl = 'http://py4e-data.dr-chuck.net/xml?'
else :
    serviceurl = 'https://maps.googleapis.com/maps/api/geocode/xml?'

ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input('Enter URL: ')
if len(url) < 1 : url = 'http://py4e-data.dr-chuck.net/comments_736155.xml'
print('Retrieving', url)

urlhandle = urllib.request.urlopen(url)
file = urlhandle.read()
print('retrieved', len(file), 'characters')

tree = ET.fromstring(file)
comments = tree.findall('.//comment')
count = 0
total = list()
for item in comments :
    count = count + 1
    number = item.find('count').text
    number = float(number)
    total.append(number)

print('Count: ', count)
print('Sum: ', sum(total))