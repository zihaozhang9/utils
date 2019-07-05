if false
then
 echo 'install env'
 conda install -y tensorflow-gpu
 pip install sh
 pip install tqdm
 apt-get update
 apt install -y wget
fi

if false
then
 echo 'processing data'
 wget https://www.cs.toronto.edu/~kriz/cifar-10-python.tar.gz
 tar -zxf cifar-10-python.tar.gz
 if [ ! -d data  ];then
   mkdir data
 fi
 mv cifar-10-batches-py data/cifar10
fi

if false
then
 echo 'start run'
 python -u xxx.py 2>&1 | tee xxx.log 
fi


echo 'start sleep'
sleep 3d
