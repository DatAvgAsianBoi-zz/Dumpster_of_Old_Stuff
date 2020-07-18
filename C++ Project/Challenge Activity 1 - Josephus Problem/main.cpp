#include "list.h"


int main(){
      int people, start, skip;
      string file;
      cout << "Enter number of people in the initial circle: " << endl;
      cin >> people;
      while(people > 91){
            cout << "Enter number of people in the initial circle: " << endl;
            cin >> people;
      }
      cout << "Enter filename: " << endl;
      cin >> file;
      cout << "Enter the number of a person to start counting from: " << endl;
      cin >> start;
      cout << "Enter the number of people to skip" << endl;
      cin >> skip;

      ifstream fin(file);

      if(!fin.is_open()){
            cout << "Error opening file";
            exit(1);
      }

      list listofpeeps;
      for(int i = 0; i < people; i++){
            string input;
            getline(fin,input);
            listofpeeps.push_back(input);
      }
      cout << "Peeps in Game: ";
      listofpeeps.print();
      cout << endl;
      // listofpeeps.remove("Cayde-6");
      // listofpeeps.print();
      // cout << endl;

      listofpeeps.playGame(start, skip);








      // cout << "End";
      return 0;
}
