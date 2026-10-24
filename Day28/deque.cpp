#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // IMPLEMENTATON OF DEQUE USING STL:

    // Integer type  deque
    deque<int> dq;

    //  Insertion: Front aur Back dono side se
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

    // Deletion: Front aur Back se
    dq.pop_front(); // 5 remove hua. Deque: [10, 20]
    dq.pop_back();  // 20 remove hua. Deque: [10]

    // Access: First element check
    if (!dq.empty())
    {
        cout << "Bacha hua element: " << dq.front() << endl;
    }

    return 0;
}