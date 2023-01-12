#include<stdio.h>
#include<stdlib.h>
#define max 30
int a[max],b[max];
int maximum(int a[],int n){
    int maxim=a[0];
    // loop start with i=1 as we have already let a[0]=maxim
    for(int i=1;i<n;i++){
        if(maxim<a[i]){
            maxim=a[i];
        }
    }
    return maxim;
}
void count_sort(int a[],int n,int pos){
    int i,j;

    // initialising the count array to 0
    int count[10]={0};

    // increament the corresponding index in the count array
    for(i=0;i<n;i++){
        count[(a[i]/pos)%10]++;
    }

    // updating the count array contains position now
    for(i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
    }

    // make another array
    for(i=n-1;i>=0;i--){
        b[--count[((a[i]/pos)%10)]]=a[i];
    }

    // copy the elements of b array in main array
    for(i=0;i<n;i++){
        a[i]=b[i];
    }

}
void radix_sort(int a[],int n){
    int maxim=maximum(a,n);
    for(int pos=1;maxim/pos>0;pos=pos*10){
        count_sort(a,n,pos);
    }
}
void main(){            
    int n,maxim;
    printf("enter no of elements in array:");
    scanf("%d",&n);
    printf("enter elements in array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("entered elements in array are:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    radix_sort(a,n);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}