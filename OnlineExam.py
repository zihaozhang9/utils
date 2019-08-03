
#编程题的输入https://blog.csdn.net/m0_37134612/article/details/80763485
def decIn(Str_in):
    line = Str_in.strip().split()
    try:
        line = [int(i) for i in line]
    except:
        print('input error')
        exit()
    return line
def read1(chang):
    tmp = decIn(input())
    while len(tmp)<chang:
        tmp = decIn(input())
    return tmp
def readN(hang,chang):
    tmp = []
    while len(tmp)<hang:
        tmp.append( read1(chang) )
    return tmp
N,M = read1(2)
DP = readN(N,2)
D = [i[0] for i in DP]
P = [i[1] for i in DP]
A = read1(M)
print(N,M)
print(D,P)
print(A)
