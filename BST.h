#pragma once
#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;

template <class T>
class BST {
private:
    struct node {
        T data;
        node* left;
        node* right;
    };
    node* root;
    int count;
    int (*cmp)(T, T);
    void destroyTree(node* branch) {
        if (branch != nullptr) {
            destroyTree(branch->left);
            destroyTree(branch->right);
            delete branch;
        }
    }

    void insertHelp(node* branch, T item) {
        node* cur = branch;
        if (!this->cmp(cur->data, item) && !this->cmp(item, cur->data)) {
            this->count--;
            return;
        }
        else if (this->cmp(cur->data, item)) {
            if (cur->left != nullptr) {
                insertHelp(cur->left, item);
            }
            else {
                cur->left = new node;
                cur->left->data = item;
                cur->left->left = nullptr;
                cur->left->right = nullptr;
            }
        }
        else if (this->cmp(item,cur->data)) {
            if (cur->right != nullptr) {
                insertHelp(cur->right, item);
            }
            else {
                cur->right = new node;
                cur->right->data = item;
                cur->right->left = nullptr;
                cur->right->right = nullptr;
            }
        }
    }

    node* searchHelp(T item, node* cur) {
        node* branch = cur;
        if (branch != nullptr) {
            if (!this->cmp(cur->data, item) && !this->cmp(item, cur->data))
                return branch;
            else if (this->cmp(branch->data, item))
                return searchHelp(item, branch->left);
            else
                return searchHelp(item, branch->right);
        }
        else
            return nullptr;
    }

    void printHelp(node* cur) {
        node* tmp = cur;
        if (tmp != nullptr) {
            if (tmp->left)
                printHelp(tmp->left);
            cout << tmp->data << " ";
            if (tmp->right)
                printHelp(tmp->right);
        }
        else
            return;
    }

    node* treeMinHelp(node* cur) {
        node* min = cur;
        while (min->left) {
            min = min->left;
        }
        return min;
    }

    node* treeMaxHelp(node* cur) {
        node* max = cur;
        while (max->right) {
            max = max->right;
        }
        return max;
    }

    node* deleteHelp(T item, node* branch) {
        if (!branch) {
            return nullptr;
        }
        if (this->cmp(branch->data, item)) {
            branch->left = deleteHelp(item, branch->left);
        }
        else if (this->cmp(item,branch->data)) {
            branch->right = deleteHelp(item, branch->right);
        }


        else {
            if (branch->left == nullptr && branch->right == nullptr) {
                delete branch;
                branch = nullptr;
                return branch;
            }
            else if (branch->left == nullptr) {
                node* tmp = branch;
                branch = branch->right;
                delete tmp;
                return branch;
            }
            else if (branch->right == nullptr) {
                node* tmp = branch;
                branch = branch->left;
                delete tmp;
                return branch;
            }
            else {
                node* tmp = treeMinHelp(branch->right);
                branch->data = tmp->data;
                branch->right = deleteHelp(tmp->data, branch->right);
            }
        }
        return branch;
    }

    vector<T>* klpHelp(node* branch, vector<T>* vect) {
        node* tmp = branch; // KLP
        if (tmp) {
            vect->push_back(branch->data);
            klpHelp(branch->left, vect);
            klpHelp(branch->right, vect);
        }
        return vect;
    }

    BST<T>* klpForEject(node* cur, BST<T>* tree) {
        node* tmp = cur;
        if (tmp) {
            tree->insert(cur->data);
            klpForEject(cur->left, tree);
            klpForEject(cur->right, tree);
        }
        return tree;
    }

    vector<T>* kplHelp(node* branch, vector<T>* vect) {
        node* tmp = branch; // KLP
        if (tmp) {
            vect->push_back(branch->data);
            kplHelp(branch->right, vect);
            kplHelp(branch->left, vect);
        }
        return vect;
    }

    vector<T>* lkpHelp(node* branch, vector<T>* vect) {
        node* tmp = branch; // KLP
        if (tmp) {
            lkpHelp(branch->left, vect);
            vect->push_back(branch->data);
            lkpHelp(branch->right, vect);
        }
        return vect;
    }

    vector<T>* pklHelp(node* branch, vector<T>* vect) {
        node* tmp = branch; // KLP
        if (tmp) {
            pklHelp(branch->right, vect);
            vect->push_back(branch->data);
            pklHelp(branch->left, vect);
        }
        return vect;
    }

    vector<T>* lpkHelp(node* branch, vector<T>* vect) {
        node* tmp = branch; // KLP
        if (tmp) {
            lpkHelp(branch->left, vect);
            lpkHelp(branch->right, vect);
            vect->push_back(branch->data);
        }
        return vect;
    }

    vector<T>* plkHelp(node* branch, vector<T>* vect) {
        node* tmp = branch; // KLP
        if (tmp) {
            plkHelp(branch->right, vect);
            plkHelp(branch->left, vect);
            vect->push_back(branch->data);
        }
        return vect;
    }

    bool findSubtreeHelp(node* cur1, node* cur2) {
        if (cur2 == nullptr)
            return 1;
        return (!this->cmp(cur1->data, cur2->data) && !this->cmp(cur2->data, cur1->data)) &&
                findSubtreeHelp(cur1->left, cur2->left) &&
               findSubtreeHelp(cur1->right, cur2->right);
    }
    node* copyNode(node* item){
        if (item == nullptr) return nullptr;
        node* res = new node;
        res->data = item->data;
        res->left = copyNode(item->left);
        res->right = copyNode(item->right);
        return res;
    }

public:
    BST(const BST<T>&a ){
        this->cmp = a.cmp;
        this->count = a.count;
        this->root = copyNode(a.root);

    }
    BST(int (*cmp) (T, T)) {
        this->root = nullptr;
        this->count = 0;
        this->cmp = cmp;
    };

    ~BST() {
        destroyTree(this->root);
    };

    bool isEmpty() {
        if (this->root == nullptr)
            return 1;
        return 0;
    }

    T whatInRoot() {
        return this->root->data;
    }

    node* treeMax() {
        return treeMaxHelp(this->root);
    }

    node* treeMin() {
        return treeMinHelp(this->root);
    }

    vector <T>* KLP() {
        vector<T>* cur = new vector<T>;
        return klpHelp(this->root, cur);
    }

    vector <T>* KPL() {
        vector <T>* cur = new vector <T>;
        return kplHelp(this->root, cur);
    }

    vector <T>* LKP() {
        vector <T>* cur = new vector <T>;
        return lkpHelp(this->root, cur);
    }

    vector <T>* PKL() {
        vector <T>* cur = new vector <T>;
        return pklHelp(this->root, cur);
    }

    vector <T>* PLK() {
        vector <T>* cur = new vector <T>;
        return plkHelp(this->root, cur);
    }
    vector <T>* LPK() {
        vector <T>* cur = new vector <T>;
        return lpkHelp(this->root, cur);
    }

    void insert(T item) {
        this->count++;
        if (this->root != nullptr)
            insertHelp(this->root, item);
        else {
            this->root = new node;
            this->root->data = item;
            this->root->right = nullptr;
            this->root->left = nullptr;
        }
    }

    void clearTree() {
        destroyTree(this->root);
        this->root = nullptr;
        this->count = 0;
    }

    node* search(T item) {
        return searchHelp(item, this->root);
    }

    void deleteItem(T item) {
        if (search(item)) {
            this->count--;
        }
        this->root = deleteHelp(item, this->root);
    }

    int checkCount() {
        return this->count;
    }

    bool findSubtree(BST<T>* little_tree) {
        if (isEmpty()) {
            return 0;
        }
        if (little_tree->isEmpty()) {
            return 1;
        }
        node* cur1 = little_tree->search(little_tree->whatInRoot());
        if (!cur1)
            return 0;
        if (findSubtreeHelp(this->root, cur1)) {
            return 1;
        }
        return 0;
    }

    void print() {
        printHelp(this->root);
        cout << endl;
    }

    BST<T>* eject(node* cur) {
        BST<T>* new_tree = new BST<T>(this->cmp);
        return klpForEject(cur, new_tree);
    }
    T whatInNode(node* cur) {
        return cur->data;
    }
};

int compareIntForBst(int a, int b) {
    if (a > b)
        return 1;
    return 0;
}