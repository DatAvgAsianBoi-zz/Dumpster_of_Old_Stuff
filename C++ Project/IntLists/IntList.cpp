
#include "IntList.h"

IntList::IntList(): head(nullptr), tail(nullptr){}

IntList::IntList(const IntList &cpy){
      if(cpy.empty()){
            head = nullptr;
            tail = nullptr;
      }
      else{
            IntNode *iterate = cpy.head;
            head = new IntNode(iterate->data);
            IntNode *temp = head;
            iterate = iterate->next;
            while(iterate != nullptr){
                  temp->next = new IntNode(iterate->data);
                  temp = temp->next;
                  iterate = iterate->next;
            }
            tail = temp;
      }
}

IntList:: ~IntList(){
      IntNode *temp;
      while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
      }
      tail = nullptr;
      // cout << head << endl << tail << endl;
}

void IntList:: display() const{
      if(head == nullptr)
            return;
      IntNode *temp = head;
      while(temp != tail){
            cout << temp->data << " ";
            temp = temp->next;
      }
      cout << temp->data;
}

void IntList::push_front(int value){
      if(head == nullptr){
            head = new IntNode(value);
            tail = head;
      }
      else{
            IntNode *temp = new IntNode(value);
            temp->next = head;
            head = temp;
      }
}

void IntList::pop_front(){
      if(empty())
            return;

      IntNode *temp = head;
      if(head == tail){
            head = nullptr;
            tail = nullptr;
      }
      else{
            head = head->next;
      }
      delete temp;
      // cout << "Popped Sucessfully" << endl;
}

bool IntList::empty() const{
      return head == nullptr;
}

const int& IntList::front() const{
      return head->data;
}

const int& IntList::back() const{
      return tail->data;
}

IntList & IntList::operator=(const IntList &rhs){
      if(rhs.head == head)
            return *this;

      if(rhs.empty()){
            head = nullptr;
            tail = nullptr;
      }
      else{
            clear();

            IntNode *iterate = rhs.head;
            head = new IntNode(iterate->data);
            IntNode *temp = head;
            iterate = iterate->next;
            while(iterate != nullptr){
                  temp->next = new IntNode(iterate->data);
                  temp = temp->next;
                  iterate = iterate->next;
            }
            tail = temp;
      }

      return *this;
}

void IntList::push_back(int value){
      if(empty()){
            head = new IntNode(value);
            tail = head;
            return;
      }
      tail->next = new IntNode(value);
      tail = tail->next;
}

void IntList::clear(){
      IntNode *temp;
      while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
      }
      tail = nullptr;
}

void IntList::selection_sort(){
      if(empty())
            return;

      for(IntNode *curr = head; curr->next != nullptr; curr = curr->next){
            IntNode *min = curr;
            for(IntNode *iter = curr; iter != nullptr; iter = iter->next)
                  if(iter->data < min->data)
                        min = iter;
            int temp = curr->data;
            curr->data = min->data;
            min->data = temp;
      }
}

void IntList::insert_ordered(int value){
      if(empty()){
            push_back(value);
            return;
      }

      IntNode* temp = head;

      while(temp->next != nullptr && temp->next->data < value)
            temp = temp->next;

      IntNode *node = new IntNode(value);

      if(temp == head && temp->data > value){
            push_front(value);
            return;
      }

      node->next = temp->next;
      temp->next = node;

      if(node->next == nullptr)
            tail = node;

}

void IntList::remove_duplicates(){
      if(empty())
            return;


      if(head->next == nullptr) //Ensure there is at least 2 node in list
            return;

      IntNode* curr = head;

      while(curr != nullptr){
            int compare = curr->data;
            IntNode *prev = curr;
            IntNode* dup = curr->next;

            while(dup != nullptr){
                  if(dup->data == compare){
                        prev->next = dup->next;
                        delete dup;
                        dup = prev->next;
                        if(dup == nullptr)
                              tail = prev;
                  }
                  else{
                        dup = dup->next;
                        prev = prev->next;
                  }
            }

            curr = curr->next;
      }
}

ostream& operator<<(ostream &out, const IntList &rhs){
      if(rhs.head == nullptr)
            return out;

      IntNode *temp = rhs.head;

      while(temp->next != nullptr){
            out << temp->data << " ";
            temp = temp->next;
      }

      out << temp->data;

      return out;
}
