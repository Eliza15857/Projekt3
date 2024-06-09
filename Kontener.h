#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

template <class T>
class Węzeł{
public:
    T data;
    Węzeł* left;
    Węzeł* right;
    Węzeł(const T& value) : data(value), left(nullptr), right(nullptr) {}
};


template<class T>
class Kontener {
private:

    Węzeł<T>* root;

    Węzeł<T>* insert(Węzeł<T>* node, const T& value) {
        if (node == nullptr) {
            return new Węzeł(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    Węzeł<T>* remove(Węzeł<T>* node, const T& value) {
        if (node == nullptr) return node;

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr) {
                Węzeł<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Węzeł<T>* temp = node->left;
                delete node;
                return temp;
            }

            Węzeł<T>* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    Węzeł<T>* minValueNode(Węzeł<T>* node) {
        Węzeł<T>* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void inorder(Węzeł<T>* node) {
        if (node != nullptr) {
            inorder(node->left);
            std::cout << node->data << " ";
            inorder(node->right);
        }
    }

    void clear(Węzeł<T>* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    void writeToFile(ofstream& file, Węzeł<T>* node) {
        if (node != nullptr) {
            file << node->data << " ";
            writeToFile(file, node->left);
            writeToFile(file, node->right);
        }
    }

    int levelOf(Węzeł<T>* node, const T& value, int level) {
        if (node == nullptr) {
            throw runtime_error("Value not found in the tree.");
        }

        if (node->data == value) {
            return level;
        } else if (value < node->data) {
            return levelOf(node->left, value, level + 1);
        } else {
            return levelOf(node->right, value, level + 1);
        }
    }

    T commonAncestor(Węzeł<T>* node, const T& first, const T& second) {
        if (node == nullptr) {
            throw runtime_error("Common ancestor not found.");
        }

        if (node->data > first && node->data > second) {
            return commonAncestor(node->left, first, second);
        } else if (node->data < first && node->data < second) {
            return commonAncestor(node->right, first, second);
        } else {
            return node->data;
        }
    }

    bool contains(Węzeł<T>* node, T& value) {
        if (node == nullptr) return false;
        if (node->data == value) return true;
        return contains(node->left, value) || contains(node->right, value);
    }

    int getHeight(Węzeł<T>* node) {
        if (node == nullptr) return 0;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return 1 + std::max(leftHeight, rightHeight);
    }

    int balanceFactor(Węzeł<T>* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Węzeł<T>* rotateLeft(Węzeł<T>* node) {
        Węzeł<T>* newParent = node->right;
        node->right = newParent->left;
        newParent->left = node;
        return newParent;
    }

    Węzeł<T>* rotateRight(Węzeł<T>* node) {
        Węzeł<T>* newParent = node->left;
        node->left = newParent->right;
        newParent->right = node;
        return newParent;
    }

public:
    Kontener() : root(nullptr) {}

    ~Kontener() {
        clear(root);
    }

    void dodaj(const T& value) {
        root = insert(root, value);
    }

    void usun(const T& value) {
        root = remove(root, value);
    }

    void zapiszDoPliku(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            writeToFile(file, root);
            file.close();
        } else {
            throw runtime_error("Unable to open file for writing: " + filename);
        }
    }

    void wczytajZPliku(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            T value;
            while (file >> value) {
                dodaj(value);
            }
            file.close();
        } else {
            throw std::runtime_error("Unable to open file for reading: " + filename);
        }
    }

    void wizualizuj() {
        inorder(root);
        cout << endl;
    }

    int levelOf(const T& value) {
        return levelOf(root, value, 0);
    }

    T commonAncestor(const T& first, const T& second) {
        return commonAncestor(root, first, second);
    }

    bool contains(const T& value) {
        return contains(root, value);
    }

    int getHeight() {
        return getHeight(root);
    }

    int balanceFactor() {
        return balanceFactor(root);
    }

    Węzeł<T>* rotateLeft() {
        return rotateLeft(root);
    }

    Węzeł<T>* rotateRight() {
        return rotateRight(root);
    }

    Kontener& operator=(const Kontener& other) {
        if (this != &other) {
            clear(root);
            root = clone(other.root);
        }
        return *this;
    }

    Węzeł<T>* clone(Węzeł<T>* node) {
        if (node == nullptr) return nullptr;
        Węzeł<T>* newNode = new Węzeł(node->data);
        newNode->left = clone(node->left);
        newNode->right = clone(node->right);
        return newNode;
    }
};
