#include <iostream>
#include <vector>
#include <utility>
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include <time.h>
#include <cmath>

using namespace std;


double elapsed_time( clock_t start, clock_t finish){
   // returns elapsed time in milliseconds
   return (finish - start)/(double)(CLOCKS_PER_SEC/1000);
}

int main( )
{
    cout << "----------This is a Experiment Program to test BSTtree and AVLtree insert and search time----------" << endl << endl;
    BinarySearchTree<int> t;
    AvlTree<int> a;
    // create BST tree and AVL tree

    int NUMS = 10000000; // size of two tree;

////////////////////////////////////<<Insert Experiment >> ////////////////////////////////////
    int* array = new int[NUMS];
    // create with array to make sure that two tree insert same date with same size;
    for(int i=0; i < NUMS; i++)
    {
        array[i] = rand()%NUMS+1;
    }
    clock_t start1, finish1, start2, finish2;
   
    
    cout << "Start to insert BSTtest" << endl;
    // insert BST tree
    start1 = clock();
    for(int i = 1 ; i <= NUMS ; i++ ){
        t.insert( array[i] );
    }
    finish1 = clock();
    double time1 = elapsed_time(start1, finish1);
    cout << "The BST tree insert time is: " << time1 << endl;
    pair<int, double > temp1 = t.heightAndDepth();
    cout << "The BST Height is: " << temp1.first << ", Mean Depth is: " << temp1.second << endl << endl;

    // insert AVL tree
    start2=clock();
     
    cout << "Start to insert AVLtest" << endl;
    for(int i = 1 ; i <= NUMS ; i++ ){
        a.insert( array[i] );
    }
    finish2 =clock();
    
    double time2 = elapsed_time(start2, finish2);
   
    cout << "The AVL tree insert time is: " << time2 << endl;
     pair<int, double > temp2 = a.heightAndDepth();
    cout << "The AVL Height is: " << temp2.first << ", Mean Depth is: " << temp2.second << endl << endl;
   
////////////////////////////////////<<Search Experiment >> ////////////////////////////////////
    
    clock_t start3, start4, finish3, finish4;
    cout << "Start to searsh BSTtest" << endl;
    start3 =clock();
    // Search for the same number of times as size
    //BST
    for(int i=0;i <NUMS; i++)
    {
        bool checker1 = t.contains(i);
    }
    
    finish3 = clock();
    double time3 = elapsed_time(start3, finish3);
    cout << "The BST tree search time is: " << time3 << endl << endl;

    //AVL
    cout << "Start to searsh AVLtest" << endl;
    start4 = clock();
    for(int i=0;i <NUMS; i++)
    {
        bool checker2 = a.contains(i);
    }
    
    finish4 = clock();
    double time4 = elapsed_time(start4, finish4);
    cout << "The AVL tree search time is: " << time4 << endl << endl;

    ////////////////////////////////////<<Remove Experiment >> ////////////////////////////////////
    clock_t start5, finish5, start6, finish6;
   
    
    cout << "Start to remove BSTtest" << endl;
    // remove BST tree
    start5 = clock();
    for(int i = 1 ; i <= NUMS ; i++ ){
        t.remove( array[i] );
    }
    finish5 = clock();
    double time5 = elapsed_time(start5, finish5);
    cout << "The BST tree remove time is: " << time5 << endl;
    pair<int, double > temp3 = t.heightAndDepth();
    cout << "The BST Height is: " << temp3.first << ", Mean Depth is: " << temp3.second << endl << endl;

    // insert AVL tree
    start6=clock();
     
    cout << "Start to remove AVLtest" << endl;
    for(int i = 1 ; i <= NUMS ; i++ ){
        a.remove( array[i] );
    }
    finish6 =clock();
    
    double time6 = elapsed_time(start6, finish6);
   
    cout << "The AVL tree remove time is: " << time6 << endl;
     pair<int, double > temp4 = a.heightAndDepth();
    cout << "The AVL Height is: " << temp4.first << ", Mean Depth is: " << temp4.second << endl << endl;
   

    cout << "END" << endl;

    return 0;
}
