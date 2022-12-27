#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*start,*newnode;
// create circular linked list
void create(int value){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(start==NULL){
        start=newnode;
        newnode->next=start;
    }
    else{
        struct node *ptr;
        ptr=start;
        while(ptr->next!=start){
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=start;
    }
}
// insert at beginning
void begin_insert(int value){
    newnode=(struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=start;
    newnode->data=value;
    start=newnode;
}
// to insert at the end
void last_insert(int value){
    newnode=(struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=start;
    newnode->data=value;
}
// to insert at particular position
void particular_insert(int value,int pos){
    newnode=(struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    ptr=start;
    if(pos==1){
        begin_insert(value);
    }
    else{
        for(int i=1;i<pos-1;i++){
            ptr=ptr->next;
            if(ptr==start){
                printf("\nThere are less than %d elements in the list\n",pos);
                return;
            }
        }
        newnode->next=ptr->next;
        ptr->next=newnode;
        newnode->data=value;   
    } 
}
// to display elements
void display(){
    if(start==NULL){
        printf("\nEmpty list\n\n");
    }
    else{
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){          
        printf("\n%d",ptr->data);
        ptr=ptr->next; 
    }
    printf("\n%d",ptr->data);
    }
}
// to count no of nodes
void count(){
    struct node *ptr;
    int count=0;
    ptr=start;
    do{
        if(ptr!=NULL){
        count++;
        ptr=ptr->next;
        }
    }while(ptr!=start);
    printf("\nNumber of nodes=%d\n",count);
}
// to reverse the list
void reverse(){
    if(start==NULL){
        printf("\nEmpty list\n\n");
    }
    else{
    struct node *ptr,*ptr1,*temp;
    ptr=ptr1=start;
    do{
        temp=ptr1;
        ptr1=ptr;
        ptr=ptr->next;
        ptr1->next=temp; 
    }while(ptr!=start);
    start=start->next=ptr1;            // also start=ptr->next=ptr1
    }
}
// to delete element from beginning
void begin_delete(){
    if(start==NULL){
        printf("\nEmpty list\n");
        return;
    }
    struct node *ptr,*ptr1;
    ptr=ptr1=start;
    if(ptr->next==ptr){
        start=NULL;
        free(ptr);
        return;
    }
    while(ptr1->next!=start){
        ptr1=ptr1->next;
    }
    start=ptr->next;
    ptr1->next=ptr->next;
    free(ptr);
}
// to delete element from the last
void last_delete(){
    if(start==NULL){
        printf("\nEmpty list\n");
        return;
    }
    struct node *ptr,*ptr1;
    ptr=start;
    if(ptr->next==ptr){
        start=NULL;
        free(ptr);
        return;
    }
    while(ptr->next!=start){
        ptr1=ptr;
        ptr=ptr->next;
    }
    ptr1->next=start;         // here ptr1->next=ptr->next can be also done as ptr->next=start
    free(ptr);
}
// to delete element from particular position
void particular_delete(int pos){
    if(start==NULL){
        printf("\nEmpty list\n");
        return;
    }
    struct node *ptr,*ptr1;
    if(pos==1){
        begin_delete();
    }
    else{
        ptr=start;
        for(int i=1;i<pos;i++){
            ptr1=ptr;
            ptr=ptr->next;
            if(ptr==start){
                printf("\nThere are less than %d elements in the list\n",pos);
                return;
            }
        }
        ptr1->next=ptr->next;
        free(ptr);
    }
}
int main(){
    int value,choice,pos;
    start=NULL;         //initially consider list is empty
    while(1){
        printf("\n\n/**--------MAIN MENU-------**/\n\n");
        printf("ENTER  1. To create a list\n");
        printf("2. To insert element at begin\n");
        printf("3. To insert element at last\n");
        printf("4. To insert element at a particular position\n");
        printf("5. To delete element fron beginning\n"); 
        printf("6. To delete element fron last\n");  
        printf("7. To delete element at a particular position\n");
        printf("8. To count number of nodes\n"); 
        printf("9. To display elements\n");  
        printf("10. To reverse list \n");  
        printf("11. To exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nEnter the value:");
            scanf("%d",&value);
            create(value);
            display();
            break;
            case 2:if(start==NULL){
                printf("\nEmpty list  First create the list(by enter choice 1)");
                }
            else{
            printf("\nEnter the value add to beginning:");
            scanf("%d",&value);
            begin_insert(value);
            display();
            }
            break;
            case 3:if(start==NULL){
                printf("\nEmpty list  First create the list(by enter choice 1)");
                }
            else{
            printf("\nEnter the value add to last:");
            scanf("%d",&value);
            last_insert(value);
            display();
            }
            break;
            case 4:if(start==NULL){
                printf("\nEmpty list  First create the list(by enter choice 1)");
                }
            else{
            printf("\nEnter the position at which you want to add element:");
            scanf("%d",&pos);
            printf("\nEnter the value add after a node:");
            scanf("%d",&value);
            particular_insert(value,pos);
            display();
            }
            break;
            case 5:begin_delete();
            display();
            break;
            case 6:last_delete();
            display();
            break;
            case 7:printf("\nEnter the position at which you want to delete element:");
            scanf("%d",&pos);
            particular_delete(pos);
            display();
            break;
            case 8:count();
            break;
            case 9:display();
            break;
            case 10:reverse();
            display();
            break;
            case 11:exit(0);
            default:printf("\nEnter valid choice\n");
        }    
    }
}