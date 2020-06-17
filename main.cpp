#include <exception>
#include <fstream>
#include <iostream>
#include <string>

/**
 * Prints out all of the items in the to-do list file and returns the number
 * of items in the to-do list
 * @param show_nums - a boolean on to show number indicators for the output
 *
 * @return - the number of items in the to-do list file
 */
int list_items(bool show_nums) {
  std::ifstream file("todo.md");
  int num = 0;

  if (file.is_open()) {
    std::string line;

    while (std::getline(file, line)) {
      num++;
      if (show_nums) {
        std::cout << num << " " << line << std::endl;
      } else {
        std::cout << line << std::endl;
      }
    }
  } else {
    std::cout << "File Not Found" << std::endl;
  }

  file.close();
  return num;
}

/**
 * Appends a new item to the end of the to-do list file
 * @param None
 *
 * @return - None
 */
void add_item() {
  std::ofstream file("todo.md", std::ios::app);

  if (file.is_open()) {
    std::cout << "New task: ";

    std::string new_item;
    std::getline(std::cin, new_item);

    file << "- [ ] " << new_item << "\n";
  } else {
    std::cout << "File Not Found" << std::endl;
  }

  file.close();
}

/**
 */
void complete_item(const int& item_count) {
  if (item_count == 0) {
    std::cout << "Your to-do list is empty." << std::endl;
    return;
  }

  while (true) {
    std::cout << "Complete task: ";
    std::string input;
    std::getline(std::cin, input);

    int choice;
    try {
      choice = std::stoi(input);
    } catch (std::exception& e) {
      choice = -1;
    }

    if ((1 <= choice) && (choice <= item_count)) {
      break;
    } else {
      std::cout << "Invalid choice. Try again." << std::endl;
      return;
    }
  }

  std::cout << "you made it to the end" << std::endl;
}

/**
 * Prints all of the keybindings to the console
 * @param None
 *
 * @return - None
 */
void cout_help() {
  std::string keybindings = R"(
Keybindings:
  - Main Controls
    - l - list items in list
    - a - add new item to the list
    - c - complete/check off item in the list
    - d - delete item in the list

  - Misc.
    - h - help (print the keybindings)
    - q - quit TODO CLI
  )";
  std::cout << keybindings << std::endl;
}

int main() {
  std::string intro = R"(
 _________  ________  ________  ________          ________  ___       ___
|\___   ___\\   __  \|\   ___ \|\   __  \        |\   ____\|\  \     |\  \
\|___ \  \_\ \  \|\  \ \  \_|\ \ \  \|\  \       \ \  \___|\ \  \    \ \  \
     \ \  \ \ \  \\\  \ \  \ \\ \ \  \\\  \       \ \  \    \ \  \    \ \  \
      \ \  \ \ \  \\\  \ \  \_\\ \ \  \\\  \       \ \  \____\ \  \____\ \  \
       \ \__\ \ \_______\ \_______\ \_______\       \ \_______\ \_______\ \__\
        \|__|  \|_______|\|_______|\|_______|        \|_______|\|_______|\|__|
  )";
  std::cout << intro << std::endl;

  while (true) {
    std::cout << ">> ";
    std::string input;
    std::getline(std::cin, input);

    int item_count;
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
          item_count = list_items(true);
          complete_item(item_count);
          break;

        case 'D':
        case 'd':
          std::cout << "d - delete item in the list" << std::endl;
          break;

        case 'H':
        case 'h':
          cout_help();
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
