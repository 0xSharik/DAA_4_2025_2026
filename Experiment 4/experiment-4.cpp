#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int heapArr[MAX];
int heapSize = 0;

void heapifyUp(int i)
{
    while(i > 0)
    {
        int parent = (i - 1) / 2;

        if(heapArr[parent] <= heapArr[i])
            break;

        swap(heapArr[parent], heapArr[i]);
        i = parent;
    }
}

void heapifyDown(int i)
{
    while(true)
    {
        int left  = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < heapSize && heapArr[left] < heapArr[smallest])
            smallest = left;

        if(right < heapSize && heapArr[right] < heapArr[smallest])
            smallest = right;

        if(smallest == i)
            break;

        swap(heapArr[i], heapArr[smallest]);
        i = smallest;
    }
}

void buildHeap()
{
    for(int i = (heapSize - 2) / 2; i >= 0; i--)
        heapifyDown(i);
}

void deleteNode(int i)
{
    if(i >= heapSize)
        return;

    heapArr[i] = heapArr[heapSize - 1];
    heapSize--;

    if(i > 0 && heapArr[i] < heapArr[(i - 1) / 2])
        heapifyUp(i);
    else
        heapifyDown(i);
}

void printHeap()
{
    for(int i = 0; i < heapSize; i++)
        cout << heapArr[i] << " ";

    cout << "\n";
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> heapArr[i];

    heapSize = n;

    buildHeap();

    int q;
    cin >> q;

    while(q--)
    {
        string cmd;
        cin >> cmd;

        if(cmd == "delete")
        {
            int idx;
            cin >> idx;
            deleteNode(idx);
        }
        else if(cmd == "deleteMin")
        {
            deleteNode(0);
        }
        else if(cmd == "print")
        {
            printHeap();
        }
    }

    return 0;
}
// sir firstly i was on medical then mst, and then i am in 7 days nss camp
// that's why it got late sir, i am extremely sorry for this 