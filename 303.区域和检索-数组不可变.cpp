/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// 解法：一维前缀和

// @lc code=start
class NumArray {
 public:
  NumArray(vector<int>& nums) {
    // 多预留一个空间，sum[1] = nums[0], 方便写循环
    sum.resize(nums.size() + 1);
    for (int i = 0; i < nums.size(); i++) {
      sum[i + 1] = sum[i] + nums[i];
    }
  }

  int sumRange(int left, int right) {
    // sum[right + 1] 实际上是 0-right 的和
    // sum[left] 则是 0-(left-1) 的和
    // 两者相减得到的便是 left 到 right 的和
    return sum[right + 1] - sum[left];
  }

 private:
  vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
