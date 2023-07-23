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

## 1.动态规划
- [x] 509-斐波那契数列
- [x] 70-爬楼梯
- [x] 746-使用最小花费爬楼梯
- [x] 62-不同路径
- [x] 63-不同路径II
- [x] 343-整数拆分
- [x] 96-不同的二叉搜索树

### 01背包
- [x] 416-分割等和子集
- [x] 1049-最后一块石头的重量II
- [x] 494-目标和
- [x] 474-一和零
- [x] 6922-将一个数字表示成幂的和的方案数(109双周赛,T4)

## 2.回溯法
- [ ] 980-不同路径III


## 3.周赛(T1)
- [x] 2778-特殊元素平方和
- [x] 2769-找出最大的可达成数字
- [x] 2765-最长交替子序列(写得有点复杂了)


## 待刷题单:
- [【灵茶山艾府】2022 年周赛题目总结（上篇）](https://leetcode.cn/circle/discuss/G0n5iY/%20%E4%BD%9C%E8%80%85%EF%BC%9A%E7%81%B5%E8%8C%B6%E5%B1%B1%E8%89%BE%E5%BA%9C%20https://www.bilibili.com/read/cv17607968?spm_id_from=333.999.0.0%20%E5%87%BA%E5%A4%84%EF%BC%9Abilibili)
- [2022 年周赛题目总结（下篇）](https://leetcode.cn/circle/discuss/WR1MJP/%20%E4%BD%9C%E8%80%85%EF%BC%9A%E7%81%B5%E8%8C%B6%E5%B1%B1%E8%89%BE%E5%BA%9C%20https://www.bilibili.com/read/cv20923021?spm_id_from=333.999.0.0%20%E5%87%BA%E5%A4%84%EF%BC%9Abilibili)
