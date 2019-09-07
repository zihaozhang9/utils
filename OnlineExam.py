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

A = [[2],[3,4],[5,4,3]]
B = [[True]*len(i) if type(i)==list else True for i in A]
B = [[True], [True, True], [True, True, True]]

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



#depth_first_search
#breadth_first_search
#赛码网例题https://discuss.acmcoder.com/topic/5d47dfa8b99ad44605a1700b
#csdn示例https://blog.csdn.net/changyuanchn/article/details/79008760

#      1
#  （2     3）
# （4 5）（6 7）
# （8）
#一种图结构
#dfs：12485367
#bfs: 12345678
#因为1连接的边23不会有重复
#在python中用dict{set(),set(),set()}的格式存储最好

'''
    -图的遍历
    初始化：要有图的结构变量
    添加边功能
    （所有节点都有边连接关系，不会有不连接的，所以不需要添加节点功能）
    广度优先搜索功能bfs:
        非递归方式：
            queue负责下次遍历的节点
        递归方式：
            queue下一次遍历的节点
            
    深度优先搜索功能dfs:非递归方式
                        递归方式
'''
class Graph:
    def __init__(self):
        self.edge={}
    def addEdge(self,a,b):
        if not a in self.edge.keys():
            self.edge[a] = set()
        self.edge[a].add(b)
    def bfs(self,node):#非递归，循环方式
        queue,order = [], []
        queue.append(node)
        order.append(node)
        while queue:
            v = queue.pop(0)
            for vv in self.edge[v]:
                if vv not in order:
                    order.append(vv)
                    queue.append(vv)
        return order
    def bfs2(self,node,order=[],queue=[]):#递归方式
        if not type(node)==list : node = [node]
        for n in node:
            if not n in order:
                order.append(n)
                for v in self.edge[n]:
                    queue.append(v)
        if len(queue)>0:self.bfs2(queue,order,[])
        return order
    #dfs非递归，太难实现    
    def dfs(self, node, order=[]): #dfs 递归方式
        order.append(node)
        for v in self.edge[node]:
            if not v in order:
                self.dfs(v, order)
        return order
        
#Test Case

def main(): 
    sides=[(1, 2),
        (1, 3),
        (2, 4),
        (2, 5),
        (4, 8),
        (5, 8),
        (3, 6),
        (3, 7),
        (6, 7)]
    g = Graph()
    for s in sides:
        g.addEdge(s[0],s[1])
        g.addEdge(s[1],s[0])
    #print(g.bfs(1))
    #import pdb;pdb.set_trace()
    #print(g.bfs2(1))
    print(g.dfs(1))
if __name__ == "__main__":
    main() 

    
#https://baike.baidu.com/item/%E7%AD%89%E5%B7%AE%E6%95%B0%E5%88%97%E6%B1%82%E5%92%8C%E5%85%AC%E5%BC%8F
#等差数列通项公式
#an = a1+(n-1)*d
def an(a1,n,d=1):
    return a1+(n-1)*d
print(an(1,3,2))#1,3,5,7,9 ->out 5

    
#等差数列前n项和
#Sn = n*a1+n*(n-1)*d/2
def Sn(a1,n,d=1):
    return n*a1+n*(n-1)*d/2    
print(Sn(1,3,2))#1,3,5,7,9 ->out 9.0

#https://baike.baidu.com/item/%E7%AD%89%E6%AF%94%E6%95%B0%E5%88%97%E6%B1%82%E5%92%8C%E5%85%AC%E5%BC%8F
#等比数列通项公式
#an = a1*q^(n-1)
def an(a1,n,q=1):
    return a1*pow(q,n-1)   
print(an(1,3,3))#1,3,9,27 ->out 9

#等比数列前n项和
#Sn = a1*(1-q^n)/(1-q)
def Sn(a1,n,q=1):
    return a1*(1-pow(q,n))/(1-q)    
print(Sn(1,3,3))#1,3,9,27 ->out 13.0
