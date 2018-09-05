#include <stdio.h>
class List {
  public:
    List();
    length();
    get();
    push_back();
    remove_front();
    List::~List()
    {
      // Free all of the ListNodes in the list
      Item t;
      while(!empty()) // while not empty
         remove(t);   // remove the next node
    }
    bool remove(Item &copy) 
    {
        if (!empty()) // if list is not empty
        {
           copy = head->getItem(); // return copy
            ListNode *tmp = head->getNext();
            delete head; // delete the node
            head = tmp;  // update the head
            if (tmp==NULL) // removed last element 
               tail = NULL;
            return true;
        }
    return false; // nothing in list
    }
  
  

