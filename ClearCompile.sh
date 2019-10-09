a=PyTorch-YOLOv3
du -h --max-depth=0 ${a}
find ${a} -iname "__pycache__" -print -exec rm -rf {} \;
find ${a} -iname "*.so" -print -exec rm -rf {} \;
zip -r ${a}".zip" ${a}"/"
ls ${a}".zip" -sh
