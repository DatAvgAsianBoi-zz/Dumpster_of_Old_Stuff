#include "Heap.h"
#include <iostream>
#include <math.h>

using namespace std;
Heap::Heap(){
      numItems = 0;
}

void Heap::enqueue(PrintJob* job){
      if(numItems == MAX_HEAP_SIZE)
            return;
      arr[numItems] = job;
      int curr = numItems;
      int parent = curr/2;

      while(parent != -1){
            if(job->getPriority() > arr[parent]->getPriority()){
                  arr[curr] = arr[parent];
                  arr[parent] = job;
                  if(parent == 0)
                        break;
                  curr = parent;
                  parent = curr/2;
            }
            else
                  break;
      }

      numItems++;
}

void Heap::dequeue(){
      if(numItems == 0)
            return;

      arr[0] = arr[--numItems];
      arr[numItems] = nullptr;

      trickleDown(0);
}

PrintJob* Heap::highest(){
      return arr[0];
}

void Heap::print(){
      if(numItems == 0)
            return;
      cout << "Priority: " << arr[0]->getPriority() << ", Job Number: " <<  arr[0]->getJobNumber() << ", Number of Pages: " << arr[0]->getPages();
      cout << endl;
}

void Heap::trickleDown(int index){
      if(numItems == 0)
            return;

      // cout << "trickleDown is called" << endl;

      int child1 = index *2 + 1;
      int child2 = child1 + 1;

      if(child1 < numItems){
            if(arr[index]->getPriority() < arr[child1]->getPriority()){
                  PrintJob* temp = arr[index];
                  arr[index] = arr[child1];
                  arr[child1] = temp;
                  trickleDown(child1);
                  trickleDown(index);
                  return;
            }
      }
      if(child2 < numItems){
            if(arr[index]->getPriority() < arr[child2]->getPriority()){
                  PrintJob* temp = arr[index];
                  arr[index] = arr[child2];
                  arr[child2] = temp;
                  trickleDown(child2);
                  trickleDown(index);
                  return;
            }
      }


}
