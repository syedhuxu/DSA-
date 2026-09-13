#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void reverseVector(vector<int> &vec1, int sz)
{
    int st = 0;
    int end = sz - 1;

    while (st < end)
    {
        swap(vec1[st], vec1[end]);
        st++;
        end--;
    }
}

int main()
{
    vector<int> vec1 = {5, 4, 3, 2, 1, 0};
    int sz = vec1.size();

    reverseVector(vec1, sz);

    for (int val : vec1)
    {
        cout << val << " ";
    }

    return 0;
}