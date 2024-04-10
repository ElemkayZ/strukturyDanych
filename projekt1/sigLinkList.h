#include "SigNode.h"
//Single Linked List containing only head pointer
class SigLinklist{
     SigNode *head;
     int len;
public:
     SigLinklist();
     void addEnd(int);
     void removeEnd();
     void addStart(int);
     void removeStart();
     void add(int,int);
     void remove(int);
     SigNode* getLastSigNode();
     int getLen();
     SigNode* getHead();


};
//Better Single Linked List containing head and tail pointers
class BetterSigLinklist{
     SigNode *head;
     SigNode *tail;
     int len;
public:
     BetterSigLinklist();
     void addEnd(int);
     void removeEnd();
     void addStart(int);
     void removeStart();
     void add(int,int);
     void remove(int);
     int getLen();
     SigNode* getHead();
     SigNode* getTail();


};
