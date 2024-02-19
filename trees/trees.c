#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *construct_node(int value)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->left = NULL;
    p->right = NULL;
    p->data = value;
    return p;
}

void *pretraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        pretraversal(root->left);
        pretraversal(root->right);
    }
}

void *posttraversal(struct node *root)
{
    if (root != NULL)
    {
        posttraversal(root->left);
        posttraversal(root->right);
        printf("%d ", root->data);
    }
}

void *inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        printf("%d ", root->data);
        inordertraversal(root->right);
    }
}

bool isbst(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isbst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isbst(root->right);
    }
    else
    {
        return 1;
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return (search(root->left, key));
    }
    else
    {
        return (search(root->right, key));
    }
}

void insert(struct node *root, int val)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == val)
        {
            printf("cannot insert %d", val);
            return;
        }
        else if (root->data > val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *newNode = construct_node(val);
    if (val < prev->data)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
}



struct node* inorderpredecessor(struct node* root)
{
    root=root->left;
    while(root->right != NULL)
    {
        root=root->right;
    }
    return root;
}



struct node* deletenode(struct node* root, int val)
{
    struct node* ipre;
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    //search for the node to be deleted
    if(val < root->data)
    {
        root->left = deletenode(root->left,val);
    }
    else if(val > root->data)
    {
        root->right = deletenode(root->right,val);
    }
    else
    {
        ipre=inorderpredecessor(root);
        root->data=ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
    return root;
}



int main()
{
    struct node *p = construct_node(5);
    struct node *p1 = construct_node(3);
    struct node *p2 = construct_node(6);
    struct node *p3 = construct_node(1);
    struct node *p4 = construct_node(4);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    pretraversal(p);
    printf("\n");
    posttraversal(p);
    printf("\n");
    inordertraversal(p);
    printf("\n");
    if (isbst(p))
    {
        printf("yes it is a binary tree\n");
    }
    struct node *n = search(p, 4);
    if (n != NULL)
    {
        printf("Found_%d", n->data);
    }
    else
    {
        printf("Element not found\n");
    }
    printf("\n");

    insert(p, 16);
    inordertraversal(p);
    printf("\n------------------------------------\n");
    inordertraversal(p);
    printf("\n");
    deletenode(p,1);
    inordertraversal(p);
}