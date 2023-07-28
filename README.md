# leetcode-solution

leetcode 题解 - 个人训练题集(c++)

> 基于 Clion 的 `Leetcode Editor` 插件 + `Single File Execution` 插件

## 0.Clion插件配置

- Code Template

```c++
${question.content}

\#include "headers.h"

${question.code}

int main() {
  Solution s;
  vector<int> arr{7, 1, 5, 3, 6, 4};
  auto res = s.twoSum(arr, 11);
  showVector(res);
}
```

headers.h 文件所在路径: `leetcode/editor/cn/headers.h`

> link template: (./leetcode/editor/cn/)

## 1.动态规划

- [x] [509-斐波那契数列](./leetcode/editor/cn/509-fibonacci-number.cpp)
- [x] [70-爬楼梯](./leetcode/editor/cn/70-climbing-stairs.cpp)
- [x] [746-使用最小花费爬楼梯](./leetcode/editor/cn/746-min-cost-climbing-stairs.cpp)
- [x] [62-不同路径](./leetcode/editor/cn/62-unique-paths.cpp)
- [x] [63-不同路径II](./leetcode/editor/cn/63-unique-paths-ii.cpp)
- [x] [343-整数拆分](./leetcode/editor/cn/343-integer-break.cpp)
- [x] [96-不同的二叉搜索树](./leetcode/editor/cn/96-unique-binary-search-trees.cpp)

### 01背包

- [x] [416-分割等和子集](./leetcode/editor/cn/416-partition-equal-subset-sum.cpp)
- [x] [1049-最后一块石头的重量II](./leetcode/editor/cn/1049-last-stone-weight-ii.cpp)
- [x] [494-目标和](./leetcode/editor/cn/494-target-sum.cpp)
- [x] [474-一和零](./leetcode/editor/cn/474-ones-and-zeroes.cpp)
- [x] [2787-将一个数字表示成幂的和的方案数(109双周赛,T4)](./leetcode/editor/cn/2787-ways-to-express-an-integer-as-sum-of-powers.cpp)

### 完全背包

- [x] [518-零钱兑换II](./leetcode/editor/cn/518-coin-change-ii.cpp)
- [x] [377-组合总和Ⅳ](./leetcode/editor/cn/377-combination-sum-iv.cpp)
- [x] [70-爬楼梯(进阶版)](./leetcode/editor/cn/70-climbing-stairs.cpp)
- [x] [322-零钱兑换](./leetcode/editor/cn/322-coin-change.cpp)
- [x] [279-完全平方数](./leetcode/editor/cn/279-perfect-squares.cpp)
- [x] [139-单词拆分(也可用回溯法，但动态规划的时间复杂度更优)](./leetcode/editor/cn/139-word-break.cpp)

### 打家劫舍篇

- [x] [198-打家劫舍](./leetcode/editor/cn/198-house-robber.cpp)
- [x] [213-打家劫舍II](./leetcode/editor/cn/213-house-robber-ii.cpp)
- [x] [337-打家劫舍III (树形DP)](./leetcode/editor/cn/337-house-robber-iii.cpp)

### 股票买卖篇

- [x] [121-买卖股票的最佳时机](./leetcode/editor/cn/121-best-time-to-buy-and-sell-stock.cpp)
- [x] [122-买卖股票的最佳时机II](./leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp)
- [x] [123-买卖股票的最佳时机III](./leetcode/editor/cn/123-best-time-to-buy-and-sell-stock-iii.cpp)
- [x] [188-买卖股票的最佳时机IV](./leetcode/editor/cn/188-best-time-to-buy-and-sell-stock-iv.cpp)
- [x] [309-最佳买卖股票时机含冷冻期](./leetcode/editor/cn/309-best-time-to-buy-and-sell-stock-with-cooldown.cpp)
- [x] [714-买卖股票的最佳时机含手续费](./leetcode/editor/cn/714-best-time-to-buy-and-sell-stock-with-transaction-fee.cpp)

### 子序列/子数组篇

- [x] [300-最长递增子序列](./leetcode/editor/cn/300-longest-increasing-subsequence.cpp)
- [x] [674-最长连续递增序列](./leetcode/editor/cn/674-longest-continuous-increasing-subsequence.cpp)
- [ ] 718-最长重复子数组
- [ ] 1143-最长公共子序列
- [ ] 1035.不相交的线
- [ ] 53-最大子序和
- [ ] 115-不同的子序列
- [ ] 583-两个字符串的删除操作
- [ ] 72-编辑距离
- [ ] 647-回文子串
- [ ] 516-最长回文子序列

## 2.贪心算法
- [ ] 455-分发饼干
- [ ] [376-摆动序列](./leetcode/editor/cn/376-wiggle-subsequence.cpp)

## 3.回溯法

- [ ] 980-不同路径III

## 3.周赛(T1)

- [x] [2778-特殊元素平方和](./leetcode/editor/cn/2778-sum-of-squares-of-special-elements.cpp)
- [x] [2769-找出最大的可达成数字](./leetcode/editor/cn/2769-find-the-maximum-achievable-number.cpp)
- [x] [2765-最长交替子序列(写得有点复杂了)](./leetcode/editor/cn/2765-longest-alternating-subarray.cpp)

### 动态规划篇(先按分数排序, 刷完后再分类)

- [x] [2320-统计放置房子的方式数](./leetcode/editor/cn/2320-count-number-of-ways-to-place-houses.cpp)
- [ ] 2140-解决智力问题
- [ ] 2321-拼接数组的最大分数
- [ ] 2266-统计打字方案数
- [ ] 2305-公平分发饼干

## 待刷题单:

- [【灵茶山艾府】2022 年周赛题目总结（上篇）](https://leetcode.cn/circle/discuss/G0n5iY/%20%E4%BD%9C%E8%80%85%EF%BC%9A%E7%81%B5%E8%8C%B6%E5%B1%B1%E8%89%BE%E5%BA%9C%20https://www.bilibili.com/read/cv17607968?spm_id_from=333.999.0.0%20%E5%87%BA%E5%A4%84%EF%BC%9Abilibili)
- [2022 年周赛题目总结（下篇）](https://leetcode.cn/circle/discuss/WR1MJP/%20%E4%BD%9C%E8%80%85%EF%BC%9A%E7%81%B5%E8%8C%B6%E5%B1%B1%E8%89%BE%E5%BA%9C%20https://www.bilibili.com/read/cv20923021?spm_id_from=333.999.0.0%20%E5%87%BA%E5%A4%84%EF%BC%9Abilibili)
