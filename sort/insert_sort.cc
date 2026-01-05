#include "sort.h"
#include <vector>
using namespace std;

void insert_sort(vector<int> &arr) {
    size_t n = arr.size();
    for (int i = 1; i < n; ++i) {
        // 下一张手牌，要往前找到合适的位置插入
        for (int j = i; arr[j - 1] > arr[j] && j > 0; --j) {  // 插入方式就是往前一直交换，直到遇到比自己小的才停止
            swap(arr, j - 1, j);
        }
    }
}

int main() {
    // test1
    vector<int> test1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    insert_sort(test1);
    show_arr(test1);
}