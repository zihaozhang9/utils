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
rootPath = '/data/'
rootPath2= 'outputs'
savePath = 'tmpdata/draws'
process(rootPath,savePath)
out2html(rootPath)
out2html2(savePath,rootPath2)


