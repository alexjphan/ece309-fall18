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
	int length()
    {
      ListNode *a = head;
      int b = 1;
      while(a != NULL)
      {
          b++;
      }
      return b;
    }
	void push_back(string a)
    {
      append(a);
    }
	string remove_front()
    {
      string a;
      remove(a);
      return a;
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
	~List()
    {
      // Free all of the ListNodes in the list
      string t;
      while(!empty()) // while not empty
         remove(t);   // remove the next node
    }
	bool empty()
    {
      return head == NULL;
    }
	bool remove(string &copy) 
    {
        if (!empty()) // if list is not empty
        {
           copy = head->getString(); // return copy
            ListNode *tmp = head->getNext();
            delete head; // delete the node
            head = tmp;  // update the head
            if (tmp==NULL) // removed last element 
               tail = NULL;
            return true;
        }
    return false; // nothing in list
    }
	
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