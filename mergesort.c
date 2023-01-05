#include<stdio.h>
#define max 30
int a[max],b[max],mid,low,high;
void merge(int a[],int low,int mid,int high){
    int i=0,k=0,j=mid+1;
    int b[high-low+1];                                    // high+1=n
    // comparing two sorted sub-array and make new sorted array
    while(i<=mid&&j<=high){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    // for remaining elements of array from low to mid
    while(i<=mid){
        b[k]=a[i];
        i++;
        k++;
    }
    // for remaining elements of array from mid+1(j) to high
    while(j<=high){
        b[k]=a[j];
        j++;
        k++;
    }
    //copying the elements of b[] in  a[]
    for(i=0;i<=high;i++){
        a[i]=b[i];
    }
}
void mergeSort(int a[],int low,int high){                      
    if(low<high){
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
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
    mergeSort(a,low,high);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}