typedef struct _stack
{
    int* a;
    int top;
    int size;
} Stack;

Stack* createStack()
{
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->a = (int*)malloc(sizeof(int)*16);
    st->size = 16;
    st->top = -1;
    return st;
}

bool isEmpty(Stack* st)
{
    return st->top==-1;
}

bool isFull(Stack* st)
{
    return st->top == st->size-1;
}

void changeSize(Stack* st)
{
    int oldSize = st->size;
    int newSize = oldSize + oldSize/2;
    st->a = (int*)realloc(st->a,sizeof(int)*newSize);
    st->size = newSize;
}

void push(Stack* st, int data)
{
    if(isFull(st))
        changeSize(st);
    st->a[++st->top] = data;
}

int pop(Stack* st)
{
    return st->a[st->top--];
}

int peek(Stack* st)
{
    return st->a[st->top];
}

int stackLength(Stack* st)
{
    return st->top+1;
}

void displayStack(Stack* st)
{
    if(isEmpty(st))
        printf("Stack is empty.");
    else
    {
        for(int i=st->top;i>=0;i--)
            printf("%d ",st->a[i]);
    }
    printf("\n");
}

