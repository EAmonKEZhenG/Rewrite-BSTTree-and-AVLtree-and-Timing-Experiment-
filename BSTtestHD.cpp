#include <iostream>
#include <vector>
#include <utility> // pair
#include "BinarySearchTree.h"
using namespace std;

    // Test program
int main( )
{
    cout << "----------This is a Test Program to Test BSTree Height and Depth function----------" << endl << endl;
    BinarySearchTree<int> t;
    BinarySearchTree<int> t2;

    int NUMS = 10;
    const int GAP  = 3 ;
    const int CAP  = 19;
    int i;
    int key ;

    cout << "Start of BSTtest" << endl;
    key = CAP/2;
    // insert first tree;
    for(int i = 0 ; i < NUMS ; i++ ){
         key = (key + GAP) % CAP ;
         t.insert( key );
       
    }
//insrt second tree with double data;
    for(int i = 0 ; i < 2*NUMS ; i++ ){
        key = (key + GAP) % CAP ;
         t2.insert( key );
    }

//print two trees;
    cout << "Dispklay first BST tree: " << endl;
    cout << "Keys:" << endl ;
    t.printTree( );
    cout << "Tree:" << endl ;
    t.displayTree(); 
    

    cout << "Display second BST tree: " << endl;
    cout << "Keys:" << endl ;
    t2.printTree( );
    cout << "Tree:" << endl ;
    t2.displayTree(); 
    
    cout << "Testing HeightAndDepth Program:" << endl ;
    std::pair<int,double> p1 = t.heightAndDepth(); //get pair of height and depth
    std::pair<int, double> p2 = t2.heightAndDepth();
    cout << "First Tree Height is: " << p1.first << ", Depth is: " << p1.second << ". "<< endl; 
    cout << "Second Tree Height is: " << p2.first << ", Depth is: " << p2.second << ". "<< endl;
    
    cout << endl << "End of BSTtree HeightAndDepth test Program." << endl;

    return 0;
}
