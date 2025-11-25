#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "BST_With_Rotate.h"
#include "Bad_Structure.h"
#include "AVLNode.h"

/** Definition of the AVL Binary Search Tree class.
    @param Item_Type The type of item to be stored in the tree
    Note: Item_Type must define the less-than operator as a
    total ordering.
*/
template < typename Item_Type >
class AVL_Tree: public BST_With_Rotate < Item_Type > {

public:
    // Constructor
    /** Construct an empty AVL_Tree */
    AVL_Tree() : BST_With_Rotate<Item_Type>() {}

    // Public Member Functions
    /** Insert an item into the tree by calling overridden insert function.
        post: The item is in the tree.
        @param item The item to be inserted
        @return true only if the item was not already in the tree
    */
    virtual bool insert(const Item_Type& item) {
        return insert(this->root, item); }

    bool verify_structure() {
        verify_structure(this->root, 0);
        return true;
    }

    virtual bool erase(const Item_Type& item) {
        return erase(this->root, item); }

private:

    // Private member functions declarations
    /** Insert an item into the tree. Called by starter function (see
        listing 11.2) with this->root as first argument.
        post: The item is in the tree.
        @param local_root A reference to the current root
        @param item The item to be inserted
        @return true only if the item was not already in the
    */

    virtual bool insert(BTNode<Item_Type>*&, const Item_Type&);

    void rebalance_left(BTNode<Item_Type>*& local_root);

    /** Correct a critical left balance condition
        pre:  local_root is the root of an AVL subtree that is
        critically heavy.
        post: balance is restored
        @param local_root is the root of the AVL subtree
        that needs rebalancing
    */


    void rebalance_right(BTNode<Item_Type>*& local_root);

    /** Correct a critical right balance condition
        pre:  local_root is the root of an AVL subtree that is
        critically heavy.
        post: balance is restored
        @param local_root is the root of the AVL subtree
        that needs rebalancing
    */


    virtual bool erase(BTNode<Item_Type>*& local_root,
                       const Item_Type& item);

    /** Find a replacement for a node that is being deleted
        This function finds the right-most local root that
        does not have a right child. The data in this local_root
        replaces the data in old_root. The pointer to local_root
        is then saved in old_root and local_root is replaced
        by its left child.
        @param old_root Reference to the pointer to old parent
        @param local_root Reference to the pointer to local root
    */
    virtual void replace_parent(BTNode<Item_Type>*& old_root,
                                BTNode<Item_Type>*& local_root);


    /** Correct a critical left balance condition due to erase
        pre:  local_root is the root of an AVL subtree that is
        critically heavy.
        post: balance is restored
        @param local_root is the root of the AVL subtree
        that needs rebalancing
    */
    void erase_rebalance_left(BTNode<Item_Type>*& local_root);

    /** Correct a critical right balance condition due to erase
        pre:  local_root is the root of an AVL subtree that is
        critically heavy.
        post: balance is restored
        @param local_root is the root of the AVL subtree
        that needs rebalancing
    */
    void erase_rebalance_right(BTNode<Item_Type>*& local_root);

    // Data Fields
    /** A flag to indicate that the height of the tree has increased */
    bool increase;

    int verify_structure(BTNode<Item_Type>* local_root,
                         BTNode<Item_Type>* parent);
};

template<typename Item_Type>
bool AVL_Tree<Item_Type>::insert(BTNode<Item_Type> *&local_root,
                                 const Item_Type &item) {
    if (local_root == nullptr) {
        local_root = new AVLNode<Item_Type>(item);
        increase = true;
        return true;
    }

    if (item < local_root->data) {
        bool return_value = insert(local_root->left, item);
        if (increase) {
            AVLNode<Item_Type>* AVL_local_root =
                    dynamic_cast<AVLNode<Item_Type>*>(local_root);
            switch (AVL_local_root->balance) {
                case AVLNode<Item_Type>::BALANCED :
                    AVL_local_root->balance = AVLNode<Item_Type>::LEFT_HEAVY;
                    break;
                case AVLNode<Item_Type>::RIGHT_HEAVY :
                    AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
                    increase = false;
                    break;
                case AVLNode<Item_Type>::LEFT_HEAVY :
                    rebalance_left(local_root);
                    increase = false;
                    break;
            }
        }
        return return_value;
    } else if (local_root->data < item) {
        bool return_value = insert(local_root->right, item);
        if (increase) {
            AVLNode<Item_Type>* AVL_local_root =
                    dynamic_cast<AVLNode<Item_Type>*>(local_root);
            switch (AVL_local_root->balance) {
                case AVLNode<Item_Type>::BALANCED :
                    AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
                    break;
                case AVLNode<Item_Type>::LEFT_HEAVY :
                    AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
                    increase = false;
                    break;
                case AVLNode<Item_Type>::RIGHT_HEAVY :
                    rebalance_right(local_root);
                    increase = false;
                    break;
            }
        }
        return return_value;
    } else {
        increase = false;
        return false;
    }
}

template<typename Item_Type>
void AVL_Tree<Item_Type>::rebalance_left(BTNode<Item_Type>*& local_root)
{
    AVLNode<Item_Type>* AVL_local_root =
            dynamic_cast<AVLNode<Item_Type>*>(local_root);
    AVLNode<Item_Type>* left_child =
            dynamic_cast<AVLNode<Item_Type>*>(local_root->left);
    if (left_child->balance == AVLNode<Item_Type>::RIGHT_HEAVY) {
        AVLNode<Item_Type>* left_right_child =
                dynamic_cast<AVLNode<Item_Type>*>(left_child->right);
        if (left_right_child->balance == AVLNode<Item_Type>::LEFT_HEAVY) {
            left_child->balance = AVLNode<Item_Type>::BALANCED;
            left_right_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
        } else if (left_right_child->balance
                   == AVLNode<Item_Type>::BALANCED) {
            left_child->balance = AVLNode<Item_Type>::BALANCED;
            left_right_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        } else {
            left_child->balance = AVLNode<Item_Type>::LEFT_HEAVY;
            left_right_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        }
        this->rotate_left(local_root->left);
    } else {
        left_child->balance = AVLNode<Item_Type>::BALANCED;
        AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
    }
    this->rotate_right(local_root);
}


template<typename Item_Type>
void AVL_Tree<Item_Type>::rebalance_right(BTNode<Item_Type>*& local_root)
{
    AVLNode<Item_Type>* AVL_local_root = dynamic_cast<AVLNode<Item_Type>*>(local_root);
    AVLNode<Item_Type>* right_child = dynamic_cast<AVLNode<Item_Type>*>(local_root->right);
    if (right_child->balance == AVLNode<Item_Type>::LEFT_HEAVY) {
        AVLNode<Item_Type>* right_left_child = dynamic_cast<AVLNode<Item_Type>*>(right_child->left);
        if (right_left_child->balance == AVLNode<Item_Type>::RIGHT_HEAVY) {
            right_child->balance = AVLNode<Item_Type>::BALANCED;
            right_left_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::LEFT_HEAVY;
        } else if (right_left_child->balance == AVLNode<Item_Type>::BALANCED) {
            right_child->balance = AVLNode<Item_Type>::BALANCED;
            right_left_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        } else {
            right_child->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
            right_left_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        }
        this->rotate_right(local_root->right);
    } else {
        right_child->balance = AVLNode<Item_Type>::BALANCED;
        AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
    }
    this->rotate_left(local_root);
}

template<typename Item_Type>
bool AVL_Tree<Item_Type>::erase(BTNode<Item_Type> *&local_root,
                                const Item_Type &item) {
    if (local_root == NULL) {
        return false;
    }
    if (item < local_root->data) {
        bool return_value = erase(local_root->left, item);
        if (increase) {
            erase_rebalance_right(local_root);
        }
        return return_value;
    } else if (local_root->data < item) {
        bool return_value = erase(local_root->right, item);
        if (increase) {
            erase_rebalance_left(local_root);
        }
        return return_value;
    } else {
        BTNode<Item_Type> *old_root = local_root;
        if (local_root->left == NULL) {
            local_root = local_root->right;
            increase = true;
        } else if (local_root->right == NULL) {
            local_root = local_root->left;
            increase = true;
        } else {
            replace_parent(old_root, old_root->left);
            if (increase) {
                erase_rebalance_right(local_root);
            }
        }
        delete old_root;
        return true;
    }
}

template<typename Item_Type>
void AVL_Tree<Item_Type>::replace_parent(BTNode<Item_Type> *&old_root,
                                         BTNode<Item_Type> *&local_root) {
    if (local_root->right != NULL) {
        replace_parent(old_root, local_root->right);
        if (increase) {
            erase_rebalance_left(local_root);
        }
    } else {
        old_root->data = local_root->data;
        old_root = local_root;
        local_root = local_root->left;
        increase = true;
    }
}

template<typename Item_Type>
void AVL_Tree<Item_Type>::erase_rebalance_left(BTNode<Item_Type> *&local_root) {
    AVLNode<Item_Type> *AVL_local_root = dynamic_cast<AVLNode<Item_Type> *>(local_root);
    if (AVL_local_root->balance == AVLNode<Item_Type>::RIGHT_HEAVY) {
        AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        return;
    }
    if (AVL_local_root->balance == AVLNode<Item_Type>::BALANCED) {
        AVL_local_root->balance = AVLNode<Item_Type>::LEFT_HEAVY;
        increase = false;
        return;
    }
    AVLNode<Item_Type> *left_child = dynamic_cast<AVLNode<Item_Type> *>(local_root->left);
    if (left_child->balance == AVLNode<Item_Type>::LEFT_HEAVY) {
        AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        left_child->balance = AVLNode<Item_Type>::BALANCED;
        this->rotate_right(local_root);
    }
    else if (left_child->balance == AVLNode<Item_Type>::BALANCED) {
        AVL_local_root->balance = AVLNode<Item_Type>::LEFT_HEAVY;
        left_child->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
        this->rotate_right(local_root);
        increase = false;
    }
    else {
        AVLNode<Item_Type> *left_right_child = dynamic_cast<AVLNode<Item_Type> *>(left_child->right);
        if (left_right_child->balance == AVLNode<Item_Type>::LEFT_HEAVY) {
            AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
            left_child->balance = AVLNode<Item_Type>::BALANCED;
            left_right_child->balance = AVLNode<Item_Type>::BALANCED;
        } else if (left_right_child->balance == AVLNode<Item_Type>::BALANCED) {
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
            left_child->balance = AVLNode<Item_Type>::BALANCED;
            left_right_child->balance = AVLNode<Item_Type>::BALANCED;
        } else {
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
            left_child->balance = AVLNode<Item_Type>::LEFT_HEAVY;
            left_right_child->balance = AVLNode<Item_Type>::BALANCED;
        }

        this->rotate_left(local_root->left);
        this->rotate_right(local_root);
    }
}

template<typename Item_Type>
void AVL_Tree<Item_Type>::erase_rebalance_right(BTNode<Item_Type> *&local_root) {
    AVLNode<Item_Type> *AVL_local_root = dynamic_cast<AVLNode<Item_Type> *>(local_root);
    if (AVL_local_root->balance == AVLNode<Item_Type>::LEFT_HEAVY) {
        AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        return;
    }
    if (AVL_local_root->balance == AVLNode<Item_Type>::BALANCED) {
        AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
        increase = false;
        return;
    }
    AVLNode<Item_Type> *right_child = dynamic_cast<AVLNode<Item_Type> *>(local_root->right);

    if (right_child->balance == AVLNode<Item_Type>::RIGHT_HEAVY) {
        AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        right_child->balance = AVLNode<Item_Type>::BALANCED;
        this->rotate_left(local_root);
    }
    else if (right_child->balance == AVLNode<Item_Type>::BALANCED) {
        AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
        right_child->balance = AVLNode<Item_Type>::LEFT_HEAVY;
        this->rotate_left(local_root);
        increase = false;
    }
    else {
        AVLNode<Item_Type> *right_left_child = dynamic_cast<AVLNode<Item_Type> *>(right_child->left);

        if (right_left_child->balance == AVLNode<Item_Type>::RIGHT_HEAVY) {
            AVL_local_root->balance = AVLNode<Item_Type>::LEFT_HEAVY;
            right_child->balance = AVLNode<Item_Type>::BALANCED;
            right_left_child->balance = AVLNode<Item_Type>::BALANCED;
        } else if (right_left_child->balance == AVLNode<Item_Type>::BALANCED) {
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
            right_child->balance = AVLNode<Item_Type>::BALANCED;
            right_left_child->balance = AVLNode<Item_Type>::BALANCED;
        } else {
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
            right_child->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
            right_left_child->balance = AVLNode<Item_Type>::BALANCED;
        }

        this->rotate_right(local_root->right);
        this->rotate_left(local_root);
    }
}

template<typename Item_Type>
int AVL_Tree<Item_Type>::verify_structure(BTNode<Item_Type>* local_root,
                                          BTNode<Item_Type>* parent) {
    if (local_root == 0) return 0;
    AVLNode<Item_Type>* avl_root =
            dynamic_cast<AVLNode<Item_Type>* >(local_root);
    if (avl_root == 0) {
        throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                       "Node not AVLNode");
    }
    if (avl_root->left == 0 && avl_root->right == 0) {
        if (avl_root->balance != AVLNode<Item_Type>::BALANCED) {
            throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                           "Leaf node not balanced");
        }
        return 1;
    } else {
        int left_height = verify_structure(avl_root->left, local_root);
        int right_height = verify_structure(avl_root->right, local_root);
        int delta = right_height - left_height;
        if (delta < -1) {
            throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                           "Balance < -1");
        }
        if (delta > 1) {
            throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                           "Balance > +1");
        }
        switch (delta) {
            case -1:
                if (avl_root->balance != AVLNode<Item_Type>::LEFT_HEAVY) {
                    throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                                   "Balance value not correct, should be -1");
                }
                break;
            case 0:
                if (avl_root->balance != AVLNode<Item_Type>::BALANCED) {
                    throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                                   "Balance value not correct, should be 0");
                }
                break;
            case +1:
                if (avl_root->balance != AVLNode<Item_Type>::RIGHT_HEAVY) {
                    throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                                   "Balance value not correct, should be +1");
                }
                break;
        }
        if (avl_root->left != 0) {
            if (avl_root->left->data >= avl_root->data) {
                throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                               "Left child >= parent");
            }
        }
        if (avl_root->right != 0) {
            if (avl_root->right->data <= avl_root->data) {
                throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                               "Right child <= parent");
            }
        }
        return (left_height > right_height ? left_height : right_height) + 1;
    }
}

#endif