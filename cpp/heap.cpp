#include <bits/stdc++.h>
using namespace std;
class BHeap {
    int *arr;
    int len, size;
public:
    BHeap(int n) {
        arr = new int[n];
        size = n;
        len = 0;
    }
    void addElementBh(int data) {
        if (len >= size) {
            cout << "Heap is full!" << endl;
            return;
        }
        arr[len] = data;
        len++;
        int child = len - 1;
        int parent = (child - 1) / 2;
        while (child > 0 && arr[parent] < arr[child]) {
            swap(arr[parent], arr[child]);
            child = parent;
            parent = (child - 1) / 2;
        }
    }
    int deletion() {
        if (len == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int val = arr[0];
        arr[0] = arr[len - 1];
        len--;
        int parent = 0;
        int child;
        while (true) {
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            if (left < len && right < len) {
                child = (arr[left] > arr[right]) ? left : right;
            } else if (left < len) {
                child = left;
            } else {
                break;
            }
            if (arr[parent] < arr[child]) {
                swap(arr[parent], arr[child]);
                parent = child;
            } else {
                break;
            }
        }
        return val;
    }
    int MaxElement() {
        return (len > 0) ? arr[0] : -1;
    }
    void HeapifyMax(int *arr, int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            int parent = i;
            while (true) {
                int left = 2 * parent + 1;
                int right = 2 * parent + 2;
                int child;

                if (left < n && right < n) {
                    child = (arr[left] > arr[right]) ? left : right;
                } else if (left < n) {
                    child = left;
                } else {
                    break;
                }

                if (arr[parent] < arr[child]) {
                    swap(arr[parent], arr[child]);
                    parent = child;
                } else {
                    break;
                }
            }
        }
    }

    void display() {
        for (int i = 0; i < len; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    BHeap bh(5);
    bh.addElementBh(1);
    bh.addElementBh(6);
    bh.addElementBh(9);
    bh.addElementBh(5);
    bh.addElementBh(2);
    bh.display();
    return 0;
}