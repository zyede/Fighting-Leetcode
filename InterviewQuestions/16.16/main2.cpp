// 本地测试一切正常，leetcode就是过不了。

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
        int left = 0;
        int right = 0;
        int len = array.size() - 1;
        bool haveRightFlag = false;
        
        if (array.size() <= 1) {
            return {-1, -1};
        }

        for (std::vector<int>::iterator iter = array.begin(); iter != array.end(); iter++) {
            auto maxLeft = std::max_element(array.begin(), iter+1);
            auto minRight = std::min_element(iter+1, array.end());
            left = std::distance(array.begin(), iter);
            if (*maxLeft < *minRight) {
                continue;
            } else {
                break;
            }
        }

        for (std::vector<int>::reverse_iterator iter = array.rbegin(); iter != array.rend(); iter++) {
            auto maxLeft = std::max_element(iter+1, array.rend());
            auto minRight = std::min_element(array.rbegin(), iter+1);
            right = std::distance(array.rbegin(), iter);
            if (*minRight > *maxLeft) {
                continue;
            } else {
                break;
            }
        }

        if (left == len) {
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
    std::vector<int> array = {1, 2, 3, 4, 5};
    auto i = std::min_element(array.end(), array.end());
    std::cout << *i << std::endl;
    Solution().subSort(array);
    std::cout << Solution().subSort(array)[0] << std::endl;
    std::cout << Solution().subSort(array)[1] << std::endl;
    return 0;
}