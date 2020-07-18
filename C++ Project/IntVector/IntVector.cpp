#include "IntVector.h"


IntVector :: IntVector(){
      sz = 0;
      cap = 0;
      data = nullptr;
}

IntVector :: IntVector(unsigned size, int value){
      sz = size;
      cap = size;
      data = new int[size];
      for(unsigned i = 0; i < size; i++)
            data[i] = value;
}

IntVector:: ~IntVector(){
      cout << "Destructor Called" << endl;
      cout << "Data should point to something: " << data << endl << endl;

      delete [] data;
      data = nullptr;

      cout << "Data should point to nothing: " << data << endl << endl;

}

unsigned IntVector::size() const{
      return sz;
}

unsigned IntVector::capacity() const{
      return cap;
}

bool IntVector:: empty() const{
      return sz == 0;
}

const int & IntVector::at(unsigned index) const{
      if(index >= sz)
            throw out_of_range("IntVector::at_range_check");
      return data[index];
}

const int & IntVector::front() const{
      return *data;
}

const int & IntVector::back() const{
      int *ptr = data;
      for(unsigned i = 1; i < sz; i++)
            ptr++;

      return *ptr;
}

int & IntVector::at(unsigned index){
      if(index >= sz)
            throw out_of_range("IntVector::at_range_check");
      return data[index];
}

void IntVector:: insert(unsigned index, int value){
      if(index >= sz)
            throw out_of_range("IntVector::at_range_check");
      if(sz >= cap)
            expand();

      // cout << "Looping" << endl;
      for(unsigned i = sz; i > index; i--){
            data[i] = data[i-1];
            //cout << "Inserting " << data[i] << " to " << i+1 << endl;
      }
      // cout << "Loop done" << endl;
      data[index] = value;
      sz++;
}

void IntVector::erase(unsigned index){
      if(index >= sz)
            throw out_of_range("IntVector::at_range_check");

      for(int i = index; i+1 < sz; i++){
            data[i] = data[i+1];
      }

      sz--;
}

int & IntVector::front(){
      return data[0];
}

int& IntVector::back(){
      return data[sz-1];
}

void IntVector::reserve(unsigned n){
      if(n > cap)
            expand(n-cap);
}

void IntVector::assign(unsigned n, int value){
      reserve(n);
      sz = n;
      for(int i = 0; i < n; i++)
            data[i] = value;
}






void IntVector::expand(){
      if(cap == 0){
            data = new int[1];
            cap = 1;
      }
      else{
            cap*= 2;
            int *ptr = new int[cap];

            for(int i = 0; i < sz; i++)
                  ptr[i] = data[i];

            delete [] data;
            data = ptr;
            ptr = nullptr;
      }
}

void IntVector::expand(unsigned amount){
      cap += amount;
      int *ptr = new int[cap];

      for(int i = 0 ; i < sz; i++)
            ptr[i] = data[i];

      delete [] data;
      data = ptr;
      ptr = nullptr;
}
