#include <iostream>
#include "list.h"
using namespace std;

List::List() : first(nullptr) {}

List::~List() {
  Node *curr = first;
  Node *tmp = first;
  while (curr != nullptr){
    tmp = curr->next;
    delete curr;
    curr = tmp;
  }
}

bool List::exists(int d) const {
  Node *curr = first;
  while(curr != nullptr){
    if(curr->value == d){
      	return true;
    }
    curr = curr->next;
  }
  return false;
}

int List::size() const {
  int size = 0;
  Node *curr = first;
  while(curr != nullptr){
    size++;
    curr = curr->next;
  }
  return size;
}

bool List::empty() const {
  return first == nullptr;
}

void List::insertFirst(int d) {
  first = new Node(d, first);
}

void List::remove(int d, DeleteFlag df) {
  Node *curr = first;
  Node *prev = first;
  while (curr != nullptr) {
    if((df == List::DeleteFlag::LESS && curr->value < d) ||
       (df == List::DeleteFlag::EQUAL && curr->value == d) ||
       (df == List::DeleteFlag::GREATER && curr->value > d))
      {
	        if(curr == prev){
	          first = curr->next;
	        } else {
            prev->next = curr->next;
          }
	        delete curr;
	        return;
      }
      prev = curr;
      curr = curr->next;
  }
}

void List::print() const {
  Node *curr = first;
  cout << "List[ ";
  while (curr != nullptr) {
    cout << curr->value;
    curr = curr->next;

    if(curr != nullptr){
      cout << ", ";
    }
  }
  cout << "]" << endl;
}
