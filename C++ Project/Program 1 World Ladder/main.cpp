#include "WordLadder.h"

int main(){
      try{
            string start, end, input, output;
            cout << "Enter a starting word:" << endl;
            cin >> start;
            cout << "Enter the ending word:" << endl;
            cin >> end;
            cout << "Enter the input file:" << endl;
            cin >> input;
            cout << "Enter the output file:" << endl;
            cin >> output;
            WordLadder ladder(input);
            ladder.outputLadder(start, end, output);

      }
      catch(runtime_error &expt){
            cout << expt.what() << endl;
            cout << "Cannot complete wordladder" << endl;
      }


      return 0;
}
