#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <iostream>
#include <stdexcept>

using namespace std;

class IntVector{
private:

      unsigned sz;      //Store Size of IntVector (elements used)
      unsigned cap;     //Store Size of array
      int *data;        //Store address of array of ints
      void expand();
      void expand(unsigned amount);

public:
      IntVector();
      IntVector(unsigned size, int value = 0);
      ~IntVector();
      unsigned size() const;
      unsigned capacity() const;
      bool empty() const;
      const int & at(unsigned index) const;
      const int & front() const;
      const int & back() const;

      //Made Public to test
      // void expand();
      // void expand(unsigned amount);

      int & at(unsigned index);
      void insert(unsigned index, int value);
      void erase(unsigned index);
      int & front();
      int & back();
      void reserve(unsigned n);
      void assign(unsigned n, int value);

      void push_back(int value);
      void pop_back();
      void clear();
      void resize(unsigned size, int value = 0);
};




#endif
