
/**
Name: Berenice Moreno-Perez
Due Date: September 11, 2023
**/

#include "function.h"

int main() {
  string fileName;
  vector<int> data;
  int num, searchNum, modifyIndex, newNum, removeIndex, size;

  string option;

  // Ask user for file name
  cout << "What is the name of the file: ";
  cin >> fileName;
  cout << endl << endl;

  // Send error if file not found
  ifstream inFile(fileName);
  if (!inFile.is_open()) {
    cerr << "Failed to open file." << endl;
    return 1;
  }

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      inFile >> num;
      data.push_back(num);
    }
  }

  inFile.close();

  // Ask the user what they would like to do with the data sets
  cout << "What would you like to do?: " << endl;
  cout << "(A) Search" << endl
       << "(B) Modify" << endl
       << "(C) Add" << endl
       << "(D) Remove" << endl
       << "(E) Exit" << endl;

  cout << "Reponse: ";
  cin >> option;
  cout << endl << endl;

  // While user's option is not exit, continue with the program
  while (option != "E") {
    // If option equals A, search for the index using the user input
    if (option == "A" or option == "a") {
      cout << "What number would you like to check?: ";
      cin >> searchNum;
      // End program if input is not int
      if (cin.fail()) {
        cout << "That's not an integer" << endl;
        break;
      }

      else {
        cout << endl << endl;
        int searchResult = findIndex(data, searchNum);
        if (searchResult != -1)
          cout << "Number " << searchNum << " found at index " << searchResult
               << endl
               << endl;

        else
          cout << "Number " << searchNum << " not found in the array." << endl
               << endl;
      }

    }

    // If option equals B, modify the number using user input
    else if (option == "B" or option == "b") {
      cout << "What is the index number for the integer you would like to "
              "modify?: ";
      cin >> modifyIndex;
      
      // End program if input is not int
      if (cin.fail()) {
        cout << "That's not an integer" << endl;
        break;
      }

      else {
        cout << endl << endl;
        cout << "What integer would you like to change it to?: ";
        cin >> newNum;
        cout << endl << endl;
        // End program if input is not int
        if (cin.fail()) {
          cout << "That's not an integer" << endl;
          break;
        }

        else {
          int oldValue = modifyValue(data, modifyIndex, newNum);

          if (oldValue != -1) {
            cout << "Value at index " << modifyIndex
                 << " has been modified. Old value: " << oldValue
                 << ", New value: " << newNum << endl
                 << endl;
          } else {
            cout << "Invalid index for modification." << endl;
          }
        }
      }
    }

    // If option equals C, add the number using user input
    else if (option == "C" or option == "c") {
      cout << "What number would you like to add?: ";
      cin >> newNum;
      cout << endl << endl;

      // End program if input is not int
      if (cin.fail()) {
        cout << "That's not an integer" << endl;
        break;
      }

      else {
        addInteger(data, newNum);
      }
    }

    // If option equals D, remove number using user input
    else if (option == "D" or option == "d") {
      cout << "What is the index number of the integer you would like to "
              "remove?: ";
      cin >> removeIndex;
      cout << endl << endl;
      // End program if input is not int
      if (cin.fail()) {
        cout << "That's not an integer" << endl;
        break;
      }

      Remove(data, removeIndex);
    }

    // If option is not A, B, C, D, or E, return error message
    else {
      cout << "Invalid Response" << endl << endl;

      cout << "What would you like to do?: " << endl;
      cout << "(A) Search" << endl
           << "(B) Modify" << endl
           << "(C) Add" << endl
           << "(D) Remove" << endl
           << "(E) Exit" << endl;

      cout << "Reponse: ";
      cin >> option;
      cout << endl << endl;
    }

    // Return updated vector
    cout << "Updated vector:" << endl;
    size = data.size();
    for (int i = 0; i < size; ++i) {
      cout << data[i] << " ";
      if ((i + 1) % 10 == 0) {
        cout << endl;
      }
    }

    cout << endl << endl;

    cout << "What would you like to do?: " << endl;
    cout << "(A) Search" << endl
         << "(B) Modify" << endl
         << "(C) Add" << endl
         << "(D) Remove" << endl
         << "(E) Exit" << endl;

    cout << "Reponse: ";
    cin >> option;
    cout << endl << endl;

    // If option equals E, break while loop
    if (option == "E" or option == "e") {
      break;
    } else {
      continue;
    }
  }

  return 0;
}
