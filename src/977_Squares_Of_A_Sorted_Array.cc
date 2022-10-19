#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        const int limit = nums.size();
        int positive_pointer = 0;
        int negative_pointer;

        vector<int> ret_nums(limit);

        while (positive_pointer < limit and nums[positive_pointer] < 0)
            ++positive_pointer;

        negative_pointer = positive_pointer - 1;
        int it_aux = 0;
        while (negative_pointer > -1 and positive_pointer < limit)
        {
            int square_negative = nums[negative_pointer] * nums[negative_pointer];
            int square_positive = nums[positive_pointer] * nums[positive_pointer];
            if (square_negative <= square_positive)
            {
                ret_nums[it_aux++] = square_negative;
                --negative_pointer;
            }
            else
            {
                ret_nums[it_aux++] = square_positive;
                ++positive_pointer;
            }
        }

        while (negative_pointer > -1)
        {
            ret_nums[it_aux++] = nums[negative_pointer] * nums[negative_pointer];
            --negative_pointer;
        }
        while (positive_pointer < limit)
        {
            ret_nums[it_aux++] = nums[positive_pointer] * nums[positive_pointer];
            ++positive_pointer;
        }
        return ret_nums;
    }
};