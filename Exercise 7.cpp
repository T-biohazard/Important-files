#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * preptr;
    struct node * nextptr;
}*head, *ennode;


void DlListcreation(int n);
void DlListDeleteFirhead();
void DlListDeleteLahead();
void DlListDeleteAnyNode(int pos);
void displayDlList(int a);

int main()
{
    int n,num1,a,insPlc;
    head = NULL;
    ennode = NULL;
	printf("\n\n Doubly Linked List : Delete node from any position of a doubly linked list :\n");
	printf("----------------------------------------------------------------------------------\n");
    printf(" Input the number of nodes (3 or more ): ");
    scanf("%d", &n);
    DlListcreation(n);
    a=1;
    displayDlList(a);
    printf(" Input the position ( 1 to %d ) to delete a node : ",n);
    scanf("%d", &insPlc);


if(insPlc<1 || insPlc>n)
    {
     printf("\n Invalid position. Try again.\n ");
    }
	      if(insPlc>=1 && insPlc<=n)
      {

    DlListDeleteAnyNode(insPlc);
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

void DlListDeleteAnyNode(int pos)
{
    struct node *curNode;
    int i;

    curNode = head;
    for(i=1; i<pos && curNode!=NULL; i++)
    {
        curNode = curNode->nextptr;
    }

    if(pos == 1)
    {
        DlListDeleteFirhead();
    }
    else if(curNode == ennode)
    {
        DlListDeleteLahead();
    }
    else if(curNode != NULL)
    {
        curNode->preptr->nextptr = curNode->nextptr;
        curNode->nextptr->preptr = curNode->preptr;

        free(curNode); //Delete the n node
    }
    else
    {
        printf(" The given position is invalid!\n");
    }
}

void DlListDeleteFirhead()
{
    struct node * NodeToDel;
    if(head == NULL)
    {
        printf(" Delete is not possible. No data in the list.\n");
    }
    else
    {
        NodeToDel = head;
        head = head->nextptr;   // move the next address of starting node to 2 node
        head->preptr = NULL;      // set previous address of staring node is NULL
        free(NodeToDel);            // delete the first node from memory
    }
}

void DlListDeleteLahead()
{
    struct node * NodeToDel;

    if(ennode == NULL)
    {
        printf(" Delete is not possible. No data in the list.\n");
    }
    else
    {
        NodeToDel = ennode;
        ennode = ennode->preptr;    // move the previous address of the last node to 2nd last node
        ennode->nextptr = NULL;     // set the next address of last node to NULL
        free(NodeToDel);            // delete the last node
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
         printf("\n After deletion the new list are :\n");
        }
        while(tmp != NULL)
        {
            printf(" node %d : %d\n", n, tmp->num);
            n++;
            tmp = tmp->nextptr; // current pointer moves to the next node
        }
    }
}
