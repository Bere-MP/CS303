
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

  cout << "What is the name of the file: ";
  cin >> fileName;
  cout << endl << endl;

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

  cout << "What would you like to do?: " << endl;
  cout << "(A) Search" << endl
       << "(B) Modify" << endl
       << "(C) Add" << endl
       << "(D) Remove" << endl
       << "(E) Exit" << endl;

  cout << "Reponse: ";
  cin >> option;
  cout << endl << endl;

  while (option != "E") {
    if (option == "A" or option == "a") {
      cout << "What number would you like to check?: ";
      cin >> searchNum;

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

    else if (option == "B" or option == "b") {
      cout << "What is the index number for the integer you would like to "
              "modify?: ";
      cin >> modifyIndex;

      if (cin.fail()) {
        cout << "That's not an integer" << endl;
        break;
      }

      else {
        cout << endl << endl;
        cout << "What integer would you like to change it to?: ";
        cin >> newNum;
        cout << endl << endl;
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

    else if (option == "C" or option == "c") {
      cout << "What number would you like to add?: ";
      cin >> newNum;
      cout << endl << endl;

      if (cin.fail()) {
        cout << "That's not an integer" << endl;
        break;
      }

      else {
        addInteger(data, newNum);
      }
    }

    else if (option == "D" or option == "d") {
      cout << "What is the index number of the integer you would like to "
              "remove?: ";
      cin >> removeIndex;
      cout << endl << endl;
      if (cin.fail()) {
        cout << "That's not an integer" << endl;
        break;
      }

      Remove(data, removeIndex);
    }

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

    cout << "Updated Array:" << endl;
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

    if (option == "E" or option == "e") {
      break;
    } else {
      continue;
    }
  }

  return 0;
}
