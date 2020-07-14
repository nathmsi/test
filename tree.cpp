//
//  tree.cpp
//  tree
//
//  Created by Nathan on 6/21/20.
//  Copyright © 2020 Nathan. All rights reserved.
//

#include "tree.hpp"
template <class T>
Tree<T>::~Tree() // deallocate tree
{
    if (root != NULL)
        clear(root);
}

template <class T>
void Tree<T>::clear(Node* current)
{
    if (current)
    {    // Release memory associated with children
        if (current->left)
            clear(current->left);
        if (current->right)
            clear(current->right);
        delete current;
    }
}

template <class T>
bool Tree<T>::isEmpty() const
{
    return  root == NULL;
}
// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node * current){
    // visit Node, left child, right child
    if (current){
        // process current Node
        process(current->value);
        // then visit children
        preOrder(current->left);
        preOrder(current->right);
    }
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node * current){
    // visit left child, Node, right child
    if (current){
        inOrder(current->left);
        process(current->value);
        preOrder(current->right);
    }
}
// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node * current){
    // visit left child, right child, node
    if (current){
        postOrder(current->left);
        postOrder(current->right);
        process(current->value);
    }
}
// add value to binary search tree
template <class T>
void SearchTree<T>::add(T val){
    // add value to binary search tree
    if (!root){
        root = new Node(val);
        return;
    }
    add(root,val);
}

