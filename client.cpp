// Tyler Taormina 
// taormina@pdx.edu
// August 2022
// Program 4

#include "client.h"


// Program runner.
int run() {
  Tree tree;

  int flag = 1;
  
  while(flag > 0)
    {
      displayMenu();
      int menu_choice = validate_menu_choice();
      processChoice(flag, menu_choice, tree);
    }
  return 0;
}

// Displays the menu of functions for the user to choose from.
// Returns-> the integer value for the menu choice 
int displayMenu() {
    std::cout << "==================================================================\n";
    std::cout << "                         MENU" << std::endl;
    std::cout << "==================================================================\n";

    std::cout << "===============================\n";
    std::cout << "1) Display sorted tree\n"; //working
    std::cout << "2) Display match by name\n"; //working
    std::cout << "3) Display match by type\n";//working
    std::cout << "4) Retrieve match by name\n";//working
    std::cout << "5) Remove by name\n";//working
    std::cout << "6) Remove all nodes\n";//working
    std::cout << "7) Add a collectable\n";//working
    std::cout << std::endl;
    std::cout << "0) Exit Program\n";
    std::cout << "Enter: ";
    return 0;
}


// Provides option processing for the menu 
void processChoice (int& flag, int menu_choice, Tree & tree)
{
  // Takes in user input for menu choice and calls the appropriate function.
  int no = 0;
  int proceed = 1;
  switch(menu_choice)
    {
      // Display sorted tree. 
      case 1: 
        {
          int count = tree.display_sorted();
          cout << "Number of nodes in list: " << count << endl;
          break;
        }

      // Display match by name
      case 2:
        {
          char * name = new char[SIZE];
          cout << "Please enter a name to match: ";
          get_input(name);
          int count = tree.display_name_match(name);
          cout << "Number of matching items: " << count << endl;
          delete [] name;
          break;         
        }

      // Display type matches.
      case 3: 
        {
          char * type = new char[SIZE];
          cout << "Please enter a name to match: ";
          get_input(type);
          int count = tree.display_type_match(type);
          cout << "Number of matching type items: " << count << endl;
          delete [] type;

          break;
        }

      // Retrieve match by name.
      case 4: 
        {
          Item items[100];
          char * name = new char[SIZE];
          cout << "Please enter a name to retrieve all matches for: ";
          get_input(name);
          int count = tree.retrieve_match(name, items);
          cout << "Number of matching items: " << count << endl;
          
          for (int i = 0; i < count; i++)
            (*(items + i)).display();
          delete [] name;
          break;
        }

      // Remove all nodes in the tree.
      case 5: 
        {
          Item items[100];
          char * name = new char[SIZE];
          cout << "Please enter a name to remove all matches for: ";
          get_input(name);
          int count = tree.remove(name);
          cout << "Number of items removed: " << count << endl;
          break;
        }

      case 6:
        { 
          int count = tree.remove_all();
          cout << "Number of nodes removed: " << count << endl;
          break;
        }

      // Add an item to the table.
      case 7:
        {
          Item item;
          char * key = new char[SIZE];
          make_item(key, item);
          tree.insert(item);
          delete [] key;
          break;
        }

      // Exit
      case 0:
        {
          std::cout << "Are you sure you want to exit?" << std::endl;
          proceed = no;
          break;
        }

      // Prevent undesired outputs from having an effect.
      default:
          break;
    }

    if (proceed == no)
    {
      std::cout << "Enter 0 to end program.\n" << std::endl;
      std::cout << "Enter any other number to continue program.\n" << std::endl;
      std::cin >> flag;
      std::cin.ignore(SIZE, '\n');
    }
}


// Returns-> Integer value for the menu choice
int validate_menu_choice()
{
  int menu_choice_int = 0;
  cin >> menu_choice_int;
  std::cin.ignore(SIZE, '\n');
 
  while (menu_choice_int > 7 || menu_choice_int < 0) {
    cout << "Please select a valid menu item." << endl;
    cin >> menu_choice_int;
  }
  return menu_choice_int;
}


// Create an item using user input.
int make_item(char* & key, Item & item) {
  char * name = new char[SIZE];
  char * type = new char[SIZE];
  char * description = new char[SIZE];
  int year;
  int worth;
  int checker;

  cout << "Please enter the name of the item to add to the list: ";
  checker = get_input(name);

  cout << "Please enter the type of the item: ";
  checker = get_input(type);

  cout << "Please enter the year the item was made: ";
  std::cin >> year;
  std::cin.ignore(SIZE, '\n');

  cout << "Please enter a description of the item: ";
  checker = get_input(description);

  cout << "Please enter the worth of the item: ";
  std::cin >> worth;
  std::cin.ignore(SIZE, '\n');

  item.set_item(name, type, year, description, worth);
  strcpy(key,name);
  delete [] name;
  delete [] type;
  delete [] description;
  return checker;
}


// Gets user input from console and stores in character array.
int get_input(char* & value)
{
  std::cin.get(value, SIZE, '\n');
  std::cin.ignore(SIZE, '\n');
  return 1;
}

