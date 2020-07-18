#include "Playlist.h"
//----------PlaylistNode-----------//
PlaylistNode::PlaylistNode(){
      uniqueID = "none";
      songName = "none";
      artistName = "none";
      songLength = 0;
      nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string id, string song, string artist, int length){
      uniqueID = id;
      songName = song;
      artistName = artist;
      songLength = length;
      nextNodePtr = nullptr;
}

void PlaylistNode::SetNext(PlaylistNode* next){
      nextNodePtr = next;
}

string PlaylistNode::GetID(){
      return uniqueID;
}

string PlaylistNode::GetSongName(){
      return songName;
}

string PlaylistNode::GetArtistName(){
      return artistName;
}

int PlaylistNode::GetSongLength(){
      return songLength;
}

PlaylistNode* PlaylistNode::GetNext(){
      return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode(){
      cout << "Unique ID: " << uniqueID << endl;
      cout << "Song Name: " << songName << endl;
      cout << "Artist Name: " << artistName << endl;
      cout << "Song Length (in seconds): " << songLength << endl;
}
//----------PlaylistNode-----------//

//----------Playlist-----------//
Playlist::Playlist(string name){
      head = nullptr;
      tail = nullptr;
      sz = 0;
      listName = name;
}

void Playlist::PrintMenu(){
      cout << listName << " PLAYLIST MENU" << endl;
      cout << "a - Add song\nd - Remove song\nc - Change position of song\ns - Output songs by specific artist\nt - Output total time of playlist (in seconds)\no - Output full playlist\nq - Quit" << endl;
      cout << endl;
}

int Playlist::getSize(){
      return sz;
}

void Playlist::InsertAfter(PlaylistNode* node, int pos){
      if(pos > sz)
            pos = sz;



      if(sz == 0){
            //cout << "Sz is 0" << endl;
            head = node;
            tail = node;
            sz++;
            return;
      }
      if(pos <= 0){
            //cout << "new pos at head" << endl;
            node->SetNext(head);
            head = node;
            sz++;
            return;
      }

      // cout << "New pos: " << pos << endl;
      PlaylistNode* before = head;
      for(int i = 0; i < pos-1; i++){
            before = before->GetNext();
      }
      node->SetNext(before->GetNext());
      before->SetNext(node);

      sz++;

      if(pos <= sz )
            tail = node;
}

string Playlist::getName(){
      return listName;
}

void Playlist::addSong(){
      string id, name, artist;
      int length;
      cout << "Enter song's unique ID:" << endl;
      cin >> id;
      cin.ignore();
      cout << "Enter song's name:" << endl;
      getline(cin,name);
      cout << "Enter artist's name:" << endl;
      getline(cin,artist);
      cout << "Enter song's length:" << endl;
      cin >> length;

      PlaylistNode* temp = new PlaylistNode(id,name,artist,length);
      // cout << "temp created" << endl;
      //cout << "SIZE: " << sz << "-----------" << endl;
      InsertAfter(temp,sz);
      // cout << "SIZE: " << sz << "-----------" << endl;
}

void Playlist::printList(){
      if(sz == 0){
            cout << "Playlist is empty" << endl;
            return;
      }
      PlaylistNode* temp = head;
      for(int i = 0; i < sz; i++){
            cout << i+1 << "." << endl;
            temp->PrintPlaylistNode();
            cout << endl;
            temp = temp->GetNext();
      }
}

void Playlist::remove(){
      if(sz == 0){
            cout << "Error - Playlist is Empty" << endl;
            return;
      }
      cout << "Enter song's uniqueID:" << endl;
      string id;
      cin >> id;
      PlaylistNode* temp = head;
      int count = 0;

      while(temp!=nullptr){
            if(temp->GetID() == id){
                  cout << "\"" << temp->GetSongName() << "\" removed" << endl;
                  removeNode(count);
                  return;
            }
            temp=temp->GetNext();
            count++;
      }
      cout << "Song Does Not Exist" << endl;
}

void Playlist::removeNode(int s){
      PlaylistNode* temp = head;
      if(s == 0){
            if(sz == 1){
                  delete head;
                  head = nullptr;
                  tail = nullptr;
                  sz--;
                  return;
            }
            temp = head;
            head = head->GetNext();
            delete temp;
            sz--;
            return;
      }

      PlaylistNode* before = temp;
      temp = temp->GetNext();
      for(int i = 1; i < s; i++){
            before = before->GetNext();
            temp = temp->GetNext();
      }
      before->SetNext(temp->GetNext());
      delete temp;
      
      if(before->GetNext() == nullptr)
            tail = before;
      sz--;
}

void Playlist::changeNode(int oldpos, int newpos){
      if(oldpos == newpos)
            return;

      PlaylistNode* temp;
      PlaylistNode* before;

      //Moving Head node
      if(oldpos == 0){
            temp = head;
            head = head->GetNext();
            before = head;
            for(int i = 1; i < newpos; i++){
                  before = before->GetNext();
            }
            temp->SetNext(before->GetNext());
            before->SetNext(temp);

            if(newpos == sz-1){
                  tail = temp;
                  tail->SetNext(nullptr);
            }

            return;
      }
      //Moving Tail
      if(oldpos == sz-1){
            temp = tail;
            before = head;
            while(before->GetNext() != tail)
                  before = before->GetNext();
            before->SetNext(nullptr);
            tail = before;
            before = head;

            if(newpos == 0){
                  temp->SetNext(before);
                  head = temp;

                  return;
            }

            for(int i = 1; i < newpos; i++){
                  before = before->GetNext();
            }
            temp->SetNext(before->GetNext());
            before->SetNext(temp);

            return;
      }

      before = head;
      temp = before->GetNext();
      for(int i = 1; i < oldpos; i++){
            before = before->GetNext();
            temp = temp->GetNext();
      }
      before->SetNext(temp->GetNext());

      //moving node to head
      if(newpos == 0){
            temp->SetNext(head);
            head = temp;
            return;
      }
      //moving node to tail
      if(newpos == sz-1){
            tail->SetNext(temp);
            tail = temp;
            tail->SetNext(nullptr);
            return;
      }

      //moving nodes
      before = head;
      for(int i = 1; i < newpos; i++){
            before = before->GetNext();
      }
      temp->SetNext(before->GetNext());
      before->SetNext(temp);

}

void Playlist::changePos(){
      cout << "Enter song's current position:" << endl;
      int oldpos;
      cin >> oldpos;
      cout << "Enter new position for song:" << endl;
      int newpos;
      cin >> newpos;

      if(oldpos < 1 || newpos > sz){
            cout << "Invalid Position" << endl;
            return;
      }
      // cout << "sz before node changes" << sz << endl;
      changeNode(oldpos-1, newpos-1);
      PlaylistNode* temp = head;
      for(int i = 1; i < newpos; i++)
            temp = temp->GetNext();
      cout << "\"" << temp->GetSongName() << "\" moved to position " << newpos << endl;



}

void Playlist::outPutArtist(){
      cout << "Enter artist's name:" << endl;
      string artist;
      cin.ignore();
      getline(cin,artist);

      PlaylistNode* temp = head;
      for(int i = 0; i < sz; i++){
            if(temp->GetArtistName() == artist){
                  cout << i + 1 << ".\n";
                  temp->PrintPlaylistNode();
                  cout << endl;
            }
            temp = temp->GetNext();
      }
}

void Playlist::printTime(){
      cout << "Total time: ";
      int t = 0;
      PlaylistNode* temp = head;
      for(int i = 0; i < sz; i++){
            t += temp->GetSongLength();
            temp = temp->GetNext();
      }
      cout << t << " seconds" << endl;
}
//----------Playlist-----------//
