#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node* createNode(int x){
  struct node* temp=(struct node*)malloc(sizeof(struct node));
  temp->data=x;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
void preorder(struct node* root){
  if(root=NULL){
    return;
  }
  printf("%d",root->data);
  preorder(root->left);
  preorder(root->right);

}
int main(int argc,char* argv[]){
  struct node* root=NULL;
  root=createNode(2);
  root->left=createNode(7);
  root->right=createNode(5);
  root->left->left=createNode(2);
  root->left->right=createNode(6);
  root->left->right->left=createNode(5);
  root->left->right->right=createNode(11);
  root->right->right=createNode(9);
  root->right->right->left=createNode(4);
  preorder(root);
  return 0;
}