#pragma once
#include "DubNode.h"
//Single Linked List containing only head pointer
class DubLinklist{
     DubNode *head;
     DubNode *tail;
     int len;
public:
     DubLinklist();
     void addEnd(int);
     void removeEnd();
     void addStart(int);
     void removeStart();
     void addBefore(int,int);
     void addAfter(int,int);
     void remove(int);
     int getLen();
     DubNode* getHead();
     DubNode* getTail();
     DubNode* getNode(int);
     DubNode* findNumber(int);

};