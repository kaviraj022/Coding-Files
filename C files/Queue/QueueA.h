typedef struct _queue
{
    int* A;
    int size;
    int length;
    int front;
    int rear;
} Queue;

Queue* createQueue(int capacity)
{
    Queue* q = (Queue*)malloc(sizeof(Queue));

    q->A = (int*)malloc(sizeof(int)*capacity);
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

void enqueue(Queue* q, int item)
{
    if(isFull(q))
        return;
    q->rear = (q->rear + 1) % q->size;
    q->A[q->rear] = item;
    q->length++;
}

int dequeue(Queue* q)
{
    if(isEmpty(q))
        return INT_MIN;
    int d = q->A[q->front];
    q->front = (q->front+1)%q->size;
    q->length--;
    return d;
}

int front(Queue* q)
{
    if(isEmpty(q))
        return INT_MIN;
    return q->A[q->front];
}

int rear(Queue* q)
{
    if(isEmpty(q))
        return INT_MIN;
    return q->A[q->rear];
}

void display(Queue* q)
{
    if(isEmpty(q))
        printf("Queue is Empty.");
    else
    {
        int i = q->front;
        for(int j=1;j<=q->length;j++)
        {
            printf("%d ",q->A[i]);
            i = (i + 1) % q->size;
        }
    }
    printf("\n");
}