#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* next;
    int data;
    //constructor for node
     node(int val){
      data=val;
      next= NULL;
     }   
};

void insertAtHead(node* &head,int val){
        node* n=new node(val);
        if(head==NULL){
            head=n;
            return;

        }
        n->next=head;
        head=n;

     }

     void insertAtTail(node* &head,int val){

        if(head==NULL){ /// if no node is present same condtion as head
             insertAtHead(head,val);
             return;
        }
        node* n=new node(val);
        
        node* temp=head; //iteratot to traverse the linkdlist
        while(temp->next!=NULL)   
        {
            temp=temp->next;

        }
        temp->next=n;
        n->next= NULL;
        // no need to point null because next has alredy null present in it


     }
     void deleteAtHead(node* &head)
     { if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head; //// free(node)   for structure and malloc, delete node - class and constructor;
        return;
    }
    node* temp = head;
        head = head->next;
        delete temp;
        return;
     }

     void deleteAtTail(node* &head){
       if((head==NULL)||(head->next ==NULL)){
        deleteAtHead(head);
        return;
    }
        node* temppp=head;
        while((temppp->next)->next !=NULL) {
            temppp=temppp->next;
        }
        node* deleted=temppp->next;
        temppp->next=NULL;
        delete deleted;

        // node* temppp = head;
        // while((temppp->next)->next !=NULL){
        // temppp = temppp->next;
        // }
        // node* deleted = temppp->next;
        // temppp->next = NULL;
        // delete deleted;

     }
     void deletion(node* &head,int val)
     {
        node* temp= head;
        while(temp->next->data!=val){
            temp=temp->next;
 
        }
        node* deletem=temp->next;
        temp->next=temp->next->next;
        delete deletem;
         return;
     }
     void deleteKthNode(node* &head, int k){
    // corner cases aint included...
        node* temp1 = head;
        while (k>2){
            temp1= temp1->next;
            k--;
        }
        node* deletedd = temp1->next;
        temp1->next =temp1->next->next;
        delete deletedd;

                    }

     void display(node* head){
        node* tempp=head; // again need to traverse till end
        while(tempp->next!=NULL){
            cout<<tempp->data<<" ->";
            tempp=tempp->next;
        }
        cout<<"NULL"<<endl;
     }
int main(){
    node* head=NULL;
   
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,1);
    insertAtTail(head,6);
    insertAtTail(head,5);
    insertAtTail(head,7);
   
    display(head);
    deleteKthNode(head,4);
    deletion(head,6);
    display(head);
    deleteAtHead(head);
     display(head);
    deleteAtTail(head);
    display(head);
     deletion(head,3);
     display(head);




    
}
