//copyright 2025
#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdexcept>
#include "BST_With_Rotate.h"
#include "RBNode.h"
#include "Bad_Structure.h"

/** Definition of the Red-Black Tree class 
 @param Item_Type the type of item to be stored in the tree
 Note: Item_Type must define the less than operator as a 
 total order.
 */
template <typename Item_Type>
class Red_Black_Tree : public BST_With_Rotate<Item_Type> {
public:
    // Constructor

    /** Construct an empty Red_Black_Tree */
    Red_Black_Tree() : BST_With_Rotate<Item_Type>() {
    }

    // Public Member Functions
    /** Insert an item into the tree 
        @param item The item to be inserted
        @return true if the item was not already
        in the tree, false otherwise.
        post: The item is in the tree.
     */
    virtual bool insert(const Item_Type& item);

    /** Remove an item from the tree 
        @param item The item to be removed
        @return true if the item was in the tree,
        false otherwise.
        Post: The item is no longer in the tree.
     */
    virtual bool erase(const Item_Type& item);

    bool verify_structure() {
        verify_structure(this->root, 0);
        return true;
    }

private:

    // Private member functions

    /** Insert an item into a the tree 
        @param local_root A reference to the current root
        @param item The item to be inserted
        @return true if the item was not already in the
        tree, false otherwise
        post: The item is in the tree.
     */
    bool insert(BTNode<Item_Type>*& local_root,
                const Item_Type& item);

    /** Function to make the two children of the a sub-tree
        black and the localRoot red.
        @param RB_local_root The root of the sub-tree
        cast to a RBNode<Item_Type>*
     */
    void move_black_down(BTNode<Item_Type>* RB_local_root);

    /** Determine whether a node is red.
        @param node A pointer to a BTNode<Item_Type>
        @return true if node points to a RBNode<Item_Type> that is red
     */
    static bool is_red(BTNode<Item_Type>* node);

    /** Set the color of a node.
        @param node A pointer to a BTNode<Item_Type>
        @param red A bool value that is true if the
               node is to be set red, false if to be set black
     */
    static void set_red(BTNode<Item_Type>* node, bool red);

    /** Recursive erase from method.  
        Removes the given item from the Red-Black tree.  
        Note that the item must implement the less-than operator.
        Pre: The values of local_root is not NULL
        @post The object is removed from the tree
        @param local_root - Root of the subtree
        @param item - The item to be removed
        @return true if the item is removed
        false if the item is not in the tree 
     */
    bool erase(BTNode<Item_Type>*& local_root, const Item_Type& item);

    /** Function to find a replacement for a node that is being
        deleted from a Red-Black tree.  If the node has a NULL
        child, then the replacement is the other child.  If neither
        are NULL, then the replacement is the largest value less
        than the item being removed.
        @pre  node is not NULL
        @post a node replaced by its replacement 
        @param node The node to be deleted or replaced
     */
    void find_replacement(BTNode<Item_Type>*& node);

    /** Find the node such that parent->right->right == NULL
        @post The found node is removed from the tree and replaced
        by its left child (if any)
        @param parent - The possible parent
        @return the value of the found node
     */
    Item_Type find_largest_child(BTNode<Item_Type>* parent);

    /** Method to restore black balance to a subtree whose right black
        height is currently one less than the left black height.
        @param local_root - The root of the tree needing fixing
     */
    void fixup_right(BTNode<Item_Type>*& local_root);

    /** Method to restore black balance to a subtree whose left black
        height is currently one less than the right black height.
        @param local_root - The root of the tree needing fixing
     */
    void fixup_left(BTNode<Item_Type>*& local_root);


    // Data Fields
    /** A boolean variable to indicate that the black height
        was reduced by a call to the recursive erase function
        or one of its subfunctions. 
     */
    bool fixup_required;

    /** Verify the strucure of the Red-Black tree
        @throws BadStructure if the structure is invalid
        @param local_root The local root
        @param parent The parent of the local root
        @return The black height of the tree
    */
    int verify_structure(BTNode<Item_Type>* local_root,
                         BTNode<Item_Type>* parent);

}; // Red-Black tree

// Implementation of member functions

template<typename Item_Type>
bool Red_Black_Tree<Item_Type>::insert(const Item_Type& item) {
    if (this->root == NULL) {
        this->root = new RBNode<Item_Type>(item);
        set_red(this->root, false);
        return true;
    } else {
        bool result = insert(this->root, item);
        set_red(this->root, false);
        return result;
    }
}

template<typename Item_Type>
bool Red_Black_Tree<Item_Type>::insert(BTNode<Item_Type>*& local_root,
                                       const Item_Type& item) {
    if (local_root == NULL) {
        local_root = new RBNode<Item_Type>(item);
        return true;
    }

    if (item == local_root->data) {
        return false;
    }

    bool result;
    if (item < local_root->data) {
        result = insert(local_root->left, item);
    } else {
        result = insert(local_root->right, item);
    }

    if (result) {
        if (is_red(local_root->left) && is_red(local_root->right)) {
            move_black_down(local_root);
        }

        // check red-red
        if (is_red(local_root->left)) {
            if (is_red(local_root->left->left)) {
                // left-left
                set_red(local_root->left, false);
                set_red(local_root, true);
                this->rotate_right(local_root);
            } else if (is_red(local_root->left->right)) {
                // left-right
                set_red(local_root->left->right, false);
                set_red(local_root, true);
                this->rotate_left(local_root->left);
                this->rotate_right(local_root);
            }
        } else if (is_red(local_root->right)) {
            if (is_red(local_root->right->right)) {
                // right-right
                set_red(local_root->right, false);
                set_red(local_root, true);
                this->rotate_left(local_root);
            } else if (is_red(local_root->right->left)) {
                // right-left
                set_red(local_root->right->left, false);
                set_red(local_root, true);
                this->rotate_right(local_root->right);
                this->rotate_left(local_root);
            }
        }
    }

    return result;
}

template<typename Item_Type>
void Red_Black_Tree<Item_Type>::move_black_down(BTNode<Item_Type>* RB_local_root) {
    set_red(RB_local_root->left, false);
    set_red(RB_local_root->right, false);
    set_red(RB_local_root, true);
}

template<typename Item_Type>
bool Red_Black_Tree<Item_Type>::is_red(BTNode<Item_Type>* node) {
    if (node == NULL) {
        return false;
    }
    RBNode<Item_Type>* rb_node = dynamic_cast<RBNode<Item_Type>*>(node);
    if (rb_node == NULL) {
        return false;
    }
    return rb_node->is_red;
}

template<typename Item_Type>
void Red_Black_Tree<Item_Type>::set_red(BTNode<Item_Type>* node, bool red) {
    if (node == NULL) {
        return;
    }
    RBNode<Item_Type>* rb_node = dynamic_cast<RBNode<Item_Type>*>(node);
    if (rb_node != NULL) {
        rb_node->is_red = red;
    }
}

template<typename Item_Type>
bool Red_Black_Tree<Item_Type>::erase(const Item_Type& item) {
    if (this->root == NULL) {
        return false;
    }

    fixup_required = false;
    bool result = erase(this->root, item);
    if (this->root != NULL) {
        set_red(this->root, false);
    }
    return result;
}

template<typename Item_Type>
bool Red_Black_Tree<Item_Type>::erase(BTNode<Item_Type>*& local_root,
                                      const Item_Type& item) {
    if (local_root == NULL) {
        fixup_required = false;
        return false;
    }

    bool result;
    if (item < local_root->data) {
        result = erase(local_root->left, item);
        if (fixup_required) {
            fixup_left(local_root);
        }
    } else if (item > local_root->data) {
        result = erase(local_root->right, item);
        if (fixup_required) {
            fixup_right(local_root);
        }
    } else {
        result = true;
        if (local_root->left == NULL || local_root->right == NULL) {
            BTNode<Item_Type>* old_root = local_root;

            if (local_root->left == NULL) {
                local_root = local_root->right;
            } else {
                local_root = local_root->left;
            }

            if (!is_red(old_root)) {
                if (is_red(local_root)) {
                    set_red(local_root, false);
                    fixup_required = false;
                } else {
                    fixup_required = true;
                }
            } else {
                fixup_required = false;
            }

            delete old_root;
        } else {
            find_replacement(local_root);
            if (fixup_required) {
                fixup_left(local_root);
            }
        }
    }

    return result;
}

template<typename Item_Type>
void Red_Black_Tree<Item_Type>::find_replacement(BTNode<Item_Type>*& node) {
    if (node->left->right == NULL) {
        BTNode<Item_Type>* old_left = node->left;
        node->data = old_left->data;
        node->left = old_left->left;

        if (!is_red(old_left)) {
            if (is_red(node->left)) {
                set_red(node->left, false);
                fixup_required = false;
            } else {
                fixup_required = true;
            }
        } else {
            fixup_required = false;
        }

        delete old_left;
    } else {
        node->data = find_largest_child(node->left);
    }
}

template<typename Item_Type>
Item_Type Red_Black_Tree<Item_Type>::find_largest_child(BTNode<Item_Type>* parent) {
    if (parent->right->right == NULL) {
        BTNode<Item_Type>* old_right = parent->right;
        Item_Type return_value = old_right->data;
        parent->right = old_right->left;

        if (!is_red(old_right)) {
            if (is_red(parent->right)) {
                set_red(parent->right, false);
                fixup_required = false;
            } else {
                fixup_required = true;
            }
        } else {
            fixup_required = false;
        }

        delete old_right;
        return return_value;
    } else {
        Item_Type return_value = find_largest_child(parent->right);
        if (fixup_required) {
            fixup_right(parent);
        }
        return return_value;
    }
}

template<typename Item_Type>
void Red_Black_Tree<Item_Type>::fixup_right(BTNode<Item_Type>*& local_root) {
    BTNode<Item_Type>* sibling = local_root->left;
    if (is_red(sibling)) {
        set_red(local_root, true);
        set_red(sibling, false);
        this->rotate_right(local_root);
        fixup_right(local_root->right);
        return;
    }

    bool inner_nephew_red = is_red(sibling->right);
    bool outer_nephew_red = is_red(sibling->left);

    if (!inner_nephew_red && !outer_nephew_red) {
        set_red(sibling, true);
        if (is_red(local_root)) {
            set_red(local_root, false);
            fixup_required = false;
        } else {
            fixup_required = true;
        }
    }
    else {
        if (!outer_nephew_red) {
            set_red(sibling->right, false);
            set_red(sibling, true);
            this->rotate_left(local_root->left);
            sibling = local_root->left;
        }

        set_red(sibling, is_red(local_root));
        set_red(local_root, false);
        set_red(sibling->left, false);
        this->rotate_right(local_root);
        fixup_required = false;
    }
}

template<typename Item_Type>
void Red_Black_Tree<Item_Type>::fixup_left(BTNode<Item_Type>*& local_root) {
    BTNode<Item_Type>* sibling = local_root->right;


    if (is_red(sibling)) {
        set_red(local_root, true);
        set_red(sibling, false);
        this->rotate_left(local_root);
        fixup_left(local_root->left);
        return;
    }

    bool inner_nephew_red = is_red(sibling->left);
    bool outer_nephew_red = is_red(sibling->right);

    if (!inner_nephew_red && !outer_nephew_red) {
        set_red(sibling, true);
        if (is_red(local_root)) {
            set_red(local_root, false);
            fixup_required = false;
        } else {
            fixup_required = true;
        }
    }
    else {
        if (!outer_nephew_red) {
            set_red(sibling->left, false);
            set_red(sibling, true);
            this->rotate_right(local_root->right);
            sibling = local_root->right;
        }

        set_red(sibling, is_red(local_root));
        set_red(local_root, false);
        set_red(sibling->right, false);
        this->rotate_left(local_root);
        fixup_required = false;
    }
}

template<typename Item_Type>
int Red_Black_Tree<Item_Type>::verify_structure(BTNode<Item_Type>* local_root,
                                                BTNode<Item_Type>* parent)
{
    if (local_root == 0) return 0;
    RBNode<Item_Type>* rb_node = dynamic_cast<RBNode<Item_Type>*>(local_root);
    if (rb_node == 0) {
        throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                       "Node is not a RBNode");
    }
    if (rb_node->is_red) {
        if (parent == 0) {
            throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                           "Root is red");
        }
        RBNode<Item_Type>* rb_parent =
                dynamic_cast<RBNode<Item_Type>*>(parent);
        if (rb_parent == 0) {
            throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                           "Parent is not a RB Node");
        }
        if (rb_parent->is_red) {
            throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                           "Red child of a red parent");
        }
    }
    int lbh = verify_structure(rb_node->left, rb_node);
    int rbh = verify_structure(rb_node->right, rb_node);
    if (lbh != rbh) {
        throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                       "Unequal black heights");
    }
    if (rb_node->is_red) {
        return lbh;
    } else {
        return lbh + 1;
    }
}

#endif
