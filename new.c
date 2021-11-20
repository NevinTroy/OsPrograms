#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<time.h>
#include<signal.h>

struct btnode
{
    int data;
    struct btnode *left;
    struct btnode *right;
};


int order[9];
int count=0;

struct btnode *create()
{
    int val;
    char ch;
    int flag=0;
    struct btnode *nnode = (struct btnode *)malloc(sizeof(struct btnode));
    printf("\nEnter the data: ");
    scanf("%d", &val);
    nnode->data = val;
    int x = val;
    printf("Do you want to enter data in left child of %d: ", val);
    scanf("%s", &ch);
    if (ch == 'Y' || ch == 'y')
        nnode->left = create();
    else
    {   
        order[count++]=nnode->data;
        flag=1;
        nnode->left = 0;
    }
    printf("\nDo you want to enter data in right child of %d: ", x);
    scanf("%s", &ch);
    if (ch == 'Y' || ch == 'y')
        nnode->right = create();
    else
    {
        if(flag==0)
            order[count++]=nnode->data;
        nnode->right = 0;
    }
    return nnode;
};


void printPreorder(struct btnode* node,int sum){
    if (node == NULL)
        return;
 
    sum+=node->data;

    printPreorder(node->left,sum);
 
    printPreorder(node->right,sum);
}

int main(){
    int ch, el,i;
    int fd[2];
    printf("\nProgram to implement Binary Tree operations\n");
    struct btnode *root = NULL;
    printf("\n\n MENU \n");
    printf("1. CREATE\n");
    root = 0;
    printf("\nEntering data for root node...");
    root = create();
    int pid;
    pid=fork();
    if(pid==0){
        close(fd[0]);
        sleep(10);
        int sum=0;
        printPreorder(root,sum);
        write(fd[1],&sum,sizeof(sum));
        close(fd[1]);
    }
    else{
        close(fd[1]);
        int sum=0;
        kill(pid,SIGSTOP);
        
        kill(pid,SIGCONT);
        wait(NULL);
        kill(pid,SIGKILL);

        read(fd[0],&sum,sizeof(sum));
        printf("The sum is %d\n",sum);

    }
    
    return 0;
}