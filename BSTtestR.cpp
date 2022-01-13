#include <iostream>
#include <vector>
#include "BinarySearchTree.h"
using namespace std;

    // Test program
int main( )
{
    cout << "----------This is a Test Program to Test BSTree InRange function----------" << endl << endl;

    //create two BST tree;
    BinarySearchTree<int> t;
    BinarySearchTree<int> t2;
    int NUMS = 10;
    const int GAP  = 3 ;
    const int CAP  = 19;
    int i;
    int key ;

    cout << "Start of BSTtest" << endl;
    int* temp = new int[NUMS];  // create a array which use to inset;
    key = CAP/2;

    // inset array tree;
    for(int i=0; i <NUMS;i++)
    {
        key = (key + GAP) % CAP;
        temp[i] = key;
    }
    //insert the first tree
    for(int i = 0 ; i < NUMS ; i++ ){
        t.insert(temp[i]);
    }

//inset the second tree different way with same data;
    for(int i = 0 ; i < NUMS ; i++ ){
        t2.insert(temp[NUMS-1-i]);
    }

//print first tree;
    cout << "Dispklay first BST tree: " << endl;
    cout << "Keys:" << endl ;
    t.printTree( );
    cout << "Tree:" << endl ;
    t.displayTree(); 
    
//print second tree;
    cout << "Display second BST tree: " << endl;
    cout << "Keys:" << endl ;
    t2.printTree( );
    cout << "Tree:" << endl ;
    t2.displayTree(); 
    
    cout << "Testing InRange:" << endl ;
     int low, high;//create the range;
    bool checker = false;
    while(checker == false)
   {
        cout << "Please enter the low number you want: ";
        cin >> low; //user type the range
        cout << "Please enter the high number you want: ";
        cin >> high;
        if(low > high)
            cout << "The Low number must smaller than the high number, please Re-enter." << endl;  // to make sure the user enter the low number must to smallar than the high number, if not, user should re enter new number;
        else
            checker = true;
    }
   
    cout << "Range is: " << low << " - " << high << "." << endl;
    cout << "First BSTtree: " << endl;
    vector<int> array1 = t.InRange(low, high);   // get the data from first tree which is in the range;
    if(array1.size() == 0 )
        cout << "There is no number between the range you give."; 
    for (int i = 0; i < array1.size(); i++) {
        cout << array1[i] << " ";
    }
    cout << endl << "Second BSTree: " << endl;
    vector<int> array2 = t2.InRange(low, high);  //get the data from second tree which is in the range
    if(array2.size() == 0 )
        cout << "There is no number between the range you give.";
    for (int i = 0; i < array2.size(); i++) {
        cout << array2[i] << " ";
    }
    cout << endl << "End of BSTtree InRange test Program." << endl;

    return 0;
}
