#include<stdio.h>
#define max 20
void binary_search(int a[],int n,int num){
    int low=0;
    int high=n-1;
    int mid,f=0;
    for(int i=0;i<n;i++){
        if(low<=high){
            mid=(low+high)/2;
            if(a[mid]==num){
                f=1;
                break;
            }
            else if(num<a[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    }
    if(f==1){
        printf("%d is found at %d position\n",num,mid+1);
    }
    else{
        printf("elemnt not found\n");
    }
}
void main(){
    int n,a[max],i,num;
    printf("enter no of elements:");
    scanf("%d",&n);
    printf("enter elementsin sorted manner:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter element to be search:");
    scanf("%d",&num);
    binary_search(a,n,num);
}