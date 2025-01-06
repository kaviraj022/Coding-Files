typedef struct _queue
{
    Node** A;
    int size;
    int length;
    int front;
    int rear;
} Queue;

Queue* createQueue(int capacity)
{
    Queue* q = (Queue*)malloc(sizeof(Queue));

    q->A = (Node**)malloc(sizeof(Node*)*capacity);
    q->size = capacity;
    q->length = 0;
    q->front = 0;
    q->rear = capacity-1;
    return q;
}

bool isEmpty(Queue* q)
{
    return q->length==0;
}

bool isFull(Queue* q)
{
    return q->length == q->size;
}

void enqueue(Queue* q, Node* item)
{
    if(isFull(q))
        return;
    q->rear = (q->rear + 1) % q->size;
    q->A[q->rear] = item;
    q->length++;
}

Node* dequeue(Queue* q)
{
    if(isEmpty(q))
        return NULL;
    Node* d = q->A[q->front];
    q->front = (q->front+1)%q->size;
    q->length--;
    return d;
}

Node* front(Queue* q)
{
    if(isEmpty(q))
        return NULL;
    return q->A[q->front];
}

Node* rear(Queue* q)
{
    if(isEmpty(q))
        return NULL;
    return q->A[q->rear];
}
