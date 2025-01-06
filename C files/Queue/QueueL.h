typedef struct _nodeq
{
    int data;
    struct _nodeq* next;
} NodeQ;
typedef struct _queuel
{
    NodeQ* front;
    NodeQ* rear;
    int length;
} QueueL;

NodeQ* createNodeQ(int data)
{
    NodeQ* nd = (NodeQ*)malloc(sizeof(NodeQ));
    nd->data = data;
    nd->next = NULL;
    return nd;
}

QueueL* createQueueL()
{
    QueueL* q = (QueueL*)malloc(sizeof(QueueL));
    q->front = q->rear = NULL;
    q->length = 0;
    return q;
}

bool isEmptyQ(QueueL* q)
{
    return q->length==0;
}

void enqueueL(QueueL* q, int data)
{
    NodeQ* nd = createNodeQ(data);
    if(isEmptyQ(q))
        q->front = q->rear = nd;
    else
    {
        q->rear->next = nd;
        q->rear = nd;
    }
    q->length++;
}

int dequeue(QueueL* q)
{
    if(isEmptyQ(q))
        return INT_MIN;
    int d = q->front->data;
    q->front = q->front->next;
    q->length--;
    return d;
}

int peekFront(QueueL* q)
{
    if(isEmptyQ(q))
        return INT_MIN;
    return q->front->data;
}

int peekRear(QueueL* q)
{
    if(isEmptyQ(q))
        return INT_MIN;
    return q->rear->data;
}

void displayQ(QueueL* q)
{
    NodeQ* curr = q->front;
    while(curr!=NULL)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}