#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> nums{1,2,3,4};
    for(int i = 0; i<nums.size(); i++)
    {
        cout<<nums[i]<<'\n';
    }
    return 0;
}
