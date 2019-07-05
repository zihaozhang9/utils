 cat charData/training_pad/training_pad.txt charData/test_pad/test_pad.txt > all.txt
 shuf all.txt > all2.txt
 a=$(wc -l <all2.txt)
 #a,b= wc -l all2.txt#| awk '{print $1}'
 echo $a
 test=$(($a/5))
 echo $test
 train=$(($a-$test))
 echo $train
 
head -$test all2.txt > test.txt
tail -$train all2.txt > train.txt
 
