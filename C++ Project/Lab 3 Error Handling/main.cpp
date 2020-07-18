#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;


template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index){
      if(index >= vals.size())
            throw runtime_error("Invalid Index.");

      unsigned smul = index;
      for(unsigned i = index + 1; i < vals.size();i++)
            if(vals.at(i) < vals.at(smul))
                  smul = i;
      return smul;
}

template<typename T>
void selection_sort(vector<T> &vals){
      for(unsigned i = 0; i < vals.size(); i++)
            swap(vals.at(i), vals.at(min_index(vals,i)));
}

template<typename T>
T getElement(vector<T> vals, int index){
      if(index >= (int)vals.size() || index < 0)
            throw runtime_error("Invalid Index.");
      return vals.at(index);
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}


int main(){

      // vector<int> v;
      // v.push_back(1);
      // v.push_back(3);
      // v.push_back(16);
      // v.push_back(4000);
      // v.push_back(5);
      //
      // for(unsigned i = 0; i < v.size(); i++)
      //       cout << v.at(i) << " ";
      // cout << endl;
      // cout << min_index(v,0) << endl;
      // cout << min_index(v,2) << endl;
      // cout << min_index(v,4) << endl;

      // vector<string> v1;
      // v1.push_back("abc");
      // v1.push_back("acb");
      // v1.push_back("bac");
      //
      // for(unsigned i = 0; i < v1.size(); i++)
      //       cout << v1.at(i) << " ";
      // cout << endl;
      // cout << min_index(v1,0) << endl;
      // cout << min_index(v1,1) << endl;
      // // cout << min_index(v1,3) << endl; //Error Handling

      // selection_sort(v);
      // for(unsigned i = 0; i < v.size(); i++)
      //       cout << v.at(i) << " ";
      // cout << endl;
      // cout << getElement(v, 2) << endl;

      // cout << "Program End" << endl;

      srand(time(0));
      vector<char> vals = createVector();
      char curChar;
      int index;
      int numOfRuns = 10;
      while(--numOfRuns >= 0){
            try{
                  cout << "Enter a number: " << endl;
                  cin >> index;
                  curChar = getElement(vals,index);
                  cout << "Element located at " << index << ": is " << curChar << endl;
            }catch(runtime_error& except){
                  cout << except.what() << endl;
                  cout << "Index is too large" << endl;
            }
      }
      return 0;

      return 0;
}
