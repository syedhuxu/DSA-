#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> &vec1, int sz, int target)
{
    for (int i = 0; i < sz; i++)
    {
        if (vec1[i] == target)
        {
            return i;
        }
    }
}

int main()
{
    vector<int> vec1 = {1, 2, 3, 4, 5, 6};
    int sz = vec1.size();
    int target = 6;

    int result = linearSearch(vec1, sz, target);
    cout << result << endl;

    return 0;
}