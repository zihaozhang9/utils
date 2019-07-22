# cat charData/training_pad/training_pad.txt charData/test_pad/test_pad.txt > all.txt
if [ ! -d data  ];then
   mkdir data
 fi
path=/data/wangzai/images/
ls $path | sed "s:^:$path:" > all.txt
 shuf all.txt > all2.txt
 a=$(wc -l <all2.txt)
 #a,b= wc -l all2.txt#| awk '{print $1}'
 echo 'all:'$a
 test=$(($a/5))
 echo 'test:'$test
 train=$(($a-$test))
 echo 'train:'$train
 
head -$test all2.txt > data/test.txt
tail -$train all2.txt > data/train.txt
rm all.txt
rm all2.txt

 
