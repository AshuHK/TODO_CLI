#include <fstream>
#include <iostream>
#include <string>

void list_items(std::fstream& file, bool show_nums) {
  
  int num = 1; 
  if (file.is_open()) {
    std::string line;

    while (std::getline(file, line)) {
      if (show_nums) {
        std::cout << num << " " << line << std::endl; 
      } else {
        std::cout << line << std::endl;
      }
      num++; 
    }
  } else {
    std::cout << "File Not Found" << std::endl;
  }
}

int main() {
  std::cout << "Welcome to TODO CLI" << std::endl;
  std::cout << "Your command line to-do list :)" << std::endl;
  std::fstream file("todo.md");

  while (true) {
    std::cout << ">> ";
    std::string input;
    std::getline(std::cin, input);

    if (!input.empty()) {
      // switch is based on the first char in the input
      switch (input[0]) {
        case 'L':
        case 'l':
          list_items(file, false);
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

  file.close();
  return 0;
}
