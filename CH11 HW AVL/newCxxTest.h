/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   testavl.h
 * Author: hloi
 *
 * Created on December 2, 2017, 9:35 PM
 */

#ifndef TESTAVL_H
#define TESTAVL_H

#include <cxxtest/TestSuite.h>

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include "Binary_Search_Tree.h"
#include "AVL_Tree.h"
#include "pre_order_traversal.h"
#include "BST_With_Rotate.h"
//Include your classes header file(s) below and uncomment.
//#include "myClass.h"

#include <iterator>
#include <algorithm>

using namespace std;

int compareFiles(const std::string& p1, const std::string& p2) {
    //  std::ifstream f1(p1, std::ifstream::in);
    //  std::ifstream f2(p2, std::ifstream::in);

    ifstream file1(p1.c_str()), file2(p2.c_str());

    int j;
    j = 0;
    string line1, line2;

    while (getline(file1, line1)) {
        getline(file2, line2);
        j++;
        line1.erase(line1.find_last_not_of(" \n\r\t")+1);
        line2.erase(line2.find_last_not_of(" \n\r\t")+1);
        if (line1.compare(line2) != 0) {
            cout << j << "-th strings are not equal" << "\n";
            cout << "   " << line1 << "\n";
            cout << "   " << line2 << "\n";
            return 0;
        }
    }
    return 1;
}

class testavl : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testMyFunction() {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        ofstream out;
        out.open("test.txt");
        Binary_Search_Tree<string>* the_tree = NULL;
        the_tree = new AVL_Tree<string>;
        double value;

        string line;
        ifstream myfile("words.txt");
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                // the_tree->insert(atof(line.c_str()));
                the_tree->insert(line);
            }
            myfile.close();
        } else cout << "Unable to open file";
        // pre_order_traversal(*the_tree, cout, 0);
        pre_order_traversal(*the_tree, out, 0);
        myfile.close();
        string f1 = "test.txt";
        string f2 = "example.txt";
        TS_ASSERT_EQUALS(compareFiles(f1, f2), 1);
    }

    void testErase1() {
        std::ostringstream out;
        std::cout << "Test erase 1..." << std::endl;
        AVL_Tree<int> test1;
        test1.insert(40);
        test1.insert(20);
        TS_ASSERT_EQUALS(test1.erase(20), true);
        TS_ASSERT_EQUALS(test1.erase(55), false);
        TS_ASSERT_EQUALS(test1.get_data(), 40);
        std::cout << test1.to_string() << std::endl;

    }

    void testErase2() {
        std::ostringstream out;
        std::cout << "Test erase 2..." << std::endl;
        AVL_Tree<int> test;
        test.insert(40);
        test.insert(20);
        test.insert(60);
        TS_ASSERT_EQUALS(test.erase(55), false);
        TS_ASSERT_EQUALS(test.get_data(), 40);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 20);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 60);
        std::cout << test.to_string() << std::endl;

    }


    void testEras3e() {
        std::ostringstream out;
        std::cout << "Test erase 3" << std::endl;
        AVL_Tree<int> test;
        test.insert(60);
        test.insert(50);
        test.insert(150);
        test.insert(25);
        test.insert(55);
        test.insert(10);
        TS_ASSERT_EQUALS(test.erase(60), true);
        TS_ASSERT_EQUALS(test.find(60), nullptr);
        TS_ASSERT_EQUALS(test.erase(55), true);
        TS_ASSERT_EQUALS(test.find(55), nullptr);
        TS_ASSERT_EQUALS(test.erase(25), true);
        TS_ASSERT_EQUALS(test.find(25), nullptr);
        TS_ASSERT_EQUALS(test.insert(125), true);
        TS_ASSERT_EQUALS(test.insert(250), true);
        TS_ASSERT_EQUALS(test.erase(125), true);
        TS_ASSERT_EQUALS(test.find(125), nullptr);
        TS_ASSERT_EQUALS(test.erase(50), true);
        TS_ASSERT_EQUALS(test.find(50), nullptr);
        TS_ASSERT_EQUALS(test.insert(15), true);
        TS_ASSERT_EQUALS(test.erase(150), true);
//        TS_ASSERT_EQUALS(test.get_data(), 15);
//        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 10);
//        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 250);
        std::cout << test.to_string() << std::endl;

    }

    void testBtNode() { // very basic test
        std::cout << "Beginning tests..." << std::endl;
        std::ostringstream out;
        BTNode<int> test(5, nullptr, nullptr);
        out << test << std::endl;
        std::cout << out.str() << std::endl;
        TS_ASSERT_EQUALS(test.data, 5);
        TS_ASSERT_EQUALS(test.right, nullptr);
        TS_ASSERT_EQUALS(test.left, nullptr);
    }

    void testEmptytree() {
        std::cout << "Beginning tests..." << std::endl;
        Binary_Tree<int> test;
        TS_ASSERT_THROWS(test.get_left_subtree(), std::invalid_argument);
        TS_ASSERT_THROWS(test.get_right_subtree(), std::invalid_argument);
        TS_ASSERT_THROWS(test.get_left_subtree().get_data(), std::invalid_argument);
    }

    void testTreeOneNode() {
        std::cout << "Beginning tests..." << std::endl;
        Binary_Search_Tree<int> test;
        test.insert(1);
        TS_ASSERT_EQUALS(test.is_leaf(), true);
        TS_ASSERT_THROWS(test.get_left_subtree().get_data(), std::invalid_argument);
        TS_ASSERT_THROWS(test.get_right_subtree().get_data(), std::invalid_argument);
    }

    void testTreeBasic() {
        std::cout << "Beginning tests..." << std::endl;
        Binary_Search_Tree<int> test;
        TS_ASSERT_EQUALS(test.is_leaf(), true); // not sure about this case, but the thing tests itself is its null, but I am not sure if that makes sense.
        test.insert(2);
        TS_ASSERT_EQUALS(test.is_leaf(), true);
        test.insert(1);
        TS_ASSERT_EQUALS(test.is_leaf(), false);
        test.insert(3);
        TS_ASSERT_EQUALS(test.is_leaf(), false);



        TS_ASSERT_EQUALS(test.is_leaf(), false);
        TS_ASSERT_EQUALS(test.get_data(), 2);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 1);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 3);

        TS_ASSERT_EQUALS(test.insert(1), false);
        TS_ASSERT_EQUALS(test.insert(2), false);
        TS_ASSERT_EQUALS(test.insert(3), false);
    }

    void testTreeBasic2() {
        std::cout << "Beginning tests..." << std::endl;
        Binary_Search_Tree<int> test;
        test.insert(10);
        test.insert(5);
        test.insert(15);

        test.insert(4);
        test.insert(6);

        test.insert(14);
        test.insert(16);

        TS_ASSERT_EQUALS(test.get_data(), 10);
        TS_ASSERT_EQUALS(test.is_leaf(), false);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 5);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 15);


        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 4);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 6);


        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 14);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 16);
    }

    void testTreeBasic3() {
        std::cout << "Beginning tests..." << std::endl;
        Binary_Search_Tree<int> test;
        test.insert(10);
        test.insert(5);
        test.insert(15);

        test.insert(4);
        test.insert(6);

        test.insert(14);
        test.insert(16);

        TS_ASSERT_EQUALS(test.get_data(), 10);
        TS_ASSERT_EQUALS(test.is_leaf(), false);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 5);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 15);


        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 4);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 6);


        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 14);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 16);

        TS_ASSERT_EQUALS(test.erase(10), true);

        TS_ASSERT_EQUALS(test.get_data(), 6);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 5);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 15);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 4);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 14);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 16);

        TS_ASSERT_EQUALS(test.find(404), nullptr);


    }

    void testTreeBasic4() {
        std::cout << "Beginning tests..." << std::endl;
        Binary_Search_Tree<int> test;
        test.insert(10);
        test.insert(5);
        test.insert(15);

        test.insert(4);
        test.insert(6);

        test.insert(14);
        test.insert(16);

        TS_ASSERT_EQUALS(test.get_data(), 10);
        TS_ASSERT_EQUALS(test.is_leaf(), false);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 5);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 15);


        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 4);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 6);


        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 14);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 16);

        TS_ASSERT_EQUALS(test.erase(10), true);

        TS_ASSERT_EQUALS(test.get_data(), 6);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 5);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 15);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 4);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 14);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 16);

    }

    void testTreeBasic5() {
        std::cout << "Beginning tests..." << std::endl;
        Binary_Search_Tree<int> test;
        test.insert(10);
        test.insert(5);
        TS_ASSERT_EQUALS(test.erase(10), true);
        TS_ASSERT_EQUALS(test.get_data(), 5);
    }

    void testTreeBasic6() {
        std::cout << "Beginning tests..." << std::endl;
        Binary_Search_Tree<int> test;
        test.insert(10);
        test.insert(15);
        TS_ASSERT_EQUALS(test.erase(10), true);
        TS_ASSERT_EQUALS(test.get_data(), 15);
    }

    void testTreeBasic7() {
        std::cout << "Beginning tests..." << std::endl;
        Binary_Search_Tree<int> test;
        test.insert(10);
        test.insert(5);
        test.insert(15);

        test.insert(4);
        test.insert(6);

        test.insert(14);
        test.insert(16);

        TS_ASSERT_EQUALS(test.get_data(), 10);
        TS_ASSERT_EQUALS(test.is_leaf(), false);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 5);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 15);


        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 4);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 6);


        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 14);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 16);

        TS_ASSERT_EQUALS(test.erase(6), true);

        TS_ASSERT_EQUALS(test.get_data(), 10);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 5);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 4);
        TS_ASSERT_THROWS(test.get_left_subtree().get_right_subtree().get_data(), std::invalid_argument);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 15);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 14);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 16);

        TS_ASSERT_EQUALS(test.erase(404), false);
    }

    void testTreeBasic8() {
        std::cout << "Beginning tests..." << std::endl;
        Binary_Search_Tree<int> test;
        TS_ASSERT_EQUALS(test.erase(404), false);
    }


    void testOrderLeftLeft() {
        std::cout << "Beginning tests..." << std::endl;
        AVL_Tree<int> test;
        test.insert(100);
        test.insert(50);
        test.insert(150);
        test.insert(175);
        test.insert(25);
        test.insert(5);

        TS_ASSERT_EQUALS(test.get_data(), 100)

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 25);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 5);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 50);


        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 150);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 175);
    }

    void testInsertAlreadyExists() {
        std::cout << "Beginning tests..." << std::endl;
        AVL_Tree<int> test;
        test.insert(100);
        test.insert(50);
        test.insert(150);

        TS_ASSERT_EQUALS(test.insert(50), false);
        TS_ASSERT_EQUALS(test.insert(100), false);
        TS_ASSERT_EQUALS(test.insert(150), false);

    }

    void testOrderRightRight() {
        std::cout << "Beginning tests..." << std::endl;
        AVL_Tree<int> test;
        test.insert(100);
        test.insert(50);
        test.insert(150);
        test.insert(175);
        test.insert(25);
        test.insert(200);


        TS_ASSERT_EQUALS(test.get_data(), 100)

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 25);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 175);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 200);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 150);

    }

    void testOrderLeftRight() {
        std::cout << "Beginning tests..." << std::endl;
        AVL_Tree<int> test;
        test.insert(100);
        test.insert(50);
        test.insert(150);
        test.insert(175);
        test.insert(25);
        test.insert(49);

        TS_ASSERT_EQUALS(test.get_data(), 100)

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 49);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 25);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 50);


        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 150);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 175);
    }

    void testOrderRightRightBasic() {
        std::cout << "Beginning rightleft..." << std::endl;
        AVL_Tree<int> test;
        test.insert(40);
        test.insert(20);
        test.insert(60);
        test.insert(80);

        TS_ASSERT_EQUALS(test.get_data(), 40)

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 20);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 60);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 80);
    }

    void testOrderRightLeftBasic() {
        std::cout << "Beginning rightleft..." << std::endl;
        AVL_Tree<int> test;
        test.insert(40);
        test.insert(20);
        test.insert(60);
        test.insert(50);

        TS_ASSERT_EQUALS(test.get_data(), 40)

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 20);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 60);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 50);
    }

    void testOrderRightLeftBasic2() {
        std::cout << "Right-Left" << std::endl;
        AVL_Tree<int> test;
        TS_ASSERT_EQUALS(test.insert(100), true);
        TS_ASSERT_EQUALS(test.insert(50), true);
        TS_ASSERT_EQUALS(test.insert(150), true);
        TS_ASSERT_EQUALS(test.insert(175), true);
        TS_ASSERT_EQUALS(test.insert(25), true);
        TS_ASSERT_EQUALS(test.insert(160), true);

        TS_ASSERT_EQUALS(test.get_data(), 100);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 160);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 25);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 160);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 150);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 175);
    }

    void testRightBranch1() {
        std::cout << "Right-Left" << std::endl;
        AVL_Tree<int> test;

        TS_ASSERT_EQUALS(test.insert(100), true);
        TS_ASSERT_EQUALS(test.insert(50), true);
        TS_ASSERT_EQUALS(test.insert(150), true);
        TS_ASSERT_EQUALS(test.insert(140), true);
        TS_ASSERT_EQUALS(test.insert(75), true);


        TS_ASSERT_EQUALS(test.get_data(), 100);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 150);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 140);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 75);


        TS_ASSERT_THROWS(test.get_left_subtree().get_left_subtree().get_data(), std::invalid_argument);
        TS_ASSERT_THROWS(test.get_right_subtree().get_right_subtree().get_data(), std::invalid_argument);

    }

    void testRightHeavyLeftChild() {
        AVL_Tree<int> test;
        TS_ASSERT_EQUALS(test.insert(50), true);
        TS_ASSERT_EQUALS(test.insert(25), true);
        TS_ASSERT_EQUALS(test.insert(75), true);
        TS_ASSERT_EQUALS(test.insert(60), true);
        TS_ASSERT_EQUALS(test.insert(100), true);
        TS_ASSERT_EQUALS(test.insert(51), true);


        TS_ASSERT_EQUALS(test.get_data(), 60);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 51);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 25);


        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 75);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 100);
    }

    void testRightLeftHeavyRightChild() {
        AVL_Tree<int> test;
        TS_ASSERT_EQUALS(test.insert(50), true);
        TS_ASSERT_EQUALS(test.insert(25), true);
        TS_ASSERT_EQUALS(test.insert(75), true);
        TS_ASSERT_EQUALS(test.insert(60), true);
        TS_ASSERT_EQUALS(test.insert(100), true);
        TS_ASSERT_EQUALS(test.insert(61), true);


        TS_ASSERT_EQUALS(test.get_data(), 60);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 25);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 75);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 100);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 61);
    }

    void testRightHeavy() {
        AVL_Tree<int> test;
        TS_ASSERT_EQUALS(test.insert(50), true);
        TS_ASSERT_EQUALS(test.insert(25), true);
        TS_ASSERT_EQUALS(test.insert(75), true);
        TS_ASSERT_EQUALS(test.insert(60), true);
        TS_ASSERT_EQUALS(test.insert(100), true);
        TS_ASSERT_EQUALS(test.insert(150), true);


        TS_ASSERT_EQUALS(test.get_data(), 75);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 25);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 60);


        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 100);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 150);
    }

    void testRebalnceLeftHeavyLeftChild() {
        AVL_Tree<int> test;
        TS_ASSERT_EQUALS(test.insert(50), true);
        TS_ASSERT_EQUALS(test.insert(25), true);
        TS_ASSERT_EQUALS(test.insert(75), true);
        TS_ASSERT_EQUALS(test.insert(30), true);
        TS_ASSERT_EQUALS(test.insert(24), true);
        TS_ASSERT_EQUALS(test.insert(26), true);

        TS_ASSERT_EQUALS(test.get_data(), 30);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 25);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 26);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 24);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 75);
    }

    void testRebalnceHeavyLeft() {
        AVL_Tree<int> test;
        TS_ASSERT_EQUALS(test.insert(50), true);
        TS_ASSERT_EQUALS(test.insert(25), true);
        TS_ASSERT_EQUALS(test.insert(75), true);
        TS_ASSERT_EQUALS(test.insert(30), true);
        TS_ASSERT_EQUALS(test.insert(24), true);
        TS_ASSERT_EQUALS(test.insert(1), true);


        TS_ASSERT_EQUALS(test.get_data(), 25);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 24);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 1);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 75);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 30);
    }

    void testRebalnceLeftHeavyRightChild() {
        AVL_Tree<int> test;
        TS_ASSERT_EQUALS(test.insert(50), true);
        TS_ASSERT_EQUALS(test.insert(30), true);
        TS_ASSERT_EQUALS(test.insert(75), true);
        TS_ASSERT_EQUALS(test.insert(33), true);
        TS_ASSERT_EQUALS(test.insert(24), true);
        TS_ASSERT_EQUALS(test.insert(25), true);


        TS_ASSERT_EQUALS(test.get_data(), 30);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 33);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 75);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 24);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 25);
    }

    void testRebalnceLeftHeavyRightChild2() {
        AVL_Tree<int> test;
        TS_ASSERT_EQUALS(test.insert(100), true);
        TS_ASSERT_EQUALS(test.insert(50), true);
        TS_ASSERT_EQUALS(test.insert(150), true);
        TS_ASSERT_EQUALS(test.insert(25), true);
        TS_ASSERT_EQUALS(test.insert(60), true);
        TS_ASSERT_EQUALS(test.insert(65), true);


        TS_ASSERT_EQUALS(test.get_data(), 60);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 100);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 65);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 150);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 25);
    }


    void testFox() {
        AVL_Tree<std::string> test;
        std::ostringstream out;

        test.insert("The");
        test.insert("quick");
        test.insert("brown");
        test.insert("fox");
        test.insert("jumps");
        test.insert("over");
        test.insert("the");
        test.insert("lazy");
        test.insert("dog");
        //pre_order_traversal(test, out, 0);


        TS_ASSERT_EQUALS(*test.find("The"), "The");
        TS_ASSERT_EQUALS(*test.find("quick"), "quick");
        TS_ASSERT_EQUALS(*test.find("brown"), "brown");
        TS_ASSERT_EQUALS(*test.find("fox"), "fox");
        TS_ASSERT_EQUALS(*test.find("jumps"), "jumps");
        TS_ASSERT_EQUALS(*test.find("over"), "over");
        TS_ASSERT_EQUALS(*test.find("the"), "the");
        TS_ASSERT_EQUALS(*test.find("lazy"), "lazy");
        TS_ASSERT_EQUALS(*test.find("dog"), "dog");


        TS_ASSERT_EQUALS(test.get_data(), "jumps");
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), "brown");
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), "The");

        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), "fox");
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_left_subtree().get_data(), "dog");


        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), "quick");

        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), "the");


        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), "over");
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_left_subtree().get_data(), "lazy");

        pre_order_traversal(test, out, 0);

        std::cout << out.str() << std::endl;

        std::cout << "test fox complete." << std::endl;


    }


    void testRemovebasicZero() {
        std::cout << "BEGINNING ERASE TESTS..." << std::endl;
        std::ostringstream out;
        std::cout << "Beginning erase_test 0..." << std::endl;
        AVL_Tree<int> test1;
        test1.insert(20);
        test1.erase(20);

        TS_ASSERT_EQUALS(test1.insert(45), true);
        TS_ASSERT_EQUALS(test1.erase(20), false);
        TS_ASSERT_EQUALS(test1.get_data(), 45);
        std::cout << test1.to_string() << std::endl;
    }

    void testRemovebasicOne() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 1..." << std::endl;
        AVL_Tree<int> test1;
        test1.insert(40);
        test1.insert(20);
        TS_ASSERT_EQUALS(test1.erase(20), true);
        TS_ASSERT_EQUALS(test1.erase(55), false);
        TS_ASSERT_EQUALS(test1.get_data(), 40);
        std::cout << test1.to_string() << std::endl;
    }

    void testRemovebasicTwo() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 2..." << std::endl;
        AVL_Tree<int> test;
        test.insert(40);
        test.insert(20);
        test.insert(60);

        TS_ASSERT_EQUALS(test.erase(55), false);

        TS_ASSERT_EQUALS(test.get_data(), 40);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 20);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 60);
        std::cout << test.to_string() << std::endl;
    }

    void testRightBasic1() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 3..." << std::endl;
        AVL_Tree<int> test;
        test.insert(40);
        test.insert(20);
        test.insert(60);
        test.insert(10);
        test.insert(90);

        TS_ASSERT_EQUALS(test.erase(60), true);

        TS_ASSERT_EQUALS(test.get_data(), 40);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 20);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 90);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 10);
        std::cout << test.to_string() << std::endl;
    }

    void testLeftBasic1() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 5..." << std::endl;
        AVL_Tree<int> test;
        test.insert(40);
        test.insert(20);
        test.insert(60);
        test.insert(10);
        test.insert(90);

        TS_ASSERT_EQUALS(test.erase(20), true);

        TS_ASSERT_EQUALS(test.get_data(), 40);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 10);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 60);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 90);
        std::cout << test.to_string() << std::endl;
    }

    void testLeftBasic2() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 6..." << std::endl;
        AVL_Tree<int> test;
        test.insert(40);
        test.insert(20);
        test.insert(60);
        test.insert(10);
        test.insert(50);

        TS_ASSERT_EQUALS(test.erase(20), true);

        TS_ASSERT_EQUALS(test.get_data(), 40);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 10);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 60);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 50);

        std::cout << test.to_string() << std::endl;
    }

    void testLeftBasic3() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 7..." << std::endl;
        AVL_Tree<int> test;
        test.insert(40);
        test.insert(60);
        test.insert(10);
        test.insert(90);

        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        pre_order_traversal(test, out, 0);
        cout << out.str() << endl;
        TS_ASSERT_EQUALS(test.erase(10), true);
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        pre_order_traversal(test, out, 0);
        cout << out.str() << endl;
        TS_ASSERT_EQUALS(test.get_data(), 60);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 40);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 90);
        std::cout << test.to_string() << std::endl;
    } //  case AVLNode<Item_Type>::RIGHT_HEAVY

    void testRightBasic2() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 6..." << std::endl;
        AVL_Tree<int> test;
        test.insert(40);
        test.insert(20);
        test.insert(60);
        test.insert(25);
        test.insert(100);

        TS_ASSERT_EQUALS(test.erase(60), true);

        TS_ASSERT_EQUALS(test.get_data(), 40);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 20);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 100);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 25);

        std::cout << test.to_string() << std::endl;
    }

    void testRightBasic3() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 7..." << std::endl;
        AVL_Tree<int> test;
        test.insert(40);
        test.insert(60);
        test.insert(10);
        test.insert(5);

        TS_ASSERT_EQUALS(test.erase(60), true);

        TS_ASSERT_EQUALS(test.get_data(), 10);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 5);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 40);
        std::cout << test.to_string() << std::endl;
    } // THESE TESTS ABOVE ARE ACTIVELY TRYING TO AVOID USING REPLACE_PARENT AS PART OF THE INCREMENTAL DEVELOPMENT PROCESS

    void testRebalanceRight1() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 9..." << std::endl;
        AVL_Tree<int> test;
        test.insert(40);
        test.insert(10);
        test.insert(46);
        test.insert(45);
        test.insert(60);


        TS_ASSERT_EQUALS(test.erase(10), true);

        TS_ASSERT_EQUALS(test.get_data(), 46);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 60);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 40);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 45);

        std::cout << test.to_string() << std::endl;
    } // THESE TESTS ABOVE ARE ACTIVELY TRYING TO AVOID USING REPLACE_PARENT AS PART OF THE INCREMENTAL DEVELOPMENT PROCESS


    void testRightHeavyLeftMiddleBranch() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 8..." << std::endl;
        AVL_Tree<int> test;
        test.insert(100);
        test.insert(50);
        test.insert(150);
        test.insert(25);
        test.insert(75);
        test.insert(125);
        test.insert(60);

        TS_ASSERT_EQUALS(test.erase(25), true);


        TS_ASSERT_EQUALS(test.get_data(), 100);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 60);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 150);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 75);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 150);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 125);

        std::cout << test.to_string() << std::endl;
    } // THESE TESTS ABOVE ARE ACTIVELY TRYING TO AVOID USING REPLACE_PARENT AS PART OF THE INCREMENTAL DEVELOPMENT PROCESS


    void testRight() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 8..." << std::endl;
        AVL_Tree<int> test;
        test.insert(100);
        test.insert(50);
        test.insert(150);
        test.insert(25);
        test.insert(75);
        test.insert(125);
        test.insert(60);


        TS_ASSERT_EQUALS(test.erase(25), true);


        TS_ASSERT_EQUALS(test.get_data(), 100);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 60);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 150);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 75);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 150);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 125);

        std::cout << test.to_string() << std::endl;
    } // THESE TESTS ABOVE ARE ACTIVELY TRYING TO AVOID USING REPLACE_PARENT AS PART OF THE INCREMENTAL DEVELOPMENT PROCESS

    void testRightHeavyLeftMiddleBranch2() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 8..." << std::endl;
        AVL_Tree<int> test;
        test.insert(100);
        test.insert(50);
        test.insert(150);
        test.insert(25);
        test.insert(75);
        test.insert(125);
        test.insert(90);


        TS_ASSERT_EQUALS(test.erase(25), true);


        TS_ASSERT_EQUALS(test.get_data(), 100);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 75);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 150);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 90);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 150);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 125);

        std::cout << test.to_string() << std::endl;
    } // THESE TESTS ABOVE ARE ACTIVELY TRYING TO AVOID USING REPLACE_PARENT AS PART OF THE INCREMENTAL DEVELOPMENT PROCESS

    void testRightHeavyLeftMiddleBranch3() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 8..." << std::endl;
        AVL_Tree<int> test;
        test.insert(100);
        test.insert(50);
        test.insert(150);
        test.insert(25);
        test.insert(75);
        test.insert(125);
        test.insert(90);
        test.insert(64);

        std::cout << test.to_string() << std::endl;
    } // THESE TESTS ABOVE ARE ACTIVELY TRYING TO AVOID USING REPLACE_PARENT AS PART OF THE INCREMENTAL DEVELOPMENT PROCESS

    void testRightHeavyLeftMiddleBranch4() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 8..." << std::endl;
        AVL_Tree<int> test;
        TS_ASSERT_EQUALS(test.insert(50), true);
        TS_ASSERT_EQUALS(test.insert(25), true);
        TS_ASSERT_EQUALS(test.insert(75), true);
        TS_ASSERT_EQUALS(test.insert(60), true);
        TS_ASSERT_EQUALS(test.insert(100), true);
        TS_ASSERT_EQUALS(test.insert(10), true);
        TS_ASSERT_EQUALS(test.insert(61), true);

        TS_ASSERT_EQUALS(test.erase(10), true);

        TS_ASSERT_EQUALS(test.get_data(), 60);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 25);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 75);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 61);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 100);


        std::cout << test.to_string() << std::endl;
    } // THESE TESTS ABOVE ARE ACTIVELY TRYING TO AVOID USING REPLACE_PARENT AS PART OF THE INCREMENTAL DEVELOPMENT PROCESS

    void testRightHeavyLeftMiddleBranch5() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 8..." << std::endl;
        AVL_Tree<int> test;
        TS_ASSERT_EQUALS(test.insert(50), true);
        TS_ASSERT_EQUALS(test.insert(25), true);
        TS_ASSERT_EQUALS(test.insert(75), true);
        TS_ASSERT_EQUALS(test.insert(12), true);
        TS_ASSERT_EQUALS(test.insert(60), true);
        TS_ASSERT_EQUALS(test.insert(100), true);
        TS_ASSERT_EQUALS(test.insert(51), true);

        TS_ASSERT_EQUALS(test.erase(12), true);

        TS_ASSERT_EQUALS(test.get_data(), 60);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 25);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 51);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 75);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 100);


        std::cout << test.to_string() << std::endl;
    } // THESE TESTS ABOVE ARE ACTIVELY TRYING TO AVOID USING REPLACE_PARENT AS PART OF THE INCREMENTAL DEVELOPMENT PROCESS

    void testleftHeavyBranch2() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 8..." << std::endl;
        AVL_Tree<int> test;
        test.insert(40);
        test.insert(60);
        test.insert(10);
        test.insert(5);
        test.insert(45);
        test.insert(90);
        test.insert(46);


        TS_ASSERT_EQUALS(test.erase(90), true);

        TS_ASSERT_EQUALS(test.get_data(), 40);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 10);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 5);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 46);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 45);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 60);

        std::cout << test.to_string() << std::endl;
    } // THESE TESTS ABOVE ARE ACTIVELY TRYING TO AVOID USING REPLACE_PARENT AS PART OF THE INCREMENTAL DEVELOPMENT PROCESS

    void testDeleteHeavyLeftChild1() {
        AVL_Tree<int> test;
        TS_ASSERT_EQUALS(test.insert(50), true);
        TS_ASSERT_EQUALS(test.insert(25), true);
        TS_ASSERT_EQUALS(test.insert(75), true);
        TS_ASSERT_EQUALS(test.insert(30), true);
        TS_ASSERT_EQUALS(test.insert(24), true);
        TS_ASSERT_EQUALS(test.insert(76), true);
        TS_ASSERT_EQUALS(test.insert(26), true);

        TS_ASSERT_EQUALS(test.erase(76), true);

        TS_ASSERT_EQUALS(test.get_data(), 30);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 25);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 26);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 24);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 75);
    }

    void testDeleteHeavyLeftChild2() {
        AVL_Tree<int> test;
        TS_ASSERT_EQUALS(test.insert(100), true);
        TS_ASSERT_EQUALS(test.insert(50), true);
        TS_ASSERT_EQUALS(test.insert(150), true);
        TS_ASSERT_EQUALS(test.insert(25), true);
        TS_ASSERT_EQUALS(test.insert(60), true);
        TS_ASSERT_EQUALS(test.insert(200), true);
        TS_ASSERT_EQUALS(test.insert(65), true);
        TS_ASSERT_EQUALS(test.erase(200), true);

        TS_ASSERT_EQUALS(test.get_data(), 60);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 100);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 65);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 150);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 25);
    }

    void testRebalanceLeftBalance() {
        std::ostringstream out;
        std::cout << "Beginning erase_test 9..." << std::endl;
        AVL_Tree<int> test;
        test.insert(50);
        test.insert(25);
        test.insert(100);
        test.insert(12);
        test.insert(26);


        TS_ASSERT_EQUALS(test.erase(100), true);

        TS_ASSERT_EQUALS(test.get_data(), 25);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 26);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 12);


        std::cout << test.to_string() << std::endl;
    } // THESE TESTS ABOVE ARE ACTIVELY TRYING TO AVOID USING REPLACE_PARENT AS PART OF THE INCREMENTAL DEVELOPMENT PROCESS

    // https://cs.stackexchange.com/questions/128245/worst-case-for-avl-tree-balancing-after-deletion
    void testFibbonacci() {
        std::ostringstream out;
        std::cout << "Beginning fibbonaci worst case scenario test" << std::endl;
        AVL_Tree<int> test;
        test.insert(13);

        test.insert(8);
        test.insert(18);

        test.insert(5);
        test.insert(11);
        test.insert(16);
        test.insert(20);

        test.insert(3);
        test.insert(7);
        test.insert(10);
        test.insert(12);
        test.insert(15);
        test.insert(17);
        test.insert(19);

        test.insert(2);
        test.insert(4);
        test.insert(6);
        test.insert(9);
        test.insert(14);

        test.insert(1);

        TS_ASSERT_EQUALS(test.erase(19), true);
        TS_ASSERT_EQUALS(test.find(19), nullptr);


        TS_ASSERT_EQUALS(test.get_data(), 8);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 5);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 3);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_right_subtree().get_data(), 4);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_left_subtree().get_data(), 2);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_left_subtree().get_left_subtree().get_data(), 1);


        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 7);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_left_subtree().get_data(), 6);



        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 13);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 11);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_left_subtree().get_data(), 10);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_left_subtree().get_left_subtree().get_data(), 9);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_right_subtree().get_data(), 12);



        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 16);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_left_subtree().get_data(), 15);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_left_subtree().get_left_subtree().get_data(), 14);



        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 16);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_left_subtree().get_data(), 15);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_left_subtree().get_left_subtree().get_data(), 14);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_right_subtree().get_data(), 18);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_right_subtree().get_left_subtree().get_data(), 17);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_right_subtree().get_right_subtree().get_data(), 20);




        std::cout << test.to_string() << std::endl; // THIS TEST IS EXPANDED UPON BY OTHER TESTS, JUST FOR CHECKING
    }

    void testFibbonacci2() {
        std::ostringstream out;
        std::cout << "Beginning fibbonaci worst case scenario test 2" << std::endl;
        AVL_Tree<int> test;
        test.insert(13);

        test.insert(8);
        test.insert(18);

        test.insert(5);
        test.insert(11);
        test.insert(16);
        test.insert(20);

        test.insert(3);
        test.insert(7);
        test.insert(10);
        test.insert(12);
        test.insert(15);
        test.insert(17);
        test.insert(19);

        test.insert(2);
        test.insert(4);
        test.insert(6);
        test.insert(9);
        test.insert(14);

        test.insert(1);

        // ostringstream out;
        pre_order_traversal(test, out, 0);
        TS_ASSERT_EQUALS(test.erase(13), true);

        TS_ASSERT_EQUALS(test.find(13), nullptr);

        TS_ASSERT_EQUALS(test.get_data(), 12);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 5);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 3);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_right_subtree().get_data(), 4);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_left_subtree().get_data(), 2);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_left_subtree().get_left_subtree().get_data(), 1);


        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_data(), 8);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_left_subtree().get_data(), 7);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_left_subtree().get_left_subtree().get_data(), 6);

        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_right_subtree().get_data(), 10);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_right_subtree().get_left_subtree().get_data(), 9);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_right_subtree().get_right_subtree().get_right_subtree().get_data(), 11);


        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 18);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_data(), 16);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_right_subtree().get_data(), 17);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_left_subtree().get_data(), 15);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_left_subtree().get_left_subtree().get_left_subtree().get_data(), 14);


        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_data(), 20);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_right_subtree().get_left_subtree().get_data(), 19);



        std::cout << test.to_string() << std::endl;
    }

    void testDeleteRoot() {
        std::ostringstream out;
        std::cout << "Delete root 1" << std::endl;
        AVL_Tree<int> test;
        test.insert(13);
        test.insert(5);
        test.insert(15);
        test.insert(20);

        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        pre_order_traversal(test, out, 0);
        cout << out.str() << endl;

        TS_ASSERT_EQUALS(test.erase(13), true);
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        pre_order_traversal(test, out, 0);
        cout << out.str() << endl;

        TS_ASSERT_EQUALS(test.find(13), nullptr);
//        TS_ASSERT_EQUALS(test.get_data(), 15);
//        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 5);
//        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 20);

        std::cout << test.to_string() << std::endl;
    }

    void testDeleteRoot2() {
        std::ostringstream out;
        std::cout << "Delete root 2" << std::endl;
        AVL_Tree<int> test;
        test.insert(13);
        test.insert(5);
        test.insert(15);
        test.insert(1);

        TS_ASSERT_EQUALS(test.erase(13), true);

        TS_ASSERT_EQUALS(test.find(13), nullptr);
        TS_ASSERT_EQUALS(test.get_data(), 5);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 1);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 15);

        std::cout << test.to_string() << std::endl;
    }

    void testDeleteRoot3() {
        std::ostringstream out;
        std::cout << "Delete root 3" << std::endl;
        AVL_Tree<int> test;
        test.insert(13);
        test.insert(5);
        test.insert(15);

        TS_ASSERT_EQUALS(test.erase(13), true);

        TS_ASSERT_EQUALS(test.find(13), nullptr);
        TS_ASSERT_EQUALS(test.get_data(), 5);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 15);

        std::cout << test.to_string() << std::endl;
    }

    void testDeleteRoot4() {
        std::ostringstream out;
        std::cout << "Delete root 4" << std::endl;
        AVL_Tree<int> test;
        test.insert(13);
        test.insert(5);
        test.insert(15);
        test.insert(1);

        TS_ASSERT_EQUALS(test.erase(13), true);

        TS_ASSERT_EQUALS(test.find(13), nullptr);
        TS_ASSERT_EQUALS(test.get_data(), 5);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 1);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 15);
        std::cout << test.to_string() << std::endl;
    }
    void testDeleteRoot5() {
        std::ostringstream out;
        std::cout << "Delete root 5" << std::endl;
        AVL_Tree<int> test;
        test.insert(100);
        test.insert(50);
        test.insert(150);
        test.insert((60));

        TS_ASSERT_EQUALS(test.erase(100), true);

        TS_ASSERT_EQUALS(test.find(100), nullptr);
        TS_ASSERT_EQUALS(test.get_data(), 60);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 150);
        std::cout << test.to_string() << std::endl;
    }

    void testDeleteRoot6() {
        std::ostringstream out;
        std::cout << "Delete root 6" << std::endl;
        AVL_Tree<int> test;
        test.insert(60);
        test.insert(50);
        test.insert(150);
        test.insert(25);
        test.insert(55);

        TS_ASSERT_EQUALS(test.erase(60), true);

        TS_ASSERT_EQUALS(test.find(60), nullptr);
        TS_ASSERT_EQUALS(test.get_data(), 55);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 50);
        TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 25);

        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 150);
        std::cout << test.to_string() << std::endl;
    }

    void testStressTest1() { // actively trying to use the program to break it.
        std::ostringstream out;
        std::cout << "Delete root 6" << std::endl;
        AVL_Tree<int> test;
        test.insert(60);
        test.insert(50);
        test.insert(150);
        test.insert(25);
        test.insert(55);
        test.insert(10);
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        pre_order_traversal(test, out, 0);
        cout << out.str() << endl;

        TS_ASSERT_EQUALS(test.erase(60), true);
        TS_ASSERT_EQUALS(test.find(60), nullptr);

        TS_ASSERT_EQUALS(test.erase(55), true);
        TS_ASSERT_EQUALS(test.find(55), nullptr);

        TS_ASSERT_EQUALS(test.erase(25), true);
        TS_ASSERT_EQUALS(test.find(25), nullptr);

        TS_ASSERT_EQUALS(test.insert(125), true);
        TS_ASSERT_EQUALS(test.insert(250), true);

        TS_ASSERT_EQUALS(test.erase(125), true);
        TS_ASSERT_EQUALS(test.find(125), nullptr);

        TS_ASSERT_EQUALS(test.erase(50), true);
        TS_ASSERT_EQUALS(test.find(50), nullptr);

        TS_ASSERT_EQUALS(test.insert(15), true);

        TS_ASSERT_EQUALS(test.erase(150), true);

        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        pre_order_traversal(test, out, 0);
        cout << out.str() << endl;

        TS_ASSERT_EQUALS(test.get_data(), 15);
//        TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 15);
//        TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 250);

        //TS_ASSERT_EQUALS(test.get_data(), 55);
        //TS_ASSERT_EQUALS(test.get_left_subtree().get_data(), 50);
        //TS_ASSERT_EQUALS(test.get_left_subtree().get_left_subtree().get_data(), 25);

        //TS_ASSERT_EQUALS(test.get_right_subtree().get_data(), 150);
        std::cout << test.to_string() << std::endl;
    }

};
#endif /* TESTAVL_H */

