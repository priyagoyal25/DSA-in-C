#include<stdio.h>
#define max 30
int a[max];
void selection_sort(int a[],int n){
    int min,i,j,temp;
    // i for no of passes and j for no of comparisons
    // work on index here
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<=n-1;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
    // swapping will take place only when value of minimum has changed
        if(min!=i){
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
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
    selection_sort(a,n);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}