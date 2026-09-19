#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] + nums[i] == target)
            {
                return {i, j};
            }
        }
    }

    return {};
}

int main()
{
    vector<int> nums = {100, 200, 300, 5};
    int target = 105;

    vector<int> result = twoSum(nums, target);

    cout << result[0] << " " << result[1];

    return 0;
}