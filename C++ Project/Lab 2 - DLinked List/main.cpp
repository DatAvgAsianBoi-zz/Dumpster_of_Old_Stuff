#include "IntList.h"

int main(){

      IntList *yo = new IntList();
      yo->push_back(1);
      yo->push_back(2);
      yo->push_back(3);
      yo->push_back(4);
      yo->push_back(5);
      yo->push_front(0);
      cout << *yo << endl;
      yo->printReverse();

      return 0;
}
