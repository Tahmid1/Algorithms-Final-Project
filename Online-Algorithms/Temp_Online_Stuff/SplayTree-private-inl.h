
//static int global_height;

template <typename K, typename V>
SplayTreeNode<K,V>*
SplayTree<K,V>::insertInSubtree(SplayTreeNode<K,V>* current, K key, V value) {

  if (current == NULL){
    size++;
    return new SplayTreeNode<K, V>(key, value); 
  }
  else if (key == current->key){
    throw std::runtime_error("SplayTree::insertInSubtree" \
      "called on key already in tree.");
  }
  else if (key < current->key){
    if(current->left != NULL) {
      current->left = insertInSubtree(current->left, key, value);
    }
    else {
      current->left = new SplayTreeNode<K, V>(key, value);
      current->left->parent = current;
      size++;
    }
    return splay(current);
  }
  else if (key > current->key){
    if(current->right != NULL) {
      current->right = insertInSubtree(current->right, key, value);
    }
    else {
      current->right = new SplayTreeNode<K, V>(key, value);
      current->right->parent = current;
      size++;
    }
    return splay(current);
  }
}

/**
 * This recursive helper function updates key-value pair in the subtree 
 * of the tree, or throws a runtime_error if the key is not present.
 */
template <typename K, typename V>
void SplayTree<K,V>::updateInSubtree(SplayTreeNode<K,V>* current, K key, V value) {
  
  if (current == NULL){
    throw std::runtime_error("Key not found in SplayTree::updateInSubtree.");
  }
  else if (key == current->key){
    current->value = value;
  }
  else if (key < current->key){
    updateInSubtree(current->left, key, value);
  }
  else if (key > current->key){
    updateInSubtree(current->right, key, value);
  }
  return;
}


/**
 * This recursive helper function removes a key-value pair from a subtree 
 * of the tree, or throws a runtime_error if that key was not present.
 *
 * It returns a pointer to the root of the subtree.  This root is often
 * the node that was passed as an argument to the function (current) but
 * might be a different node if current contains the key we are removing
 * from the tree.
 */
template <typename K, typename V>
SplayTreeNode<K,V>* 
SplayTree<K,V>::removeFromSubtree(SplayTreeNode<K,V>* current, 
                                  K key) {
  if (current == NULL) {
    throw std::runtime_error("SplayTree::remove called on key not in tree.");
  }

  else if (key == current->key) {       // We've found the node to remove
    if ((current->left == NULL) && (current->right == NULL)) {
      size--;
      delete current;
      return NULL;
    }
    else if (current->left == NULL) {
      SplayTreeNode<K,V>* tempNode = current->right;
      delete current;
      size--;
      return balance(tempNode);
    }
    else if (current->right == NULL) {
      SplayTreeNode<K,V>* tempNode = current->left;
      delete current;
      size--;
      return balance(tempNode);
    }
    else {
      SplayTreeNode<K,V>* minimum = current->right;
      while (minimum->left != NULL) {
        minimum = minimum->left; 
      }
      current->key = minimum->key;
      current->value = minimum->value;
      current->right = removeFromSubtree(current->right, current->key);
    }  
  }

  else if (key < current->key) {
    current->left = removeFromSubtree(current->left, key);
  } 
  else {
    current->right = removeFromSubtree(current->right, key);
  }
  return balance(current);
}


/**
 * Returns true if a key is contained in a subtree of the tree, and
 * false otherwise.
 */
template <typename K, typename V>
bool SplayTree<K,V>::containsInSubtree(SplayTreeNode<K,V>* current, K key) {
  if (current == NULL){
    return false;
  }
  else if (key == current->key){
    splay(current);
    return true;
  }
  else if (key < current->key){
    return containsInSubtree(current->left, key);
  }
  else {
    return containsInSubtree(current->right, key);
  }
}


/**
 * Given a key, returns the value for that key from a subtree of the tree.
 * Throws a runtime_error if the key is not in the subtree.
 */
template <typename K, typename V>
V SplayTree<K,V>::findInSubtree(SplayTreeNode<K,V>* current, K key) {
  if (current == NULL) {
    throw std::runtime_error("LinkedBS::findInSubtree called on an empty tree");
  }
  else if (key == current->key) {
    current = splay(current);
    return current->value;
  }
  else if (key < current->key) {
    return findInSubtree(current->left, key);
  }
  else {
    return findInSubtree(current->right, key);
  }
}


/**
 * Returns the largest key in a subtree of the tree.
 */
template <typename K, typename V>
K SplayTree<K,V>::getMaxInSubtree(SplayTreeNode<K,V>* current) {
  if (current->right == NULL) {
    return current->key;
  }
  return getMaxInSubtree(current->right);
}


/**
 * Returns the smallest key in a subtree of the tree.
 */
template <typename K, typename V>
K SplayTree<K,V>::getMinInSubtree(SplayTreeNode<K,V>* current) {
  if (current->left == NULL) {
    return current->key;
  }
  return getMinInSubtree(current->left);
}


/*
 * Returns the height of a subtree of the tree, or -1 if the subtree
 * is empty.
 *
template <typename K, typename V>
int SplayTree<K,V>::getHeightOfSubtree(SplayTreeNode<K,V>* current) {
  if (current == NULL) {
    return -1;
  }
  int l = getHeightOfSubtree(current->left);
  int r = getHeightOfSubtree(current->right);
  if (l >= r) {
    return ++l;
  }
  else 
    return ++r;
}
*/


/**
 * Recursively builds a post-order iterator for a subtree of the tree.
 */
template <typename K, typename V>
void SplayTree<K,V>::buildPostOrder(SplayTreeNode<K,V>* current,
                                       Queue< Pair<K,V> >* it) {
  if (current == NULL) {
    return;
  }
  buildPostOrder(current->left, it);
  buildPostOrder(current->right, it);
  it->enqueue( Pair<K,V>(current->key, current->value) );
}

/**
 * Recursively builds a pre-order iterator for a subtree of the tree.
 */
template <typename K, typename V>
void SplayTree<K,V>::buildPreOrder(SplayTreeNode<K,V>* current,
                                      Queue< Pair<K,V> >* it) {
  if (current == NULL){
    return;
  }
  it->enqueue( Pair<K,V>(current->key, current->value) );
  buildPreOrder(current->left, it);
  buildPreOrder(current->right, it);
}


/**
 * Recursively builds an in-order iterator for a subtree of the tree.
 */
template <typename K, typename V>
void SplayTree<K,V>::buildInOrder(SplayTreeNode<K,V>* current,
                                      Queue< Pair<K,V> >* it) {
  if (current == NULL){
    return;
  }
  buildInOrder(current->left, it);
  it->enqueue( Pair<K,V>(current->key, current->value) );
  buildInOrder(current->right, it);
}


/**
 * Performs a post-order traversal of the tree, deleting each node from the
 * heap after we have already traversed its children.
 */
template <typename K, typename V>
void SplayTree<K,V>::traverseAndDelete(SplayTreeNode<K,V>* current) {
  if (current == NULL) {
    return;  //nothing to delete
  }
  traverseAndDelete(current->left);
  traverseAndDelete(current->right);
  delete current;
}

template <typename K, typename V>
SplayTreeNode<K,V>* SplayTree<K,V>::balance(SplayTreeNode<K,V>* current) {
    //check height to see if stop with AVL (note we need to think about global_height)
    if (current->height > 0) {
        /*do AVL balance, but we will implement this once SplayTree is working
        well. Also remember to add the balance functions from AVLTree.h
        */
        return current;
    }
    else{
        return current;
    }
}


template <typename K, typename V>
SplayTreeNode<K,V>* SplayTree<K,V>::splay(SplayTreeNode<K,V>* current) {
    
    //consider adding computeHeightFromChildren here for AVL

    //finished splay, return this node to obtain value
    if (current->parent == NULL){
        return current;
    }
    else if (current->parent->parent == NULL) {
        if (current == current->parent->left){
            zigRight(current);
            return current;

        }
        else {
            zigLeft(current);
            return(current);
        }
    }
    else {
        SplayTreeNode<K,V>* gParent = current->parent->parent;
        SplayTreeNode<K,V>* gPP = gParent->parent;          
        if (current == current->parent->left) {
          if (current->parent == gParent->left) {
            if(gPP == NULL) {
              zig_zigLeft(current);
            }
            else {
              if (gPP->key > current->key) {
                gPP->left = zig_zigLeft(current);
              }
              else {
                gPP->right = zig_zigLeft(current);
              }
            }
          }

          else {
            if(gPP == NULL) {
              zig_zagLeft(current);
            }
            else {
              if (gPP->key > current->key) {
                gPP->left = zig_zagLeft(current);
              }
              else {
                gPP->right = zig_zagLeft(current);
              }
            }
          }
          splay(current);
        }

        else {
          if (current->parent == gParent->right) {
            if(gPP == NULL) {
              zig_zigRight(current);
            }
            else {
              if (gPP->key > current->key) {
                gPP->left = zig_zigRight(current);
              }
              else {
                gPP->right = zig_zigRight(current);
              }
            }
          }
          else {
            if(gPP == NULL) {
              zig_zigRight(current);
            }
            else {
              if (gPP->key > current->key) {
                gPP->left = zig_zagRight(current);
              }
              else {
                gPP->right = zig_zagRight(current);
              }
            }
          }
          splay(current);
        }
      return current;
    }        
}

template <typename K, typename V>
SplayTreeNode<K,V>* SplayTree<K,V>::zigLeft(SplayTreeNode<K,V>* current) {
    //making the assumption that we know current is left child
   SplayTreeNode<K,V> * P = current->parent;
    P->left = current->right;
    P->left->parent = P; 
    current->right = P;
    current->parent = P->parent;
    P->parent = current;

    //premptively added these calls here for AVL section
    //computeHeightFromChildren(current);
    //computeHeightFromChildren(P);
    return current; 
}

template <typename K, typename V>
SplayTreeNode<K,V>* SplayTree<K,V>::zigRight(SplayTreeNode<K,V>* current) {
    SplayTreeNode<K,V> * P = current->parent;

    P->right = current->left;
    P->right->parent = P;
    current->left = P;
    current->parent = P->parent;
    P->parent = current;

    //premptively added these calls here for AVL section
    //computeHeightFromChildren(current);
    //computeHeightFromChildren(P);
    return current;
}


    /* for all four we zig from the bottom, then zig from the top */
    
template <typename K, typename V>
SplayTreeNode<K,V>* SplayTree<K,V>::zig_zigLeft(SplayTreeNode<K,V>* current) {
    SplayTreeNode<K,V> * gParent = current->parent->parent;
    gParent->left = zigLeft(current);
    return zigLeft(current);
}


template <typename K, typename V>
SplayTreeNode<K,V>* SplayTree<K,V>::zig_zigRight(SplayTreeNode<K,V>* current) {
    SplayTreeNode<K,V> * gParent = current->parent->parent;
    gParent->right = zigRight(current);
    return zigRight(current);
}

template <typename K, typename V>
SplayTreeNode<K,V>* SplayTree<K,V>::zig_zagLeft(SplayTreeNode<K,V>* current) {
    SplayTreeNode<K,V> * gParent = current->parent->parent;
    gParent->left = zigRight(current);
    gParent->right->parent = gParent;
    return zigLeft(current);
}

template <typename K, typename V>
SplayTreeNode<K,V>* SplayTree<K,V>::zig_zagRight(SplayTreeNode<K,V>* current) {
    SplayTreeNode<K,V> * gParent = current->parent->parent;
    gParent->right = zigLeft(current);
    return zigRight(current);
}

