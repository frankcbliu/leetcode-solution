#include "sort.h"
#include <vector>
using namespace std;

void select_sort(vector<int> &arr) {
    size_t n = arr.size();
    // 从 0 到 n-2，每次找到最小值，然后替换位置；n-1只剩一个，所以不用换
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        swap(arr, i, min_idx);
    }
}

int main() {
    // test1
    vector<int> test1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    select_sort(test1);
    show_arr(test1);
}