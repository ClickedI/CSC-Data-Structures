//copyright 2025
#ifndef BST_WITH_ROTATE_H_
#define BST_WITH_ROTATE_H_
#include "Binary_Search_Tree.h"

/** This class extends the Binary_Search_Tree by adding the rotate
    operations. Rotate will change the balance of a search
    tree while preserving the search tree property.
    Used as a common base class for self-adjusting trees.
*/
template<typename Item_Type>
class BST_With_Rotate : public Binary_Search_Tree<Item_Type> {
protected:
    /** rotate_right
       @param local_root The root of the binary tree to be rotated
    */
    void rotate_right(BTNode<Item_Type>*& local_root) {
        BTNode<Item_Type>* temp = local_root->left;
        local_root->left = temp->right;
        temp->right = local_root;
        local_root = temp;
    }

    /** Insert rotate_left here
     @param local_root The root of the binary tree to be rotated
    */
    void rotate_left(BTNode<Item_Type>*& local_root) {
        BTNode<Item_Type>* temp = local_root->right;
        local_root->right = temp->left;
        temp->left = local_root;
        local_root = temp;
    }
};

#endif
