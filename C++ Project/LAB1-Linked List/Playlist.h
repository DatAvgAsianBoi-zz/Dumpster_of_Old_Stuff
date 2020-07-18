#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
using namespace std;

class PlaylistNode{
private:
      string uniqueID;
      string songName;
      string artistName;
      int songLength;
      PlaylistNode* nextNodePtr;
public:
      PlaylistNode();
      PlaylistNode(string id, string song, string artist, int length);
      void SetNext(PlaylistNode* next);
      string GetID();
      string GetSongName();
      string GetArtistName();
      int GetSongLength();
      PlaylistNode* GetNext();
      void PrintPlaylistNode();


};

class Playlist{
private:
      PlaylistNode* head;
      PlaylistNode* tail;
      int sz;
      string listName;
      void removeNode(int s);
public:
      Playlist(string name);
      void PrintMenu();
      int getSize();
      void InsertAfter(PlaylistNode* node, int pos);
      void addSong();
      string getName();
      void printList();
      void remove();
      void changePos();
      void changeNode(int oldpos, int newpos);
      void outPutArtist();
      void printTime();

};




#endif
