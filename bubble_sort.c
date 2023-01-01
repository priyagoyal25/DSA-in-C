#include<stdio.h>
#define max 30
int a[max];
void bubble_Sort(int a[],int n){
    int temp,i,j;
    for(i=0;i<n-1;i++){               // for no of passes which is 1 less than the no of elements
        for(j=0;j<n-i-1;j++){         // for no of comparisons which is 1 less than the no of unsorted elements
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }       

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
    bubble_Sort(a,n);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}