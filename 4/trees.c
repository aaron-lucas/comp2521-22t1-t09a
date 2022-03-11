#include <stdlib.h>
#include <stdio.h>

typedef struct BSTNode *BSTree;

typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
} BSTNode;

int BSTreeNumNodes(BSTree t) {
    if (t == NULL) {
        return 0;
    }

    return 1 + BSTreeNumNodes(t->left) + BSTreeNumNodes(t->right);
}

int BSTreeHeight(BSTree t) {
    if (t == NULL) {
        return -1;
    }

    int leftHeight = BSTreeHeight(t->left);
    int rightHeight = BSTreeHeight(t->right);
    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

int BSTreeNodeLevel(BSTree t, int key) {
    if (t == NULL) {
        return -1;
    } else if (key == t->value) {
        return 0;
    } else if (key < t->value) {
        // check left
        int leftLevel = BSTreeNodeLevel(t->left, key);
        if (leftLevel == -1) {
            return -1;
        } else {
            return 1 + leftLevel;
        }
    } else {
        // check right
        int rightLevel = BSTreeNodeLevel(t->right, key);
        return (rightLevel == -1) ? -1 : 1 + rightLevel;
    }
}

int BSTreeCountGreater(BSTree t, int key) {
    return 0;
}
