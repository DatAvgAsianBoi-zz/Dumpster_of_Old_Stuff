#include <iostream>
#include <time.h>
using namespace std;

const int NUMBERS_SIZE = 50000;
const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds

//collad with zybook

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}
int partition(int numbers[] , int i , int k){
      int midpoint = i + (k-i) / 2;
      int pivot = numbers[midpoint];

      int l = i;
      int h = k;
      bool done = false;

      while(!done){
            while(numbers[l] < pivot)
                  l++;
            while(pivot < numbers[h])
                  h--;
            if(l>=h)
                  done = true;
            else{
                  int temp = numbers[l];
                  numbers[l] = numbers[h];
                  numbers[h] = temp;

                  l++;
                  h--;
            }
      }
      return h;
}

int partition2(int numbers[] , int i , int k){
      int leftmost = numbers[i];
      int rightmost = numbers[k];
      int median = numbers[(i+k)/2];

      int pivotIndex;
      int pivot;

      if(rightmost > leftmost && rightmost > median){
            if(leftmost > median){
                  pivotIndex = i;
                  pivot = leftmost;
            }
            else{
                  pivotIndex = (i+k)/2;
                  pivot = median;
            }
      }
      else if(leftmost > rightmost && leftmost > median){
            if(rightmost > median){
                  pivotIndex = k;
                  pivot = rightmost;
            }
            else{
                  pivotIndex = (i+k)/2;
                  pivot = median;
            }
      }
      else{
            if(rightmost > leftmost){
                  pivotIndex = k;
                  pivot = rightmost;
            }
            else{
                  pivotIndex = i;
                  pivot = leftmost;
            }
      }

      int midpoint = pivotIndex;
      pivot = numbers[midpoint];

      int l = i;
      int h = k;
      bool done = false;

      while(!done){
            while(numbers[l] < pivot)
                  l++;
            while(pivot < numbers[h])
                  h--;
            if(l>=h)
                  done = true;
            else{
                  int temp = numbers[l];
                  numbers[l] = numbers[h];
                  numbers[h] = temp;

                  l++;
                  h--;
            }
      }
      return h;
}

//this function sorts the given array in the range from i to k using quicksort method.
// In this function, pivot is the midpoint element (numbers[(i+k)/2]).
// (implementation of this function is given in section 21.5)
void Quicksort_midpoint(int numbers[], int i, int k){
      // if(i >= k) return;
      // if(i<0 || k<0) return;
      //
      // int pivotIndex = (i+k) / 2;
      // int pivot = numbers[pivotIndex];
      // // cout << "P-Index: " << pivotIndex << "\tP: "<< pivot << endl;
      //
      // int tempArr[NUMBERS_SIZE];
      // int part1 = i;
      // int part2 = k;
      // // cout << "Partition1: "<< part1 << "\tPartition2: " << part2 << endl;
      //
      // for(int j = i; j < k+1; j++)
      //       if(numbers[j] < pivot)
      //             tempArr[part1++] = numbers[j];
      //       else if(numbers[j] > pivot)
      //             tempArr[part2--] = numbers[j];
      //       else if(numbers[j] == pivot && j != pivotIndex)
      //             tempArr[part1++] = numbers[j];
      //
      // tempArr[part1] = pivot;
      //
      // // for(int j = i; j < k; j++)
      // //       cout << tempArr[j] << " ";
      // // cout << endl;
      // for(int j = i; j < k+1; j++)
      //       numbers[j] = tempArr[j];
      //
      // // cout << "Iteration Complete" << endl;
      // if(i >= part1-1)
      //       return;
      // Quicksort_midpoint(numbers, i, part1-1);
      // Quicksort_midpoint(numbers, part1+1, k);

      //zybook peusdo code
      int j = 0;
      if(i>=k)
            return;

      j = partition(numbers,i,k);

      Quicksort_midpoint(numbers,i,j);
      Quicksort_midpoint(numbers, j+1, k);

}

// this function utilizes different pivot selection technique in quicksort algorithm.
// The pivot is the median of the following three values: leftmost (numbers[i]), midpoint (numbers[(i+k)/2]) and rightmost (numbers[k]).
//  You should modify the partition function given in section 21.5 to select the pivot using median-of-three technique.
void Quicksort_medianOfThree(int numbers[], int i, int k){
      // if(i >= k) return;
      // if(i<0 || k<0) return;
      // int leftmost = numbers[i];
      // int rightmost = numbers[k];
      // int median = numbers[(i+k)/2];
      //
      // int pivotIndex;
      // int pivot;
      //
      // if(rightmost > leftmost && rightmost > median){
      //       if(leftmost > median){
      //             pivotIndex = i;
      //             pivot = leftmost;
      //       }
      //       else{
      //             pivotIndex = (i+k)/2;
      //             pivot = median;
      //       }
      // }
      // else if(leftmost > rightmost && leftmost > median){
      //       if(rightmost > median){
      //             pivotIndex = k;
      //             pivot = rightmost;
      //       }
      //       else{
      //             pivotIndex = (i+k)/2;
      //             pivot = median;
      //       }
      // }
      // else{
      //       if(rightmost > leftmost){
      //             pivotIndex = k;
      //             pivot = rightmost;
      //       }
      //       else{
      //             pivotIndex = i;
      //             pivot = leftmost;
      //       }
      // }
      //
      // int tempArr[NUMBERS_SIZE];
      // int part1 = i;
      // int part2 = k;
      //
      // for(int j = i; j < k+1; j++)
      //       if(numbers[j] < pivot)
      //             tempArr[part1++] = numbers[j];
      //       else if(numbers[j] > pivot)
      //             tempArr[part2--] = numbers[j];
      //       else if(numbers[j] == pivot && j != pivotIndex)
      //             tempArr[part1++] = numbers[j];
      //
      // tempArr[part1] = pivot;
      //
      // for(int j = i; j < k+1; j++)
      //       numbers[j] = tempArr[j];
      //
      // Quicksort_medianOfThree(numbers, i, part1-1);
      // Quicksort_medianOfThree(numbers, part1+1, k+1);
      int j = 0;
      if(i>=k)
            return;

      j = partition2(numbers,i,k);

      Quicksort_medianOfThree(numbers,i,j);
      Quicksort_medianOfThree(numbers, j+1, k);
}

// this function sorts the given array using InsertionSort method.
// (implementation of this method is provided in section 21.3).
 void InsertionSort(int numbers[], int numbersSize){
       for(int i = 1; i < numbersSize; i++)
             for(int j = i; j > 0; j--)
                   if(numbers[j] < numbers[j-1]){
                        int temp = numbers[j-1];
                        numbers[j-1] = numbers[j];
                        numbers[j] = temp;
                  }
 }

int main(){
      int arr1[NUMBERS_SIZE], arr2[NUMBERS_SIZE], arr3[NUMBERS_SIZE];
      fillArrays(arr1,arr2,arr3);

      // clock_t Start = clock();
      // cout << "Quicksort Starting\n";
      // for(int i = 0; i < NUMBERS_SIZE; i++)
      //       cout << arr1[i] << " ";
      // cout << endl;
      // Quicksort_midpoint(arr1, 0, NUMBERS_SIZE-1);
      // cout << "Quicksort Completed\n";
      // for(int i = 0; i < NUMBERS_SIZE; i++)
      //       cout << arr1[i] << " ";
      // cout << endl << endl;
      // clock_t End = clock();
      // int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
      // cout << "Elapsed Time: " << elapsedTime << endl;

      // Start = clock();
      // cout << "Quicksort-2 Startings\n";
      // for(int i = 0; i < NUMBERS_SIZE; i++)
      //       cout << arr2[i] << " ";
      // cout << endl;
      // Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE-1);
      // cout << "Quicksort-2 Completed\n";
      // for(int i = 0; i < NUMBERS_SIZE; i++)
      //       cout << arr2[i] << " ";
      // cout << endl << endl;
      //  End = clock();
      // elapsedTime = (End - Start)/CLOCKS_PER_MS;
      // cout << "Elapsed Time: " << elapsedTime << endl;
      //
      // Start = clock();
      // cout << "InsertionSort Starting\n";
      // for(int i = 0; i < NUMBERS_SIZE; i++)
      //       cout << arr3[i] << " ";
      // cout << endl;
      // InsertionSort(arr3, NUMBERS_SIZE);
      // cout << "InsertionSort Completed\n";
      // for(int i = 0; i < NUMBERS_SIZE; i++)
      //       cout << arr3[i] << " ";
      // cout << endl << endl;
      //  End = clock();
      // elapsedTime = (End - Start)/CLOCKS_PER_MS;
      // cout << "Elapsed Time: " << elapsedTime << endl;

      return 0 ;
}
