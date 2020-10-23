
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
        std::vector<int> sortArray = array;
        std::vector<int> result;
        int left = 0;
        int right = 0;
        bool haveRightFlag = false;
        
        if (array.size() <= 1) {
            return {-1, -1};
        }

        std::sort(sortArray.begin(), sortArray.end());

        for (int i = 0; i < array.size(); i++) {
            if (sortArray[i] != array[i]) {
                left = i;
                break;
            }
        }

        for (int j = array.size(); j > 0; j--) {
            if (sortArray[j-1] != array[j-1]) {
                right = j - 1;
                break;
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
    std::vector<int> array = {1, 3, 9, 7, 5};
    auto i = std::min_element(array.end(), array.end());
    std::cout << *i << std::endl;
    std::vector<int> result = Solution().subSort(array);
    std::cout << result[0] << std::endl;
    std::cout << result[1] << std::endl;
    return 0;
}