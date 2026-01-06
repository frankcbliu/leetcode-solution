#include "sort.h"
#include <random>
#include <vector>
using namespace std;

// 左闭右闭区间
int random_l_r(int l, int r) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(l, r);
    return dis(gen);
}

// 核心分区逻辑
vector<int> partition(vector<int> &arr, int l, int r) {
    int less = l - 1;// 小于区的右边界
    int more = r;    // 大于区的左边届
    while (l < more) {
        if (arr[l] < arr[r]) {// 小于区
            swap(arr, ++less, l++);
        } else if (arr[l] > arr[r]) {
            swap(arr, --more, l);
        } else {
            ++l;
        }
    }
    swap(arr, more, r);
    return vector<int>{less, more + 1};
}

void quick_sort(vector<int> &arr, int l, int r) {
    if (l < r) {
        // 随机数生成
        int ran = random_l_r(l, r);
        // 以随机数为基准
        swap(arr, ran, r);
        // 计算 partition 数组
        vector<int> p = partition(arr, l, r);
        quick_sort(arr, l, p[0]);
        quick_sort(arr, p[1], r);
    }
}

// 快速排序
void quick_sort(vector<int> &arr) {
    if (arr.empty()) return;
    quick_sort(arr, 0, arr.size() - 1);
}


int main() {
    // test1
    vector<int> test1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    quick_sort(test1);
    std::cout << endl;
    show_arr(test1);
}