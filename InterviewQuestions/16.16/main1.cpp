// 有问题，尚未解决。

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
        bool haveRightFlag = false;
        
        if (array.size() <= 1) {
            return {-1, -1};
        }

        for (std::vector<int>::iterator iter = array.begin(); iter != array.end(); iter++) {
            auto maxLeft = std::max_element(array.begin(), iter);
            auto minRight = std::min_element(iter, array.end());

            if (*maxLeft <= *minRight) {
                continue;
            } else {
                if (!haveRightFlag) {
                    left = std::distance(array.begin(), iter);
                    haveRightFlag = true;
                }
                right = std::distance(array.begin(), iter);
            }

        }

        if ((left == 0) && (right == 0)) {
            return {-1, -1};
        }
        return {left, right};
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
    std::vector<int> array = {1,3,9,7,5};
    auto i = std::min_element(array.end(), array.end());
    std::cout << *i << std::endl;
    Solution().subSort(array);
    std::cout << Solution().subSort(array)[0] << std::endl;
    std::cout << Solution().subSort(array)[1] << std::endl;
    return 0;
}