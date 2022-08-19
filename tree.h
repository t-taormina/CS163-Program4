// Tyler Taormina 
// taormina@pdx.edu
// August 2022
// Program 4

#include "item.h"

// Tree Class
// - The tree class consists of binary search tree that is made up of nodes that contain
// a data field for a data type (Item object from this project), a left node, and a right
// node. All methods in this class make use of recursion through a wrapper function and
// a recursive function.   



struct node 
{
  Item item;
  node * left;
  node * right;
  
  // Constructor to establish nullptrs with each new instance. 
  node()
  {
    item = Item();
    left = nullptr;
    right = nullptr;
  }
};


class Tree
{
  public: 
    // Constructor sets root member to a null pointer.
    Tree();

    // Deconstructor calls remove all recursive function and leaves root node as a null
    // pointer.
    ~Tree();

    // Compares the name for the item calling and item passed as an argument. Returns the
    // result from strcmp. A returned result of 0 indicates a match. 
    int compare(Item& item);

    // Inserts an item into the binary tree. Returns an integer for success. Tree
    // insertion goes to the right if name is greater than or equal to, and left if the
    // name is less than. 
    int insert(Item& item);

    // Displays the entire BST in sorted order and returns the total number of nodes in
    // the binary tree. 
    int display_sorted();

    // Displays only the items in the tree that have a matching name to the character
    // passed as an argument. Returns the number of matches. 
    int display_name_match(char* name_to_match);

    // Displays only the items in the tree that have a matching type to the character
    // passed as an argument. Returns the number of matches.
    int display_type_match(char* type_to_match);

    // Fills the array passed as an argument with all items that match the character array
    // passed as an argument. Only compares the character array with name field of each
    // item in the binary search tree. 
    int retrieve_match(char* name_to_match, Item* items);
    
    // Removes all items that have a name that matches the character array passed as an
    // argument. Returns the number of matches found and removed. 
    int remove(char* name_to_remove);

    // Removes all nodes the BST. Returns the number of nodes removed. 
    int remove_all();


  private:
    node * root;

    // Recursive functions for all wrapper functions above.
    int insert(Item& item, node*& root);
    int display_sorted(node* root);
    int display_name_match(char* name_to_match, node* root);
    int display_type_match(char* type_to_match, node* root);
    int retrieve_match(char* name_to_match, Item* items, node* root);
    int remove(char* name_to_remove, node*& root);
    int remove_all(node*& root);
};

