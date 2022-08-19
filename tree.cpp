// Tyler Taormina 
// taormina@pdx.edu
// August 2022
// Program 4

#include "tree.h"

// Default constuctor
Tree::Tree(): root(nullptr){}


// Deconstructor
Tree::~Tree()
{
  remove_all();
}


// @Dev - wrapper function to insert a node into the tree. 
// Args -> takes an Item object passed by reference. 
// Returns -> integer success.
int Tree::insert(Item & item)
{
  return insert(item, root);
}


// @Dev - recursive call to a node into the tree. 
// Args -> takes an Item object passed by reference and private member root node as an argument. 
// Returns -> integer success.
int Tree::insert(Item & item, node *& root)
{
  if (!root)
  {
    root = new node;
    root->item.copy_item(item);
    return 1;
  }
  if (root->item.compare(item) >= 0)
  {
    cout << "right node entered" << endl;
    return insert(item, root->right);
  }
  else 
  {
    cout << "left node entered" << endl;
    return insert(item, root->left);
  }
}


// @Dev - wrapper function to display all nodes in sorted order. Calls recursive function. 
// Args -> none 
// Returns -> total number of items stored in the binary tree.
int Tree::display_sorted()
{
  return display_sorted(root);
}


// @Dev - recursive call to display all nodes in sorted order. 
// Args -> takes private member root node as an argument. 
// Returns -> total number of items stored in the binary tree.
int Tree::display_sorted(node * root)
{
  if (!root)
    return 0;
  
  int count = 0;
  count = display_sorted(root->left);
  cout << "displaying node" << endl;
  root->item.display();
  count++;
  count += display_sorted(root->right);
  return count;
}


// @Dev - wrapper function to display all nodes with a matching name. Calls recursive function
// Args -> character array to match 
// Returns -> number of nodes matched
int Tree::display_name_match(char * name_to_match)
{
  return display_name_match(name_to_match, root);
}


// @Dev - recursive call to display all nodes with a name matching the argument 
// Args -> character array to match and private member root node 
// Returns -> number of nodes matched
int Tree::display_name_match(char * name_to_match, node * root)
{
  if (!root)
    return 0;
  int count = 0;
  count = display_name_match(name_to_match, root->left);
  if (root->item.is_match(name_to_match))
  {
    count++;
    root->item.display();
  }
  count += display_name_match(name_to_match, root->right);
  return count;
}


// @Dev - wrapper function to recursive function to display all nodes with a type matching the argument 
// Args -> character array to match 
// Returns -> number of nodes matched
int Tree::display_type_match(char * type_to_match)
{
  return display_type_match(type_to_match, root);
}


// @Dev - recursive function to display all nodes with a type matching the argument 
// Args -> character array to match and private member root node 
// Returns -> number of nodes matched
int Tree::display_type_match(char * type_to_match, node * root)
{
  if (!root)
    return 0;
  int count = 0;
  count = display_type_match(type_to_match, root->left);
  count += display_type_match(type_to_match, root->right);
  if (root->item.is_type_match(type_to_match))
  {
    count++;
    root->item.display();
  }
  return count;
}


// @Dev - wrapper function to retrieve all items with a name matching the argument passed
// Args -> character array with a name to match and an Item array to fill with matches
// Returns -> number of nodes matched
// UNFINISHED: don't hard code the size into the array. Use a proper constant
int Tree::retrieve_match(char * name_to_match, Item items[100])
{
  return retrieve_match(name_to_match, items, root);
}


// @Dev - recursive function to retrieve all items with a name matching the argument passed
// Args -> character array with a name to match, Item array to fill with matches, and node
//         root
// Returns -> number of nodes matched
int Tree::retrieve_match(char * name_to_match, Item items[100], node * root)
{
  if (!root)
    return 0;
  int count = 0;
  count = retrieve_match(name_to_match, items, root->left);
  count += retrieve_match(name_to_match, items, root->right);
  Item found;
  int check = root->item.retrieve_match(name_to_match, found); 
  if (check)
  {
    cout << "Index = " << count << endl;
    items[count].copy_item(found);
    count ++;
  }
  return count;
}


// @Dev - wrapper function to remove all nodes with a name that matches the argument
// Args -> character array of a name to match  
// Returns -> number of nodes with matching names removed
int Tree::remove(char * name_to_remove)
{
  if (!root)
  {
    cout << "empty tree" << endl;
    return 0;
  }
  return remove(name_to_remove, root);
}


// @Dev - recursive function to remove all nodes with a name that matches the argument
// Args -> character array of a name to match and private member root node
// Returns -> number of nodes with matching names removed
int Tree::remove(char* name_to_remove, node*& root)
{
  if (!root)
    return 0;
  int count = 0;
  count = remove(name_to_remove, root->left);
  count += remove(name_to_remove, root->right);
  if (root->item.is_match(name_to_remove))
  {
    //no children
    if (!root->left  && !root->right){ 
      cout << "find node - no children" << endl;
      delete root;
      root = nullptr;
      count++;
    }
    //one child left
    else if (root->left && !root->right) {
      cout << "find node - left child" << endl;
      node * temp = root->left;
      delete root;
      root = temp;
      count++;
    }
    //one child right
    else if (!root->left && root->right) {
      cout << "find node - right child" << endl;
      node * temp = root->right;
      delete root;
      root = temp;
      count++;
    }
    //two children (find in order successor)
    else {
      cout << "find node - two children" << endl;
      node* current = root->right;
      if (!current->left)
      {
        root->item.copy_item(current->item);
        node* hold = current->right;
        delete current;
        current = nullptr;
        root->right = hold;
        count++;
      } else 
      {
        node* parent = current;
        while (current->left)
        {
          parent = current;
          current = current->left;
        }
        root->item.copy_item(current->item);
        node * hold = current->right;
        parent->left = hold;
        delete current;
        current = nullptr;
        count++;
      }
    }
  }
  return count;
}


// @Dev - wrapper function to remove all nodes in the tree
// Args -> none 
// Returns -> number of nodes removed
int Tree::remove_all()
{
  return remove_all(root);
}


// @Dev - recursive call to remove all nodes in tree 
// Args -> takes private member root node as an argument 
// Returns -> total number of items deleted from the binary tree
int Tree::remove_all(node * & root)
{
  if (!root)
    return 0;
  int count = remove_all(root->left);
  count += remove_all(root->right);
  delete root;
  root = nullptr;
  count++;
  return count;
}


