#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::cout << "Welcome to TODO CLI" << std::endl;
  std::cout << "Your command line to-do list :)" << std::endl;

  while (true) {
    std::cout << ">> ";
    std::string input;
    std::getline(std::cin, input);

    if (!input.empty()) {
      // switch is based on the first char in the input
      switch (input[0]) {
        case 'L':
        case 'l':
          std::cout << "l - list items in list" << std::endl;
          break;

        case 'A':
        case 'a':
          std::cout << "a - add new item to the list" << std::endl;
          break;

        case 'C':
        case 'c':
          std::cout << "c - complete/check off item in the list" << std::endl;
          break;

        case 'D':
        case 'd':
          std::cout << "d - delete item in the list" << std::endl;
          break;

        case 'H':
        case 'h':
          std::cout << "h - help (print the keybindings)" << std::endl;
          break;

        case 'Q':
        case 'q':
          std::cout << "q - quit TODO CLI" << std::endl;
          return 0;

        default:
          std::cout << "Try again. You can type 'h' for help" << std::endl;
          break;
      }

    } else {
      std::cout << "Try again. You can type 'h' for help" << std::endl;
    }

    input.clear();
  }

  return 0;
}
