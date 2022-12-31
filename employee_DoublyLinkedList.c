// to enter and display employee details using doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int sno,phone,salary;
    char name[20],dept[50],desig[40];
    struct node *prev,*next;
}*start,*newnode;
// create employee list
void create(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter sno,name,salary,phone number,department,designation:\n");
    scanf("%d%s%d%d%s%s",&newnode->sno,newnode->name,&newnode->salary,&newnode->phone,newnode->dept,newnode->desig);
    struct node *ptr;
    if(start==NULL){
        newnode->prev=NULL;
        newnode->next=NULL;
        start=newnode;
    }
    else{
        ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        newnode->prev=ptr;
        newnode->next=NULL;
        ptr->next=newnode;
    }
}
// to insert at the beginning
void begin_insert(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter sno,name,salary,phone number,department,designation:\n");
    scanf("%d%s%d%d%s%s",&newnode->sno,newnode->name,&newnode->salary,&newnode->phone,newnode->dept,newnode->desig);
    newnode->next=start;
    newnode->prev=NULL;
    start->prev=newnode;
    start=newnode;
}
// to insert at last;
void last_insert(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter sno,name,salary,phone number,department,designation:\n");
    scanf("%d%s%d%d%s%s",&newnode->sno,newnode->name,&newnode->salary,&newnode->phone,newnode->dept,newnode->desig);
    struct node *ptr;
    ptr=start;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=NULL;
    newnode->prev=ptr;
}
// to delete from beginning
void begin_delete(){
    if(start==NULL){
        printf("\nEmpty list\n");
        return;
    }
    struct node *ptr;
    ptr=start;
    if(ptr->next==NULL){
        start=NULL;
        free(ptr);
    }
    else{
    start=ptr->next;
    ptr->next->prev=NULL;
    free(ptr);
    }
}
// to delete from last
void last_delete(){
    if(start==NULL){
        printf("\nEmpty list\n");
        return;
    }
    struct node *ptr;
    ptr=start;
    if(ptr->next==NULL){
        start=NULL;
        free(ptr);
        return;
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
}
void display(){
    struct node *ptr;
    if(start==NULL){
        printf("\nEmpty list\n\n");
    }
    else{
        struct node *ptr;
        ptr=start;
        while(ptr!=NULL){
            printf("\n%d || %s || %d || %d || %s || %s\n",ptr->sno,ptr->name,ptr->salary,ptr->phone,ptr->dept,ptr->desig);
            ptr=ptr->next; 
        }
    }
}
// to count no of employees
void count(){
    int count=0;
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL){
        ptr=ptr->next;
        count++; 
    }
    printf("\nNumber of Employees=%d\n",count);
}
int main(){
    int no,choice;
    start=NULL;         //initially consider list is empty
    while(1){
        printf("\n\n/**--------MAIN MENU-------**/\n\n");
        printf("ENTER  1. To create a Employee list\n");
        printf("2. To insert data at begin\n");
        printf("3. To insert data at last\n");
        printf("4. To delete data fron beginning\n"); 
        printf("5. To delete data fron last\n");  
        printf("6. To display elements\n");  
        printf("7. To count number of employees\n"); 
        printf("8. To exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nEnter the no of employees:");
            scanf("%d",&no);
            for(int i=0;i<no;i++){
                create();
            }
            display();
            break;
            case 2:if(start==NULL){
                printf("\nEmpty list  First create the list(by enter choice 1)");
                }
            else{
            begin_insert();
            display();
            }
            break;
            case 3:if(start==NULL){
                printf("\nEmpty list  First create the list(by enter choice 1)");
                }
            else{
            last_insert();
            display();
            }
            break;
            case 4:begin_delete();
            display();
            break;
            case 5:last_delete();
            display();
            break;
            case 6:display();
            break;
            case 7:count();
            break;
            case 8:exit(0);
            default:printf("\nEnter valid choice\n");
        }    
    }
}