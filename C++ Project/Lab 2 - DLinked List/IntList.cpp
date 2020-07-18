#include "IntList.h"


IntList::IntList(){
      dummyHead = new IntNode(0);
      dummyTail = new IntNode(0);
      dummyHead->next = dummyTail;
      dummyTail->prev = dummyHead;
}

IntList::~IntList(){

      IntNode *temp = dummyHead->next;
      while(temp != nullptr){
            IntNode * nhead = temp->next;
            delete temp;
            temp = nhead;
      }
      dummyTail = new IntNode(0);
      dummyTail->prev = dummyHead;
      dummyHead->next = dummyTail;
}

void IntList::push_front(int val){
      IntNode * newNode = new IntNode(val);
      newNode->next = dummyHead->next;
      newNode->prev = dummyHead;
      dummyHead->next = newNode;
      newNode->next->prev = newNode;
}

void IntList::pop_front(){
      if(empty())
            return;

      IntNode* temp = dummyHead->next;
      dummyHead->next = temp->next;
      temp->next->prev = dummyHead;
      delete temp;
}

void IntList::push_back(int val){
      IntNode *temp = new IntNode(val);
      temp->next = dummyTail;
      temp->prev = dummyTail->prev;
      temp->prev->next = temp;
      dummyTail->prev = temp;
}

void IntList::pop_back(){
      if(empty())
            return;

      IntNode *temp = dummyTail->prev;
      dummyTail->prev = temp->prev;
      temp->prev->next = dummyTail;
      delete temp;
}

bool IntList::empty() const{
      return dummyHead->next == dummyTail;
}

ostream & operator<<(ostream &out, const IntList &rhs){
      if(rhs.empty())
            return out;
      // cout << "Operator";
      IntNode *temp = rhs.dummyHead->next;
      while(temp != rhs.dummyTail->prev){
            out<<temp->data << " " ;
            temp = temp->next;
      }
      out << temp->data;

      return out;
}

void IntList::printReverse() const{
      if(empty())
            return;
      IntNode *temp = dummyTail->prev;
      while(temp != dummyHead->next){
            cout << temp->data << " ";
            temp = temp->prev;
      }
      cout << temp->data;
}
