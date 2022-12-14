#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*start,*newnode;
// create linked list
void create(int value){
    struct node *ptr;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(start==NULL){
        start=newnode;
        newnode->data=value;
        newnode->next=NULL;
    }
    else{
        ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->data=value;
        newnode->next=NULL;
    }
}
// insert at beginning
void begin_insert(int value){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=start;
    newnode->data=value;
    start=newnode;
}
// insert at last
void last_insert(int value){
    newnode=(struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    ptr=start;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=NULL;
    newnode->data=value;
}
// insert after a node
void after_insert(int value,int pos){
    newnode=(struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    ptr=start;
    for(int i=1;i<pos;i++){        //loop will run only for 1 time if pos=2
        ptr=ptr->next;
        if(ptr==NULL){
            printf("\nThere are less than %d elements in the list\n",pos);
            return;
        }
    }
    newnode->next=ptr->next;
    newnode->data=value;
    ptr->next=newnode;

}
// insert at particular position
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
            if(ptr==NULL){
                printf("\nThere are less than %d elements in the list\n",pos);
                return;
            }
        }
        newnode->next=ptr->next;
        newnode->data=value;
        ptr->next=newnode;
    }
}
// to count no of nodes 
void count(){
    struct node *ptr;
    int count=0;
    ptr=start;
    while(ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    printf("\nNumber of Nodes=%d\n",count);
}
// display linked list(display means traverse)
void display(){
    if(start==NULL){
        printf("\nEmpty list\n\n");
    }
    else{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL){          
        printf("\n%d",ptr->data);
        ptr=ptr->next; 
    }
    }
}
// reverse the linked list
void reverse(){
    if(start==NULL){
        printf("\nEmpty list\n\n");
    }
    else{
    struct node *ptr,*ptr1,*temp;
    ptr=start;
    ptr1=NULL;
    while(ptr!=NULL){
        temp=ptr1;
        ptr1=ptr;
        ptr=ptr->next;
        ptr1->next=temp; 
    }
    start=ptr1;
    }
}
// to delete element from beginning
void begin_delete(){
    if(start==NULL){
        printf("\nEmpty list\n");
        return;
    }
    struct node *ptr;
    ptr=start;
    start=ptr->next;
    free(ptr);
}
// to delete element from last
void last_delete(){
    if(start==NULL){
        printf("\nEmpty list\n");
        return;
    }
    struct node *ptr,*ptr1;
    ptr=start;
    if(ptr->next==NULL){
        start=NULL;
        free(ptr);
        return;
    }
    while(ptr->next!=NULL){
        ptr1=ptr;
        ptr=ptr->next;
    }
    ptr1->next=NULL;
    free(ptr);
}
// to delete element after a node
void after_delete(int pos){
    struct node *ptr,*ptr1;
    ptr=start;
    for(int i=0;i<pos;i++){          // start with 0 bcoz ptr1 has to be linked with the list and ptr has to be free
        ptr1=ptr;
        ptr=ptr->next;
        if(ptr==NULL){
            printf("\nThere are less than %d elements in the list\n",pos);
            return;
        }
    }
    ptr1->next=ptr->next;
    free(ptr);
}
// to delete the particular node
void particular_delete(int pos){
    struct node *ptr,*ptr1;
    if(pos==1){
        begin_delete();
    }
    else{
        ptr=start;
        for(int i=1;i<pos;i++){ 
            ptr1=ptr;
            ptr=ptr->next;
            if(ptr==NULL){
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
        printf("4. To insert element after a node\n");
        printf("5. To insert element at a particular position\n");
        printf("6. To delete element fron beginning\n"); 
        printf("7. To delete element fron last\n");  
        printf("8. To delete element after a node\n");
        printf("9. To delete element at a particular position\n");
        printf("10. To count number of nodes\n"); 
        printf("11. To display elements\n");  
        printf("12. To reverse list \n");  
        printf("13. To exit\n");
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
            printf("\nEnter the position after which you want to add element:");
            scanf("%d",&pos);
            printf("\nEnter the value add after a node:");
            scanf("%d",&value);
            after_insert(value,pos);
            display();
            }
            break;
            case 5:if(start==NULL){
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
            case 6:begin_delete();
            display();
            break;
            case 7:last_delete();
            display();
            break;
            case 8:printf("\nEnter the position after which you want to delete element:");
            scanf("%d",&pos);
            after_delete(pos);
            display();
            break;
            case 9:printf("\nEnter the position at which you want to delete element:");
            scanf("%d",&pos);
            particular_delete(pos);
            display();
            break;
            case 10:count();
            break;
            case 11:display();
            break;
            case 12:reverse();
            display();
            break;
            case 13:exit(0);
            default:printf("\nEnter valid choice\n");
        }    
    }
}
