#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 * Prints out all of the items in the to-do list file and returns the number
 * of items in the to-do list
 * @param show_nums - a boolean on to show number indicators for the output
 *
 * @return - the number of items in the to-do list file
 */
int list_items(bool show_nums) {
  std::ifstream file(".todo.user");
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
    std::cout << "File not Found" << std::endl;
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
  std::ofstream file(".todo.user", std::ios::app);

  if (file.is_open()) {
    std::cout << "New item: ";

    std::string new_item;
    std::getline(std::cin, new_item);

    file << "- [ ] " << new_item << "\n";
  } else {
    std::cout << "File not Found" << std::endl;
  }

  file.close();
}

/**
 * Updates the file for checking off an item in the to-do list
 * @param choice - a constant reference to an int of the user's choice of
 *                 which item should be checked off on the list
 *
 * @return - None
 */
void ci_update_file(const int& choice) {
  std::ifstream infile(".todo.user");
  if (infile.is_open()) {
    std::string line;
    std::vector<std::string> lines;

    while (std::getline(infile, line)) {
      lines.push_back(line);
    }
    infile.close();

    if (lines[choice - 1][3] == ' ') {
      lines[choice - 1][3] = 'x';
    } else if (lines[choice - 1][3] == 'x') {
      lines[choice - 1][3] = ' ';
    }

    std::ofstream outfile(".todo.user");
    for (const std::string& item : lines) {
      outfile << item << "\n";
    }
    outfile.close();

  } else {
    std::cout << "File not found." << std::endl;
  }
}

/**
 * Takes input for which item in the list should be checked off.
 * For any file manipulation, see ci_update_file
 *
 * @param item_count - a constant reference to an int for the number of items
 *                     in the to-do list file
 *
 * @return - None
 */
void check_item(const int& item_count) {
  if (item_count == 0) {
    std::cout << "Your to-do list is empty." << std::endl;
    return;
  }

  int choice;
  while (true) {
    std::cout << "Check item: ";
    std::string input;
    std::getline(std::cin, input);

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

  ci_update_file(choice);
}

/**
 * Updates the file for deleting a file in the to-do list file
 * @param choice - a constant reference to an int for the user's choice
 *
 * @return - None
 */
void delete_update_file(const int& choice) {
  std::ifstream infile(".todo.user");

  if (infile.is_open()) {
    std::string line;
    std::vector<std::string> lines;

    while (std::getline(infile, line)) {
      lines.push_back(line);
    }
    infile.close();

    lines.erase(lines.begin() + (choice - 1));

    std::ofstream outfile(".todo.user");
    for (const std::string& item : lines) {
      outfile << item << "\n";
    }
    outfile.close();

  } else {
    std::cout << "File not found." << std::endl;
  }
}

/**
 * Takes the input from the user on which item in the to-do list file to
 * delete.
 * For any file manipulation, see delete_update_file
 * @param item_count - a constant reference to an int for the number of items
 *                     in the to-do list file
 *
 * @return - None
 */
void delete_item(const int& item_count) {
  if (item_count == 0) {
    std::cout << "Your to-do list is empty." << std::endl;
    return;
  }

  int choice;
  while (true) {
    std::cout << "Delete item: ";
    std::string input;
    std::getline(std::cin, input);

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

  delete_update_file(choice);
}

/**
 * Take input on what the new name for the item should be and updates the
 * to-do list file
 * @param choice - a constant reference to an int for the user's choice
 *
 * @return None
 */
void rename_update_file(const int& choice) {
  std::ifstream infile(".todo.user");

  if (infile.is_open()) {
    std::string line;
    std::vector<std::string> lines;

    while (std::getline(infile, line)) {
      lines.push_back(line);
    }
    infile.close();

    std::string part1 = "- [ ] ";
    std::string part2;
    std::cout << "Rename item to: ";
    std::getline(std::cin, part2);

    std::string renamed = part1 + part2;

    lines[choice - 1] = renamed;

    std::ofstream outfile(".todo.user");
    for (const std::string& item : lines) {
      outfile << item << "\n";
    }
    outfile.close();

  } else {
    std::cout << "File not found" << std::endl;
  }
}

/**
 * Take input for which item in the list should be renamed.
 * For any file manipulation, see rename_update_file
 *
 * @param item_count - a constant reference to an int for the number of items
 *                     in the to-do list file
 *
 * @return None
 */
void rename_item(const int& item_count) {
  if (item_count == 0) {
    std::cout << "Your to-do list is empty." << std::endl;
    return;
  }

  int choice;
  while (true) {
    std::cout << "Rename item: ";
    std::string input;
    std::getline(std::cin, input);

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

  rename_update_file(choice);
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
    - l - show your to do list
    - a - append new item to the list
    - c - toggle checkmark on an item in the list
    - d - delete item in the list
    - r - rename item in the list

  - Misc.
    - h - help
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
          check_item(item_count);
          break;

        case 'D':
        case 'd':
          item_count = list_items(true);
          delete_item(item_count);
          break;

        case 'R':
        case 'r':
          item_count = list_items(true);
          rename_item(item_count);
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
