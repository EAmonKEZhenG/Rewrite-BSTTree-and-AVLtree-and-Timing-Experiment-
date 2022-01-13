#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "dsexceptions.h"
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;       

// BinarySearchTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// void displayTree()     --> Print the tree structure
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class BinarySearchTree
{
  public:
    BinarySearchTree( ) : root{ nullptr }
    {
    }

    /**
     * Copy constructor
     */
    BinarySearchTree( const BinarySearchTree & rhs ) : root{ nullptr }
    {
        root = clone( rhs.root );
    }

    /**
     * Move constructor
     */
    BinarySearchTree( BinarySearchTree && rhs ) : root{ rhs.root }
    {
        rhs.root = nullptr;
    }
    
    /**
     * Destructor for the tree
     */
    ~BinarySearchTree( )
    {
        makeEmpty( );
    }

    /**
     * Copy assignment
     */
    BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        BinarySearchTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move assignment
     */
    BinarySearchTree & operator=( BinarySearchTree && rhs )
    {
        std::swap( root, rhs.root );       
        return *this;
    }
    
    
    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMin( root )->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMax( root )->element;
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == nullptr;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            printTree( root, out );
    }

    /**
     * Print the tree structure in sorted order.
     */
    void displayTree( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            displayTree( root, 0, out );
    }
/**
     * Print the tree structure and each datalink in sorted order.
     */
    void displayLinks( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            displayLinks( root, 0, out );
    }

/**
     * return a vector that include the Range which is user given.
     */
    std::vector<Comparable> InRange(Comparable low, Comparable high, ostream & out = cout)
    {
        std::vector<Comparable> v;
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else        
            InRangeHelper(root, v, low, high, out);

        return v;
    }

/**
     * calculas the mean Depth of the tree.
     */
    double Depth() 
    {
        if( isEmpty( ) )
        {
            return 0.0;
        }
            
        else
        {
            double Depth =totalDepth(root);    
            int Node = totalNode(root);
            return Depth/Node;
        }
    }

/**
     * calculas the total height of the tree.
     */
    int totalHeight()
    {
        if(isEmpty())
        {
            return 0;
        }
        else
        {
            return totalHeight(root);
        }
    }

/**
     * Return A pair that include the Height with int data type and Depth with double data type.
     */
    std::pair<int,double> heightAndDepth(ostream & out = cout)
    {
        pair<int, double> p1;
        if(isEmpty())
        {
            out << "Empty tree" << endl;
            pair<int, double> p1(0,0.0);
            return p1;
        }
        else
        {
             pair<int, double>  p1(totalHeight(), Depth());
           
            return p1;
        }
    }



    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        makeEmpty( root );
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const Comparable & x )
    {
        insert( x, root );
    }
     
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( Comparable && x )
    {
        insert( std::move( x ), root );
    }
    
    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const Comparable & x )
    {
        remove( x, root );
    }

  private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
          : element{ theElement }, left{ lt }, right{ rt } { }
        
        BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt )
          : element{ std::move( theElement ) }, left{ lt }, right{ rt } { }
    };

    BinaryNode *root;


    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, BinaryNode * & t )
    {
        if( t == nullptr )
            t = new BinaryNode{ x, nullptr, nullptr };
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else
            ;  // Duplicate; do nothing
    }
    
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( Comparable && x, BinaryNode * & t )
    {
        if( t == nullptr )
            t = new BinaryNode{ std::move( x ), nullptr, nullptr };
        else if( x < t->element )
            insert( std::move( x ), t->left );
        else if( t->element < x )
            insert( std::move( x ), t->right );
        else
            ;  // Duplicate; do nothing
    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( const Comparable & x, BinaryNode * & t )
    {
        if( t == nullptr )
            return;   // Item not found; do nothing
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            BinaryNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }
    }

   

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode * findMin( BinaryNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        if( t->left == nullptr )
            return t;
        return findMin( t->left );
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode * findMax( BinaryNode *t ) const
    {
        if( t != nullptr )
            while( t->right != nullptr )
                t = t->right;
        return t;
    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        if( t == nullptr )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }
/****** NONRECURSIVE VERSION*************************
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        while( t != nullptr )
            if( x < t->element )
                t = t->left;
            else if( t->element < x )
                t = t->right;
            else
                return true;    // Match

        return false;   // No match
    }
*****************************************************/

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( BinaryNode * & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( BinaryNode *t, ostream & out ) const
    {
        if( t != nullptr )
        {
            printTree( t->left, out );
            out << t->element << endl;
            printTree( t->right, out );
        }
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void displayTree( BinaryNode *t, int depth, ostream & out ) const
    {
        const int SHIFT = 4 ;
        if( t != nullptr )
        {
            for( int i = 0 ; i < SHIFT*depth ; i++ ){ out << " " ; }
            out << t->element << endl;
            displayTree( t->left, depth+1, out );
            displayTree( t->right, depth+1, out );
        }
    }
 /**
     * Internal method to print tree t data and link.
     */
    void displayLinks( BinaryNode *t, int depth, ostream& out) const
    {
        const int SHIFT = 4 ;
            if( t != nullptr )
            {
                for( int i = 0 ; i < SHIFT*depth ; i++ ){ out << " " ; }
                out << t->element << ") @:" << &t->element <<" L:" << t->left << " R:" << t->right<< endl;
                displayLinks( t->left, depth+1, out );
                displayLinks( t->right, depth+1, out );
            }
    }

/**
     * return a vector that include the Range which is user given.
     */
    void InRangeHelper(BinaryNode *node, std::vector<Comparable> &v, Comparable low, Comparable high, ostream& out)
    {
        if(node == nullptr)
            return;
        else
        {
            InRangeHelper(node->left, v, low, high, out);
            
            if (node->element > low && node->element < high) {
                v.push_back(node->element);
            }
            
            InRangeHelper(node->right, v, low, high, out);
            
        }
    }




    double totalDepth(BinaryNode *node)
    {
        return totalDepthHelper(node, 0);
    }
   
/**
     * calculas the totalDepth of the tree.
     */
    double totalDepthHelper(BinaryNode* node, int depth)
    {
        if(node == nullptr)
        {
            return 0.0;
        }
        else
        {
            return depth + totalDepthHelper(node->left, depth+1) + totalDepthHelper(node->right, depth +1);
        }
    }

/**
     * calculas the total Node of the tree.
     */
    int totalNode(BinaryNode *node)
    {
        return totalNodeHelper(node);
    }

    int totalNodeHelper(BinaryNode* node)
    {
        if(node == nullptr)
            return 0;
        else
        {
            return 1 + totalNodeHelper(node->left) + totalNodeHelper(node->right);
        }
    }

   /**
     * calculas the total Height of the tree.
     */
    int totalHeight(BinaryNode* node)
    {
        if(node == nullptr)
        {
            return 0;
        }
        else
        {
            return 1 + max(totalHeight(node->right), totalHeight(node->left));
        }
    }
    /**
     * compare two value and return a max value.
     */
    int max(int num1, int num2)
    {
        if(num1 > num2)
        {
            return num1;
        }
            
        return num2;
    }

    

   



    /**
     * Internal method to clone subtree.
     */
    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new BinaryNode{ t->element, clone( t->left ), clone( t->right ) };
    }
};

#endif
