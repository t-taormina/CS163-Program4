// Tyler Taormina 
// taormina@pdx.edu
// August 2022
// Program 4


struct node 
{
  Item item;
  node * left;
  node * right;
};

class tree
{
  public: 
    table();
    ~table();

    int insert(Item & item);
    int display_sorted();
    int display_name_match(char * name_to_match);
    int display_type_match(char * type_to_match);
    int retrieve_match(char * name_to_match, Item & found);
    int remove(char * name_to_remove);
    int remove_all();


  private:
    node * root;

    // Recursive functions
    int insert(Item & item, node * root);
    int display_sorted(node * root);
    int display_name_match(char * name_to_match, node * root);
    int display_type_match(char * type_to_match, node * root);
    int retrieve_match(char * name_to_match, Item & found, node * root);
    int remove(char * name_to_remove, node * root);
    int remove_all(node * & root);

};

