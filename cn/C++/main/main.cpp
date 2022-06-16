#include "question/2_Add_Two_Numbers.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[2,4,3]\",\"[5,6,4]\"],[\"[0]\",\"[0]\"],[\"[9,9,9,9,9,9,9]\",\"[9,9,9,9]\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      ListNode * arg0 = parseListNode(args[0]);
      ListNode * arg1 = parseListNode(args[1]);
      ListNode * result=s->addTwoNumbers(arg0,arg1);
      string resultabc =serializeListNode(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}