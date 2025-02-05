#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * preptr;
    struct node * nextptr;
}*head, *ennode;


void DlListcreation(int n);
void DlLinsertNodeAtBeginning(int num);
void displayDlList(int a);

int main()
{
    int n,num1,a;
    head = NULL;
    ennode = NULL;
	printf("\n\n Doubly Linked List : Insert new node at the beginning in a doubly linked list :\n");
	printf("------------------------------------------------------------------------------------\n");

    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    DlListcreation(n);
    a=1;
    displayDlList(a);
    printf(" Input data for the first node : ");
    scanf("%d", &num1);
    DlLinsertNodeAtBeginning(num1);
    a=2;
    displayDlList(a);
    return 0;
}

void DlListcreation(int n)
{
    int i, num;
    struct node *fnNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        if(head != NULL)
        {
            printf(" Input data for node 1 : "); // assigning data in the first node
            scanf("%d", &num);

            head->num = num;
            head->preptr = NULL;
            head->nextptr = NULL;
            ennode = head;
            for(i=2; i<=n; i++)
            {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode != NULL)
                {
                    printf(" Input data for node %d : ", i);
                    scanf("%d", &num);
                    fnNode->num = num;
                    fnNode->preptr = ennode;    // new node is linking with the previous node
                    fnNode->nextptr = NULL;

                    ennode->nextptr = fnNode;   // previous node is linking with the new node
                    ennode = fnNode;            // assign new node as last node
                }
                else
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf(" Memory can not be allocated.");
        }
    }
}

void DlLinsertNodeAtBeginning(int num)
{
    struct node * newnode;
    if(head == NULL)
    {
        printf(" No data found in the list!\n");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->num = num;
        newnode->nextptr = head;  // next address of new node is linking with starting node
        newnode->preptr = NULL;     // set previous address field of new node is NULL
        head->preptr = newnode;   // previous address of starting node is linking with new node
        head = newnode;           // set the new node as starting node
    }
}

void displayDlList(int m)
{
    struct node * tmp;
    int n = 1;
    if(head == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = head;
        if (m==1)
        {
        printf("\n Data entered in the list are :\n");
        }
        else
        {
         printf("\n After insertion the new list are :\n");
        }
        while(tmp != NULL)
        {
            printf(" node %d : %d\n", n, tmp->num);
            n++;
            tmp = tmp->nextptr; // current pointer moves to the next node
        }
    }
}
