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
- [x] 416-分割等和子集
- [x] 1049-最后一块石头的重量II
- [x] 494-目标和
- [x] 474-一和零

## 2.回溯法
- [ ] 980-不同路径III


