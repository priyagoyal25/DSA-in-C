#include<stdio.h>
#define max 30
int a[max];

// swapping values by reference
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

// heapify method using max heap 
void maxheapify(int a[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=(2*i)+1;
    int temp;
  if(left<=n && a[left]>a[largest]){
        largest=left;
    }
  if(right<=n && a[right]>a[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(& a[largest],& a[i]);
        maxheapify(a,n,largest);
    }
}

// heap sort consisting two steps ;
void heap_sort(int a[],int n){

    // step 1:constructing max heap
    for(int i=n/2;i>=1;i--){
        maxheapify(a,n,i);
    }
    
    // step 2:deleting from max heap and sort
    for(int i=n,j=1;i>=1;i--,j++){
        swap(& a[1],& a[i]);
        maxheapify(a,n-j,1);
    }
}
void main(){            
    int n;
    printf("enter no of elements in array:");
    scanf("%d",&n);
    printf("enter elements in array:\n");
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    printf("entered elements in array are:\n");
    for(int i=1;i<=n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    heap_sort(a,n);
    printf("Sorted array:\n");
    for(int i=1;i<=n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}