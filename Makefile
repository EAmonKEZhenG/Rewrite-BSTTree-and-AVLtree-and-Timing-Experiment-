all: test1 test2 test3 test4

test1: BSTtestD.cpp BinarySearchTree.h dsexceptions.h
	g++ -o test1 BSTtestD.cpp
	./test1
	
test2: BSTtestR.cpp BinarySearchTree.h dsexceptions.h
	g++ -o test2 BSTtestR.cpp 
	./test2

test3: BSTtestHD.cpp BinarySearchTree.h dsexceptions.h
	g++ -o test3 BSTtestHD.cpp
	./test3

test4: A2exp.cpp AVLTree.h dsexceptions.h
	g++ -o test4 A2exp.cpp
	./test4

clean:
	rm -f test1 test2 test3 test4

