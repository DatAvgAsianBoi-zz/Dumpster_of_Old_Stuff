#include "list.h"

list::~list(){
      if(head == nullptr)
            return;

      Node* temp = head->next;
      while(temp != head){
            Node* next = temp->next;
            delete temp;
            temp = next;
      }
}

void list::push_back(string name){
      Node *temp = new Node(name);

      if(size() == 0){
            head = temp;
            tail = temp;
            temp->next = temp;
            return;
      }

      temp->next = head;
      tail->next = temp;
      tail = temp;
}

void list::remove(string name){
      if(size() == 0)
            return;
      if(size() == 1)
            if(head->name == name){
                  delete head;
                  head = nullptr;
                  tail = nullptr;
                  return;
            }
            else
                  return;


      Node *temp = head;
      Node *prev = tail;
      // cout << "Loop starts" << endl;
      while(temp != tail){
            if(temp->name == name){
                  prev->next = temp->next;
                  if(temp == head)
                        head = temp->next;
                  delete temp;
                  // cout << "Deleting temp" << endl;
                  return;
            }
            temp = temp->next;
            prev = prev->next;
      }

      if(temp->name == name){
            prev->next = temp->next;
            delete temp;
            tail = prev;
      }
}

void list::print(){
      // cout << "Starting print" << endl;
      if(size() == 0)
            return;
      if(size() == 1){
            cout << head->name;
            return;
      }

      // cout << "Base case passed" << endl;
      Node *temp = head;
      while(temp != tail){
            cout << temp->name << " ";
            temp = temp->next;
      }
      cout << tail->name;
      // cout << "Print end" << endl;
}

int list::size(){
      if(head == nullptr)
            return 0;

      Node *temp = head;
      int sz = 0;
      while(temp != tail){
            sz++;
            temp = temp->next;
      }
      return ++sz;
}

void list::playGame(int start, int skip){
      if(size() == 1){
            cout << "Winner: " <<  head->name << endl;
            return;
      }

      // cout << "Tail: " << tail->name << " Tail->next " << tail->next->name;

      Node *currNode = head;
      for(int i = 1; i < start; i++)
            currNode=currNode->next;
      // cout << currNode->name << endl;

      while(size() > 1){
            // cout << "Loop Start" << endl;
            // cout << "Starting with: " << currNode->name << endl;

            for(int i = 1; i < skip; i++)
                  currNode = currNode->next;

            // cout << "Skip Loop Finish ---" << endl;
            string death = currNode->name;
            currNode = currNode->next;

            remove(death);
            cout << death << " has been killed" << endl;
            // cout << "Number of People Remaining: " << size() << endl;
            // print();
            // cout << endl << "Loop End" << endl;
            if(size() == 1)
                  break;
      }
      cout << "Winner: " <<  head->name << endl;

}
