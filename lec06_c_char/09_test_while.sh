#!/bin/sh
cc 06_random.c -o createrand -lm
i=2
while [ ${i} -le 32 ] # i が 32 以下なら do -- done を実行
do                    # [ ] の前後にはスペース必要
  echo "${i}" > read.dat # read.dat に数 (2,4,8,...) を格納
  ./createrand < read.dat
  mv rand.dat rand${i}.dat # 名前の変更
  i=`expr ${i} \* 2` # i を 2 倍する; 演算は ‘ ‘で囲んで expr を付ける
                     # 演算子記号の前後はスペースが必要
done
