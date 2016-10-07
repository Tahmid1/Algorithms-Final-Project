/*Dylan Jeffers
 *Tahmid Rahman
 *founders of RahmROMJeffers ltd.
 */ 

/*
 * This recursive helper function inserts a key-value pair into a subtree 
 * of the tree, or throws a runtime_error if the key is already present.
 */
template <typename K, typename V>
BSTNode<K,V>*
LinkedBST<K,V>::insertInSubtree(BSTNode<K,V>* current, K key, V value) {

  if (current == NULL){
    size++;
    return new BSTNode<K, V>(key, value); 
  }
  else if (key == current->key){
    throw std::runtime_error("LinkedBST::insertInSubtree" \
      "called on key already in tree.");
  }
  else if (key < current->key){
    current->left = insertInSubtree(current->left, key, value);
  }
  else if (key > current->key){
    current->right = insertInSubtree(current->right, key, value);
  }
  return current;
}

/**
 * This recursive helper function updates key-value pair in the subtree 
 * of the tree, or throws a runtime_error if the key is not present.
 */
template <typename K, typename V>
void LinkedBST<K,V>::updateInSubtree(BSTNode<K,V>* current, K key, V value) {
  
  if (current == NULL){
    throw std::runtime_error("Key not found in LinkedBST::updateInSubtree.");
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
BSTNode<K,V>* 
LinkedBST<K,V>::removeFromSubtree(BSTNode<K,V>* current, 
                                  K key) {
  if (current == NULL) {
    throw std::runtime_error("LinkedBST::remove called on key not in tree.");
  }

  else if (key == current->key) {       // We've found the node to remove
    if ((current->left == NULL) && (current->right == NULL)) {
      size--;
      delete current;
      return NULL;
    }
    else if (current->left == NULL) {
      BSTNode<K,V>* tempNode = current->right;
      delete current;
      size--;
      return tempNode;
    }
    else if (current->right == NULL) {
      BSTNode<K,V>* tempNode = current->left;
      delete current;
      size--;
      return tempNode;
    }
    else {
      BSTNode<K,V>* minimum = current->right;
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
  return current;
}


/**
 * Returns true if a key is contained in a subtree of the tree, and
 * false otherwise.
 */
template <typename K, typename V>
bool LinkedBST<K,V>::containsInSubtree(BSTNode<K,V>* current, K key) {
  if (current == NULL){
    return false;
  }
  else if (key == current->key){
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
V LinkedBST<K,V>::findInSubtree(BSTNode<K,V>* current, K key) {
  if (current == NULL) {
    throw std::runtime_error("LinkedBS::findInSubtree called on an empty tree");
  }
  else if (key == current->key) {
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
K LinkedBST<K,V>::getMaxInSubtree(BSTNode<K,V>* current) {
  if (current->right == NULL) {
    return current->key;
  }
  return getMaxInSubtree(current->right);
}


/**
 * Returns the smallest key in a subtree of the tree.
 */
template <typename K, typename V>
K LinkedBST<K,V>::getMinInSubtree(BSTNode<K,V>* current) {
  if (current->left == NULL) {
    return current->key;
  }
  return getMinInSubtree(current->left);
}


/**
 * Returns the height of a subtree of the tree, or -1 if the subtree
 * is empty.
 */
template <typename K, typename V>
int LinkedBST<K,V>::getHeightOfSubtree(BSTNode<K,V>* current) {
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

/**
 * Recursively builds a post-order iterator for a subtree of the tree.
 */
template <typename K, typename V>
void LinkedBST<K,V>::buildPostOrder(BSTNode<K,V>* current,
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
void LinkedBST<K,V>::buildPreOrder(BSTNode<K,V>* current,
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
void LinkedBST<K,V>::buildInOrder(BSTNode<K,V>* current,
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
void LinkedBST<K,V>::traverseAndDelete(BSTNode<K,V>* current) {
  if (current == NULL) {
    return;  //nothing to delete
  }
  traverseAndDelete(current->left);
  traverseAndDelete(current->right);
  delete current;
}



