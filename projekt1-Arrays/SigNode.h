#pragma once

//SigNode class used for elements of a Linked List
class SigNode{
     //private variables for better safety
     int data;
     SigNode *adress;
public:
     //constructors:
     SigNode();
     SigNode(int);
     //functions to return private variables
     int getData();
     SigNode* getAdress();
     void changeData(int);
     void changeAdress(SigNode*);
};
