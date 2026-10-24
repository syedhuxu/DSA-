#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int f;
    int r;
    int cap;

public:
    CircularQueue(int sz)
    {
        f = r = -1;
        cap = sz;
        arr = new int[sz];
    }

    void enqueue(int val)

    {
        if ((r + 1) % cap == f)
        {
            cout << "Overflow" << endl;
        }
        if (f == -1)
        {
            f = r = 0;
        }
        else
        {
            r = (r + 1) % cap;
        }
        arr[r] = val;

        cout << val << " Enqueued (Queue mein aagaya).\n";
    }

    int dequeue()
    {
        if (f == -1)
        {
            cout << "Underflow" << endl;
            return -1;
        }
        int poppedValue = arr[f];
        if (f == r)
        {
            f = -1; // Queue ko wapas empty state mein le jao
            f = -1;
        }
        else
        {
            f = (f + 1) % cap;
        }
        cout << poppedValue << " Dequeued (Queue se chala gaya).\n";
        return poppedValue;
    }
};

int main()
{

    CircularQueue c1(5);
    c1.enqueue(100);
    c1.enqueue(200);
    c1.enqueue(300);
    c1.enqueue(400);

    cout << c1.dequeue() << endl;

    return 0;
}