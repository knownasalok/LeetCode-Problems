/*#include<iostream>
using namespace std ;

class node { 
public:

int data ;
node *next ;

node (int data ){ 
this ->data=data ;
this ->next =NULL;
  
}
};
void Insertathead(node* &head,int d){ 
   node *temp= new node (d);
  temp->next=head;
  head= temp ;
  
}
 void Insertattail(node* &tail,int d ){ 
    node *temp= new node (d);
   temp->next=tail;
   tail= tail->next;
   
 }

void print(node* &head){ 
  node* temp=head ;

  while (temp!=NULL){ 
  cout<<temp->data<<" ";
    temp=temp->next;
    
  }cout<<endl;
}


//insert at position 
void Insertatpos(node* &head,int position , int d){ 
node* temp=head;
  int cnt =1;

  while (cnt<position-1){ 
  temp=temp->next;
    cnt++;
  }
//creating a node for d
  node* nodetoinsert=new node(d); 
  nodetoinsert->next=temp->next;
  temp->next =nodetoinsert;
  
}



int main(){ 
node *node1=new node(10);
  //cout<<node1->data<<endl;
  //cout<<node1->next<<endl;

  node* head= node1 ;
  node* tail= node1 ;
  
  print(head);
  

  Insertattail(tail,12 );
  print (tail );

  Insertattail(tail,16);
  print(head);

  Insertatpos(head,2,22);
  
  return 0;
}*/


#include <iostream>
using namespace std;

class Node { 
public:
    int data;
    Node *next;

    Node(int data) { 
        this->data = data;
        this->next = nullptr;
    }
};

void InsertAtHead(Node* &head, int d) { 
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &head, Node* &tail, int d) { 
    Node *temp = new Node(d);
    if (tail == nullptr) { // If the list is empty
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

 void Print(Node* head) { 
     Node* temp = head;
     while (temp != nullptr) { 
         cout << temp->data << " ";
         temp = temp->next;
     }
     cout << endl;
 }
void InsertAtPos(Node* &head, int position, int d) { 
    if (position <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (position == 1) {
        InsertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (temp != nullptr && cnt < position - 1) { 
        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// Main function to test the code
int main() { 
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    Print(head);

    InsertAtTail(head, tail, 12);
    Print(head);

    InsertAtTail(head, tail, 16);
    Print(head);

    InsertAtPos(head, 2, 22);
    Print(head);

    return 0;
}
