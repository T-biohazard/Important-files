#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * preptr;
    struct node * nextptr;
}*head, *ennode;


void DlListcreation(int n);
void DlLinsertNodeAtMiddle(int num, int pos);
void displayDlList(int a);

int main()
{
    int n,num1,a,insPlc;
    head = NULL;
    ennode = NULL;
	printf("\n\n Doubly Linked List : Insert new node at the middle in a doubly linked list :\n");
	printf("----------------------------------------------------------------------------------\n");
    printf(" Input the number of nodes (3 or more ): ");
    scanf("%d", &n);
    DlListcreation(n);
    a=1;
    displayDlList(a);
    printf(" Input the position ( 2 to %d ) to insert a new node : ",n-1);
    scanf("%d", &insPlc);


if(insPlc<=1 || insPlc>=n)
    {
     printf("\n Invalid position. Try again.\n ");
    }
	      if(insPlc>1 && insPlc<n)
      {
    printf(" Input data for the position %d : ", insPlc);
    scanf("%d", &num1);
    DlLinsertNodeAtMiddle(num1,insPlc);
        a=2;
    displayDlList(a);
      }
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
                    fnNode->nextptr = NULL;     // set next address of fnnode is NULL
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

void DlLinsertNodeAtMiddle(int num, int pos)
{
    int i;
    struct node * newnode, *tmp;
    if(ennode == NULL)
    {
        printf(" No data found in the list!\n");
    }
    else
    {
        tmp = head;
        i=1;
        while(i<pos-1 && tmp!=NULL)
        {
            tmp = tmp->nextptr;
            i++;
        }
        if(tmp!=NULL)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->num = num;
//next address of new node is linking with the next address of temp node
            newnode->nextptr = tmp->nextptr;
// previous address of new node is linking with the tmp node
            newnode->preptr = tmp;
            if(tmp->nextptr != NULL)
            {
                tmp->nextptr->preptr = newnode; // n+1th node is linking with new node
            }
            tmp->nextptr = newnode; // n-1th node is linking with new node
        }
        else
        {
            printf(" The position you entered, is invalid.\n");
        }
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
