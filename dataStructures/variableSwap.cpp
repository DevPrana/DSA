node *deleteNode(node *parent, int key) {
  // Find the node and delete it
  if (parent == NULL)
    return parent;
  if (key < parent->key)
    parent->left = deleteNode(parent->left, key);
  else if (key > parent->key)
    parent->right = deleteNode(parent->right, key);
  else {
    if ((parent->left == NULL) ||
      (parent->right == NULL)) {
      node *tempNode = parent->left ? parent->left : parent->right;
      if (tempNode == NULL) {
        tempNode = parent;
        parent = NULL;
      } else
        *parent = *tempNode;
      free(tempNode);
    } else {
      node *tempNode = nodeWithMimumValue(parent->right);
      parent->key = tempNode->key;
      parent->right = deleteNode(parent->right,
                   tempNode->key);
    }
  }

  if (parent == NULL)
    return parent;

  // Update the balance factor of each node and
  // balance the tree
  parent->height = 1 + max(height(parent->left),
               height(parent->right));
  int balanceFactor = getBalanceFactor(parent);
  if (balanceFactor > 1) {
    if (getBalanceFactor(parent->left) >= 0) {
      return rightRotate(parent);
    } else {
      parent->left = leftRotate(parent->left);
      return rightRotate(parent);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(parent->right) <= 0) {
      return leftRotate(parent);
    } else {
      parent->right = rightRotate(parent->right);
      return leftRotate(parent);
    }
  }
  return parent;
}