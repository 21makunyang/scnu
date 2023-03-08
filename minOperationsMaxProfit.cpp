#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool clear(vector<int> &ferr)
    {
        for (int i = 0; i < 4; i++)
        {
            if (ferr[0] != 0)
            {
                return false;
            }
        }
        return true;
    }
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost)
    {
        if (boardingCost * 4 < runningCost)
        {
            return -1;
        }
        int waitingPeo = 0, nextPeopleNum = 0;
        int earn = 0;
        int leastNum = 1;
        for (int i = 0; i < 4; i++)
        {
            if (i * boardingCost >= runningCost)
            {
                leastNum = i;
                break;
            }
        }

        vector<int> ferriswheel;

        for (int i = 0; i < 4; i++)
        {
            ferriswheel.push_back(0);
        }
        int AllTime = customers.size();
        bool stop;

        for (int i = 0; i < AllTime; i++)
        {
            waitingPeo += customers[i];
            nextPeopleNum = min(4, waitingPeo);
            // stop
            if (waitingPeo == 0 && stop)
            {
                continue;
            }
            if (stop && nextPeopleNum < leastNum)
            {
                continue;
            }

            earn = earn - runningCost;
            waitingPeo -= nextPeopleNum;
            earn += nextPeopleNum * boardingCost;

            ferriswheel.erase(ferriswheel.begin());
            ferriswheel.push_back(nextPeopleNum);
            stop = clear(ferriswheel);
        }

        while (waitingPeo != 0 || !clear(ferriswheel))
        {
            nextPeopleNum = min(4, waitingPeo);
            if(nextPeopleNum < leastNum){
                break;
            }
            earn = earn - runningCost;
            waitingPeo -= nextPeopleNum;
            earn += nextPeopleNum * boardingCost;

            ferriswheel.erase(ferriswheel.begin());
            ferriswheel.push_back(nextPeopleNum);
        }
        earn-=4*runningCost;

        if(earn<0){
            return -1;
        }
        return earn;
    }
};

int main(){
    Solution so;
    vector<int> nums{8,3};
    cout<<so.minOperationsMaxProfit(nums,5,6);

    return 0;
}