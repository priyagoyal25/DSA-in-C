#include<stdio.h>
#define max 30
int a[max],pivot,low,high;
int partition(int a[],int low,int high){
    pivot=a[low];
    int i=low;
    int j=high;
    int temp;
    //until I find j<i
    while(i<j){
        // to find element > pivot 
        while(a[i]<=pivot){
            i++;
        }
        // to find element < pivot 
        while(a[j]>pivot){
            j--;
        }
        // interchange when i<j  and if j<i then this interchange will not occur
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    // when i find j<i then interchange a[j] wit a[low](low=pivot)
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j; // j represent the position of pivot element after partition
}
void quickSort(int a[],int low,int high){
    int partitionIndex;                       // position of pivot after partitioning the array
    if(low<high){
        partitionIndex=partition(a,low,high);     // call partition function to perform partition algo
        quickSort(a,low,partitionIndex-1);        //sort the left sub-array
        quickSort(a,partitionIndex+1,high);       //sort the right sub-array
    }
}
void main(){
    int n;
    printf("enter no of elements in array:");
    scanf("%d",&n);
    low=0;
    high=n-1;
    printf("enter elements in array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("entered elements in array are:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    quickSort(a,low,high);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}
