#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec1 = {1, 2, 3, 4, 5, 6};

    int sz = vec1.size();
    cout << sz << endl;

    int cap = vec1.capacity();
    cout << cap << endl;

    vec1.pop_back();
    int frnt = vec1.front();
    cout << frnt << endl;

    for (int i : vec1)
    {
        cout << i << " ";
    }

    return 0;
}