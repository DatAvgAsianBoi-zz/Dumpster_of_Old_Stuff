#include "IntVector.h"

int  main(){

      // cout << "------------------TEST 1 ----------------------" << endl;
      // cout << "Testing Default Constructor w/ size(), capacity(), and empty()" << endl;
      // IntVector x;
      // cout << "Size(Expecting 0): " << x.size() << endl;
      // cout << "Capacity(Expecting 0): " << x.capacity() << endl << endl;
      // cout << "Empty(Expecting True(1)): " << x.empty() << endl << endl;
      //
      // cout << "------------------TEST 2 ----------------------" << endl;
      // x = IntVector(5,0);
      // cout << "Testing Constructor w/ size(), capacity(), and empty()" << endl;
      // cout << "Size(Expecting 5): " << x.size() << endl;
      // cout << "Capacity(Expecting 5): " << x.capacity() << endl << endl;
      // cout << "Empty(Expecting False(0)): " << x.empty() << endl << endl;
      //
      // cout << "------------------TEST 3 ----------------------" << endl;
      // x = IntVector(151,0);
      // cout << "Testing Constructor w/ size(), capacity(), and empty()" << endl;
      // cout << "Size(Expecting 151): " << x.size() << endl;
      // cout << "Capacity(Expecting 151): " << x.capacity() << endl << endl;
      // cout << "Empty(Expecting False(0)): " << x.empty() << endl << endl;

      // cout << "------------------TEST 4 ----------------------" << endl;
      // IntVector x = IntVector(10,0);
      // cout << "Testing Function empty() (Expect False(0)): " << x.empty() << endl;
      // cout << "Testing Function at() (Expect 0): " << x.at(5) << endl;
      // cout << "Testing Function at() (Expect out of bound error): " << x.at(10) << endl;

      // cout << "------------------TEST 5 ----------------------" << endl;
      // IntVector x = IntVector(10,0);
      // cout << "Testing Function empty() (Expect False(0)): " << x.empty() << endl;
      // cout << "Testing Function front() (Expect 0): " << x.front() << endl;
      // cout << "Testing Function back() (Expect 0): " << x.back() << endl;
      // cout << endl;

      // cout << "------------------TEST 6 ----------------------" << endl;
      // IntVector x = IntVector(10,0);
      // cout << "Testing Constructor w/ size() and capacity()" << endl;
      // cout << "Size(Expecting 10): " << x.size() << endl;
      // cout << "Capacity(Expecting 10): " << x.capacity() << endl << endl;
      // x.expand(); // Making expand() public for testing purposes
      // cout << "Size(Expecting 10): " << x.size() << endl;
      // cout << "Capacity(Expecting 20): " << x.capacity() << endl << endl;
      // x.expand(5); // Making expand() public for testing purposes
      // cout << "Size(Expecting 10): " << x.size() << endl;
      // cout << "Capacity(Expecting 25): " << x.capacity() << endl << endl;

      // cout << "------------------TEST 7 ----------------------" << endl;
      // IntVector x;;
      // cout << "Testing Constructor w/ size() and capacity()" << endl;
      // cout << "Size(Expecting 0): " << x.size() << endl;
      // cout << "Capacity(Expecting 0): " << x.capacity() << endl << endl;
      // x.expand(); // Making expand() public for testing purposes
      // cout << "Size(Expecting 0): " << x.size() << endl;
      // cout << "Capacity(Expecting 1): " << x.capacity() << endl << endl;
      // x.expand(5); // Making expand() public for testing purposes
      // cout << "Size(Expecting 0): " << x.size() << endl;
      // cout << "Capacity(Expecting 6): " << x.capacity() << endl << endl;

      // cout << "------------------TEST 8 ----------------------" << endl;
      // cout << "Testing Constructor w/ size(), capacity(), insert(), and at()" << endl;
      // IntVector x = IntVector(10,0);
      // cout << "Size(Expecting 10): " << x.size() << endl;
      // cout << "Capacity(Expecting 10): " << x.capacity() << endl << endl;
      // x.insert(5, 5);
      // cout << "Size(Expecting 11): " << x.size() << endl;
      // cout << "Capacity(Expecting 20): " << x.capacity() << endl;
      // cout << "Element at 5(Expecting 5):" << x.at(5) << endl << endl;
      // x.insert(0, 3);
      // cout << "Size(Expecting 12): " << x.size() << endl;
      // cout << "Capacity(Expecting 20): " << x.capacity() << endl;
      // cout << "Element at 0(Expecting 3):" << x.at(0) << endl << endl;
      // x.insert(11,6);
      // cout << "Size(Expecting 13): " << x.size() << endl;
      // cout << "Capacity(Expecting 20): " << x.capacity() << endl;
      // cout << "Element at 11(Expecting 6):" << x.at(11) << endl << endl;
      // cout << "Expecting out of range error" << endl;
      // x.insert(13,6);

      // cout << "------------------TEST 9 ----------------------" << endl;
      // cout << "Testing Constructor w/ size(), capacity(), insert(), and at()" << endl;
      // IntVector x = IntVector(1,0);
      // cout << "Size(Expecting 1): " << x.size() << endl;
      // cout << "Capacity(Expecting 1): " << x.capacity() << endl;
      // cout << "Back(Expect 0): " << x.back() << endl;
      // cout << "Front(Expect 0): " << x.front() << endl << endl;
      // x.insert(0, 5);
      // cout << "Size(Expecting 2): " << x.size() << endl;
      // cout << "Capacity(Expecting 2): " << x.capacity() << endl;
      // cout << "Element at 0(Expecting 5):" << x.at(0) << endl;
      // cout << "Front(Expecting 5): " << x.front() << endl;
      // cout << "Back(Expecting 0): " << x.back() << endl << endl;
      // // x.erase(1);
      // // cout << "Size(Expecting 1): " << x.size() << endl;
      // // cout << "Capacity(Expecting 2): " << x.capacity() << endl;
      // // cout << "Element at 0(Expecting 5):" << x.at(0) << endl << endl;
      // // cout << "Expecting out of range error" << endl;
      // // x.at(1);

      cout << "------------------TEST 10 ----------------------" << endl;
      cout << "Testing assign() and reserve()" << endl;
      IntVector x = IntVector(1,0);
      cout << "Size(Expecting 1): " << x.size() << endl;
      cout << "Capacity(Expecting 1): " << x.capacity() << endl;
      cout << "Back(Expect 0): " << x.back() << endl;
      cout << "Front(Expect 0): " << x.front() << endl << endl;
      x.insert(0, 5);
      cout << "Size(Expecting 2): " << x.size() << endl;
      cout << "Capacity(Expecting 2): " << x.capacity() << endl;
      cout << "Element at 0(Expecting 5):" << x.at(0) << endl;
      cout << "Front(Expecting 5): " << x.front() << endl;
      cout << "Back(Expecting 0): " << x.back() << endl << endl;
      x.assign(3,9);
      cout << "Size(Expecting 3): " << x.size() << endl;
      cout << "Capacity(Expecting 3): " << x.capacity() << endl;
      cout << "Front(Expecting 9): " << x.front() << endl;
      cout << "Element at 1(Expecting 9): " << x.at(1) << endl;
      cout << "Back(Expecting 9): " << x.back() << endl << endl;








      return 0;
}
