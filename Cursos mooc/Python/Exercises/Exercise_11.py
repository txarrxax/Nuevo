import re

name = input('Enter file:')
if len(name) < 1: name = 'numbers.txt'
handle = open(name)

count = 0
total = 0 
num = []

for line in handle:
	line = line.rstrip()
	x = re.findall('[0-9]+', line)
	if len(x) > 0:
		num = num + x

for item in num:
	item = int(item)
	total = total + item
	count += 1

print(total)