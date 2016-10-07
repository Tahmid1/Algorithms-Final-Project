/*Dylan Jeffers
 *Tahmid Rahman
 *founders of RahmROMJeffers ltd.
 * 
 *Test script for BST and AVL - AVL tests
 *are at the bottom of the script 
 */ 


#include <stdlib.h>  // Used for pseudo-random number generation.
#include <assert.h>  // Used for testing below.

#include "pair.h"
#include "BST.h"
#include "linkedBST.h"
#include "library/circularArrayList.h"
#include "library/queue.h"
#include "AVLTree.h"

using namespace std;

void insertTest();
void updateTest();
void removeTest();
void findTest();
void testMaxMin();
void testgetHeight();
void AVLInsertTest();
void AVLRemoveTest();

int main() {
  insertTest();
  updateTest();
  removeTest();
  findTest();
  testMaxMin();
  testgetHeight();
  AVLInsertTest();
  AVLRemoveTest();
  return 0;
}

/* Follow this template for writing new functions.
 * 1. return type void, no paramters
 * 2. No input/output
 * 3. use asserts to detect failures
 * 4. No memory leaks!
 * 5. Each function should be stand alone i.e., I can copy and paste it
 *    or rename it and it will still work
 * 6. You can create a few long tests or lots of short ones
 */

/* insertTest - accomplishes the following
 *    *tests getSize
 *
 *    *ensures a new tree is indeed empty
 *
 *    *ensures each insert increases the size by 1
 *
 *    *tests contains method with items going down right
 *     and with items going down left
 *
 *    *tests that each inserted element is in the tree
 *    
 *    *tests that each inserted element is in the right spot
 *     by checking all four traversal algorithms on all five
 *     elementary subtrees (i.e. with 3 nodes)
 */
void insertTest(){
  LinkedBST<int,int> BST;
  LinkedBST<int, char> SBST1, SBST2, SBST3, SBST4, SBST5;
  Queue< Pair<int,char> >* queue1;
  Queue< Pair<int,char> >* queue2; 
  Queue< Pair<int,char> >* queue3; 
  Queue< Pair<int,char> >* queue4; 

  assert(BST.getSize() == 0);  // Checks that initial size is correct.  assert
                               // causes the program to immediately crash if
                               // the condition is false.
  
  for (int i = 0; i < 100; ++i) {
    BST.insert(2*i + 1, i);
    assert(BST.getSize() == i+1);
  }  
  for (int i = 0; i < 100; ++i) {  // Checks that keys are in the tree.
    assert(BST.contains(2*i + 1));
  }

  for (int i = 0; i < 100; ++i) {
    BST.insert(-2*i - 1, i);
    assert(BST.getSize() == i+1 + 100);
  }  
  for (int i = 0; i < 100; ++i) {  // Checks that keys are in the tree.
    assert(BST.contains(-2*i - 1));
  }

  for (int i = 0; i < 100; ++i) {  //Error returned if key already exists.
    try{
      BST.insert(2*i + 1, i);
      assert(false);
    } catch(runtime_error& exc){}
  }
 
  //===============================================

  /* The following tests each tree traversal algorithm on
   * all five elementary subtrees.
   */

  SBST1.insert(1, 'A');
  SBST1.insert(2, 'B');
  SBST1.insert(3, 'C');

  queue1 = SBST1.getPostOrder();
  queue2 = SBST1.getPreOrder();
  queue3 = SBST1.getInOrder();
  queue4 = SBST1.getLevelOrder();

  assert(queue1->dequeue().second == 'C');
  assert(queue1->dequeue().second == 'B');
  assert(queue1->dequeue().second == 'A');

  assert(queue2->dequeue().second == 'A');
  assert(queue2->dequeue().second == 'B');
  assert(queue2->dequeue().second == 'C');

  assert(queue3->dequeue().second == 'A');
  assert(queue3->dequeue().second == 'B');
  assert(queue3->dequeue().second == 'C');

  assert(queue4->dequeue().second == 'A');
  assert(queue4->dequeue().second == 'B');
  assert(queue4->dequeue().second == 'C');

  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;

  //===============================================

  SBST2.insert(3, 'C');
  SBST2.insert(2, 'B');
  SBST2.insert(1, 'A');

  queue1 = SBST2.getPostOrder();
  queue2 = SBST2.getPreOrder();
  queue3 = SBST2.getInOrder();
  queue4 = SBST2.getLevelOrder();

  assert(queue1->dequeue().second == 'A');
  assert(queue1->dequeue().second == 'B');
  assert(queue1->dequeue().second == 'C');

  assert(queue2->dequeue().second == 'C');
  assert(queue2->dequeue().second == 'B');
  assert(queue2->dequeue().second == 'A');

  assert(queue3->dequeue().second == 'A');
  assert(queue3->dequeue().second == 'B');
  assert(queue3->dequeue().second == 'C');

  assert(queue4->dequeue().second == 'C');
  assert(queue4->dequeue().second == 'B');
  assert(queue4->dequeue().second == 'A');

  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;


  //===============================================

  SBST3.insert(2, 'B');
  SBST3.insert(1, 'A');
  SBST3.insert(3, 'C');

  queue1 = SBST3.getPostOrder();
  queue2 = SBST3.getPreOrder();
  queue3 = SBST3.getInOrder();
  queue4 = SBST3.getLevelOrder();

  assert(queue1->dequeue().second == 'A');
  assert(queue1->dequeue().second == 'C');
  assert(queue1->dequeue().second == 'B');

  assert(queue2->dequeue().second == 'B');
  assert(queue2->dequeue().second == 'A');
  assert(queue2->dequeue().second == 'C');

  assert(queue3->dequeue().second == 'A');
  assert(queue3->dequeue().second == 'B');
  assert(queue3->dequeue().second == 'C');

  assert(queue4->dequeue().second == 'B');
  assert(queue4->dequeue().second == 'A');
  assert(queue4->dequeue().second == 'C');

  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;



  //===============================================

  SBST4.insert(3, 'C');
  SBST4.insert(1, 'A');
  SBST4.insert(2, 'B');

  queue1 = SBST4.getPostOrder();
  queue2 = SBST4.getPreOrder();
  queue3 = SBST4.getInOrder();
  queue4 = SBST4.getLevelOrder();

  assert(queue1->dequeue().second == 'B');
  assert(queue1->dequeue().second == 'A');
  assert(queue1->dequeue().second == 'C');

  assert(queue2->dequeue().second == 'C');
  assert(queue2->dequeue().second == 'A');
  assert(queue2->dequeue().second == 'B');

  assert(queue3->dequeue().second == 'A');
  assert(queue3->dequeue().second == 'B');
  assert(queue3->dequeue().second == 'C');

  assert(queue4->dequeue().second == 'C');
  assert(queue4->dequeue().second == 'A');
  assert(queue4->dequeue().second == 'B');

  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;


  //===============================================

  SBST5.insert(1, 'A');
  SBST5.insert(3, 'C');
  SBST5.insert(2, 'B');

  queue1 = SBST5.getPostOrder();
  queue2 = SBST5.getPreOrder();
  queue3 = SBST5.getInOrder();
  queue4 = SBST5.getLevelOrder();

  assert(queue1->dequeue().second == 'B');
  assert(queue1->dequeue().second == 'C');
  assert(queue1->dequeue().second == 'A');

  assert(queue2->dequeue().second == 'A');
  assert(queue2->dequeue().second == 'C');
  assert(queue2->dequeue().second == 'B');

  assert(queue3->dequeue().second == 'A');
  assert(queue3->dequeue().second == 'B');
  assert(queue3->dequeue().second == 'C');

  assert(queue4->dequeue().second == 'A');
  assert(queue4->dequeue().second == 'C');
  assert(queue4->dequeue().second == 'B');

  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;
}


/* updateTest - accomplishes the following
 *    *tests that update returns error if key is
 *     not in tree
 *     
 *    *tests that each updated element is in the right spot
 *     by checking on all five elementary subtrees (i.e. with 3 nodes) 
 */
void updateTest(){
  LinkedBST<int, char> SBST1, SBST2, SBST3, SBST4, SBST5;
  Queue< Pair<int,char> >* queue;
  LinkedBST<int, int> BST;

  assert(BST.getSize() == 0);  // Checks that initial size is correct.  
  
 try{ // errors returned when key does not exist in subtree
      BST.update(5, 10);
      assert(false);
  } catch(runtime_error& exc){}
                         
  for (int i = 0; i < 100; ++i) { //inserts and updates 100 elements
    BST.insert(2*i + 1, i);
    assert(BST.contains(2*i + 1));
    BST.update(2*i + 1, 2*i);
    assert(BST.getSize() == i+1);
  }

 try{
      BST.update(2*99 + 2, 100);
      assert(false);
  } catch(runtime_error& exc){}

  for (int i = 0; i < 100; ++i) {  // Checks that keys haven't been changed
    assert(BST.contains(2*i + 1));
  }

  SBST1.insert(1, 'A');
  SBST1.insert(2, 'B');
  SBST1.insert(3, 'C');
  SBST1.update(2, 'D');

  queue = SBST1.getPostOrder();

  assert(queue->dequeue().second == 'C');
  assert(queue->dequeue().second == 'D');
  assert(queue->dequeue().second == 'A');

  delete queue;

  //===============================================

  SBST2.insert(3, 'C');
  SBST2.insert(2, 'B');
  SBST2.insert(1, 'A');
  SBST2.update(1, 'E');
  SBST2.update(2, 'B');

  queue = SBST2.getPostOrder();

  assert(queue->dequeue().second == 'E');
  assert(queue->dequeue().second == 'B');
  assert(queue->dequeue().second == 'C');

  delete queue;

  //===============================================

  SBST3.insert(2, 'B');
  SBST3.insert(1, 'A');
  SBST3.insert(3, 'C');
  SBST3.update(3, 'F');

  queue = SBST3.getPostOrder();

  assert(queue->dequeue().second == 'A');
  assert(queue->dequeue().second == 'F');
  assert(queue->dequeue().second == 'B');

  delete queue;

  //===============================================

  SBST4.insert(3, 'C');
  SBST4.insert(1, 'A');
  SBST4.insert(2, 'B');
  SBST4.update(3, 'D');
  SBST4.update(1, 'E');
  SBST4.update(2, 'F');

  queue = SBST4.getPostOrder();

  assert(queue->dequeue().second == 'F');
  assert(queue->dequeue().second == 'E');
  assert(queue->dequeue().second == 'D');

  delete queue;

  //===============================================

  SBST5.insert(1, 'A');
  SBST5.insert(3, 'C');
  SBST5.insert(2, 'B');
  SBST5.update(2, 'G');
  SBST5.update(2, 'E');
  SBST5.update(3, 'F');
  SBST5.update(2, 'M');

  queue = SBST5.getPostOrder();

  assert(queue->dequeue().second == 'M');
  assert(queue->dequeue().second == 'F');
  assert(queue->dequeue().second == 'A');

  delete queue;
}


/* removeTest - accomplishes the following
 *
 *    *ensures we can't delete in empty tree
 *
 *    *ensures each remove decreases the size by 1
 *
 *    *for tests that check each removed element 
 *     is not in the tree, look at findTest
 *    
 *    *tests that each removed element results in tree
 *     with elements in the right spot
 *     by checking all four traversal algorithms on all remove
 *     situations 
 */

void removeTest() {
  LinkedBST<int, char> BST;
  Queue< Pair<int,char> >* queue1;
  Queue< Pair<int,char> >* queue2; 
  Queue< Pair<int,char> >* queue3; 
  Queue< Pair<int,char> >* queue4;  

  try{ // testing removing on an empty tree
    BST.remove(1);
    assert(false);
  } catch(runtime_error& exc){}
  
  BST.insert(2, 'B');
  BST.insert(1, 'A');
  BST.insert(5, 'E');
  BST.insert(3, 'C');
  BST.insert(4, 'D');

  assert(BST.getSize() == 5);
  
  try { // Testing remove on non-existant keys
    BST.remove(6);
    assert(false);
  } catch(runtime_error& exc){}

  try {
    BST.remove(0);
    assert(false);
  } catch(runtime_error& exc){}

  //===============================================  
  
  /* The following is a comprehensive test of the LinkedBST::remove
   * function. We have designed the tree to test all possible 
   * removal algorithms (right/left leaves, parent nodes with one
   * right/left child node, and parent node with two subchildren).
   * Tested with all four search algorithms.
   * The original tree looks like:
   *
   *        2,B
   *      /    \
   *    1,A     5,E
   *            / 
   *          3,C
   *            \
   *            4,D 
   */
  queue1 = BST.getPostOrder();
  queue2 = BST.getPreOrder();
  queue3 = BST.getInOrder();
  queue4 = BST.getLevelOrder();

  assert(queue1->dequeue().second == 'A');
  assert(queue1->dequeue().second == 'D');
  assert(queue1->dequeue().second == 'C');
  assert(queue1->dequeue().second == 'E');
  assert(queue1->dequeue().second == 'B');

  assert(queue2->dequeue().second == 'B');
  assert(queue2->dequeue().second == 'A');
  assert(queue2->dequeue().second == 'E');
  assert(queue2->dequeue().second == 'C');
  assert(queue2->dequeue().second == 'D');

  assert(queue3->dequeue().second == 'A');
  assert(queue3->dequeue().second == 'B');
  assert(queue3->dequeue().second == 'C');
  assert(queue3->dequeue().second == 'D');
  assert(queue3->dequeue().second == 'E');

  assert(queue4->dequeue().second == 'B');
  assert(queue4->dequeue().second == 'A');
  assert(queue4->dequeue().second == 'E');
  assert(queue4->dequeue().second == 'C');
  assert(queue4->dequeue().second == 'D');

  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;


  //===============================================

  BST.remove(2);

  assert(BST.getSize() == 4);

  queue1 = BST.getPostOrder();
  queue2 = BST.getPreOrder();
  queue3 = BST.getInOrder();
  queue4 = BST.getLevelOrder();

  assert(queue1->dequeue().second == 'A');
  assert(queue1->dequeue().second == 'D');
  assert(queue1->dequeue().second == 'E');
  assert(queue1->dequeue().second == 'C');

  assert(queue2->dequeue().second == 'C');
  assert(queue2->dequeue().second == 'A');
  assert(queue2->dequeue().second == 'E');
  assert(queue2->dequeue().second == 'D');

  assert(queue3->dequeue().second == 'A');
  assert(queue3->dequeue().second == 'C');
  assert(queue3->dequeue().second == 'D');
  assert(queue3->dequeue().second == 'E');

  assert(queue4->dequeue().second == 'C');
  assert(queue4->dequeue().second == 'A');
  assert(queue4->dequeue().second == 'E');
  assert(queue4->dequeue().second == 'D');

  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;

  //===============================================

  BST.remove(5);

  assert(BST.getSize() == 3);

  queue1 = BST.getPostOrder();
  queue2 = BST.getPreOrder();
  queue3 = BST.getInOrder();
  queue4 = BST.getLevelOrder();

  assert(queue1->dequeue().second == 'A');
  assert(queue1->dequeue().second == 'D');
  assert(queue1->dequeue().second == 'C');
  
  assert(queue2->dequeue().second == 'C');
  assert(queue2->dequeue().second == 'A');
  assert(queue2->dequeue().second == 'D');

  assert(queue3->dequeue().second == 'A');
  assert(queue3->dequeue().second == 'C');
  assert(queue3->dequeue().second == 'D');

  assert(queue4->dequeue().second == 'C');
  assert(queue4->dequeue().second == 'A');
  assert(queue4->dequeue().second == 'D');

  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;

  //===============================================

  BST.remove(1);

  assert(BST.getSize() == 2);

  queue1 = BST.getPostOrder();
  queue2 = BST.getPreOrder();
  queue3 = BST.getInOrder();
  queue4 = BST.getLevelOrder();

  assert(queue1->dequeue().second == 'D');
  assert(queue1->dequeue().second == 'C');

  assert(queue2->dequeue().second == 'C');
  assert(queue2->dequeue().second == 'D');

  assert(queue3->dequeue().second == 'C');
  assert(queue3->dequeue().second == 'D');

  assert(queue4->dequeue().second == 'C');
  assert(queue4->dequeue().second == 'D');

  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;

  //===============================================

  BST.remove(4);

  assert(BST.getSize() == 1);

  queue1 = BST.getPostOrder();
  queue2 = BST.getPreOrder();
  queue3 = BST.getInOrder();
  queue4 = BST.getLevelOrder();

  assert(queue1->dequeue().second == 'C');
  assert(queue2->dequeue().second == 'C');
  assert(queue3->dequeue().second == 'C');
  assert(queue4->dequeue().second == 'C');


  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;

  //===============================================

  BST.remove(3);

  assert(BST.getSize() == 0);

  queue1 = BST.getPostOrder();
  queue2 = BST.getPreOrder();
  queue3 = BST.getInOrder();
  queue4 = BST.getLevelOrder();

  assert(queue1->getSize() == 0);
  assert(queue2->getSize() == 0);
  assert(queue3->getSize() == 0);
  assert(queue4->getSize() == 0);

  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;
}



/* findTest - accomplishes the following
 *
 *    *tests that each removed element 
 *     is not in the tree
 *    
 *    *tests that right value is returned when find is called 
 */
void findTest() {
  LinkedBST<int,int> BST;
  LinkedBST<int, char> BST2;

  assert(BST.getSize() == 0);  // Checks that initial size is correct.
  
  for (int i = 0; i < 100; ++i) {
    BST.insert(2*i + 1, i);
    assert(BST.getSize() == i+1);
  }  
  for (int i = 0; i < 100; ++i) {  // Checks that keys are in the tree.
    assert(BST.find(2*i + 1) == i);
  }
  for (int i = 0; i < 100; ++i) { // Checks that key returns proper update.
    BST.update(2*i + 1, 2*i);
    assert(BST.find(2*i + 1) == 2*i);
  }
  
  try{ // Testing edge cases
    BST.find(0);
    assert(false);
  } catch(runtime_error& exc){}

  try{
    BST.find(2*99 + 2);
    assert(false);
  } catch(runtime_error& exc){}

  BST2.insert(4, 'D');
  BST2.insert(3, 'C');
  BST2.insert(5, 'E');
  BST2.insert(1, 'A');
  BST2.insert(2, 'B');

  assert(BST2.find(4) == 'D');
  BST2.remove(4);

  try{
    BST2.find(4);
    assert(false);
  } catch(runtime_error& exc){}

  assert(BST2.find(2) == 'B');
  BST2.remove(2);

  try{
    BST2.find(2);
    assert(false);
  } catch(runtime_error& exc){}

  assert(BST2.find(1) == 'A');
  BST2.remove(1);

  try{
    BST2.find(1);
    assert(false);
  } catch(runtime_error& exc){}

  assert(BST2.find(3) == 'C');
  BST2.remove(3);

  try{
    BST2.find(3);
    assert(false);
  } catch(runtime_error& exc){}

  assert(BST2.find(5) == 'E');
  BST2.remove(5);

  try{
    BST2.find(5);
    assert(false);
  } catch(runtime_error& exc){}
}


/* testMaxMin - accomplishes the following
 *
 *    *tests that calling getMax or getMin on empty tree
 *     results in error thrown
 *    
 *    *tests that tree with one element returns same max
 *     and min key
 *
 *    *tests max and min by creating tree and incrementally
 *     removing nodes  
 */
void testMaxMin(){
  LinkedBST<int, char> BST; 

  try{
    BST.getMax();
    assert(false);
  } catch(runtime_error& exc){}

  try{
    BST.getMin();
    assert(false);
  } catch(runtime_error& exc){}

  BST.insert(6, 'A');
  assert(BST.getMax() == 6);
  assert(BST.getMin() == 6);
  assert(BST.getMax() == BST.getMin());

  BST.insert(1, 'B');
  BST.insert(5, 'C');
  BST.insert(2, 'D');
  BST.insert(4, 'E');
  BST.insert(3, 'F');
  BST.insert(11, 'G');
  BST.insert(7, 'H');
  BST.insert(10, 'I');
  BST.insert(8, 'J');
  BST.insert(9, 'K');

  assert(BST.getMax() == 11);
  assert(BST.getMin() == 1);

  BST.remove(11);
  BST.remove(1);

  assert(BST.getMax() == 10);
  assert(BST.getMin() == 2);

  BST.remove(10);
  BST.remove(2);

  assert(BST.getMax() == 9);
  assert(BST.getMin() == 3);

  BST.remove(9);
  BST.remove(3);

  assert(BST.getMax() == 8);
  assert(BST.getMin() == 4);

  BST.remove(8);
  BST.remove(4);

  assert(BST.getMax() == 7);
  assert(BST.getMin() == 5);

  BST.remove(7);
  BST.remove(5);

  assert(BST.getMax() == 6);
  assert(BST.getMin() == 6);
  assert(BST.getMax() == BST.getMin());
}


/* testgetHeight - accomplishes the following
 *
 *    *tests that empty tree yields height of -1
 *    
 *    *tests that tree with one element returns height of 0
 *
 *    *tests height by creating tree and incrementally
 *     removing nodes  
 */
void testgetHeight(){
  LinkedBST<int, char> BST;

  BST.insert(4, 'D');
  BST.insert(2, 'B');
  BST.insert(1, 'A');
  BST.insert(3, 'C');
  BST.insert(6, 'F');
  BST.insert(5, 'E');
  BST.insert(7, 'G');

  for (int i = 0; i < 4; i++) {
    assert(BST.getHeight() == 2);
    BST.remove(2*i + 1);
  }  

  for (int i = 0; i < 2; i++) {
    assert(BST.getHeight() == 1);
    BST.remove(4*i + 2);
  }

  assert(BST.getHeight() == 0);
  BST.remove(4);

  assert(BST.getHeight() == -1);
}

/* AVLInsertTest - accomplishes the following
 *
 *    *tests tree is balanced after series of insertions and removals
 *  
 *    *tests that each kind of imbalance is properly adjusted for 
 */
void AVLInsertTest(){
  AVLTree<int,int> AVL;
  AVLTree<int, char> SAVL1, SAVL2, SAVL3, SAVL4, SAVL5;
  Queue< Pair<int,char> >* queue1;
  Queue< Pair<int,char> >* queue2; 
  Queue< Pair<int,char> >* queue3; 
  Queue< Pair<int,char> >* queue4; 

  assert(AVL.getSize() == 0);  // Checks that initial size is correct.  assert
                               // causes the program to immediately crash if
                               // the condition is false.

  for (int i = 0; i < 100; ++i) {
    AVL.insert(2*i + 1, i);
    assert(AVL.isBalanced());
    assert(AVL.getSize() == i+1);
  }  
  for (int i = 0; i < 100; ++i) {  // Checks that keys are in the tree.
    assert(AVL.contains(2*i + 1));
  }

  for (int i = 0; i < 100; ++i) {
    AVL.insert(-2*i - 1, i);
    assert(AVL.isBalanced());
    assert(AVL.getSize() == i+1 + 100);
  }  
  for (int i = 0; i < 100; ++i) {  // Checks that keys are in the tree.
    assert(AVL.contains(-2*i - 1));
  }

  for (int i = 0; i < 100; ++i) {  //Error returned if key already exists.
    try{
      AVL.insert(2*i + 1, i);
      assert(false);
    } catch(runtime_error& exc){}
  }
  
  assert(AVL.isBalanced());
  //=============================================== 
  
  // The following tests use inserts that create LL, LR, RL, RR imbalances.
  // They ensure that the tree is balanced in the right way. 

  assert(SAVL1.getSize() == 0);
 
  SAVL1.insert(1, 'A');
  SAVL1.insert(2, 'B');
  SAVL1.insert(3, 'C');

  queue1 = SAVL1.getPostOrder();
  queue2 = SAVL1.getPreOrder();
  queue3 = SAVL1.getInOrder();
  queue4 = SAVL1.getLevelOrder();

  assert(queue1->dequeue().second == 'A');
  assert(queue1->dequeue().second == 'C');
  assert(queue1->dequeue().second == 'B');

  assert(queue2->dequeue().second == 'B');
  assert(queue2->dequeue().second == 'A');
  assert(queue2->dequeue().second == 'C');

  assert(queue3->dequeue().second == 'A');
  assert(queue3->dequeue().second == 'B');
  assert(queue3->dequeue().second == 'C');

  assert(queue4->dequeue().second == 'B');
  assert(queue4->dequeue().second == 'A');
  assert(queue4->dequeue().second == 'C');

  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;

  //===============================================

  assert(SAVL2.getSize() == 0);

  SAVL2.insert(3, 'C');
  SAVL2.insert(2, 'B');
  SAVL2.insert(1, 'A');

  queue1 = SAVL2.getPostOrder();
  queue2 = SAVL2.getPreOrder();
  queue3 = SAVL2.getInOrder();
  queue4 = SAVL2.getLevelOrder();

  assert(queue1->dequeue().second == 'A');
  assert(queue1->dequeue().second == 'C');
  assert(queue1->dequeue().second == 'B');

  assert(queue2->dequeue().second == 'B');
  assert(queue2->dequeue().second == 'A');
  assert(queue2->dequeue().second == 'C');

  assert(queue3->dequeue().second == 'A');
  assert(queue3->dequeue().second == 'B');
  assert(queue3->dequeue().second == 'C');

  assert(queue4->dequeue().second == 'B');
  assert(queue4->dequeue().second == 'A');
  assert(queue4->dequeue().second == 'C');

  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;


  //===============================================

  assert(SAVL3.getSize() == 0);

  SAVL3.insert(2, 'B');
  SAVL3.insert(1, 'A');
  SAVL3.insert(3, 'C');

  queue1 = SAVL3.getPostOrder();
  queue2 = SAVL3.getPreOrder();
  queue3 = SAVL3.getInOrder();
  queue4 = SAVL3.getLevelOrder();

  assert(queue1->dequeue().second == 'A');
  assert(queue1->dequeue().second == 'C');
  assert(queue1->dequeue().second == 'B');

  assert(queue2->dequeue().second == 'B');
  assert(queue2->dequeue().second == 'A');
  assert(queue2->dequeue().second == 'C');

  assert(queue3->dequeue().second == 'A');
  assert(queue3->dequeue().second == 'B');
  assert(queue3->dequeue().second == 'C');

  assert(queue4->dequeue().second == 'B');
  assert(queue4->dequeue().second == 'A');
  assert(queue4->dequeue().second == 'C');

  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;



  //===============================================

  assert(SAVL4.getSize() == 0);

  SAVL4.insert(3, 'C');
  SAVL4.insert(1, 'A');
  SAVL4.insert(2, 'B');

  queue1 = SAVL4.getPostOrder();
  queue2 = SAVL4.getPreOrder();
  queue3 = SAVL4.getInOrder();
  queue4 = SAVL4.getLevelOrder();

  assert(queue1->dequeue().second == 'A');
  assert(queue1->dequeue().second == 'C');
  assert(queue1->dequeue().second == 'B');

  assert(queue2->dequeue().second == 'B');
  assert(queue2->dequeue().second == 'A');
  assert(queue2->dequeue().second == 'C');

  assert(queue3->dequeue().second == 'A');
  assert(queue3->dequeue().second == 'B');
  assert(queue3->dequeue().second == 'C');

  assert(queue4->dequeue().second == 'B');
  assert(queue4->dequeue().second == 'A');
  assert(queue4->dequeue().second == 'C');

  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;


  //===============================================

  assert(SAVL5.getSize() == 0);

  SAVL5.insert(1, 'A');
  SAVL5.insert(3, 'C');
  SAVL5.insert(2, 'B');

  queue1 = SAVL5.getPostOrder();
  queue2 = SAVL5.getPreOrder();
  queue3 = SAVL5.getInOrder();
  queue4 = SAVL5.getLevelOrder();

  assert(queue1->dequeue().second == 'A');
  assert(queue1->dequeue().second == 'C');
  assert(queue1->dequeue().second == 'B');

  assert(queue2->dequeue().second == 'B');
  assert(queue2->dequeue().second == 'A');
  assert(queue2->dequeue().second == 'C');

  assert(queue3->dequeue().second == 'A');
  assert(queue3->dequeue().second == 'B');
  assert(queue3->dequeue().second == 'C');

  assert(queue4->dequeue().second == 'B');
  assert(queue4->dequeue().second == 'A');
  assert(queue4->dequeue().second == 'C');

  delete queue1;
  delete queue2;
  delete queue3; 
  delete queue4;
}

/* AVLRemoveTest - accomplishes the following
 *
 *    *tests proper removal of leaf nodes
 *    
 *    *tests tree is balanced after series of insertions and removals 
 */
void AVLRemoveTest(){
  AVLTree<int,int> AVL;

  //Our insertTest method makes sure that the balancing calls
  //do what they should. The only case to take care of is
  //when we delete a leaf node (and we call balance on NULL.

  //This adds a bunch of elements and then
  //deletes a bunch of elements, and makes sure things still stay
  //balanced.

  assert(AVL.getSize() == 0);  // Checks that initial size is correct.  assert
                               // causes the program to immediately crash if
                               // the condition is false.
  
  for (int i = 0; i < 100; ++i) {
    AVL.insert(2*i + 1, i);
    assert(AVL.isBalanced());
    assert(AVL.getSize() == i+1);
  }  
  for (int i = 0; i < 100; ++i) {  // Checks that keys are in the tree.
    assert(AVL.contains(2*i + 1));
  }

  for (int i = 0; i < 100; ++i) {
    AVL.insert(-2*i - 1, i);
    assert(AVL.isBalanced());
    assert(AVL.getSize() == i+1 + 100);
  }  
  for (int i = 0; i < 100; ++i) {  // Checks that keys are in the tree.
    assert(AVL.contains(-2*i - 1));
  }

  for (int i = 0; i < 100; ++i) {
    AVL.remove(-2*i - 1);
    assert(AVL.isBalanced());
    assert(AVL.getSize() == 199 - i);
  } 

  for (int i = 0; i < 100; ++i) {
    AVL.remove(2*(99-i) + 1);
    assert(AVL.isBalanced());
    assert(AVL.getSize() == 99 - i);
  }  

  assert(AVL.getSize() == 0);
}
