#include "sort.h"
#include <random>
#include <vector>
using namespace std;


// 随机数获取: 左闭右闭区间
int random_l_r(int l, int r) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(l, r);
  return dis(gen);
}
// 快速排序的核心原理
// 每次随机寻找基准，放在最后一位，然后把左边的数据按小于基准和大于基准进行排列。排列完成后，对小于的区间和大于的区间，分别进行递归的 partition 操作

vector<int> partition(vector<int> &arr, int l, int r) {
  int less = l - 1;
  int more = r;
  while (l < more) {
    if (arr[l] < arr[r]) {// 小于区间
      swap(arr, ++less, l++);
    } else if (arr[l] > arr[r]) {
      swap(arr, --more, l);
    } else {
      l++;
    }
  }
  swap(arr, more, r);
  return vector<int>{less, more + 1};
}


void quick_sort(vector<int> &arr, int l, int r) {
  if (l < r) {
    // 使用 l 作为基准值
    swap(arr, l, r);
    // partition
    vector<int> p = partition(arr, l, r);
    quick_sort(arr, l, p[0]);
    quick_sort(arr, p[1], r);
  }
}

void quick_sort(vector<int> &arr) {
  if (arr.empty()) return;
  quick_sort(arr, 0, arr.size() - 1);
}


int main() {
  // test1
  vector<int> test1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  quick_sort(test1);
  show_arr(test1);
}