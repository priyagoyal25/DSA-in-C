#include<stdio.h>
#define max 10
void main(){
    int row,col,i,j,a[max][max],count=0;
    printf("enter rows:");
    scanf("%d",&row);
    printf("enter columns:");
    scanf("%d",&col);
// taking input from user
    printf("enter elements in array:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&a[i][j]);
// counting how many elements are 0 
            if(a[i][j]==0){
                count++;
            }
        }
    }
// printing entered elements
    printf("entered elements are:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
// checking matrix is spasrse or not if yes then represent in triplet form
if(count>(row*col)/2){
    printf("Given matrix is sparse matrix\n");
    printf("\nTRIPLET REPRESENTATION OF SPARSE MATRIX\n");
    printf("\t ROW \t COL \t NON-ZERO ELEMENT\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(a[i][j]!=0){
                printf("\t %d \t %d \t %d\n",i,j,a[i][j]);
            }
        }
    }
    printf("TOTAL:  %d \t %d \t %d\n",row,col,row*col-count);
}
else{
    printf("NOT SPARSE\n");
}
}