#include "sort.h"
#include <vector>
using namespace std;

void bubble_sort(vector<int> &arr) {
    size_t n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

int main() {
    // test1
    vector<int> test1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubble_sort(test1);
    show_arr(test1);
}