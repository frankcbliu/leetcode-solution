#include "sort.h"
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int r) {
    // 边界1: 注意数组大小
    int n = r - l + 1;
    vector<int> help(n);
    // 归并排序合并，两部分都是各自已经排好序的
    int i = 0;
    int p1 = l;
    int p2 = mid + 1;
    // 双指针往后走，任一指针走完结束
    while (p1 <= mid && p2 <= r) {
        help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }

    while (p1 <= mid) {
        help[i++] = arr[p1++];
    }

    while (p2 <= mid) {
        help[i++] = arr[p2++];
    }

    //  替换方案
    //  copy(help.begin(), help.end(), arr.begin() + l);
    for (int j = 0; j < n; ++j) {
        arr[l + j] = help[j];
    }
}

// 二分
void merge_sort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

// 归并排序
void merge_sort(vector<int> &arr) {
    merge_sort(arr, 0, arr.size() - 1);
}

int main() {
    // test1
    vector<int> test1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(test1);
    show_arr(test1);
}