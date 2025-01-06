typedef struct _node
{
    int data;
    struct _node* next;
} Node;

typedef struct _linkedlist
{
    Node* headNode;
    Node* lastNode;
    int len;
} LinkedList;

LinkedList*  createLinkedList()
{
    LinkedList* LL = (LinkedList*)malloc(sizeof(LinkedList));
    LL->headNode = LL->lastNode = NULL;
    LL->len = 0;
    return LL;
}

Node* createNode(int data)
{
    Node* nd = (Node*)malloc(sizeof(Node));
    nd->data = data;
    nd->next = NULL;
    return nd;
}

bool isLLEmpty(LinkedList* LL)
{
    return LL->headNode==NULL;
}

void insertNewNodeInLL(LinkedList* LL, int data)
{
    Node* nd = createNode(data);
    if(isLLEmpty(LL))
        LL->headNode = LL->lastNode = nd;
    else
    {
        LL->lastNode->next = nd;
        LL->lastNode = nd;
    }
    LL->len++;
}

void displayLL(LinkedList* LL)
{
    Node* curr = LL->headNode;
    while(curr!=NULL)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }
}

void extendList(LinkedList* LL1, LinkedList* LL2)
{
    Node* curr = LL2->headNode;
    while(curr!=NULL)
    {
        insertNewNodeInLL(LL1,curr->data);
        curr = curr->next;
    }
}

void insertNodeAtPos(LinkedList* LL, int data, int pos) 
{
    if(pos<0)
        return;
    if(pos>LL->len)
        pos = LL->len;
    Node* nd = createNode(data);
    if(pos==0)
    {
        nd->next = LL->headNode;
        LL->headNode = nd;
    }
    else
    {
        Node* curr = LL->headNode;
        for(int i=1;i<=pos-1;i++)
            curr = curr->next;
        nd->next = curr->next;
        curr->next = nd;
    }
    if(nd->next==NULL)
        LL->lastNode = nd;
    LL->len++;
}



void insertNodeInSortedLL(LinkedList* LL, int data) 
{
    int pos = 0;
    Node* curr = LL->headNode;
    while(curr!=NULL && data>curr->data)
    {
        curr = curr->next;
        pos++;
    }
    insertNodeAtPos(LL,data,pos);
}

void removeNodeFromPos(LinkedList* LL, int pos)
{
    if(pos<0 || pos>=LL->len)
        return;
    if(pos==0)
    {
        LL->headNode = LL->headNode->next;
        if(LL->headNode==NULL)
            LL->lastNode = NULL;
    }
    else
    {
        Node* curr = LL->headNode;
        for(int i=1;i<=pos-1;i++)
            curr = curr->next;
        curr->next = curr->next->next;
        if(curr->next==NULL)
            LL->lastNode = curr;
    }
    LL->len--;
}

bool removeOneValue(LinkedList* LL, int data)
{
  Node* curr = LL->headNode;
  int pos = 0;
  while(curr!=NULL && data!=curr->data)
  {
    curr = curr->next;
    pos++;
  }
  if(pos==LL->len)
    return false;
  removeNodeFromPos(LL,pos);
  return true;
}
void removeAllValue(LinkedList* LL, int data)
{
  while(removeOneValue(LL,data));  
}

int searchData(LinkedList* LL, int data) 
{
    int pos = 0;
    Node* curr = LL->headNode;
    while(curr!=NULL && data!=curr->data)
    {
        curr = curr->next;
        pos++;
    }
    if(pos==LL->len)
        return -1;
    return pos;
}

void reverseLL(LinkedList* LL) 
{
    Node* curr = LL->headNode;
    Node* prev = NULL;
    Node* nextNode = NULL;
    while(curr!=NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    Node* temp = LL->headNode;
    LL->headNode = LL->lastNode;
    LL->lastNode = temp;
}

void sortLinkedList(LinkedList* LL)
{
    bool swapped = true;
    while(swapped){
        swapped = false;
        Node* curr = LL->headNode;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->data > curr->next->data){
                int t = curr->data;
                curr->data = curr->next->data;
                curr->next->data = t;
                swapped = true;
            }
            curr = curr->next;
        }
    }
}