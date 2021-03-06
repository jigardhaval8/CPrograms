// To run - Compile gcc <filename>.c and then ./<obj file name>.out
// e.x. gcc ll.c;./a.out
#include <stdio.h>
#include <stdlib.h>
struct node {
    unsigned int data;
    struct node *link;    
};

// It will print Singly Link List // JJSONI
void printncountlinklist(struct node *headpt, char operation)
{
    struct node *traverse;
    traverse = headpt;
    unsigned int no_of_element=0;


        if(traverse==NULL)
        {
            printf(" Link List is empty!\n\n");
        }
        else if(traverse->link==NULL)
        {
            printf(" This Link List has single node only!\n\n");
            printf("[ %d ]->|*END*|\n",traverse->data);
            no_of_element++;
        }
        else
        {
            while(traverse->link!=NULL)
            {
                printf("[ %d ]->",traverse->data);
                traverse = traverse->link;
                no_of_element++;
            }
            printf("[ %d ]->|*END*|\n",traverse->data);
            no_of_element++;
        }
    if(operation==1)
    {
        printf("| # of Elements : %d\n", no_of_element);
    }
}
// It will add node at the end of link list
void addNodeAtEnd(struct node *headpt, unsigned int value)
{
    struct node *traverse, *prev, *current;
    traverse = headpt;
    while(traverse->link!=NULL)
    {
        traverse = traverse->link;
    }
    prev = traverse;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = value;
    current->link = NULL;
    prev->link=current;
}
void deleteNodeAtEnd(struct node *headptr)
{
    struct node *traverse, *newtail;
    traverse = headptr;
    while(traverse->link!=NULL)
    {
        newtail = traverse;
        traverse = traverse->link;
    }

    newtail->link = NULL;
    free(traverse);
    traverse = NULL;
}
// It will add node at the N th location in link list and rest of list will be shifted, it doesnt have safety check
void addNodeAtNthlocation(unsigned int location, struct node *headpt, unsigned int value)
{
    struct node *traverse, *prev, *current, *next;
    traverse = headpt;
    for(unsigned int i=0; i<location-1; i++)
    {
        traverse = traverse->link;
    }
    prev = traverse;
    next = traverse->link;

    current = (struct node*)malloc(sizeof(struct node));
    current->data = value;

    prev->link=current;
    current->link = next;
}
void deleteNodeAtNthLocation(unsigned int location, struct node *headpt)
{
    struct node *traverse, *prev, *current, *next;
    traverse = headpt;    
    for(unsigned int i=0; i<location; i++)
    {
        prev = traverse;
        traverse = traverse->link;
    }
    // printf("%d",traverse->data);
    // printf("%d",prev->data);
    prev->link = traverse->link;
    free(traverse);
    traverse=NULL;
}
void printcircularLL(struct node *tailptr, char operation)
{
    struct node *traverse;
    traverse = tailptr;
    unsigned int count=0;
    printf("TAIL");
    while(traverse->link!=tailptr)
    {
        printf("| %d  ->",traverse->data);
        traverse = traverse->link;
        count++;
    }
    printf("| %d ->->(%d) \n",traverse->data, traverse->link->data);
    count++;

    if(operation==1)
    {
        printf("| # of Elements : %d\n", count);
    }

}

void addnodeatTailCircularLL(struct node **tailptr, unsigned int ipdata)
{
    struct node *traverse, *next;
    traverse = *tailptr;
    next = traverse->link;
    struct node *new=malloc(sizeof(struct node *));
    new->data=ipdata;
    new->link=next;
    traverse->link=new;
    *tailptr=new;
}

void addnodeatBegCircularLL(struct node **tailptr, unsigned int ipdata)
{
    struct node *traverse, *next;
    traverse = *tailptr;
    next = traverse->link;
    struct node *new=malloc(sizeof(struct node *));
    new->data=ipdata;
    new->link=next;
    traverse->link=new;
}

void deleteTailNodeCircularLL(struct node **tailptr)
{
    struct node *traverse, *next, *prev;
    traverse = *tailptr;
    prev = traverse;
    next = traverse->link;
    *tailptr = next;
    while(prev->link!=traverse)
    {
        prev = prev->link;
    }
    prev->link = next;
    free(traverse);
    traverse=NULL;
}

void deleteFirstNodeCircularLL(struct node **tailptr)
{
    struct node *traverse, *next, *next2;
    traverse = *tailptr;
    next2 = traverse->link->link;
    next = traverse->link;

    traverse->link=next2;
    free(next);
    next=NULL;
}

// It will add node at the beginning of link list, and will return new head as return value
struct node* addNodeAtHead(struct node *headptr, unsigned int value)
{
    struct node *traverse, *prev, *current;
    traverse = headptr;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = value;
    current->link = traverse;
    headptr = current;
    return headptr;
}

// It will add node at beginning of link list and will update Head
void addNodeAtHead2(struct node **headptr, unsigned int value)
{
    struct node *traverse, *prev, *current;
    traverse = *headptr;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = value;
    current->link = traverse;
    *headptr = current;
}
void deleteNodeAtHead2(struct node **headptr)
{
    struct node *traverse, *newhead;
    traverse = *headptr;
    newhead = traverse->link;
    *headptr = newhead;
    free(traverse);
    traverse=NULL;
}

void deletefullList(struct node **headptr)
{
    struct node *traverse;
    traverse = *headptr;
    while(traverse!=NULL)
    {
        traverse = traverse->link;
        free(traverse);
        *headptr = traverse;
    }
    *headptr=NULL;
}

void reverseLL(struct node **headptr)
{
    struct node *newhead,*ptrL,*ptrR;
    newhead = *headptr;
    ptrR = newhead;
    ptrL = NULL;
    while(newhead->link!=NULL)
    {
        ptrR = newhead->link;
        newhead->link = ptrL;
        ptrL=newhead;
        newhead = ptrR;
    }
        newhead->link = ptrL;
        ptrL=newhead;

    *headptr = ptrL;

}

int main()
    {
        struct node *headptr=(struct node*)malloc(sizeof(struct node));
        headptr->data = 99;
        headptr->link = NULL;

        struct node *circularlltail=(struct node*)malloc(sizeof(struct node));
        circularlltail->data = 77;
        circularlltail->link = circularlltail;

        printcircularLL(circularlltail,1);
        addnodeatTailCircularLL(&circularlltail, 54);
        printcircularLL(circularlltail,1);

        addnodeatTailCircularLL(&circularlltail, 4);

        printcircularLL(circularlltail,1);
        addnodeatBegCircularLL(&circularlltail, 99);
        addnodeatBegCircularLL(&circularlltail, 97);

        // addnodeatTailCircularLL(&circularlltail, 45);
        // addnodeatTailCircularLL(&circularlltail, 11);

        printcircularLL(circularlltail,1);
        deleteTailNodeCircularLL(&circularlltail);
        printcircularLL(circularlltail,1);
        deleteFirstNodeCircularLL(&circularlltail);
        printcircularLL(circularlltail,1);
        deleteFirstNodeCircularLL(&circularlltail);
        printcircularLL(circularlltail,1);
        deleteFirstNodeCircularLL(&circularlltail);
        printcircularLL(circularlltail,1);

        addNodeAtEnd(headptr, 27);
        addNodeAtEnd(headptr, 85);
        addNodeAtEnd(headptr, 77);
        addNodeAtEnd(headptr, 7);

        printncountlinklist(headptr,1);
        headptr = addNodeAtHead(headptr, 57);
        headptr = addNodeAtHead(headptr, 17);
        headptr = addNodeAtHead(headptr, 75);
        printncountlinklist(headptr,1);
        addNodeAtNthlocation(4,headptr,35);
        printncountlinklist(headptr,1);
        addNodeAtNthlocation(1,headptr,11);
        printncountlinklist(headptr,1);
        addNodeAtNthlocation(7,headptr,31);
        printncountlinklist(headptr,1);
        addNodeAtHead2(&headptr,88);
        printncountlinklist(headptr,1);
        deleteNodeAtHead2(&headptr);
        printncountlinklist(headptr,1);
        deleteNodeAtEnd(headptr);
        printncountlinklist(headptr,1);
        deleteNodeAtEnd(headptr);
        printncountlinklist(headptr,1);
        deleteNodeAtEnd(headptr);
        printncountlinklist(headptr,1);
        deleteNodeAtNthLocation(5, headptr);
        printncountlinklist(headptr,1);
        reverseLL(&headptr);
        printncountlinklist(headptr,1);
        reverseLL(&headptr);
        printncountlinklist(headptr,1);

        // deletefullList(&headptr);
        // printncountlinklist(headptr,1);
        return 0;
    }
