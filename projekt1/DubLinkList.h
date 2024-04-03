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
     void add(int,int);
     void remove(int);
     int getLen();
     DubNode* getHead();
     DubNode* getTail();


};