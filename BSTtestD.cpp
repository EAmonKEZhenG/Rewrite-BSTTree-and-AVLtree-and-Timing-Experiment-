#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

    // Test program
int main( )
{

    cout << "----------This is a Test Program to Test BSTree displaylink function----------" << endl << endl;
    BinarySearchTree<int> t;
    int NUMS = 10;
    const int GAP  = 3 ;
    const int CAP  = 19;
    int i;
    int key ;

    cout << "Start of BSTtest" << endl;
//insert the BSTtree.
    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        t.insert( key );
    }

    cout << "Keys:" << endl ; //out the tree value;
    t.printTree( );
    cout << "Tree:" << endl ; //out the tree;
    t.displayTree(); 
    cout << "Links:" << endl ; //out the tree data link;
    t.displayLinks(); 
    

    cout << "End of BSTree displaylink test program." << endl << endl;

    return 0;
}
