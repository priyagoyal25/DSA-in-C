#include<stdio.h>
#define max 20
void linear_search(int a[],int n,int num){
    int pos,f=0;
    for(int i=0;i<n;i++){
        if(a[i]==num){
            f=1;
            pos=i+1;
            break;
        }
    }
    if(f==1){
        printf("%d is present at %d position\n",num,pos);
    }
    else{
        printf("not present\n");
    }
}
void main(){
    int n,a[max],i,num;
    printf("enter no of elements:");
    scanf("%d",&n);
    printf("enter elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter element to be search:");
    scanf("%d",&num);
    linear_search(a,n,num);
}