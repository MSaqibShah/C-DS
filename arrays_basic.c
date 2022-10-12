// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

# define SIZE 5

int main(int argc, char *argv) {
    // Arrays
    // 1.Fixed Size
    
    //   a: Size defined in code 
    int arr1[15];
    int arr2[] = {1,2,3};
    int arr3[SIZE];
    
    //   b: Size defined at runtime using a variable
    int size;
    scanf("%d", &size);
    int arr4[size];
    int arr5[argc];
    
    // 2.Dynamic Size using pointers
   
    //   a: Using malloc, realloc and free
    //   Note: malloc doesn't initialize to anything
    int *arr6 = (int *)malloc(sizeof(int)*5); // array pointer of size = 5
    arr6 = (int *)realloc(arr6,sizeof(int)*10); // Changing size during execution
    free(arr6); // Deallocating arr6 after using it to release the memory back to the heap
    
    //   a: Using calloc, realloc and free
    //   Note: calloc initializes to 0
    int *arr7 = (int *)calloc(sizeof(int),5);// array pointer of size = 5
    arr7 = (int *)realloc(arr7, sizeof(int)*10);// Changing size during execution
    free(arr7); // Deallocating arr6 after using it to release the memory back to the heap
    
}