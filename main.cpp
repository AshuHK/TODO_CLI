#include <fstream>
#include <iostream>
#include <string>

/**
 * Prints out all of the items in the to-do list file
 * @param show_nums - a boolean on to show number indicators for the output
 *
 * @return - None
 */
void list_items(bool show_nums) {
  std::ifstream file("todo.md");
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

  file.close();
}

/**
 * Adds a new item onto the to-do list file
 * @param file - a reference to a file stream for the to-do list file
 */
void add_item() {}

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
          list_items(false);
          break;

        case 'A':
        case 'a':
          add_item();
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
