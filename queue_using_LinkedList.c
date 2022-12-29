// queue using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*front,*rear,*newnode;
// to insert in queue
void q_insert(int value){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(front== NULL){
        front=rear=newnode;
        return;
    }
    else{
        rear->next=newnode;
        rear=rear->next;
    }
}
// to delete from queue
void q_delete(){
    if(front==NULL){
        printf("\nQUEUE IS EMPTY\n");
        return;
    }
    else{
        struct node *ptr;
        ptr=front;
        front=front->next;
        printf("\nDELETED ELEMENT : %d\n",ptr->data);
        free(ptr);
    }
}
// to display the elements
void display(){
    if(front==NULL){
        printf("\nQUEUE IS EMPTY\n\n");
        return;
    }
    else{
        struct node *ptr;
        ptr=front;
        printf("\n");
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
    }
}
int main(){
    front =rear=NULL;
    int value,choice,n;
    while(1){
        printf("\n\n/**--------MAIN MENU-------**/\n\n");
        printf("ENTER  1. To insert element in queue\n");
        printf("2. To delete element from queue\n");
        printf("3. To display all elements of queue\n");
        printf("4. Exit\n"); 
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\nEnter no of elemets to be inserted:");
            scanf("%d",&n);
            printf("\nEnter values:\n");
            for(int i=0;i<n;i++){
                scanf("%d",&value);
                q_insert(value);
            }
            break;
            case 2:q_delete();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            default:printf("\nEnter valid choice\n");
        }
    }
}