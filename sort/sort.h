//
// Created by 菜饼 on 26-1-5.
//

#ifndef LEETCODE_SORT_H
#define LEETCODE_SORT_H

#include <iostream>
#include <vector>

using namespace std;

void show_arr(const vector<int> &arr) {
    for (int i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

void swap(vector<int> &arr, int i, int j) {
//    cout << "swap: arr[" << i << "]" << arr[i] << " [" << j << "]" << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

#endif//LEETCODE_SORT_H
