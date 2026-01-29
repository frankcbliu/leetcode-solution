//
// Created by frankcbliu on 2026/1/30.
//
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class OddPrinter {
  private:
  int current;
  int max_num;
  mutex mtx;
  std::condition_variable cv;
  bool is_odd_turn;

  public:
  OddPrinter(int max) : current(1), max_num(max), is_odd_turn(true) {}

  void printOdd(); // 奇数线程函数
  void printEven();// 偶数线程函数
  void run();      // 线程启动
};

void OddPrinter::printOdd() {
  while (true) {
    std::unique_lock<mutex> lock(mtx);
    // 奇数，或者数已经到达边界，需要唤醒线程并且往后走
    cv.wait(lock, [this]() {
      return is_odd_turn || current > max_num;
    });

    // 超出边界， 结束线程
    if (current > max_num) break;

    cout << "Odd: " << current << endl;
    current++;

    is_odd_turn = false;

    // 唤醒
    cv.notify_all();
  }
}

void OddPrinter::printEven() {
  while (true) {
    std::unique_lock<mutex> lock(mtx);
    cv.wait(lock, [this]() {
      return !is_odd_turn || current > max_num;
    });

    if (current > max_num) break;

    cout << "Even: " << current << endl;
    ++current;

    is_odd_turn = true;
    cv.notify_all();
  }
}

void OddPrinter::run() {
  thread t1(&OddPrinter::printOdd, this);
  thread t2(&OddPrinter::printEven, this);

  t1.join();
  t2.join();
}

int main() {
  OddPrinter odd_printer(10);
  odd_printer.run();
  return 0;
}