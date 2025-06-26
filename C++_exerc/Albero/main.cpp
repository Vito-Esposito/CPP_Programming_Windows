#include <iostream>
using namespace std;

class node3tree {
private:
    int data;
    node3tree* left;
    node3tree* mid;
    node3tree* right;

public:
    // Costruttore
    node3tree(int val) : data(val), left(nullptr), mid(nullptr), right(nullptr) {}

    // Setters
    void setLeft(node3tree* l) { left = l; }
    void setMid(node3tree* m) { mid = m; }
    void setRight(node3tree* r) { right = r; }

    // Getters
    node3tree* getLeft() { return left; }
    node3tree* getMid() { return mid; }
    node3tree* getRight() { return right; }
    int getData() { return data; }

    // Visita 2d1
    void visita2d1(node3tree* node) {
        if (node == nullptr) return;

        if (node->left == nullptr && node->mid == nullptr && node->right == nullptr) {
            cout << node->data << " ";
            return;
        }

        visita2d1(node->left);
        visita2d1(node->mid);
        cout << node->data << " ";
        visita2d1(node->right);
    }

    // Visita Postorder (left, mid, right, root)
    void visitaPostorder(node3tree* node) {
        if (node == nullptr) return;

        visitaPostorder(node->left);
        visitaPostorder(node->mid);
        visitaPostorder(node->right);
        cout << node->data << " ";
    }
};

int main() {
    // Costruzione dell'albero
    node3tree* root = new node3tree(1);
    node3tree* n2 = new node3tree(2);
    node3tree* n3 = new node3tree(3);
    node3tree* n4 = new node3tree(4);
    node3tree* n5 = new node3tree(5);
    node3tree* n6 = new node3tree(6);

    root->setLeft(n2);
    root->setMid(n3);
    root->setRight(n4);

    (root->getLeft())->setLeft(n5);
    n2->setMid(n6);

    cout << "Visita 2d1: ";
    root->visita2d1(root);
    cout << endl;

    cout << "Visita Postorder: ";
    root->visitaPostorder(root);
    cout << endl;

    // Pulizia della memoria (non richiesta ma buona pratica)
    delete n5;
    delete n6;
    delete n2;
    delete n3;
    delete n4;
    delete root;

    return 0;
}
