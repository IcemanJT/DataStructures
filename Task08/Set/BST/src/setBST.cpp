#include "setBST.h"
#include <iostream>

setBST::setBST()
{
    root = nullptr;
    size = 0;
}

setBST::setBST(const setBST &s)
{
    root = nullptr;
    size = 0;
    setAdd(s.root, *this);
}

bool setBST::isInSet(int x)
{
    setBSTNode *current = root;
    while (current != nullptr)
    {
        if (current->data == x)
            return true;
        else if (current->data > x)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}

setBSTNode* setBST::isInSet_pointer(int x)
{
    setBSTNode *current = root;
    while (current != nullptr)
    {
        if (current->data == x)
            return current;
        else if (current->data > x)
            current = current->left;
        else
            current = current->right;
    }
    return nullptr;
}

void setBST::printSet()
{
    printSet(root);
}

void setBST::printSet(setBSTNode *root)
{
    if (root != nullptr)
    {
        printSet(root->left);
        std::cout << root->data << " ";
        printSet(root->right);
    }
}

int setBST::getSize()
{
    return size;
}

void setBST::insert(int x)
{


    setBSTNode *newNode = new setBSTNode(x);
    setBSTNode *current = root;
    setBSTNode *parent = nullptr;

    while (current != nullptr)
    {
        if (current->data == x)
        {
            delete newNode;
            return;
        }

        parent = current;
        if (current->data > x)
            current = current->left;
        else if (current->data < x)
            current = current->right;
        else
        {
            delete newNode;
            return;
        }
    }

    newNode->parent = parent;
    if (parent == nullptr)
        root = newNode;
    else if (parent->data > x)
        parent->left = newNode;
    else
        parent->right = newNode;
    size++;
}

void setBST::withdraw(int x)
{
    size--;
    setBSTNode* node = isInSet_pointer(x);
    if (node == nullptr)
        return;
    
    if (node->left == nullptr){
        shiftNodes(root, node, node->right);
        delete node;
    }
    else if (node->right == nullptr){
        shiftNodes(root, node, node->left);
        delete node;
    }
    else{
        setBSTNode* min = node->right;
        while (min->left != nullptr)
            min = min->left;
        if (min->parent != node){
            shiftNodes(root, min, min->right);
            min->right = node->right;
            min->right->parent = min;
        }
        shiftNodes(root, node, min);
        min->left = node->left;
        min->left->parent = min;
        delete node;
    }
}

void setBST::shiftNodes(setBSTNode *root, setBSTNode *node, setBSTNode *child)
{
    if (node->parent == nullptr)
        this->root = child;
    else if (node == node->parent->left)
        node->parent->left = child;
    else
        node->parent->right = child;

    if (child != nullptr)
        child->parent = node->parent;
}

void setBST::setAdd(setBSTNode *root, setBST &s)
{
    if (root != nullptr)
    {
        setAdd(root->left, s);
        s.insert(root->data);
        setAdd(root->right, s);
    }
}


setBST &setBST::operator+(const setBST &s)
{
    setBST *newSet = new setBST();
    setAdd(root, *newSet);
    setAdd(s.root, *newSet);
    return *newSet;
}

void setBST::setIntersection(setBSTNode *root, setBST &s, setBST &result)
{
    if (root != nullptr)
    {
        setIntersection(root->left, s, result);
        if (s.isInSet(root->data))
            result.insert(root->data);
        setIntersection(root->right, s, result);
    }
}

setBST &setBST::operator*(const setBST &s)
{
    setBST *newSet = new setBST();
    setIntersection(root, const_cast<setBST &>(s), *newSet);
    return *newSet;
}

void setBST::setDifference(setBSTNode *root, setBST &s, setBST &result)
{
    if (root != nullptr)
    {
        setDifference(root->left, s, result);
        if (!s.isInSet(root->data))
            result.insert(root->data);
        setDifference(root->right, s, result);
    }
}

setBST &setBST::operator-(const setBST &s)
{
    setBST *newSet = new setBST();
    setDifference(root, const_cast<setBST &>(s), *newSet);
    return *newSet;
}

bool setBST::operator<=(const setBST &s)
{
    bool result = true;
    setSubset(root, const_cast<setBST &>(s), result);
    return result;
}

void setBST::setSubset(setBSTNode *root, setBST &s, bool &result)
{
    if (root != nullptr)
    {
        setSubset(root->left, s, result);
        if (!s.isInSet(root->data))
            result = false;
        setSubset(root->right, s, result);
    }
}

bool setBST::operator==(const setBST &s)
{
    bool result = true;
    setEqual(root, const_cast<setBST &>(s), result);
    setEqual(s.root, const_cast<setBST &>(*this), result);
    return result;
}

void setBST::setEqual(setBSTNode *root, setBST &s, bool &result)
{
    if (root != nullptr)
    {
        setEqual(root->left, s, result);
        if (!s.isInSet(root->data))
            result = false;
        setEqual(root->right, s, result);
    }
}

setBST::~setBST()
{
    std::cout << "Destructor called for root:" << root->data << std::endl;
    deleteTree(root);
}

void setBST::deleteTree(setBSTNode *root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

void setBST::clearSet()
{
    clearSet(root);
    root = nullptr;
    size = 0;
}

void setBST::clearSet(setBSTNode *root)
{
    if (root != nullptr)
    {
        clearSet(root->left);
        clearSet(root->right);
        delete root;
    }
}
