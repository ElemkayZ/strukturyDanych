#pragma once
//DubNode class used for elements of a Linked List
class DubNode{
     //private variables for better safety
     int data;
     DubNode *prev;
     DubNode *next;
public:
     //constructors:
     DubNode();
     DubNode(int);
     //functions to return private variables
     int getData();
     DubNode* getNext();
     void changeData(int);
     void changeNext(DubNode*);
     DubNode* getPrev();
     void changePrev(DubNode*);


};
