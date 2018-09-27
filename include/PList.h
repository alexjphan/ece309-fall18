#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#ifndef DLIST_H
#define DLIST_H

using namespace std;

class Object
{
	public:
	virtual void print(){printf("Object");}
};

class Num : public Object
{
	public:
		Num(int i){dataNum = i;}
		void print(){cout<<dataNum<<endl;}
	private:
		int dataNum;
};

class Doub : public Object
{
	public:
		Doub(double d){dataDoub = d;}
		void print(){cout<<dataDoub<<endl;}
	private:
		double dataDoub;
};

class Strn : public Object
{
	public:
		Strn(string s){dataStrn = s;}
		void print(){cout<<dataStrn<<endl;}
	private:
		string dataStrn;
};


class DList {
private:
  // DListNode represents each
  // node of the list
  class DListNode {
  public:
    Object *object;
    DListNode *next;
    DListNode *prev;
    DListNode(Object *o,DListNode *n=NULL, DListNode *p=NULL)
    {
      object = o; next = n; prev = p; // constructs the node for us
    }
  };

  // add head and tail pointer
  DListNode *head;
  DListNode *tail;

public:
  class iterator {
  private:
    DListNode *node;

  public:
    iterator(DListNode *n=NULL) { node = n; }
    Object *getObject() { return node->object; }
    void increment() { node = node->next; }
    bool end() {  return node==NULL; }

    friend class DList;
  };

public:
  DList();
  void append(Object *a);
  void insertAfter(iterator it, Object *a);
  void erase(iterator it);
  DListNode* begin(){return head;}
  DListNode* end(){return tail;}
  bool empty();
};

#endif //DLIST_H
