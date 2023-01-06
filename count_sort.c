#include<stdio.h>
#include<stdlib.h>
#define max 30
int a[max];
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
void count_sort(int a[],int n){
    int i,j;

    // find maximum element in array
    int maxim=maximum(a,n);

    // create count array
    int* count=(int*)malloc((maxim+1)*sizeof(int));

    // initialising the count array to 0
    for(i=0;i<maxim+1;i++){
        count[i]=0;
    }

    // increament the corresponding index in the count array
    for(i=0;i<n;i++){
        j=a[i];     // these 2 lines can be written : count[a[i]]++
        count[j]++;
    }

    // copying the count array in main array
    i=0;         // counter for count array
    j=0;         // counter for main array
    while(i<maxim+1){
        if(count[i]!=0){
            a[j]=i;
            count[i]--;
            j++;
        }
        else{
            i++;
        }
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
    count_sort(a,n);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}