/*
 * 临时测试使用
 */
#include <iostream>
using namespace std;

bool isHuiWen(string data) {
  int n = data.size();
  for (int i = 0; i < n / 2; ++i) {
    if (data[i] != data[n - 1 - i]) {
      return false;
    }
  }
  return true;
}

string change(int n, int b) {
  string res;
  int a = n;
  int c = 0;
  while (a) {
    cout << "a:" << a << " b:" << b << " c:" << c << endl;
    c = a % b;
    res = to_string(c) + res;
    a = a / b;
  }
  return res;
}

// 严格回文数
bool check(int n) {
  // b: 2~n-2
  for (int i = 2; i <= n-2; ++i) {
    string data = change(n,i);
    if (!isHuiWen(data)) {
      return false;
    }
  }
  return true;
}


int main() {
  cout << change(5, 2) << endl;
}
