#include <iostream>
#include <memory>
#include <cassert>

template<typename T>
class Node {

typedef std::shared_ptr<Node<T>> NodePtr;

protected:
    NodePtr left;
    NodePtr right;
    T key;

public:
    Node(const T &key) : key{key} {}

    NodePtr getLeft() {
        return this->left;
    }

    NodePtr getRight() {
        return this->right;
    }

    void setLeft(NodePtr node) {
        this->left = node;
    }

    void setRight(NodePtr node) {
        this->right = node;
    }

    T getKey() {
        return this->key;
    }

    virtual ~Node<T>() = default;
};

template<class N, typename T>
class BST {

typedef std::shared_ptr<Node<T>> NodePtr;

protected:
    NodePtr add(NodePtr tree, const T &key) {
        NodePtr node;

        if (tree->getKey() > key) {
            if (!tree->getLeft()) {
                tree->setLeft((node = std::make_shared<N>(key)));
            } else {
                node = add(tree->getLeft(), key);
            }
        } else if (tree->getKey() < key) {
             if (!tree->getRight()) {
                tree->setRight((node = std::make_shared<N>(key)));
            } else {
                node = add(tree->getRight(), key);
            }
        } else {
            node = tree;
        }

        return node;
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

    BST() {
        this->root = NULL;
    }

    ~BST() {
    }

    NodePtr add(const T &key) {
        if (root) {
            return this->add(this->root, key);
        } else {
            return (root = std::make_shared<N>(key));
        }
    }

    NodePtr search(const T &key) {
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
class MapNode : public Node<K> {


public:
    V value;

    MapNode(const K &key) : Node<K>{key} {
        
    };

    V getValue() {
        return this->value;
    }
};


template<typename K, typename V>
class Map : private BST<MapNode<K, V>, K> {

public:
    V& operator[](const K &key) {
        return std::dynamic_pointer_cast<MapNode<K, V>>(this->add(key))->value;
    }
};

int main() {
    Set<int> set;

    for (int i = 0; i <= 10000; i++) {
        set.insert(i);
    }

    for (int i = 0; i <= 10000; i++) {
        assert(set.contains(i));
    }

    std::cout << "SET TEST PASSED" << std::endl;

    Map<int, int> map;

    map[3] = 2;
    map[3] = 7;

    map[12] = 123;
    std::cout << map[12] << std::endl;
    std::cout << map[4] << std::endl;

    Map<std::string, int> stringMap;

    stringMap["text"] = 12;

    std::cout << stringMap["text"] << std::endl;


}