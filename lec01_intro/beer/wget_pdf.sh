#!/bin/sh


for year in `seq 2011 1 2019`; do
  for month in `seq -f '%02g' 1 1 12`; do
    echo ${year} ${month}
    wget https://www.asahigroup-holdings.com/ir/financial_data/monthly${year}${month}.html
    mv monthly${year}${month}.html data_html/${year}_${month}.html
  done
done

#year=2020
#month=01
#wget https://www.asahigroup-holdings.com/ir/20pdf/200213.pdf
#mv 200213.pdf data_pdf/${year}_${month}.pdf

#for year in `seq 2020 1 2021`; do
#  for month in `seq -f '%02g' 1 1 12`; do
#    echo ${year} ${month}
#    wget https://www.asahigroup-holdings.com/ir/financial_data/pdf/${year}/${month}.pdf
#    mv ${month}.pdf data_pdf/${year}_${month}.pdf
#  done
#done

#for year in `seq 2022 1 2022`; do
#  for month in `seq -f '%02g' 1 1 8`; do
#    echo ${year} ${month}
#    wget https://www.asahigroup-holdings.com/ir/financial_data/pdf/${year}/${month}.pdf
#    mv ${month}.pdf data_pdf/${year}_${month}.pdf
#  done
#done
