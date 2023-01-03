#include<stdio.h>
#define max 30
int a[max];
void insertion_sort(int a[],int n){
    int temp,i,j;
    // i for no of passes 
    for(i=0;i<n-1;i++){
        temp=a[i+1];
        j=i;
        while(temp<a[j] && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

void main(){            
    int n;
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
    insertion_sort(a,n);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}