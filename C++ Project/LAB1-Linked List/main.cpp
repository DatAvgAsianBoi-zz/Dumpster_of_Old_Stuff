#include "Playlist.h"

int main(){
      //----Program----//
      string name;
      cout << "Enter playlist\'s title:" << endl;
      getline(cin,name);
      // cin.ignore();
      cout << endl;

      Playlist list(name);

       char input;
       do{
             list.PrintMenu();
             cout << "Choose an option:";
             cin >> input;

             switch(input){
                   case 'a':
                        cout << "ADD SONG" << endl;
                        list.addSong();
                        break;
                  case 'd':
                        cout << "REMOVE SONG" << endl;
                        list.remove();
                        break;
                  case 'c':
                        cout << "CHANGE POSITION OF SONG" << endl;
                        list.changePos();
                        break;
                  case 's':
                        cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
                        list.outPutArtist();
                        break;
                  case 't':
                        cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
                        list.printTime();
                        break;
                  case 'o':
                        cout <<  list.getName() << " - OUTPUT FULL PLAYLIST" << endl;
                        list.printList();
                        break;
                  case 'q':
                        break;
                  default:
                        cout << "Invalid" << endl;
                        break;
             }
             cout << endl;

       }while(input != 'q');


      //----Program----//


      //-----Test-----//
      // Playlist list("NO");
      // list.PrintMenu();
      //
      //
      // cout << "Hello" << endl;
      //-----Test-----//
      return 0;
}
