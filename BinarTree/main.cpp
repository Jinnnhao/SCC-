
#include "BinaryTree.h"
#include <cmath>
int main() {
  BinaryTree tree;
 // create a tree with 13 nodes
 // the root will be 5 and inserting in order will give it 5 levels
  tree.insert(5);
  tree.insert(10);
  tree.insert(3);
  tree.insert(7);
  tree.insert(1);
  tree.insert(9);
  tree.insert(6);
  tree.insert(2);
  tree.insert(8);
  tree.insert(4);
  tree.insert(14);
  tree.insert(11);
  tree.insert(15);
  //print the tree in sorted order
   std::cout<<" In Order Traversal \n";
   tree.inorderTraversal();
  // get the heigth of the tree. This is the level with the greatest depth
   int height=tree.height()+1;
// get the number of nodes
   int numOfNodes=tree.getCount();
// use the formula to get the ideal number of levels in a balanced
  //binary tree
   int numOfLevels= (int)log2(numOfNodes);
   std::cout<<"The height of the tree is : "<<height<<"\n";
  std::cout<<"The number of nodes are :  "<<numOfNodes<<"\n";
  std::cout<<"The number of levels should be :  "<<numOfLevels<<"\n";
  
  //delete 4 nodes so that there is one path of depth 5 and all others are of depth 3. This makes the tree unbalanced since the difference between the height and the closest next level is greater than 1
  tree.deleteNode(2);
  tree.deleteNode(6);
  tree.deleteNode(11);
  tree.deleteNode(15);
  
  std::cout<<"\nAfter Deletion, the tree is :  \n";
  tree.inorderTraversal();
// get the details of the pruned tree, these should be same as above except numOflevels which should be smaller
   height=tree.height()+1;
   numOfNodes=tree.getCount();
   numOfLevels= (int)log2(numOfNodes);
  std::cout<<"The heigth of tree after deletion :  ="<<height<<"\n";
  std::cout<<"The number of nodes after deletion :  ="<<numOfNodes<<"\n";
//
  std::cout<<"The height of the tree should be  "<<numOfLevels<<"\n";
  // if the tree is not balanced
//  if (abs(height-numOfLevels)>1)
  // calculate the height of the tree and the idea height of the tree 

   height=tree.height()+1;
   numOfNodes=tree.getCount();
  //ideal height
   numOfLevels= (int)log2(numOfNodes);
  //see if balancing the tree is required
   if (abs(height-numOfLevels)>1)
           tree.balance();
   std::cout<<"\nAfter Balance, the tree looks like: \n";
  // Should be the same in order traversal as before
   tree.inorderTraversal();
  //new height after balancing
    height=tree.height();
  
   std::cout<<"\nNew Height after balancing  ="<<height<<"\n";

  //delete this tree
    tree.deleteTree();
  // create another tree which is a linear structure
  //height =15
  std::cout<<"\n**********Creating another Tree *********\n\n";
   tree.insert(1);
   tree.insert(2);
   tree.insert(3);
   tree.insert(4);
   tree.insert(5);
   tree.insert(6);
   tree.insert(7);
   tree.insert(8);
   tree.insert(9);
   tree.insert(10);
   tree.insert(11);
   tree.insert(12);
   tree.insert(13);
   tree.insert(14);
   tree.insert(15);
 // Dont delete nodes, just balance this tree. 
   std::cout<<" In Order Traversal \n";
   tree.inorderTraversal();
    height=tree.height();
    numOfNodes=tree.getCount();
    numOfLevels= (int)log2(numOfNodes);
    std::cout<<"The height of the tree is : "<<height<<"\n";
    std::cout<<"The number of nodes are :  "<<numOfNodes<<"\n";
    std::cout<<"The heigth of the tree should  be :  "<<numOfLevels<<"\n";
    
    if (abs(height-numOfLevels)>1)
        tree.balance();
     std::cout<<"\nAfter Balance, the tree looks like: \n";
     tree.inorderTraversal();
     height=tree.height();
     std::cout<<"\nNew Height after balancing  ="<<height<<"\n";



} 
