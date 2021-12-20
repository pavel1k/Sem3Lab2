#pragma once
#include <cassert>
#include "BST.h"

void test_is_empty_1() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    assert(!a->isEmpty());
}

void test_is_empty_2() {
    BST<int>* a = new BST<int>(compareIntForBst);
    assert(a->isEmpty());
}

void test_check_count() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(22);
    assert(a->checkCount() == 2);
}

void test_insert_1() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    assert(a->whatInRoot() == 13);
}

void test_insert_2() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(22);
    assert(a->whatInNode(a->treeMax()) == 22);
}

void test_insert_3() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(22);
    a->insert(23);
    a->insert(22);
    a->insert(22);
    a->insert(13);
    a->insert(23);
    assert(a->checkCount() == 3);
}

void test_delete_1() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->deleteItem(13);
    assert(a->isEmpty() == 1);
}

void test_max() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    assert(a->whatInNode(a->treeMax()) == 25);
}

void test_min() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    assert(a->whatInNode(a->treeMin()) == 5);
}

void test_delete_2() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(22);
    a->insert(7);
    a->deleteItem(7);
    assert(a->checkCount() == 2);
    assert(a->whatInNode(a->treeMin()) == 13);
}

void test_search_1() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    assert(a->whatInNode(a->search(13)) == 13);
    assert(a->whatInRoot() == 13);
}

void test_search_2() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(22);
    a->insert(7);
    assert(a->whatInNode(a->search(22)) == 22);
}

void test_KLP() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    vector <int> exp = { 13 , 7 , 5 , 10 , 22 , 17 , 25 };
    for (int i = 0; i < a->checkCount(); i++) {
        assert((*a->KLP())[i] == exp[i]);
    }
}

void test_KPL() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    vector <int> exp = { 13 , 22 , 25 , 17 , 7 , 10 , 5 };
    for (int i = 0; i < a->checkCount(); i++) {
        assert((*a->KPL())[i] == exp[i]);
    }
}

void test_LKP() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    vector <int> exp = { 5 , 7 , 10 , 13 , 17 , 22 , 25 };
    for (int i = 0; i < a->checkCount(); i++) {
        assert((*a->LKP())[i] == exp[i]);
    }
}

void test_LPK() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    vector <int> exp = { 5 , 10 , 7 , 17 , 25 , 22 , 13 };
    for (int i = 0; i < a->checkCount(); i++) {
        assert((*a->LPK())[i] == exp[i]);
    }
}

void test_PLK() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    vector <int> exp = { 25 , 17 , 22 , 10 , 5 , 7 , 13 };
    for (int i = 0; i < a->checkCount(); i++) {
        assert((*a->PLK())[i] == exp[i]);
    }
}

void test_PKL() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    vector <int> exp = { 25 , 22 , 17 , 13 , 10 , 7 , 5 };
    for (int i = 0; i < a->checkCount(); i++) {
        assert((*a->PKL())[i] == exp[i]);
    }
}

void test_vhozhdenie_1() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    BST<int>* b = new BST<int>(compareIntForBst);
    assert(b->isEmpty());
    assert(a->findSubtree(b));
}

void test_vhozhdenie_2() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    BST<int>* b = new BST<int>(compareIntForBst);
    b->insert(13);
    b->insert(7);
    b->insert(22);
    assert(a->findSubtree(b));
}
void test_vhozhdenie_3() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    BST<int>* b = new BST<int>(compareIntForBst);
    b->insert(13);
    b->insert(22);
    b->insert(7);
    b->insert(25);
    assert(a->findSubtree(b));
}

void test_vhozhdenie_4() {
    BST<int>* a = new BST<int>(compareIntForBst);

    BST<int>* b = new BST<int>(compareIntForBst);
    b->insert(13);
    b->insert(22);
    b->insert(17);
    b->insert(25);
    assert(!a->findSubtree(b));
}

void test_vhozhdenie_5() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    BST<int>* b = new BST<int>(compareIntForBst);
    b->insert(13);
    b->insert(22);
    b->insert(17);
    b->insert(25); //25
    b->insert(7);
    b->insert(5);
    b->insert(10);
    assert(a->findSubtree(b));
}

void test_izvlechenie_1() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    BST<int>* b = new BST<int>(compareIntForBst);
    b = a->eject(a->search(22));
    assert(a->checkCount() == 7); // ïðîâåðèëè, ÷òî ñ à âñ¸ îê
    assert(b->checkCount() == 3);
    assert(b->whatInRoot() == 22);
    assert((*b->KLP())[0] == 22);
    assert((*b->KLP())[1] == 17);
    assert((*b->KLP())[2] == 25);
}

void test_izvlechenie_2() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    BST<int>* b = new BST<int>(compareIntForBst);
    b = a->eject(a->search(17));
    assert(a->checkCount() == 7);
    assert(b->checkCount() == 1);
    assert(b->whatInRoot() == 17);
}

void test_izvlechenie_3() {
    BST<int>* a = new BST<int>(compareIntForBst);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    BST<int>* b = new BST<int>(compareIntForBst);
    b = a->eject(a->search(13));
    assert(a->checkCount() == 7);
    assert(b->checkCount() == 7);
    for (int i = 0; i < 7; i++) {
        assert((*a->KLP())[i] == (*b->KLP())[i]);
    }
    for (int i = 0; i < 7; i++) {
        assert((*a->LKP())[i] == (*b->LKP())[i]);
    }
    for (int i = 0; i < 7; i++) {
        assert((*a->PKL())[i] == (*b->PKL())[i]); // ïðîâåðþ 3 âàðèàíòà
    }
}

void TEST_ALL_BST() {
    test_check_count();
    test_delete_1();
    test_delete_2();
    test_min();
    test_max();
    test_insert_1();
    test_insert_2();
    test_insert_3();
    test_is_empty_1();
    test_is_empty_2();
    test_izvlechenie_1();
    test_izvlechenie_2();
    test_izvlechenie_3();
    test_vhozhdenie_1();
    test_vhozhdenie_2();
    test_vhozhdenie_3();
    test_vhozhdenie_4();
    test_vhozhdenie_5();
    test_KLP();
    test_KPL();
    test_PKL();
    test_PLK();
    test_LKP();
    test_LPK();
    test_search_1();
    test_search_2();
}