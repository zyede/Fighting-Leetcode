#include <vector>


class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
        int len = intervals.size();
        for (int i = 0; i < len; i++) {
            if (intervals[i][0] > intervals[i+1][0]) {
                if (i + 1 = len) {
                    
                }
                std::swap(intervals[i], intervals[i+1]);
            }
        }
    }
};