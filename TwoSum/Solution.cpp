#include <map>

// "Two sum"

//https://t.me/cpptasks

//https://leetcode.com/problems/two-sum/

class Solution {
public:
    
    //better by memory (28.52% by speed, 98.12% by memory on leetcode)
    /*std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }*/
    
    //better by speed (95.19% by speed, 28.36 by memory on leetcode)
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> storage;
        for(int i = 0; i < nums.size(); i++) {
            auto found = storage.find(target - nums[i]);
            if(found != storage.end()) {
                return {found->second, i};
            }
            storage[nums[i]] = i;
        }
        return {-1, -1};
    }
};
