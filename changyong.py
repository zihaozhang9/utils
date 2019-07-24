import os
from os import path as osp
import shutil
import sh

##################################################################

#os path
#判断文件/路径是否存在，不存在则创建
if not os.path.exists(savePath):os.makedirs(savePath)   

#路径中的文件名
os.path.basename('http://10.60.242.105:8087/imgs/aaa') #bea8bdc84b651ef329a6e117a0a48d0a
os.path.basename('http://10.60.242.105:8087/imgs/aaa.png') #bea8bdc84b651ef329a6e117a0a48d0a.png

#切路径中的文件名
os.path.split('/home/ubuntu/python/example.py') #('/home/ubuntu/python', 'example.py')
os.path.split('/home/ubuntu/python/example') #('/home/ubuntu/python', 'example')

#切后缀
os.path.splitext('a.jpg') #('a', '.jpg')
os.path.splitext('c:/b/a.jpg') #('c:/b/a', '.jpg')

os.remove(path)   #删除文件
os.removedirs(path)   #删除空文件夹


##################################################################

#shutil

#删除文件夹 https://blog.csdn.net/xiaodongxiexie/article/details/77155864
#拷贝文件夹 https://blog.csdn.net/chaipp0607/article/details/60779129
#拷贝非空文件夹，判断是否存在，如果存在递归删除，再拷贝
if os.path.exists(dst):
    shutil.rmtree(dst) 
    shutil.copytree(src, dst)

##如果存在，则删除，再创建目录
if os.path.exists(dst):shutil.rmtree(dst) 
os.makedirs(dst)   

##################################################################
#sh
#python中执行linux命令
#复制 https://www.programcreek.com/python/example/96729/sh.cp
sh.cp(src,dst)
sh.cp('-R',src,dst)

#新建文件夹
sh.mkdir("-p", root)

#下载文件
sh.wget("-O", dst_path , label.image.image_url)

#删除文件
sh.rm(imgp)


##################################################################

#opencv cv2

#resize
#cv2.resize(src,dsize,dst=None,fx=None,fy=None,interpolation=None)
#scr:原图,dsize：输出图像尺寸,fx:沿水平轴的比例因子,fy:沿垂直轴的比例因子,interpolation：插值方法
img = cv2.resize(img,(640,640))

#长边resize
w = h = 640
img_width,img_height = img.shape[1],img.shape[0]
scale = float(w)/max(img_width,img_height)
height = int(img_height * scale)
width = int(img_width * scale)       
img = cv2.resize(img,(width, height))

#短边padding
img = np.array(img, dtype=np.uint8)
canvas = np.full((w, h, 3), 128,dtype=np.uint8)
canvas[0:height,0:width,  :] = img

#保存图像
cv2.imwrite(os.path.join(savePath,imgName),img)

def pil2cv(img):
    return cv2.cvtColor(np.array(img),cv2.COLOR_RGB2BGR)

def cv2pil(img):
    return Image.fromarray(cv2.cvtColor(img,cv2.COLOR_BGR2RGB))
    

#outhtml.py,需要完善
import os
import cv2
import shutil
#import pdb;pdb.set_trace()
def deal(img):
    w = h = 1024
    img_width,img_height = img.shape[1],img.shape[0]
    scale = float(w)/max(img_width,img_height)
    height = int(img_height * scale)
    width = int(img_width * scale)        
    img = cv2.resize(img,(width, height))
    return img

def process(rootPath,savePath):
    if os.path.exists(savePath): shutil.rmtree(savePath) 
    os.makedirs(savePath)
    imgList = [i for i in os.listdir(rootPath) ]#if i.endswith('.bmp')]
    for idx,imgName in enumerate(imgList):
        img = cv2.imread(os.path.join(rootPath,imgName))
        #img = deal(img)
        cv2.imwrite(os.path.join(savePath,imgName),img)

def out2html(rootPath):
    f = open('out.html','w')
    f.close()
    imgList = [i for i in os.listdir(rootPath) ]#if i.endswith('.bmp')]
    #import pdb;pdb.set_trace()
    for idx,imgName in enumerate(imgList):
        f = open('out.html','a')
        wstr = '<tr><td><img src="'+os.path.join(rootPath,imgName)+'"></img></td></tr>\r\n'
        f.write(wstr)
        f.close()
        if idx>100:
            break
    print(idx+1)

def out2html2(rootPath,rootPath2):
    f = open('out.html','w')
    f.close()
    imgList = [i for i in os.listdir(rootPath) ]#if i.endswith('.bmp')]
    #import pdb;pdb.set_trace()
    for idx,imgName in enumerate(imgList):
        f = open('out.html','a')
        imgPath1 = os.path.join(rootPath,imgName)
        imgPath2 = os.path.join(rootPath2,imgName)
        wstr = '<tr><td><img src="'+imgPath1+'"></img><img src="'+imgPath2+'"></img></td></tr><br>\r\n'
        f.write(wstr)
        f.close()
        if idx>100:
            break
    print(idx+1)
rootPath = '/data/'
rootPath2= 'outputs'
savePath = 'tmpdata/draws'
process(rootPath,savePath)
out2html(rootPath)
out2html2(savePath,rootPath2)


