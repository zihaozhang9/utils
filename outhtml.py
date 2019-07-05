import os
rootPath = 'path'#
f = open('out.html','w')
f.close()
imgList = [i for i in os.listdir(rootPath) if i.endswith('.bmp')]
for idx,imgName in enumerate(imgList):
    f = open('out.html','a')
    wstr = '<tr><td><img src="'+os.path.join(rootPath,imgName)+'"></img></td></tr>\r\n'
    f.write(wstr)
    f.close()
    #if idx>100:
    #    break
print(idx)
