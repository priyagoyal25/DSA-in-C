// queue using array
#include<stdio.h>
#include<stdlib.h>
#define max 5
int q[20],front=-1,rear=-1,i=0;
// to insert element in queue(ENQUEUE)
void q_insert(int value){
    if(front==-1 && rear== -1){
        front=rear=0;
    }
    else{
        rear++;
    }
    q[rear]=value;
}
// to delete element from queue(DEQUEUE)
int q_delete(){
    int value;
    if(front==-1 && rear== -1){
        printf("\nUNDERFLOW\n");
         return -1;
    }
    else if(front>rear){
        front=rear=-1;
    }
    else{
        value=q[front];
        front++;
        return value;
    }
}
// to display all elements
void display(){ 
    if(front==-1||front>rear){
        printf("\nQUEUE IS EMPTY\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d\n",q[i]);
        }
    }
}
// to display the first element of queue(PEEK)
void q_peek(){
    if(front==-1||front>rear){
        printf("\nQUEUE IS EMPTY\n");  
    }
    else{
        printf(" First element=%d\n",q[front]);
    }
}
int main(){
    int value,choice;
    while(1){
        printf("\n\n/**--------MAIN MENU-------**/\n\n");
        printf("ENTER  1. To insert element in queue\n");
        printf("2. To delete element from queue\n");
        printf("3. To display first element of queue\n");
        printf("4. To display all elements of queue\n");
        printf("5. Exit\n"); 
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:if(rear== max-1){
                printf("\nOVERFLOW\n");
            }
            else{
                printf("Enter elements:");
                for( i=0;i<max;i++){
                    scanf("%d",&value);
                    q_insert(value);
                }
            }
            break;
            case 2:value=q_delete();
            if(value!=-1){
                printf("\nElement deleted:%d",value);
            }
            break;
            case 3:q_peek();
            break;
            case 4:display();
            break;
            case 5:exit(0);
            default:printf("\nEnter valid choice\n");
        }
    }
}