#define MAX(A,B) ((A)>(B)?(A):(B))
typedef struct _node
{
    int data;
    struct _node* left;
    struct _node* right;
    int height;
} Node;
#include "QueueAN.h"
Node* createNode(int data)
{
    Node* nd = (Node*)malloc(sizeof(Node));
    nd->data = data;
    nd->left = nd->right = NULL;
    nd->height = 1;
    return nd;
}

typedef struct _avl
{
    Node* root;
    int len;
} AVL;

AVL* createAVL()
{
    AVL* a = (AVL*)malloc(sizeof(AVL));
    a->root = NULL;
    a->len = 0;
    return a;
}

int getHeight(Node* root)
{
    if(root==NULL)
        return 0;
    return root->height;
}
Node* rightRotate(Node* root)
{
    Node* a = root;
    Node* b = a->left;
    Node* c = b->right;
    b->right = a;
    a->left = c;
    a->height = MAX(getHeight(a->left), getHeight(a->right)) + 1;
    b->height = MAX(getHeight(b->left),getHeight(b->right)) + 1;
    return b;
}
Node* leftRotate(Node* root)
{
    Node* a = root;
    Node* b = a->right;
    Node* c = b->left;
    b->left = a;
    a->right = c;
    a->height = MAX(getHeight(a->left), getHeight(a->right)) + 1;
    b->height = MAX(getHeight(b->left),getHeight(b->right)) + 1;
    return b;
}
Node* insertNode(Node* root, int data)
{
    if(root==NULL)
        return createNode(data);
    else if(data<root->data)
        root->left = insertNode(root->left, data);
    else if(data>root->data)
        root->right = insertNode(root->right, data);
    root->height = MAX(getHeight(root->left),getHeight(root->right)) +  1;
    int b_f = getHeight(root->left) - getHeight(root->right);
    if(b_f>1 && data < root->left->data)
        root = rightRotate(root);
    else if(b_f>1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }
    else if(b_f<-1 && data > root->right->data)
        root = leftRotate(root);
    else if(b_f<-1 && data<root->right->data)
    {
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }
    return root;
}
Node* deleteNode(Node* root, int data)
{
    if(root==NULL)
        return root;
    else if(data<root->data)
        root->left = deleteNode(root->left, data);
    else if(data>root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if(root->left==NULL)
            return root->right;
        if(root->right==NULL)
            return root->left;
        Node* succ = root->right;
        Node* parent = root;
        while(succ->left!=NULL)
        {
            parent = succ;
            succ = succ->left;
        }
        root->data = succ->data;
        if(root==parent)
            parent->right = deleteNode(parent->right,succ->data);
        else
            parent->left = deleteNode(parent->left, succ->data);
    }
    if(root==NULL)
        return root;
    root->height = MAX(getHeight(root->left),getHeight(root->right)) +  1;
    int b_f = getHeight(root->left) - getHeight(root->right);
    if(b_f>1 && data < root->left->data)
        root = rightRotate(root);
    else if(b_f>1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }
    else if(b_f<-1 && data > root->right->data)
        root = leftRotate(root);
    else if(b_f<-1 && data<root->right->data)
    {
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }
    return root;
}

void level_order(AVL* a)
{
    Node* root = a->root;
    Queue* q = createQueue(a->len);
    enqueue(q, root);
    while(!isEmpty(q))
    {
        Node* d = dequeue(q);
        printf("%d ",d->data);
        if(d->left!=NULL)
            enqueue(q,d->left);
        if(d->right!=NULL)
            enqueue(q,d->right);
    }
}

bool  search(Node* root, int data)
{
    if(root==NULL)
        return false;
    else if(data<root->data)
        return search(root->left, data);
    else if(data>root->data)
        return search(root->right, data);
    return true;
}

void inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(Node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
