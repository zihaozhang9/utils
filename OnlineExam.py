import os
import os.path as osp

def decode_input(Str_in):
	list = Str_in.strip().split()
	try:
		list =  [int(i) for i in list]
	except:
		print('input error')
		exit()
	return list

print('input:')
N,M = decode_input(input())
print('out input:')
print(N,M,type(N))
