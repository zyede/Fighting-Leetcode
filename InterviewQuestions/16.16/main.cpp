
#include <algorithm>
#include <vector>
#include <ostream>
#include <iostream>

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();

public:
    std::vector<int> subSort(std::vector<int> &array) {
        int left, right = 0;
        int len = array.size() - 1;
        
        if (array.size() <= 1) {
            return {-1, -1};
        }
        
        for (std::vector<int>::iterator iter = array.begin(); iter != array.end(); iter++) {
            auto maxRight = std::max_element(array.begin(), iter+1);
            auto minLeft = std::min_element(iter+1, array.end());
            left = std::distance(array.begin(), iter);
            if (*maxRight < *minLeft) {
                continue;
            } else {
                break;
            }
        }

        for (std::vector<int>::reverse_iterator iter = array.rbegin(); iter != array.rend(); iter++) {
            auto maxRight = std::max_element(iter+1, array.rend());
            auto minLeft = std::min_element(array.rbegin(), iter+1);
            right = std::distance(array.rbegin(), iter);
            if (*minLeft > *maxRight) {
                continue;
            } else {
                break;
            }
        }

        if ((left == len) && (right == len)) {
            return {-1, -1};
        }
        return {left, len - right};
    }
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}


int main()
{
    std::vector<int> array = {1,3,5,7,9};
    Solution().subSort(array);
    std::cout << Solution().subSort(array)[0] << std::endl;
    std::cout << Solution().subSort(array)[1] << std::endl;
    return 0;
}