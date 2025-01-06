typedef struct _bheap
{
    int* h;
    int size;
    int length;
} BHeap;

BHeap* createBHeap(int size)
{
    BHeap* bh = (BHeap*)malloc(sizeof(BHeap));
    bh->h = (int*)malloc(sizeof(int)*size);
    bh->size = size;
    bh->length = 0;
    return bh;
}

void addElementMaxBH(BHeap* bh, int data)
{
    bh->h[bh->length] = data;
    int child = bh->length;
    int parent = (child-1)/2;
    while(child!=0 && bh->h[child]>bh->h[parent])
    {
        int t = bh->h[child];
        bh->h[child] = bh->h[parent];
        bh->h[parent] = t;
        child = parent;
        parent = (child-1)/2;
    }
    bh->length++;
}

int extractMax(BHeap* bh)
{
    int d = bh->h[0];
    bh->h[0] = bh->h[bh->length-1];
    bh->length--;
    int parent = 0;
    while(true)
    {
        int lc = 2*parent+1,rc = 2*parent+2,child;
        if(lc<bh->length && rc<bh->length)
            child = bh->h[lc] > bh->h[rc]?lc:rc;
        else if(lc<bh->length)
            child = lc;
        else
            return d;
        if(bh->h[child]>bh->h[parent])
        {
            int t = bh->h[child];
            bh->h[child] = bh->h[parent];
            bh->h[parent] = t;
            parent = child;
        }
        else
            return d;
    }
}

void heapifyMax(BHeap* bh)
{
    for(int i = bh->length-1;i>=0;i--)
    {
        int parent = i;
        while(true)
        {
            int lc = 2*parent+1,rc = 2*parent+2,child;
            if(lc<bh->length && rc<bh->length)
                child = bh->h[lc] > bh->h[rc]?lc:rc;
            else if(lc<bh->length)
                child = lc;
            else
                break;
            if(bh->h[child]>bh->h[parent])
            {
                int t = bh->h[child];
                bh->h[child] = bh->h[parent];
                bh->h[parent] = t;
                parent = child;
            }
            else
                break;
        }
    }
}

void displayBH(BHeap* bh)
{
    for(int i=0;i<bh->length;i++)
        printf("%d ",bh->h[i]);
}

void heapSortAsc(BHeap* bh)
{
    int n = bh->length;
    while(bh->length>0)
    {
        int d = extractMax(bh);
        bh->h[bh->length] = d;
        displayBH(bh);
    }
    bh->length = n;
}