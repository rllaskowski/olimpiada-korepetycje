#include <iostream>
#include <memory>
#include <cassert>
#include <set>
#include <chrono>


template<typename T>
class AVLNode {
typedef AVLNode<T> * NodePtr;

protected:
    NodePtr left;
    NodePtr right;
    T key;
    int leftLength;
    int rightLength;

    NodePtr leftRotate();

    NodePtr rightRotate();
public:
    AVLNode<T>(const T &key) : 
        key{key}, 
        leftLength{0}, 
        rightLength{0},
        left{NULL},
        right{NULL} {}

    NodePtr getLeft() {
        return this->left;
    }

    NodePtr getRight() {
        return this->right;
    }

    void setLeft(NodePtr node) {
        left = node;
        if (node) {
            leftLength = 1+std::max(left->leftLength, left->rightLength);
        } else {
            leftLength = 0;
        }
    }

    void setRight(NodePtr node) {
        right = node;
        if (node) {
            rightLength = 1+std::max(right->leftLength, right->rightLength);
        } else {
            rightLength = 0;
        }
    }

    T getKey() {
        return this->key;
    }

    NodePtr rotate() {
        if (leftLength-rightLength > 1) {
            if (left->leftLength < left->rightLength) {
                setLeft(left->leftRotate());
            }
            return rightRotate();
        } else if (rightLength-leftLength > 1) {
            if (right->leftLength > right->rightLength) {
                setRight(right->rightRotate());
            }
            return leftRotate();
        } else {
            return this;
        }
    }

    ~AVLNode<T>() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    };
};

template<typename T>
AVLNode<T> * AVLNode<T>::leftRotate() {
    NodePtr a = this;
    NodePtr b = this->right;
    
    a->setRight(b->left);
    b->setLeft(a);
    
    return b;
}

template<typename T>
AVLNode<T> * AVLNode<T>::rightRotate() {
    NodePtr a = this;
    NodePtr b = this->left;

    a->setLeft(b->right);
    b->setRight(a);
    
    return b;
}

template<class N, typename T>
class AVL {

typedef AVLNode<T> * NodePtr;

protected:
    NodePtr add(NodePtr tree, const T &key, NodePtr &res) {
        if (tree->getKey() > key) {
            if (!tree->getLeft()) {
                tree->setLeft((res = new N(key)));
            } else {
                tree->setLeft(add(tree->getLeft(), key, res));
            }
        } else if (tree->getKey() < key) {
             if (!tree->getRight()) {
                tree->setRight((res = new N(key)));
            } else {
                tree->setRight(add(tree->getRight(), key, res));
            }
        } else {
            res = tree;
        }

        return tree->rotate();
    }

    NodePtr search(NodePtr tree, const T &key) {
        if (!tree) {
            return NULL;
        } else if (tree->getKey() > key) {
            return search(tree->getLeft(), key);
        } else if (tree->getKey() < key) {
            return search(tree->getRight(), key);
        } else {
            return tree;
        }
    }

    NodePtr root;

    AVL() : root{NULL} {}

    ~AVL() {
        delete root;
    }

    NodePtr add(const T &key) {
        if (root) {
            NodePtr res = NULL;
            root = this->add(this->root, key, res);
            return res;
        } else {
            return (root = new N(key));
        }
    }

    NodePtr search(const T &key) {
        return this->search(this->root, key);
    }
};


template<typename T>
class Set : private AVL<AVLNode<T>, T> {

public:
    void insert(const T &key) {
        this->add(key);
    }

    bool contains(const T &key) {
        return this->search(key) != NULL; 
    }
};

auto now = std::chrono::high_resolution_clock::now;

int main() {
    auto start = now();
    Set<int> set;

    for (int i = 0; i <= 10000000; i++) {
        set.insert(i);
    }

    auto mid = now();

    for (int i = 0; i <= 10000000; i++) {
        assert(set.contains(i));
    }
    
    auto end = now();
    std::chrono::duration<double> durationInsert = mid-start;
    std::chrono::duration<double> durationAll = end-start;

    std::cout << "SET TIME: " << std::endl;
    std::cout << "INSERT: " << durationInsert.count() << std::endl;
    std::cout << "ALL: " << durationAll.count() << std::endl;

    start = now();
    std::set<int> stdSet;

    for (int i = 0; i <= 10000000; i++) {
        stdSet.insert(i);
    }
    mid = now();

    for (int i = 0; i <= 10000000; i++) {
        stdSet.count(i);
    }

    end = now();

    durationAll = end-start;
    durationInsert = mid-start;
    std::cout << "STD::SET TIME: " << std::endl;
    std::cout << "INSERT: " << durationInsert.count() << std::endl;
    std::cout << "ALL: " << durationAll.count() << std::endl;
}