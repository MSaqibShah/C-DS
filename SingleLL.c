// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *flink;
};

typedef struct node* NODE;

// Function prototypes
NODE create_node_single();
NODE create_node_with_data_single(int data);
NODE create_list_single();
void display_list_single(NODE HEAD);
NODE append_to_list_single(NODE HEAD, int DATA);
NODE insert_into_list_single(NODE HEAD, int POS, int DATA);
NODE update_data_in_list_single(NODE HEAD, int POS, int data);
NODE delete_node_from_list_single(NODE HEAD, int POS);
int length_of_list_single(NODE HEAD);
int get_node_by_pos_single(NODE HEAD, int POS, NODE* currentNode, NODE* previousNode);

// =================== CREATE =================== 
// Create a node 
NODE create_node_single(){
    NODE newNode;
    int data;
    newNode = (NODE)malloc(sizeof(NODE));

    printf("\nEnter the Data for the node: ");

    scanf("%d", &data);
    newNode -> data = data;
    newNode->flink = NULL;
    printf("\nNode Created Succesfully!");
    return newNode;
}

NODE create_node_with_data_single(int data){
    NODE newNode;
    newNode = (NODE)malloc(sizeof(NODE));
    newNode -> data = data;
    newNode->flink = NULL;
    printf("\nNode Created Succesfully!");
    return newNode;
}

// Create a List
NODE create_list_single(){
    printf("\n++++++++++++++++++++++++++++++++");
    printf("\nCreating a singly linked list...");
    // printf("\n++++++++++++++++++++++++++++++++");
    
    int N;
    NODE head, newNode, next;
    
    printf("\nEnter number of nodes in the list: ");
    scanf("%d", &N);
    
    if(N == 0){
        return NULL;
    }
    
    
    head = create_node_single();
    next = head;
    for(int i = 0; i<N-1; i++){
        newNode = create_node_single();
        next -> flink = newNode;
        next = next-> flink;
    }
    printf("\nList Created Succesfully!");
    display_list_single(head);
    printf("\n++++++++++++++++++++++++++++++++");
    printf("\n");
    
    return head;
}

// =================== READ ===================
void display_list_single(NODE HEAD){
    NODE temp = HEAD;
    printf("\n");
    // printf("=======================================\n");
    while(temp->flink !=NULL){
      printf("|%d| -> ", temp-> data);
      temp = temp->flink;
  }
  printf("|%d|\n", temp->data);
//   printf("=======================================\n");
  return;
}

// =================== UPDATE ===================

// Append a Node to a list
NODE append_to_list_single(NODE HEAD, int DATA){
    printf("\nAppending...\n");
    
    NODE temp = HEAD, newNode;
    newNode = create_node_with_data_single(DATA);
    while(temp->flink!=NULL){
        temp= temp->flink;
    }
    temp->flink = newNode;
    
    printf("Node Appended Succesfully!\n");
    display_list_single(HEAD);
    return HEAD;
    
}

// Insert a node anywhere on a list i.e front, last, or End
NODE insert_into_list_single(NODE HEAD, int POS, int DATA)
{
    printf("\n++++++++++++++++++++++++++++++++");
    printf("\nTrying to insert...\n");
    int len = length_of_list_single(HEAD);
    NODE currentNode = HEAD, previousNode = HEAD, newNode;
    newNode = create_node_with_data_single(DATA);
    int status = get_node_by_pos_single(HEAD, POS, &currentNode, &previousNode);

    if (status==200||202){
        previousNode->flink = newNode;
        newNode->flink = currentNode;
        printf("\nNode Inserted Succesfully!");
        display_list_single(HEAD);
    }else if(status==201){
        newNode->flink = currentNode;
        HEAD = newNode;
        printf("\nNode Inserted Succesfully!");
        display_list_single(HEAD);
    }
    else{
        printf("Insertion Failed");
    }
printf("\n++++++++++++++++++++++++++++++++");
printf("\n");
return HEAD;
}

NODE update_data_in_list_single(NODE HEAD, int POS, int data){
    printf("\n++++++++++++++++++++++++++++++++");
    printf("\nTrying to update data...\n");
    // int len = lengthOfList(HEAD);
    NODE currentNode = HEAD, previousNode = HEAD, newNode;
    int status = get_node_by_pos_single(HEAD, POS, &currentNode, &previousNode);

    if (status==200 || status==201){
        // POS == 1
        currentNode->data = data;
        printf("\nNode Updated Succesfully!");
        display_list_single(HEAD);
    }else if(status==202){
        printf("\nERROR: %d is not a valid position as the list contains only %d elements", POS, POS-1);
        printf("\nERROR: Update Failed");
    }
    else{
        printf("\nERROR: Update Failed");
    }
printf("\n++++++++++++++++++++++++++++++++");
printf("\n");
return HEAD;
}

// =================== DELETE ===================
NODE delete_node_from_list_single(NODE HEAD, int POS){
    printf("\n++++++++++++++++++++++++++++++++");
    printf("\nTrying to delete node...\n");
    // int len = lengthOfList(HEAD);
    NODE currentNode = HEAD, previousNode = HEAD, deletedNode;
    int status = get_node_by_pos_single(HEAD, POS, &currentNode, &previousNode);

    if (status==200){
        deletedNode =currentNode;
        previousNode-> flink = currentNode->flink;
        printf("Deleted %d", deletedNode->data);
        printf("\nNode Deleted Succesfully!");
        deletedNode->flink = NULL;
        free(deletedNode);
        display_list_single(HEAD);
    }else if(status == 201){
        deletedNode =currentNode;
        HEAD= HEAD->flink;
        printf("Deleted %d", deletedNode->data);
        printf("\nNode Deleted Succesfully!");
        deletedNode->flink = NULL;
        free(deletedNode);
        display_list_single(HEAD); 
    }
    else if(status==202){
        printf("\nERROR: %d is not a valid position as the list contains only %d elements", POS, POS-1);
        printf("\nERROR: Delete Failed");
    }
    else{
        printf("\nERROR: Delete Failed");
    }
printf("\n++++++++++++++++++++++++++++++++");
printf("\n");
return HEAD;
}



// Auxallay Functions
int length_of_list_single(NODE HEAD){
    NODE temp=HEAD;
    int length = 0;

    while(temp!=NULL){
        length++;
        temp = temp->flink ;
    }
    return length;
}

int get_node_by_pos_single(NODE HEAD, int POS, NODE* currentNode, NODE* previousNode)
{
    int  status, len;
    *currentNode = *previousNode = HEAD;
    len = length_of_list_single(HEAD);
    
    if (HEAD == NULL)
    {
        // List is Empty
        printf("\nERROR: List is Empty\n");
        status = 401;
        return status;
    }
    else if (POS < 1)
    {
        printf("\nERROR: POS cannot be less than 1\n");
        printf("\t\tValue of POS: %d\n", POS);
        status = 100;
        return status;
    }
    else if (POS > len && POS != len+1)
    {
        printf("\nERROR: %d is not a valid position as the list contains only %d elements", POS, len);
        status = 402;
        return status;
    }
    else
    {
        if (POS == 1)
        {
            *previousNode = NULL;
            status=201;
            return status;
        }
        else if(POS==len+1){
            int i = 1;
            while(i<POS){;
                *previousNode = *currentNode;
                *currentNode = (*currentNode)->flink;
                i++;
            }
            status = 202;
            return status;
        }
        else
        {
            int i = 1;
            while(i<POS){;
                *previousNode = *currentNode;
                *currentNode = (*currentNode)->flink;
                i++;
            }
            status = 200;
            return status;
        }
    }
}

int main() {
    
  NODE singleList = create_list_single();
    int len = length_of_list_single(singleList);
//   singleList = appendToSingleList(singleList);


     singleList = insert_into_list_single(singleList, 3, 5);
    // singleList = update_data_in_list_single(singleList, 3, 1000);
    // singleList = delete_node_from_list_single(singleList, 3);
    
     
}





