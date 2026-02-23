//给定两个以 非递减顺序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。
//
// 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
//
// 请找到和最小的 k 个数对 (u1,v1), (u2,v2) ... (uk,vk) 。
//
//
//
// 示例 1:
//
//
//输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
//输出: [[1,2],[1,4],[1,6]]
//解释: 返回序列中的前 3 对数：
//     [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
//
//
// 示例 2:
//
//
//输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
//输出: [[1,1],[1,1]]
//解释: 返回序列中的前 2 对数：
//     [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
//
//
//
//
// 提示:
//
//
// 1 <= nums1.length, nums2.length <= 10⁵
// -10⁹ <= nums1[i], nums2[i] <= 10⁹
// nums1 和 nums2 均为 升序排列
//
// 1 <= k <= 10⁴
// k <= nums1.length * nums2.length
//
//
// Related Topics 数组 堆（优先队列） 👍 710 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

  typedef tuple<int, int, int> Tuple;

  struct PairHash {
    template<class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
      auto h1 = std::hash<T1>{}(p.first);
      auto h2 = std::hash<T2>{}(p.second);
      return h1 ^ (h2 << 1);
    }
  };

  public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<vector<int>> result;

    if (nums1.empty() || nums2.empty()) return result;

    int m = nums1.size();
    int n = nums2.size();

    // 定义最小堆
    auto cmp = [](const Tuple &a, const Tuple &b) {
      return get<0>(a) > get<0>(b);
    };
    priority_queue<Tuple, vector<Tuple>, decltype(cmp)> minHeap(cmp);

    unordered_set<pair<int, int>, PairHash> visited;
    // 初始化堆
    minHeap.emplace(nums1[0] + nums2[0], 0, 0);
    visited.insert({0, 0});

    while (!minHeap.empty() && result.size() < k) {
      // 取出堆顶
      auto [sum, i, j] = minHeap.top();
      minHeap.pop();

      // 将当前组合加入结果
      result.push_back({nums1[i], nums2[j]});
      visited.insert({i, j});

      if (i + 1 < m && !visited.count({i + 1, j})) {
        minHeap.push({nums1[i + 1] + nums2[j], i + 1, j});
        visited.insert({i + 1, j});
      }

      if (j + 1 < n && !visited.count({i, j + 1})) {
        minHeap.push({nums1[i] + nums2[j+1], i, j + 1});
        visited.insert({i, j + 1});
      }
    }
    return result;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{7, 1, 5, 3, 6, 4};
  auto res = s.twoSum(arr, 11);
  showVector(res);
}