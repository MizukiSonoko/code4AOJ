#! /bin/bash

ID=${PWD##*/}
url="http://analytic.u-aizu.ac.jp:8080/aoj/testcase.jsp"
echo ${ID}

i=0
while [ $i -ne 20 ]
do
	i=`expr $i + 1`
	request_i=${url}"?id="${PWD##*/}"&case="${i}"&type=in"
	request_o=${url}"?id="${PWD##*/}"&case="${i}"&type=out"
	echo ${request_i}
	echo ${request_o}
	curl $request_i -o i_${i}
	curl $request_o -o o_${i}

	cat i_${i} | grep "<html>"
	if [ $? -eq 0 ] ; then
		rm i_${i} o_${i} 
		break
	fi

done

make

while [ $i -ne 1 ]
do

	i=`expr $i - 1`
	./run < i_${i} > my_out_${i}
	diff -s o_${i} my_out_${i} | grep Files
	diff -q o_${i} my_out_${i} | grep Files
	rm i_${i} o_${i} my_out_${i} 

done

rm run