#include <fstream>
#include <iostream>

/**
 * Keybindings
 *
 * main controls
 * l - list items in list
 * a - add new item to the list
 * c - complete/check off item in the list
 * d - delete item in the list
 *
 * misc. keybindings
 * h - help (print the keybindings)
 * q - quit TODO CLI
 */

int main() {
  std::cout << "Welcome to TODO CLI" << std::endl;
  std::cout << "Your command line to-do list :)" << std::endl;

  while (true) {
    char input;
    std::cin >> input;

    switch (input) {
      case 'l':
        std::cout << "l - list items in list" << std::endl;
        break;

      case 'a': 
        std::cout << "a - add new item to the list" << std::endl; 
        break; 
      
      case 'c': 
        std::cout << "c - complete/check off item in the list" << std::endl;
        break; 

      case 'd': 
        std::cout << "d - delete item in the list" << std::endl; 
        break;

      case 'h': 
        std::cout << "h - help (print the keybindings)" << std::endl; 
        break; 

      case 'q': 
        std::cout << "q - quit TODO CLI" << std::endl; 
        break; 

      default:
        std::cout << "Try again. You can type 'h' for help" << std::endl;
        break;
    }

    std::cin.clear(); 
    std::cin.ignore(INT_MAX, '\n'); 
  }

  return 0;
}
