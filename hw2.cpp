#include <stdio.h>
#include <string>
using namespace std
  
class List {
  public:
    List()
        {
       // there’s nothing in the list
       head = NULL;
       tail = NULL;
        }
    length();
    get();
    void push_back(string a)
    {
      append(a);
    }
    remove_front();
    ~List()
    {
      // Free all of the ListNodes in the list
      Item t;
      while(!empty()) // while not empty
         remove(t);   // remove the next node
    }
      void append(string a) 
      {
      ListNode *node = new ListNode(a);
      if (head==NULL) { 
         // list is empty, so set head and 
         // tail to be node
         head = node;
         tail = node;
      } else {
        // put new node at end of list
        tail->setNext(node); //(1)
        tail = node;         //(2)
      }
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
  private:
    ListNode *head;
    ListNode *tail;
  
};
  
  class ListNode {
private:
   string word; // data in the list
   ListNode *next;	
public:
   ListNode(string a) 
      { word = a; next=NULL; }
   ListNode* getNext() { return next; }
   void setNext(ListNode *n) { next = n; }
   string getWord() { return word; }
};

  

