//copyright 2025
#include <cxxtest/TestSuite.h>
#include <sstream>
#include <string>
#include "Red_Black_Tree.h"

using namespace std;

class RedBlackTreeTestSuite : public CxxTest::TestSuite {
public:

    void testInsertUniqueWords() {
        Red_Black_Tree<string> tree;
        TS_ASSERT(tree.insert("the"));
        TS_ASSERT(tree.insert("quick"));
        TS_ASSERT(tree.insert("brown"));
        TS_ASSERT(tree.insert("fox"));
        TS_ASSERT(tree.insert("jumps"));
        TS_ASSERT(tree.insert("over"));
        TS_ASSERT(tree.insert("lazy"));
        TS_ASSERT(tree.insert("dog"));
    }

    void testInsertDuplicates() {
        Red_Black_Tree<string> tree;
        TS_ASSERT(tree.insert("the"));
        TS_ASSERT(!tree.insert("the"));
    }

    void testFullPangramInsertion() {
        Red_Black_Tree<string> tree;
        string sentence = "the quick brown fox jumps over the lazy dog";
        istringstream iss(sentence);
        string word;
        int unique_count = 0;
        while (iss >> word) {
            if (tree.insert(word)) {
                unique_count++;
            }
        }
        TS_ASSERT_EQUALS(unique_count, 8);
    }

    void testStructureAfterInsertion() {
        Red_Black_Tree<string> tree;

        string words[] = {"the", "quick", "brown", "fox", "jumps",
                          "over", "lazy", "dog"};
        for (int i = 0; i < 8; i++) {
            tree.insert(words[i]);
        }
        TS_ASSERT_THROWS_NOTHING(tree.verify_structure());
    }

    void testDeleteExistingWord() {
        Red_Black_Tree<string> tree;
        tree.insert("the");
        tree.insert("quick");
        tree.insert("brown");
        TS_ASSERT(tree.erase("quick"));
        TS_ASSERT_THROWS_NOTHING(tree.verify_structure());
    }

    void testDeleteNonExistentWord() {
        Red_Black_Tree<string> tree;
        tree.insert("the");
        tree.insert("quick");
        TS_ASSERT(!tree.erase("elephant"));
    }

    void testMultipleDeletions() {
        Red_Black_Tree<string> tree;
        string words[] = {"the", "quick", "brown", "fox", "jumps",
                          "over", "lazy", "dog"};
        for (int i = 0; i < 8; i++) {
            tree.insert(words[i]);
        }

        TS_ASSERT(tree.erase("the"));
        TS_ASSERT_THROWS_NOTHING(tree.verify_structure());
        TS_ASSERT(tree.erase("fox"));
        TS_ASSERT_THROWS_NOTHING(tree.verify_structure());
        TS_ASSERT(tree.erase("dog"));
        TS_ASSERT_THROWS_NOTHING(tree.verify_structure());
    }

    void testDeleteAll() {
        Red_Black_Tree<string> tree;
        string words[] = {"the", "quick", "brown", "fox", "jumps",
                          "over", "lazy", "dog"};
        for (int i = 0; i < 8; i++) {
            tree.insert(words[i]);
        }
        for (int i = 0; i < 8; i++) {
            TS_ASSERT(tree.erase(words[i]));
        }
        TS_ASSERT_THROWS_NOTHING(tree.verify_structure());
    }

    void testInsertAfterDelete() {
        Red_Black_Tree<string> tree;
        tree.insert("the");
        tree.insert("quick");
        tree.insert("brown");

        TS_ASSERT(tree.erase("quick"));
        TS_ASSERT(tree.insert("quick"));
        TS_ASSERT_THROWS_NOTHING(tree.verify_structure());
    }

    void testEmptyTreeOperations() {
        Red_Black_Tree<string> tree;
        TS_ASSERT_THROWS_NOTHING(tree.verify_structure());
        TS_ASSERT(!tree.erase("anything"));
    }

    void testStressTest() {
        Red_Black_Tree<string> tree;
        string sentence = "the quick brown fox jumps over the lazy dog";
        for (int i = 0; i < 10; i++) {
            istringstream iss(sentence);
            string word;
            while (iss >> word) {
                tree.insert(word);
            }
        }

        TS_ASSERT_THROWS_NOTHING(tree.verify_structure());
        string words[] = {"the", "quick", "brown", "fox", "jumps",
                          "over", "lazy", "dog"};
        for (int i = 0; i < 8; i++) {
            tree.erase(words[i]);
        }
        TS_ASSERT_THROWS_NOTHING(tree.verify_structure());
    }

    void testEdgeCases() {
        Red_Black_Tree<int> tree;
        tree.insert(10);
        tree.insert(30);
        tree.insert(20);
        TS_ASSERT_THROWS_NOTHING(tree.verify_structure());
        Red_Black_Tree<int> tree2;
        tree2.insert(30);
        tree2.insert(10);
        tree2.insert(20);
        TS_ASSERT_THROWS_NOTHING(tree2.verify_structure());
        tree2.insert(5);
        TS_ASSERT_THROWS_NOTHING(tree2.verify_structure());
        Red_Black_Tree<int> tree3;
        tree3.insert(20);
        tree3.insert(10);
        tree3.insert(30);
        tree3.insert(5);
        tree3.insert(25);

        tree3.erase(5);
        TS_ASSERT_THROWS_NOTHING(tree3.verify_structure());
    }

};
