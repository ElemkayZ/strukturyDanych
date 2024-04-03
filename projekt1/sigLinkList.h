//Node class used for elements of a Linked List
class Node{
     //private variables for better safety
     int data;
     Node *adress;
public:
     //constructors:
     Node();
     Node(int);
     //functions to return private variables
     int getData();
     Node* getAdress();
     void changeData(int);
     void changeAdress(Node*);
};
//Single Linked List containing only head pointer
class SigLinklist{
     Node *head;
     int len;
public:
     SigLinklist();
     void addEnd(int);//
     void removeEnd();//
     void addStart(int);//
     void removeStart();//
     void add(int,int);//
     void remove(int);//
     Node* getLastNode();//
     int getLen();//
     Node* getHead();//


};
//Better Single Linked List containing head and tail pointers
class BetterSigLinklist{
     Node *head;
     Node *tail;
     int len;
public:
     BetterSigLinklist();
     void addEnd(int);
     void removeEnd();
     void addStart(int);
     void removeStart();
     void add(int,int);
     void remove(int);
     Node* getLastNode();
     int getLen();
     Node* getHead();


};
