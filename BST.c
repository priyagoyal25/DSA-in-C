#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
}*root;
// to insert data in binary search tree
struct node* insert(struct node* root,int value){
    if(root==NULL){
        root=(struct node*)malloc(sizeof(struct node));
        root->data=value;
        root->left=NULL;
        root->right=NULL;
    }
    else{
        if(value<root->data){
            root->left=insert(root->left,value);
        }
        else{
            root->right=insert(root->right,value);
        }
    }
    return root;
}
// preorder traversal
void preorder(struct node* root){
    if(root!=NULL){
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
// Inorder traversal
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}
// postorder traversal
void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\n",root->data);
    }
}

// search element
void search(struct node *root,int value){
    if(root==NULL){
        printf("element not found\n");
        return;
    }
    if(value==root->data){
        printf("%d is found at %d position\n",value,root);
    }
    else if(value<root->data){
        search(root->left,value);
    }
    else{
        search(root->right,value);
    }
}

// inorder predecessor is the rightmost child of left subtree
struct node* inorderPredecessor(struct node* root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
// delete element 
/*struct node* delete(struct node *root,int value){
    struct node* ipre;
    if(root==NULL){
        printf("\nelement not present\n");
        return root;
    }
    // searching the node to be deleted
    if(value<root->data){
        root->left=delete(root->left,value);
    }
    else if(value>root->data){
        root->right=delete(root->right,value);
    }   
    //deletion strategy when node is found
    else{
        // node has no child i.e. leaf node
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
            return root->left;
        }
        else if(root->left==NULL && root->right!=NULL){
            return root->right;
        }
        else{
            root=inorderPredecessor(root);
        }
        // ipre=inorderPredecessor(root);
        // root->data=ipre->data;
        // root->left= delete(root->left,ipre->data);
        // if(root->left==NULL && root->right !=NULL){
            
        // }
    }
    return root;
}
*/
void main(){
    int value,choice,no;
    root=NULL;
    while(1){
        printf("\n\n/**--------MAIN MENU-------**/\n\n");
        printf("ENTER  1. To insert element\n");
        printf("2. To delete element\n");
        printf("3. To search element\n");
        printf("4. preorder display\n"); 
        printf("5. postorder display\n");  
        printf("6. inorder display\n");  
        printf("7. exit\n");  
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter no of nodes:");
            scanf("%d",&no);
            printf("\nenter values in tree:\n");
            for(int i=0;i<no;i++){
                scanf("%d",&value);
                root=insert(root,value);
            }
            break;
            case 2: printf("enter value to be deleted:");
            scanf("%d",&value);
            root=delete(root,value);
            break;
            case 3: printf("enter value to be search:");
            scanf("%d",&value);
            search(root,value);
            break;
            case 4: if(root==NULL){
                printf("\nempty tree\n");
            }
            else{
            printf("\nPREORDER TRAVERSAL:\n:");
            preorder(root);
            }
            break;
            case 5:if(root==NULL){
                printf("\nempty tree\n");
            }
            else{
            printf("\nPOSTORDER TRAVERSAL:\n");
            postorder(root);
            }
            break;
            case 6:if(root==NULL){
                printf("\nempty tree\n");
            }
            else{
            printf("\nINORDER TRAVERSAL:\n");
            inorder(root);
            }
            break;
            case 7: exit(0);
            default:printf("\nenter valid choice\n");
        }
    }
}