/*
 * 临时测试使用
 */
#include <iostream>
#include <vector>
using namespace std;

// dp题目单
//2266. 统计打字方案数(比较复杂) https://leetcode.cn/problems/count-number-of-texts/

// 第一个大于等于 num 的元素下标
int binarySearch(vector<int> &arr, int num) {
  int l = 0;
  int r = arr.size();

  while (l < r) {
    int mid = l + (r - l) / 2;
    if (arr[mid] < num) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}

int main() {
  vector<int> arr{1, 1, 2, 2, 3, 3, 3, 5, 5};
  vector<int> idx{0, 1, 2, 3, 4, 5, 6, 7, 8};
  int res = binarySearch(arr, 4);
  cout << "idx: " << res << " val: " << arr[res];
}
