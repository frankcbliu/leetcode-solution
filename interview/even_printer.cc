#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class Printer {
  private:
  mutex mtx;
  int max_num;
  int current;
  bool is_odd_turn;
  condition_variable cv;

  public:
  Printer(int max) : max_num(max), current(1), is_odd_turn(true) {}
  void run();
  void EvenPrinter();
  void OddPrinter();
};

void Printer::EvenPrinter() {
  while (true) {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [this]() {
      return !is_odd_turn || current > max_num;
    });

    if (current > max_num) break;

    cout << "Even: " << current << endl;
    current++;

    is_odd_turn = true;

    cv.notify_all();
  }
}

void Printer::OddPrinter() {
  while (true) {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [this]() {
      return is_odd_turn || current > max_num;
    });
    if (current > max_num) break;

    cout << "Odd: " << current << endl;
    current++;

    is_odd_turn = false;

    cv.notify_all();
  }
}

void Printer::run() {
  thread t1(&Printer::OddPrinter, this);
  thread t2(&Printer::EvenPrinter, this);

  t1.join();
  t2.join();
}

int main() {
  Printer print(10);
  print.run();
}