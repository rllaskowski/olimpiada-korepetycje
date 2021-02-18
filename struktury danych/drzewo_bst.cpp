#include <iostream>

template<typename T>
class Node {

protected:
    Node<T> *left;
    Node<T> *right;
    T key;

public:
    Node(const T &key) : key{key} {

    }

    Node<T> * getLeft() {
        return this->left;
    }

    Node<T> * getRight() {
        return this->right;
    }

    void setLeft(Node<T> *node) {
        this->left = node;
    }

    void setRight(Node<T> *node) {
        this->right = node;
    }

    T getKey() {
        return this->key;
    }
};

template<class N, typename T>
class BST {

protected:
    N * add(N *tree, const T &key) {
        N * node;

        if (tree->getKey() > key) {
            if (!tree->getLeft()) {
                tree->setLeft((node = new N(key)));
            } else {
                node = add(tree->getLeft(), key);
            }
        } else if (tree->getKey() < key) {
             if (!tree->getRight()) {
                tree->setRight((node = new N(key)));
            } else {
                node = add(tree->getRight(), key);
            }
        } else {
            node = tree;
        }

        return node;
    }

    N * search(N *tree, const T &key) {
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

    void freeTree(N *tree) {
        if (tree) {
            freeTree(tree->getLeft());
            freeTree(tree->getRight());

            delete tree;
        }
    }

    N *root;

    BST() {
        this->root = NULL;
    }

    ~BST() {
        freeTree(this->root);
    }

    N * add(const T &key) {
        if (root) {
            return this->add(this->root, key);
        } else {
            return (root = new N(key));
        }
    }

    N * search(const T &key) {
        return this->search(this->root, key);
    }
};

template<typename T>
class Set : private BST<Node<T>, T> {

public:
    void insert(const T &key) {
        this->add(key);
    }

    bool contains(const T &key) {
        return this->search(key) != NULL; 
    }
};

template<typename K, typename V>
class MapNode {

private:
    MapNode *left;
    MapNode *right;
    K key;

public:
    V value;

    MapNode(const K &key) : key{key} {
        
    };

    MapNode<K, V> * getLeft() {
        return this->left;
    }

    MapNode<K, V> * getRight() {
        return this->right;
    }

    K getKey() {
        return this->key;
    }

    void setLeft(MapNode<K, V> *node) {
        this->left = node;
    }

    void setRight(MapNode<K, V> *node) {
        this->right = node;
    }

    V getValue() {
        return this->value;
    }
};


template<typename K, typename V>
class Map : private BST<MapNode<K, V>, K> {

public:
    K& operator[](const K &key) {
        return this->add(key)->value;
    }
};

int main() {
    Set<int> set;

    set.insert(3);
    set.insert(6);

    std::cout << set.contains(5) << std::endl;
    std::cout << set.contains(6) << std::endl;


    Map<int, int> map;

    map[3] = 2;
    map[3] = 7;

    map[12] = 123;
    std::cout << map[12] << std::endl;
    std::cout << map[4] << std::endl;

}