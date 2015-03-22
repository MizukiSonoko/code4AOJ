#! /bin/bash

echo -n "Which problem do you want to do? " 
read question

echo -n "You want to do this question?:"${question}" [y/n]"
read answer
if [ ${answer} != "y" ] ; then
	exit 1
else
	mkdir ${question}
	cd ${question}
	cp ../template/cpp_solv.cpp .
	cp ../template/Makefile .
	cp ../template/commit.sh .
	make
	./run
	rm run
fi