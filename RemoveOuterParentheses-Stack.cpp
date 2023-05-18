#include<iostream>
#include<stack>
using namespace std;

string removeOuterParentheses(string s) {
    std::stack<char> stack;
    std::string result;

    for (char c : s) {
        if (c == '(') {
            if (!stack.empty()) {
                result += c;
            }
            stack.push(c);
        }
        else {
            stack.pop();
            if (!stack.empty()) {
                result += c;
            }
        }
    }

    return result;

}

int main() {
    string S = "(()())(())";
    cout << removeOuterParentheses(S) << endl;
    return 0;
}