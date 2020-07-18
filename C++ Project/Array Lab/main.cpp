//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);

#include <iostream>

using namespace std;

const int ARR_CAP = 10;

int main() {
    // 1. Declare an array of doubles of size 10.
    double arr[10];
    int size = 10;
    // 2. Fill the array with 10 doubles entered by the user.
    cout << "Enter 10 values:" << endl;
    for(int i = 0 ; i < 10; i++){
      double s;
      cin >> s;
      arr[i] = s;
    }
    cout << endl;

    // 3. Call the mean function passing it this array and output the
    // value returned.
    cout << "Mean: " << mean(arr,size) << endl;
    cout << endl;

    // 4. Ask the user for the index (0 to 9) of the value they want to remove.
    cout << "Enter index of value to be removed: ";
    int s;
    cin >> s;
    cout << endl;

    // 5. Call the display function to output the array.
    cout << "Before removing value: ";
    display(arr, size);
    cout << endl;

    // 6. Call the remove function to remove the value at the index
    // provided by the user.
    remove(arr, size, s);


    // 7. Call the display function again to output the array
    // with the value removed.
    cout << "After removing value: ";
    display(arr,size);
    cout << endl;


	return 0;
}

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array
double mean(const double array[], int arraySize){
    double sum = 0;
    for(int i = 0; i < arraySize; i++)
      sum+=array[i];

    return sum/arraySize;
}

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index){

  for(int i = index ; i < arraySize - 1; i++){
    array[i] =  array[i+1];
  }
  arraySize--;
}


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize){
  for(int i = 0; i < arraySize; i++){
    if(i == arraySize - 1)
      cout << array[i];
    else
      cout << array[i] << ", ";
  }
}
