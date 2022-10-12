// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node {
    int data;
    struct node *flink;
};

typedef struct node Node;

Node* create_node(int data);
Node* insert_at_front(Node **head, Node *newNode);
Node* insert_at_end(Node *head, Node *newNode);
Node *insert_in_middle(Node *head, Node *newNode, int index);
void print_list(Node *head);
int list_len(Node *head);
Node* sort(Node **head, bool reverse);

Node* create_node(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->flink = NULL;
    return newNode;
}

Node* insert_at_front(Node **head, Node *newNode){
    newNode->flink = *head;
    *head = newNode;
    return newNode;
}

Node* insert_at_end(Node *head, Node *newNode){
    Node *temp=head;
    while(temp->flink!=NULL){
        temp=temp->flink;
    }
    temp->flink = newNode;
}

Node *insert_in_middle(Node *head, Node *newNode, int index){
    Node *curr,*prev;
    curr= head; 
    prev=NULL;
    int len=list_len(head);
    
    if(index>0 && index<len){ 
        int i =0;
        while(i<index){ 
            prev=curr; 
            curr=curr->flink; 
            i++;
        }
        
        prev->flink=newNode; //n2->nexwNode
        newNode->flink=curr; // n2->newNode->n3
        return newNode;
    }else{
        return NULL;
    }
}

void print_list(Node *head){
    Node* temp=head;
    while(temp->flink!=NULL){
        printf("|%d|->", temp->data);
        temp = temp->flink;
    }
    printf("|%d|",temp->data);
}

int list_len(Node *head){
    Node *temp = head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp = temp->flink;
    }
    return len;
}

Node* sort(Node **head, bool reverse){
    Node *temp_head = *head;
    Node *temp, *curr, *prev, *prev2;
    
    int i=0, len = list_len(*head);
       while(i<len-1){
        curr = (*head)->flink; 
        prev = *head; 
        prev2=temp=NULL; 
        
        while(curr!=NULL){
         if(curr->data<prev->data && reverse == false){
            
            prev->flink = curr->flink; 
            curr->flink = prev; 
            if(prev2==NULL ){
                *head=curr; 
            }else{
                prev2->flink = curr;
            }
            
            temp = curr; 
            curr = prev; 
            prev = temp; 
            
         }else if(curr->data>prev->data && reverse==true){
            prev->flink = curr->flink; 
            curr->flink = prev; 
            if(prev2==NULL ){
                *head=curr; 
            }else{
                prev2->flink = curr;
            }
            
            temp = curr; 
            curr = prev; 
            prev = temp; 
         }
         prev2 = prev; 
         prev = curr; 
         curr = curr->flink; 
        }
        i++;
    }
    return *head;
}

int main(int argc, char *argv) {
    Node *head, *temp;
    head = temp =NULL;
    temp = create_node(10);
    
    insert_at_front(&head,temp);
    // insert_at_front(&head, create_node(10));
    // for(int i = 0; i<5; i++){
    //     insert_at_end(head, create_node(9-i));
    // }
    insert_at_end(head, create_node(7));
    insert_at_end(head, create_node(70));
    insert_at_end(head, create_node(5));
    insert_in_middle(head,create_node(100), 2);
    sort(&head, true);
    
    print_list(head);
    
}















