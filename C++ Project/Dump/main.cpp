#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(){
  ifstream sin("out.txt");


  if(!sin){
    cout << "nani";
    exit(1);
  }
  string s;
  sin >> s;
  cout << s;


  return 0;

}


/*
  1. B
  3. B
  4. C
  5. C - A
  7. A
  8. B
  9. B
  10. D
  12. D
  14. D
  15. B
  16. D
  17. C
  19. A
  20. C
  21. D





*/
