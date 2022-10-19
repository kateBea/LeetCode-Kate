#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2);
        int i, j;
        bool found = false;
        i = j = 0;
        while (i < nums.size() and not found) {
            j = i;
            ++j;
            while (j < nums.size() and not found) {
                if (nums[i]+nums[j] == target) {
                    found = true;
                    ret[0] = i;
                    ret[1] = j;
                }
                else ++j;
            }
            ++i;
        }
        return ret;
    }   
};