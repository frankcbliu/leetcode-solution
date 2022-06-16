// @algorithm @lc id=1 lang=cpp
// @title two-sum

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([2,7,11,15],9)=[0,1]
// @test([3,2,4],6)=[1,2]
// @test([3,3],6)=[0,1]
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    // 方法1: 
    // 目标 target = a + b, 用哈希表存储 a->b / b->a 的关系
    // 在判断之后才填值，使得可以通过顺序方式遍历 nums
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
      auto it = hash.find(target - nums[i]);
      if (it != hash.end()) {
        return {it->second, i};
      }
      hash[nums[i]] = i;
    }
    return {};
  }
};