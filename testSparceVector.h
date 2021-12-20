#pragma once
#include "SparseVector.h"
#include <cassert>

template<class T>
int compare_pairs_for_sparce(Tpair_for_dict<int, T> a, Tpair_for_dict<int, T> b) {
    if (a.key > b.key)
        return 1;
    return 0;
}


void test_1_vector_sparce_vector() {
    int* a = new int[10];
    for (int i = 0; i < 10; i++) {
        if (i % 2)
            a[i] = i + 3;
        else
            a[i] = 0;
    }
    SparseVector<int>* sparce_vector = new SparseVector<int>(a, 10, compare_pairs_for_sparce);
    for (int i = 0; i < 10; i++) {
        assert(a[i] == sparce_vector->getSparseVector()[i]);
    }
    assert(10 == sparce_vector->getSize());
}


void test_2_vector_sparce_vector() {
    int* a = new int[14];
    for (int i = 0; i < 14; i++) {
        a[i] = 0;
    }
    SparseVector<int>* sparce_vector = new SparseVector<int>(a, 14, compare_pairs_for_sparce);
    for (int i = 0; i < 14; i++) {
        assert(a[i] == sparce_vector->getSparseVector()[i]);
    }
    assert(14 == sparce_vector->getSize());
}

void test_3_vector_sparce_vector() {
    int* a = new int[9];
    for (int i = 0; i < 9; i++) {
        a[i] = i * 5;
    }
    SparseVector<int>* sparce_vector = new SparseVector<int>(a, 9, compare_pairs_for_sparce);
    for (int i = 0; i < 9; i++) {
        assert(a[i] == sparce_vector->getSparseVector()[i]);
    }
}

void test_4_count_sparce_vector() {
    int* a = new int[9];
    for (int i = 0; i < 9; i++) {
        a[i] = i * 5;
    }
    SparseVector<int>* sparce_vector = new SparseVector<int>(a, 9, compare_pairs_for_sparce);
    assert(9 == sparce_vector->getSize());
}

void test_5_count_sparce_vector() {
    int* a = new int[1];
    for (int i = 0; i < 1; i++) {
        a[i] = i * 5;
    }
    SparseVector<int>* sparce_vector = new SparseVector<int>(a, 0, compare_pairs_for_sparce);
    assert(0 == sparce_vector->getSize());
}

void TEST_ALL_SPARCE_VECTOR() {
    test_1_vector_sparce_vector();
    test_2_vector_sparce_vector();
    test_3_vector_sparce_vector();
    test_4_count_sparce_vector();
    test_5_count_sparce_vector();
}