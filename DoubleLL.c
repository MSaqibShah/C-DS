// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *flink;
    struct node *blink;
};

typedef struct node* NODE;

// Function prototypes
NODE create_node_double();
NODE create_node_with_data_double(int data);
NODE create_list_double();
void display_list_double(NODE HEAD);
NODE append_to_list_double(NODE HEAD, int DATA);
NODE insert_into_list_double(NODE HEAD, int POS, int DATA);
NODE update_data_in_list_double(NODE HEAD, int POS, int data);
NODE delete_node_from_list_double(NODE HEAD, int POS);
int length_of_list_double(NODE HEAD);
int get_node_by_pos_double(NODE HEAD, int POS, NODE* currentNode);

// =================== CREATE =================== 
// Create a node 
NODE create_node_double(){
    NODE newNode;
    int data;
    newNode = (NODE)malloc(sizeof(NODE));

    printf("\nEnter the Data for the node: ");
    scanf("%d", &data);
    
    newNode -> data = data;
    newNode->flink = NULL;
    newNode->blink = NULL;
    
    printf("\nNode Created Succesfully!");
    return newNode;
}

NODE create_node_with_data_double(int data){
    NODE newNode;
    newNode = (NODE)malloc(sizeof(NODE));
    newNode -> data = data;
    newNode->flink = NULL;
    newNode->flink = NULL;
    printf("\nNode Created Succesfully!");
    return newNode;
}

// Create a List
NODE create_list_double(){
    printf("\n++++++++++++++++++++++++++++++++");
    printf("\nCreating a doubly linked list...");
    // printf("\n++++++++++++++++++++++++++++++++");
    
    int N;
    NODE head, newNode, next;
    
    printf("\nEnter number of nodes in the list: ");
    scanf("%d", &N);
    
    if(N == 0){
        return NULL;
    }
    
    
    head = create_node_double();
    next = head;
    for(int i = 0; i<N-1; i++){
        newNode = create_node_double();
        next -> flink = newNode;
        newNode -> blink = next;
        next = next-> flink;
    }
    printf("\nList Created Succesfully!");
    display_list_double(head);
    printf("\n++++++++++++++++++++++++++++++++");
    printf("\n");
    
    return head;
}

// =================== READ ===================
void display_list_double(NODE HEAD){
    NODE temp = HEAD;
    printf("\n");
    // printf("=======================================\n");
    while(temp->flink !=NULL){
      printf("|%d| <-> ", temp-> data);
      temp = temp->flink;
  }
  printf("|%d|\n", temp->data);
//   printf("=======================================\n");
  return;
}

// =================== UPDATE ===================

// Append a Node to a list
NODE append_to_list_double(NODE HEAD, int DATA){
    printf("\nAppending...\n");
    
    NODE temp = HEAD, newNode;
    newNode = create_node_with_data_double(DATA);
    while(temp->flink!=NULL){
        temp= temp->flink;
    }
    temp->flink = newNode;
    
    printf("Node Appended Succesfully!\n");
    display_list_double(HEAD);
    return HEAD;
    
}

// Insert a node anywhere on a list i.e front, last, or End
NODE insert_into_list_double(NODE HEAD, int POS, int DATA)
{
    printf("\n++++++++++++++++++++++++++++++++");
    printf("\nTrying to insert...\n");
    int len = length_of_list_double(HEAD);
    NODE currentNode = HEAD, previousNode = HEAD, newNode;
    newNode = create_node_with_data_double(DATA);
    int status = get_node_by_pos_double(HEAD, POS, &currentNode);
    
    if(status==401 || status==402 || status==403){
        // Empty list or POS is less than 1 or POS > len+1
        printf("\nInsersion Failed");
    }else if(status==201){
        // Node is the first Node in the list
        newNode->flink = currentNode;
        currentNode->blink = newNode;
        HEAD = newNode;
        printf("\nNode Inserted Succesfully!");
        display_list_double(HEAD);
    }else if(status==202){
        // POS is the next POS to last node i.e appending
        currentNode->flink = newNode;
        newNode->blink = currentNode;
        printf("\nNode Appended!");
        display_list_double(HEAD);
    }else{
        previousNode = currentNode->blink;
        
        previousNode->flink = newNode;
        newNode->blink = previousNode;
        
        newNode->flink = currentNode;
        currentNode->blink = newNode;
        
        printf("\nNode Inserted Succesfully!");
        display_list_double(HEAD);
    }
printf("\n++++++++++++++++++++++++++++++++");
printf("\n");
return HEAD;
}

// NODE update_data_in_list_double(NODE HEAD, int POS, int data){
//     printf("\n++++++++++++++++++++++++++++++++");
//     printf("\nTrying to update data...\n");
//     // int len = lengthOfList(HEAD);
//     NODE currentNode = HEAD, previousNode = HEAD, newNode;
//     int status = get_node_by_pos_double(HEAD, POS, &currentNode, &previousNode);

//     if (status==200 || status==201){
//         // POS == 1
//         currentNode->data = data;
//         printf("\nNode Updated Succesfully!");
//         display_list_double(HEAD);
//     }else if(status==202){
//         printf("\nERROR: %d is not a valid position as the list contains only %d elements", POS, POS-1);
//         printf("\nERROR: Update Failed");
//     }
//     else{
//         printf("\nERROR: Update Failed");
//     }
// printf("\n++++++++++++++++++++++++++++++++");
// printf("\n");
// return HEAD;
// }

// // =================== DELETE ===================
// NODE delete_node_from_list_double(NODE HEAD, int POS){
//     printf("\n++++++++++++++++++++++++++++++++");
//     printf("\nTrying to delete node...\n");
//     // int len = lengthOfList(HEAD);
//     NODE currentNode = HEAD, previousNode = HEAD, deletedNode;
//     int status = get_node_by_pos_double(HEAD, POS, &currentNode, &previousNode);

//     if (status==200){
//         deletedNode =currentNode;
//         previousNode-> flink = currentNode->flink;
//         printf("Deleted %d", deletedNode->data);
//         printf("\nNode Deleted Succesfully!");
//         deletedNode->flink = NULL;
//         free(deletedNode);
//         display_list_double(HEAD);
//     }else if(status == 201){
//         deletedNode =currentNode;
//         HEAD= HEAD->flink;
//         printf("Deleted %d", deletedNode->data);
//         printf("\nNode Deleted Succesfully!");
//         deletedNode->flink = NULL;
//         free(deletedNode);
//         display_list_double(HEAD); 
//     }
//     else if(status==202){
//         printf("\nERROR: %d is not a valid position as the list contains only %d elements", POS, POS-1);
//         printf("\nERROR: Delete Failed");
//     }
//     else{
//         printf("\nERROR: Delete Failed");
//     }
// printf("\n++++++++++++++++++++++++++++++++");
// printf("\n");
// return HEAD;
// }



// Auxallay Functions
int length_of_list_double(NODE HEAD){
    NODE temp=HEAD;
    int length = 0;

    while(temp!=NULL){
        length++;
        temp = temp->flink ;
    }
    return length;
}


int get_node_by_pos_double(NODE HEAD, int POS, NODE* currentNode){
    int status, len;
    
    *currentNode = NULL;
    len = length_of_list_double(HEAD);
    
    if(HEAD == NULL){
        status = 401;
        printf("\nERROR (%d): List is Empty\n", status);
        printf("\nWarning: Returning NULL");
        return status;
    }else if(POS<1){
        status = 402;
        printf("\nERROR (%d): POS cannot be less than 1\n", status);
        printf("\nWarning : Returning NULL");
        return status;
    }else if(POS== 1){
        status = 201;
        printf("\nNOTE (%d):Node is the first node in the list", status);
        printf("\nWarning : Returning first node in the list");
        *currentNode = HEAD;
        return status;
    }
    else if(POS>len && POS != len+1){
      status = 403;
        printf("\nERROR (%d): %d is not a valid position as the list contains only %d elements", status,POS, len);
        printf("\nWarning : Returning NULL");
        return status;  
    }else if(POS == len+1){
        status = 202;
        printf("\nWarning (%d): %d is not a valid position as the list contains only %d elements.", status,POS, len);
        printf("\nWarning : Returning last node in the list");
         *currentNode =HEAD;
         int i = 1;
         while(i<POS-1){
            *currentNode = (*currentNode)->flink;
            i++;
        }
        return status;
    }else{
        status = 200;
        printf("\nNote : Returning node");
         *currentNode =HEAD;
         int i = 1;
         while(i<POS){
            *currentNode = (*currentNode)->flink;
            i++;
        }
        return status;
    }
    
    
}

int main() {
    NODE temp, temp2;
    
    // temp = create_node_with_data_double(5);
    // temp2 = create_node_with_data_double(10);
    // temp->flink = temp2;
    // temp2->blink = temp;
    // printf("%d", temp2->blink->data);
    
    NODE doubleList = create_list_double();
    
    // doubleList = append_to_list_double(doubleList, 5);
    
     doubleList = insert_into_list_double(doubleList, 6, 5);
    
    // doubleList = update_data_in_list_double(doubleList, 3, 1000);
    
    // doubleList = delete_node_from_list_double(doubleList, 3);
    
    // int len = length_of_list_double(doubleList);
    // printf("Length of list is: %d \n", len);
    
    // int status = get_node_by_pos_double(doubleList, 3, &temp);
    // printf("Status: %d\n", status);
    // printf("|%d|\n", temp->data);
     
}





