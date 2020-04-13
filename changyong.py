import os
from os import path as osp
import numpy as np
import json
import cv2
from PIL import Image, ImageDraw
import random
import sys
from matplotlib import pyplot as plt #%matplotlib inline
import tqdm
import shutil
import sh
#######

import argparse

import pandas as pd
import seaborn as sn
from glob import glob
import tqdm
import json
from easydict import EasyDict as edict
import hashlib
from functools import total_ordering
import glob
from utils import *
from skimage.util import montage
import csv
import random
import sys
import shutil
import shapely

from shapely.geometry import Polygon,MultiPoint

def pil2cv(img):
    return cv2.cvtColor(np.array(img),cv2.COLOR_RGB2BGR)

def cv2pil(img):
    return Image.fromarray(cv2.cvtColor(img,cv2.COLOR_BGR2RGB))


##################################################################

#字符串
#自动给数字前面补0
n = "123"
s = n.zfill(5)

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

#列举文件排序 https://blog.csdn.net/cdw_FstLst/article/details/50009203
list.sort(key=len) #按长度排序
list.sort(key = str.lower) #按字母排序
a.sort(key= lambda x:int(x[:-4])) #按数字大小排序

#解压文件https://blog.csdn.net/webzhuce/article/details/79950027
zFile = zipfile.ZipFile('zipname.zip', "r")
for fileM in zFile.namelist(): 
     zFile.extract(fileM, "savedir/")
zFile.close();
##################################################################

#shutil

#删除文件夹 https://blog.csdn.net/xiaodongxiexie/article/details/77155864
#拷贝文件夹 https://blog.csdn.net/chaipp0607/article/details/60779129
#拷贝非空文件夹，判断是否存在，如果存在递归删除，再拷贝
if os.path.exists(dst):
    shutil.rmtree(dst) 
    shutil.copytree(src, dst)

##如果存在，则删除，再创建目录
def creatdir(dst): 
    if os.path.exists(dst):shutil.rmtree(dst) 
    os.makedirs(dst) 
#或者直接创建
if not os.path.exists(dst):os.makedirs(dst) 
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

##
#json载入
result = json.loads(open(labfile).read())
#json树
aaa= {'a':{'a1':1},'b':{'b1':2,'b2':{'b22':22}}}
def dicts(t): 
    if isinstance(t,dict):
        return {k: dicts(t[k]) for k in t.keys()}
    elif isinstance(t,list):
        return str(type(t))+str(len(t))
    else:
        return str(type(t))
print(dicts(aaa))

##################################################################

#opencv cv2
#@@@@需要添加cv2.findContours等
#resize
#cv2.resize(src,dsize,dst=None,fx=None,fy=None,interpolation=None)
#scr:原图,dsize：输出图像尺寸,fx:沿水平轴的比例因子,fy:沿垂直轴的比例因子,interpolation：插值方法
img = cv2.resize(img,(640,640))

#打印文字 - 照片/添加的文字/左上角坐标/字体/字体大小/颜色/字体粗细
cv2.putText(I,'there 0 error(s):',(50,150),cv2.FONT_HERSHEY_COMPLEX,1,(0,0,255),1)

#画矩形 -     图片，左上顶底，坐下顶底，颜色，  线条粗细
cv2.rectangle(img, (x,y), (x+w,y+h), (0,255,0), 2)

#画多边形
cv2.polylines(img,[pts],True,(0,255,255))

#绘图trick
img[mask==255] = ( 0.7*img[mask==255]+0.3*np.array([0,0,255]) ).astype(np.uint8)

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

#padding函数
def cv_padding():
    #https://www.jianshu.com/p/d9e982f6046a
    img_path = '00043.jpg'
    img = cv2.imread(img_path) 
    width = img.shape[1]
    heigh = img.shape[0]
    padding = abs(width-heigh)
    if width>heigh:
        img = cv2.copyMakeBorder(img,padding//2, padding-padding//2, 0, 0 ,cv2.BORDER_CONSTANT,(0,0,0) )#top, bottom, left, right 
    else:
        img = cv2.copyMakeBorder(img,0, 0, padding//2, padding-padding//2,cv2.BORDER_CONSTANT,(0,0,0) )#top, bottom, left, right 
    cv2.imwrite('temp.jpg',img)

#padding函数
from PIL import Image,ImageOps
def pil_padding():
    #https://blog.csdn.net/WYXHAHAHA123/article/details/88092722
    img_path = '42vehicle_0000041.jpg'
    img = Image.open(img_path).convert('RGB')
    width = img.width
    heigh = img.height
    padding = abs(width-heigh)
    if width>heigh:
        constant2=ImageOps.expand(img, border=(0,padding//2,0,padding-padding//2), fill=0)##left,top,right,bottom
    else:
        constant2=ImageOps.expand(img, border=(padding//2,0,padding-padding//2,0), fill=0)##left,top,right,bottom
    constant2.save('temp.jpg')

#pil crop 
#https://www.cnblogs.com/way_testlife/archive/2011/04/17/2019013.html
from PIL import Image
img = Image.open(img_path).convert('RGB')
img = img.crop((left,top,right,bottom))
img.save(save_path)
    
#https://blog.csdn.net/guyuealian/article/details/86488008
#计算相交面积、交并比
def claOverlapArea(ocr_dict,string_label):
    cx1 = ocr_dict['x1']
    cy1 = ocr_dict['y1']
    cx2 = ocr_dict['x2']
    cy2 = ocr_dict['y2']

    gx1 = string_label['x1']
    gy1 = string_label['y1']
    gx2 = string_label['x2']
    gy2 = string_label['y2']

    x1 = max(cx1, gx1)
    y1 = max(cy1, gy1)
    x2 = min(cx2, gx2)
    y2 = min(cy2, gy2)
    w = max(0, x2 - x1)
    h = max(0, y2 - y1)
    area = w * h
    
    S_rec1 = (cx2 - cx1) * (cy2 - cy1)# C area
    S_rec2 = (gx2 - gx1) * (gy2 - gy1)# g area
    iou = area / (S_rec1 + S_rec2 - area)
    
    return area,iou

#计算旋转矩形相交面积
def claOverlapPolygonArea(char_dict,line_dict):
    from shapely.geometry import Polygon,MultiPoint
    a=char_dict['bboxs'].reshape(4, 2)
    poly1 = Polygon(a).convex_hull
    b=line_dict['bboxs'].reshape(4, 2)
    poly2 = Polygon(b).convex_hull
    if not poly1.intersects(poly2):
        return 0
    inter_area = poly1.intersection(poly2).area
    return inter_area

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
    
    
def out2html_ex(rootPath,rootPath2):
    f = open('out.html','w')
    f.close()
    imgList = [i for i in os.listdir(rootPath) ]#if i.endswith('.bmp')]
    imgList2 = [i.split('.')[0] for i in os.listdir(rootPath2) ]
    #import pdb;pdb.set_trace()
    count  = 0
    for idx,imgName in enumerate(imgList):
        imgName_ex = imgName.split('.')[0]
        if imgName_ex in imgList2: continue
        f = open('out.html','a')
        wstr = '<tr><td><img src="'+os.path.join(rootPath,imgName)+'"></img></td></tr>\r\n'
        f.write(wstr)
        f.close()
        #if idx>100:
        #    break
        count += 1
    print(count)
    
rootPath = '/data/'
rootPath2= 'outputs'
savePath = 'tmpdata/draws'
process(rootPath,savePath)
out2html(rootPath)
out2html2(savePath,rootPath2)

#torch
#torch.load gpu<-->cpu
#https://www.cnblogs.com/xiaodai0/p/10413711.html
#cpu -> gpu 1
torch.load('modelparameters.pth', map_location=lambda storage, loc: storage.cuda(1))
#gpu -> cpu
torch.load('modelparameters.pth', map_location=lambda storage, loc: storage)


#qt
pyside2-uic -o 1.py package.ui #ui转py https://zhuanlan.zhihu.com/p/75637361
#pycharm配置qt https://www.jianshu.com/p/5b063c5745d0
#qt demo https://www.cnblogs.com/linyfeng/p/11223707.html

