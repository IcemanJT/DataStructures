// Creator: Jeremi Toroj
// Date:    6/12/2023

#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <utility>
#include <iostream>

template <typename T>
class TreeNode {
public:
    T key;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode<T>* parent;

    TreeNode(T val) : key(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree{
private:

    TreeNode<T>* root;
    int size;

    int depth(TreeNode<T>* node){
        if(node == nullptr){
            return 0;
        }
        else {
            int leftDepth = depth(node->left);
            int rightDepth = depth(node->right);

            if(leftDepth > rightDepth){
                return leftDepth + 1;
            } else {
                return rightDepth + 1;
            }
        }
    }

    void inorder(TreeNode<T>* node){
        if(node != nullptr){
            inorder(node->left);
            std::cout << node->key << std::endl;
            inorder(node->right);
        }
    }


    void preorder(TreeNode<T>* node){
        if(node != nullptr){
            std::cout << node->key << std::endl;
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(TreeNode<T>* node){
        if(node != nullptr){
            postorder(node->left);
            postorder(node->right);
            std::cout << node->key << std::endl;
        }
    }

public:

    // constructor
    BinaryTree(): root(nullptr), size(0) {}

    void insert(T x){
        TreeNode<T>* newNode = new TreeNode<T>(x);
        TreeNode<T>* parent = nullptr;
        TreeNode<T>* current = root;

        size++;

        while(current != nullptr){
            parent = current;
            if(x < current->key){
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if(parent == nullptr){
            root = newNode;
        } else if(x < parent->key){
            parent->left = newNode;
            
        } else {
            parent->right = newNode;
        }
        newNode->parent = parent;
    }

    TreeNode<T>* search(const T& x){
        TreeNode<T>* node = root;
        while(node != nullptr && node->key != x){
            if(x < node->key){
                node = node->left;
            } else {
                node = node->right;
            }
        }
        
        TreeNode<T>* result = node;

        return result;
    }

    TreeNode<T>* searchRecursive(TreeNode<T>* node, const T& x){
        if (node == nullptr || node->key == x){
            return node;
        }

        if (x < node->key){
            return searchRecursive(node->left, x);
        } else {
            return searchRecursive(node->right, x);
        }

        TreeNode<T>* result = node;

        return result;
    }

    int current_size(){
        return size;
    }
    

    T minimum(){
        TreeNode<T>* current = root;
        while(current->left != nullptr){
            current = current->left;
        }
        return current->key;
    }

    T maximum(){
        TreeNode<T>* current = root;
        while(current->right != nullptr){
            current = current->right;
        }
        return current->key;
    }

    int depth(){
        return depth(root);
    }

    void inorder(){
        inorder(root);
    }

    void preorder(){
        preorder(root);
    }

    void postorder(){
        postorder(root);
    }

    void deleteTree(TreeNode<T>* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    ~BinaryTree(){
        deleteTree(root);
    };

};

#endif
