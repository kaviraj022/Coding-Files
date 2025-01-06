typedef struct _node
{
    int data;
    struct _node* left;
    struct _node* right;
} Node;

Node* createNode(int val)
{
    Node* nd = (Node*)malloc(sizeof(Node));
    nd->data = val;
    nd->left = nd->right = NULL;
    return nd;
}

typedef struct _bst
{
    Node* root;
    int len;
} BST;


BST* createBST()
{
    BST* b = (BST*)malloc(sizeof(BST));
    b->root = NULL;
    b->len = 0;
    return b;
}

Node* insertNode(Node* root, int data)
{
    if(root==NULL)
        return createNode(data);
    else if(data < root->data)
        root->left = insertNode(root->left, data);
    else if(data>root->data)
        root->right = insertNode(root->right, data);
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
    return root;
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