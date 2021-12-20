#pragma once
#include <iostream>
#include <string>
#include "testSorts.h"
#include "testBST.h"
#include "testDictionary.h"
#include "testSparceVector.h"
#include "testHistogram.h"
#include "testSearchOftenSub.h"

void menu() {
    int switcher = 1;
    while (switcher) {
        cout << "1. to make histogram" << endl
             << "2. to make sparse vector" << endl
             << "3. to find often sub sequence" << endl
             << "0. to exit" << endl;

        cin >> switcher;
        if (switcher == 1) { //histogram
            Histogram<Person>* cur_hist = new Histogram<Person>(Get_int_value, compare_int_int_pairs);
            cout << "how many persons u want to add?" << endl;
            int amount_case1 = 0;
            cin >> amount_case1;
            for (int i = 0; i < amount_case1; i++) {
                Person cur_person;
                string filler;
                cout << "enter name:  ";
                cin >> filler;
                cur_person.name = filler;
                filler.clear();
                cout << "enter surname:  ";
                cin >> filler;
                cur_person.second_name = filler;
                filler.clear();
                cout << "enter age:  ";
                int age_person = 0;
                cin >> age_person;
                cur_person.age = age_person;
                cout << "enter your country:  ";
                cin >> filler;
                cur_person.country = filler;
                filler.clear();
                cur_hist->Add(cur_person);
                cout << endl;
            }
            cout << "1. to do even partition" << endl
                 << "2. to do uneven partition" << endl;
            cin >> switcher;
            if (switcher == 1) {
                int min, max, divider;
                cout << "enter minimum age for histogram" << endl;
                cin >> min;
                cout << "enter maximum age for histogram" << endl;
                cin >> max;
                cout << "enter divider for histogram" << endl;
                cin >> divider;
                if (max < min)
                    break;
                cur_hist->even_partition(min, max, divider)->Print();
            }
            else if (switcher == 2) {
                ArraySequence<int>* arr = new ArraySequence<int>;
                cout << "enter boundaries of splitting" <<
                     endl << "if u want to stop - 1" << endl;
                int boundary = 1;
                while (boundary != -1) {
                    int boundary = 0;
                    cin >> boundary;
                    if (boundary == -1)
                        break;
                    arr->Append(boundary);
                }
                cur_hist->uneven_partition(arr)->Print();
            }
            switcher = 1;
        }


        else if (switcher == 2) {   //  sparce vector
            cout << "how many elements contain in vector?" << endl;
            int amount_case2 = 0;
            cin >> amount_case2;
            int* vect = new int[amount_case2];
            for (int i = 0; i < amount_case2; i++) {
                int value = 0;
                cout << i << ") ";
                cin >> value;
                vect[i] = value;
            }
            SparseVector<int>* cur_vect = new SparseVector<int>(vect, amount_case2, compare_pairs_for_sparce);
            cout << "size of vector is: " << cur_vect->getSize() << endl;
            cout << "your vector:" << endl;
            cout << "index - value" << endl;
            cur_vect->Print();
            cout << endl;
        }

        else if (switcher == 3) {
            cout << "enter your string(use _ instead of " ")" << endl;
            string input_string;
            cin >> input_string;
            ArraySequence<char>* arr = new ArraySequence<char>;
            for (size_t i = 0; i < input_string.size(); i++) {
                arr->InsertAt(input_string[i], i);
            }
            int min = 0, max = 0;
            cout << "enter min: ";
            cin >> min;
            cout << endl << "enter max: ";
            cin >> max;
            if (min > max)
                continue;
            SearchOftenSub* finder = new SearchOftenSub(arr, min, max, compare_string_int);
            cout << "1. to find often sub sequence" << endl
                 << "2. to show dictionary" << endl;
            cin >> switcher;
            if (switcher == 1) {
                Sequence<Tpair_for_dict<string, int>>* seq_for_search =
                        finder->Get_max();
                cout << "sub sequence - times on string" << endl;
                for (int i = 0; i < seq_for_search->GetLength(); i++) {
                    cout << seq_for_search->Get(i).key << " - " <<
                         seq_for_search->Get(i).element << endl;
                }
            }
            else if (switcher == 2)
                finder->print();
        }
    }
}

void TESTS_LAB_2() {
    TEST_ALL_SORTS();
    TEST_ALL_BST();
    TEST_ALL_DICTIONARY();
    TEST_ALL_SPARCE_VECTOR();
    TEST_ALL_HISTOGRAM();
    TEST_ALL_SEARCH_OFTEN_SUB();
    cout << "tests passed succesfully!" << endl;
}