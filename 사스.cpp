#include<stdio.h>
#include<stdlib.h>
int space_Num = 24;
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;

node* root;

node* insert(node* root, int data) {
    if (root == NULL)
    {
        root = (node*)malloc(sizeof(node));
        root->right = root->left = NULL;
        root->data = data;
        return root;
    }
    else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        }
        else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}
node* fMin(node* root) {
    node* min = root;
    while (min->left != NULL) {
        min = min->left;
    }
    return min;
}
node* del(node* root, int data) {
    node* tmproot = NULL;
    if (root = NULL) {
        return NULL;
    }
    if (data < root->data) {
        root->left = del(root->left, data);
    }
    else if (data > root->data) {
        root->right = del(root->right, data);
    }
    else {
        if (root->left != NULL && root->right != NULL) {
            tmproot = fMin(root->right);
            root->data = tmproot->data;
            root->right = del(root->right, tmproot->data);
        }
        else {
            tmproot = (root->left = NULL) ? root->right : root->left;
            free(root);
            return tmproot;
        }
    }
    return root;
}
void print(node* t)
{

    if (t == NULL)
    {
        return;
    }
    for (int i = 0; i < space_Num; i++) {
        printf(" ");
    }
    printf("%d\n", t->data);

    if (t->left != NULL)
    {
        space_Num = space_Num - 2;
        for (int i = 0; i < space_Num; i++) {
            printf(" ");
        }
        printf("/\n");
        space_Num = space_Num - 2;
        for (int i = 0; i < space_Num; i++) {
            printf(" ");
        }
        printf("%d\n ", (t->left)->data);
    }
    if (t->right != NULL)
    {
        space_Num = space_Num + 2;
        for (int i = 0; i < space_Num; i++) {
            printf(" ");
        }
        printf("\\\n");
        space_Num = space_Num + 3;
        for (int i = 0; i < space_Num; i++) {
            printf(" ");
        }
        printf("%d\n", (t->right)->data);
    }
    printf("\n");

    if (t->left)
    {
        space_Num = space_Num - 2;
        for (int i = 0; i < space_Num; i++) {
            printf(" ");
        }
        printf("/\n");
        print(t->left);
    }
    if (t->right)
    {
        space_Num = space_Num + 2;
        for (int i = 0; i < space_Num; i++) {
            printf(" ");
        }
        printf("\\\n");
        print(t->right);
    }
}