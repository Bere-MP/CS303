#include "function.h"

// This function finds the index using the number provided by the user
int findIndex(vector<int> &dataSet, int num) {
  int vSize = dataSet.size();
  // Goes through the entire vector to find the number and returns the index
  for (int i = 0; i < vSize; ++i) {
    if (dataSet[i] == num) {
      return i;
    }
  }
  return -1;
}

// This function goes to the index provided and modifys the value
int modifyValue(vector<int> &dataSet, int index, int newNum) {
  try {
    int vSize = dataSet.size();
    // Replaces the number
    if (index >= 0 && index < vSize) {
      int oldValue = dataSet[index];
      dataSet[index] = newNum;
      return oldValue;
    } else {
      throw out_of_range("Error: Index is out of range.");
    }
  }
  // Catches any other errors that were not specified
  catch (const exception &error) {
    cerr << "Error: " << error.what() << endl << endl;
  }
}

// This function add a number to the vector
void addInteger(vector<int> &dataSet, int num) {
  try {
    dataSet.push_back(num);
  } 
  // Catches any other errors that were not specified
  catch (const exception &error) {
    cerr << "Error: " << error.what() << endl << endl;
  }
}

// This function removes the integer using the index the user provided
void Remove(vector<int> &dataSet, int index) {
  int vSize = dataSet.size();
  if (index >= 0 && index < vSize) {
    dataSet.erase(dataSet.begin() + index);
  }
}

