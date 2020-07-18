#include "WordLadder.h"


bool WordLadder::singleletter(const string &word1, const string &word2){
      int diff = 0;
      for(int i = 0; i < 5; i++)
            if(word1[i] != word2[i])
                  diff++;
      return diff == 1;
}

void WordLadder::print(const stack<string> &stk){
      stack<string> stak(stk);
      stack<string> printer;
      while(stak.size() != 0){
            string s = stak.top();
            stak.pop();
            printer.push(s);
      }

      while(printer.size() > 1){
            cout << printer.top() << " -> ";
            printer.pop();
      }
      cout << printer.top() << endl;
}

void WordLadder::deleteWord(const string &word){
      int count = 0;
      for(string s: dict){
            if(s == word)
                  break;
            count++;
      }
      list<string>::iterator it = dict.begin();
      advance(it,count);
      dict.erase(it);
}

WordLadder::WordLadder(const string & filename){
      fstream fin(filename);
      if(!fin.is_open())
            throw runtime_error("Invalid Input Filename");
      string words;
      while(fin >> words){
            if(words.size() != 5)
                  throw runtime_error("File contains invalid words");
            dict.push_back(words);
      }
      fin.clear();
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile){
      fstream fin(outputFile);
      if(!fin.is_open())
            throw runtime_error("Invalid Output Filename");
      bool contain1 = false, contain2 = false;
      for(string s:dict){
            if(s == start)
                  contain1 = true;
            else if(s == end)
                  contain2 = true;
      }
      if(!contain1 || !contain2)
            throw runtime_error("Dictionary doesnt not contain some or all of these words.");


      //
      // if(singleletter(start,end))
      //       cout << start << " and " << end << " differs by 1" << endl;



      //Creating queue of stack
      queue<stack<string>> qofstack;

      stack<string> startstack;
      startstack.push(start);
      deleteWord(start);

      qofstack.push(startstack);

      while(!qofstack.empty()){
            string currword = qofstack.front().top();
            for(string check: dict){
                  if(singleletter(currword,check)){
                        if(check == end){
                              print()
                        }
                  }
            }
      }
}
