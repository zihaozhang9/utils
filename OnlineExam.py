#牛客网-我自己的输入方式
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



#赛码网-我自己的输入方式。区别：测试用例是循环输入的
def decIn(Str_in):
    line = Str_in.strip().split()
    try:
        line = [int(i) for i in line]
    except:
        print('input error')
        exit()
    return line
def read1():
    return decIn(input())
def readN(hang):
    tmp = []
    while len(tmp)<hang:
        tmp.append( read1() )
    return tmp
def findt(v,gsn, tong):
    for vv in v:
        if not str(vv) in tong:
            tong.add(str(vv))
            findt(gsn[vv],gsn,tong)
while 1:            
    N,M = read1()
    gs = readN(M)
    print(N,M)
    print(gs)

#赛码网别人的输入方式
nm = list(map(int,input().split(" ")))
