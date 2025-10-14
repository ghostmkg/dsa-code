#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
	struct node *prev;
    struct node *next;
};

void create(struct node **head,struct node **ftail);
void display(struct node *head);
void insert_at_beg(struct node **fhead);
void insert_at_end(struct node **fhead,struct node **ftail);
void insert_by_pos(struct node **fhead, struct node **tail);
void delete_at_beg(struct node **fhead);
void delete_at_end(struct node **ftail);
void delete_by_pos(struct node **fhead);
void reverse(struct node **fhead,struct node **ftail);

int menu() 
{
    int choice;
    do 
	{
        printf("\n\nTHE MENU IS : ");
        printf("\n1. Create ");
        printf("\n2. Display");
        printf("\n3. Insert at beg");
        printf("\n4. Insert at end");
        printf("\n5. Insert by position");
        printf("\n6. Delete at beg");
        printf("\n7. Delete at end");
        printf("\n8. Delete by position");
        printf("\n9.Reverse the linked list");
        printf("\n0. Invalid Choice");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
    } while (choice < 0 || choice >9); 

    return choice;
}

int main() 
{
    struct node *head = NULL;
    struct node *tail = NULL;

    int ch;
    do 
	{
        ch = menu(); 
        switch (ch) 
		{
            case 1:
                create(&head, &tail);
                break;
            case 2:
                display(head);
                break;
            case 3:
                insert_at_beg(&head);
                display(head);
                break;
            case 4:
                insert_at_end(&head,&tail);
                display(head);
                break;
            case 5:
                insert_by_pos(&head, &tail);
                display(head);
                break;
            case 6:
                delete_at_beg(&head);
                display(head);
                break;
            case 7:
                delete_at_end(&tail);
                display(head);
                break;
            case 8:
                delete_by_pos(&head);
                display(head);
                break;
            case 9:
            	reverse(&head,&tail);
            	display(head);
            	break;
            case 0:
                printf("\nInvalid choice\n");
                break;
        }
    } while (ch != 0); 

    return 0;
}

void create(struct node **head,struct node **tail)
{
	struct node *newnode  =NULL;
	struct node *temp  =NULL;
	char ch = '\0';
	do 
	{
        newnode = (struct node*)calloc(1, sizeof(struct node));
        printf("\nEnter the data: ");
        scanf("%d", &newnode->data);
        newnode -> prev = NULL;
        newnode -> next = NULL;
        if(*head == NULL)
        {
        	temp = newnode;
        	*head = temp;
        	*tail = newnode;
		}
		else
		{
			temp -> next = newnode;
			newnode->prev = temp;
			temp = newnode;
			*tail = newnode;
		}
        printf("Do you want to add more nodes (Y/N): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');	
}

void display(struct node *head)
{
	struct node* i = NULL;
    printf("\nThe Linked List is: ");
    for (i = head; i != NULL; i = i->next) 
	{
        printf("%d\t", i->data);
    }
    printf("\n");
}

void insert_at_beg(struct node **fhead)
{
	struct node *newnode  = NULL;
	struct node *temp  =NULL;
	struct node *head = NULL;
	head = *fhead;
	newnode = (struct node*)calloc(1,sizeof(struct node));
	printf("\nEnter the data to insert at beg: ");
	scanf("%d", &newnode->data);

	newnode -> prev = NULL;
	newnode -> next = NULL;
	head ->  prev = newnode;
	newnode -> next = head ;
	head = newnode;
	*fhead = head ;
	printf("\nThe Insertion at beg Successful !!");
}
void insert_at_end(struct node **fhead,struct node **ftail)
{
	struct node *newnode  = NULL;
	struct node *head = NULL;
	head = *fhead;
	struct node *tail = NULL;
	tail = *ftail;

	newnode = (struct node*)calloc(1,sizeof(struct node));
	printf("\nEnter the data to insert at end ");
	scanf("%d", &newnode->data);
	newnode -> prev = NULL;
	newnode -> next = NULL;
	tail -> next = newnode;
	newnode -> prev = tail;
	tail = newnode;
	*fhead = head ;
	*ftail = tail ;
	printf("\nThe Insertion at end Successful !!");
}

void insert_by_pos(struct node **fhead, struct node **ftail)
{
	struct node *newnode  = NULL;
	struct node *head = NULL;
	struct node *temp = NULL;
	head = *fhead;
	struct node *tail = NULL;
	tail = *ftail;
	int pos = 0, 
	cnt = 1;
	printf("\nEnter the position: ");
    scanf("%d", &pos);
    
	newnode = (struct node*)calloc(1,sizeof(struct node));
	printf("\nEnter the data to insert at end ");
	scanf("%d", &newnode->data);
	
	temp = head;
	while(cnt < pos - 1)
	{
		temp = temp -> next;
		cnt++;
	}
	newnode -> prev = temp;
	newnode -> next = temp -> next;
	temp -> next = newnode;
	newnode -> next -> prev = newnode;
	*fhead = head ;
	*ftail = tail ;
	printf("\nThe Insertion by pos Successful !!");
}

void delete_at_beg(struct node **fhead) 
{
    struct node *head = *fhead;
    if (head != NULL) 
	{
        *fhead = head ->next; 
        free(head); 
        printf("\n\nDeletion performed at beginning.");
    } 
	else 
	{
        printf("\n\nList is empty");
    }
}

void delete_at_end(struct node **ftail) 
{
    struct node *tail = *ftail;
    tail = *ftail;
    struct node *temp = NULL;

	if(tail == NULL)
	{
		printf("List is Empty.");
	}
	else
	{
		temp = tail;
		tail -> prev -> next = NULL;
		tail = tail -> prev;
		free(temp);
	}
    printf("\n\nDeletion performed at end.");
    *ftail = tail;
}

void delete_by_pos(struct node **fhead) 
{
    struct node *head = *fhead;
    struct node *temp = NULL;
    temp = head;
    int pos = 0,
	cnt = 1;

    printf("\n\nEnter the position: ");
    scanf("%d", &pos);
    if (pos < 1) 
	{
        printf("Invalid position!\n");
    }

    while (cnt < pos) 
	{
        temp = temp->next;
        cnt++;
    }
	temp -> prev -> next = temp -> next;
	temp -> next -> prev = temp -> prev;
	free(temp);
    printf("\n\nDeletion performed at position %d.", pos);
}

