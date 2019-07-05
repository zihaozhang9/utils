for i in data/labels/*.txt
do
  cat $i >> all.txt
done
cat all.txt | sed 's/.bmp/.bmp /' > all2.txt
cat all2.txt | sed 's/images/data\/images/' > all3.txt
shuf all3.txt > all.txt
head -2000 all.txt > test.txt
tail -10000 all.txt > train.txt
