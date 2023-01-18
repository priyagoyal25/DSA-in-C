#include<stdio.h>
#define max 10
void main(){
    int n,r,c,i,j,base=2000,no,a[max],b[max][max],address,pos=0,posi=0,posj=0;
    printf("for 1-d array:\n");
    printf("enter size:");
    scanf("%d",&n);
    printf("enter elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("for 2-d array:\n");
    printf("enter rows:");
    scanf("%d",&r);
    printf("enter columns:");
    scanf("%d",&c);
    printf("enter elements in array:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&b[i][j]);
        }
    }
    printf("entered elements of 1-d array are:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\nenter element whose address to be find:");
    scanf("%d",&no);
    for(i=0;i<n;i++){
        if(a[i]==no){
            pos=i;
            break;
        }
    }
    // here pos represents the actual index of the element 
    address=base+(pos)*2;
    printf("address=%d\n",address);

    printf("entered elements of 2-d array are:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    printf("\nenter element whose address to be find:");
    scanf("%d",&no);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(b[i][j]==no){
                posi=i;
                posj=j;
                break;
            }
        }
    }
    address=base+(posi*c+posj)*2;
    printf("address=%d\n",address);
}