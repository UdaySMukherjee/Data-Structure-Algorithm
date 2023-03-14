// create and display a linked list it should be menu driven
#include<stdio.h>
struct node
    {
        int data;
        struct node *next;
    };
    struct node *head=NULL;
    struct node *current=NULL;

    void print(){
        struct node *ptr=head;
        printf("\n [head] => ");
        while(ptr!= NULL){
            printf("%d =>", ptr->data);
            ptr=ptr -> next;
        }
        printf("[NULL] \n");
    }

void insert(int data){
    struct node *link=(struct node*)malloc(sizeof(struct node));
    link->data=data;
    link->next=head;
    head=link;
}

int main(){
    printf("PRESS 0 to EXIT\n");
    printf("PRESS 1 to INSERT\n");
    printf("PRESS 2 TO DISPLAY\n");
    int c,ch;
    do{
    printf("ENTER YOUR CHOICE :");
    scanf("%d",&ch);
    switch(ch){
        case 0:
        	break;
        case 1:
        	printf("ENTER VALUE TO INSERT :");
            int val;
            scanf("%d",&val);
            insert(val);
        case 2:
            print();
        default:
            printf("WRONG CHOICE");
            break;
    }
    printf("PRESS 0 TO EXIT OR 3 TO CONTINUE: ");
    scanf("%d",&c);
} while(c==3);

    return 0;
}
