#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                    //Data of the node
    struct node *nextptr;       //Address of the node
}*head;

void createNodeList(int n);     //function to create the list
void LaheadDeletion();	    //function to delete the last nodes
void displayList();             //function to display the list

int main()
{
    int n,num,pos;
		printf("\n\n Linked List : Delete the last node of Singly Linked List :\n");
		printf("---------------------------------------------------------------\n");
	
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createNodeList(n);

    printf("\n Data entered in the list are : \n");		
    displayList();
    LaheadDeletion();
	    printf("\n The new list after deletion the last node are  : \n");	
    displayList();
    return 0;
}
void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
 
    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL) //check whether the head is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard
        printf(" Input data for node 1 : ");
        scanf("%d", &num);
 
        head-> num = num;      
        head-> nextptr = NULL; //Links the address field to NULL
        tmp = head;
 
//Creates n nodes and adds to linked list
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL) //check whether the fnnode is NULL and if so no memory allocation
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
                fnNode->num = num;      // links the num field of fnNode with num
                fnNode->nextptr = NULL; // links the address field of fnNode with NULL
                tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->nextptr;
            }
        }
    }
} 
// Deletes the last node of the linked list
void LaheadDeletion()
{
    struct node *toDelLast, *preNode;
    if(head == NULL)
    {
        printf(" There is no element in the list.");
    }
    else
    {
        toDelLast = head;
        preNode = head;
        /* Traverse to the last node of the list*/
        while(toDelLast->nextptr != NULL)
        {
            preNode = toDelLast;
            toDelLast = toDelLast->nextptr;
        }
        if(toDelLast == head)
        {
            head = NULL;
        }
        else
        {

            /* Disconnects the link of second last node with last node */
            preNode->nextptr = NULL;
        }
 
        /* Delete the last node */
        free(toDelLast);
    }
}
// function to display the entire list
void displayList()
{
    struct node *tmp;
    if(head == NULL)
    {
        printf(" No data found in the empty list.");
    }
    else
    {
        tmp = head;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);   // prints the data of current node
            tmp = tmp->nextptr;                 // advances the position of current node
        }
    }
}
