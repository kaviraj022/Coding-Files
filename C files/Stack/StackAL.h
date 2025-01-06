typedef struct _stackl
{
    LinkedList** a;
    int top;
    int size;
} StackL;

StackL* createStackL()
{
    StackL* st = (StackL*)malloc(sizeof(StackL));
    st->a = (LinkedList**)malloc(sizeof(LinkedList*)*16);
    st->size = 16;
    st->top = -1;
    return st;
}

bool isEmptyL(StackL* st)
{
    return st->top==-1;
}

bool isFullL(StackL* st)
{
    return st->top == st->size-1;
}

void changeSizeL(StackL* st)
{
    int oldSize = st->size;
    int newSize = oldSize + oldSize/2;
    st->a = (LinkedList**)realloc(st->a,sizeof(LinkedList*)*newSize);
    st->size = newSize;
}

void pushL(StackL* st, LinkedList* data)
{
    if(isFullL(st))
        changeSizeL(st);
    st->a[++st->top] = data;
}

LinkedList* popL(StackL* st)
{
    return st->a[st->top--];
}

LinkedList* peekL(StackL* st)
{
    return st->a[st->top];
}

int stackLengthL(StackL* st)
{
    return st->top+1;
}



