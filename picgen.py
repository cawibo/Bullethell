from random import randint

for a in range(128):
	rowlist = []
	for b in range(8):
		rowlist.append(str(randint(0,255)))
	out = ", ".join(rowlist)
	print(out + ",")

for a 
