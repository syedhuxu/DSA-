#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // IMPLEMENTATON OF DEQUE USING STL:

    // Integer type  deque
    deque<int> dq;

    //  Insertion:
    dq.push_back(10); // Deque: [10]
    dq.push_back(20); // Deque: [10, 20]
    dq.push_front(5); // Deque: [5, 10, 20]

    //  Traversal: Elements  print
    cout << "Current Deque: ";
    for (int val : dq)
    {
        cout << val << " ";
    }
    cout << endl;

    // Deletion:
    dq.pop_front(); // 5 removed [10, 20]
    dq.pop_back();  // 20 removed [10]

    // Access: First element check
    if (!dq.empty())
    {
        cout << "Deque After Operations: " << dq.front() << endl;
    }

    return 0;
}