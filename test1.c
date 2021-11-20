#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


struct bin_tree {
    int data;
    struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val){
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}


node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}

int main(int argc,char* argv[]){
    int pid;
    pid=fork();
    node *root;
    node *tmp;

    if(pid!=0){
        insert(&root, 9);
        insert(&root, 4);
        insert(&root, 15);
        insert(&root, 6);
        insert(&root, 12);
        insert(&root, 17);
        insert(&root, 2);

        printf("Display\n");
        print_preorder(root);
        
    }
    //int i;


    tmp = search(&root, 4);

    return 0;
}