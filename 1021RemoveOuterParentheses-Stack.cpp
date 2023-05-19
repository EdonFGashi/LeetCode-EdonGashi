//Detyra kerkon qe brenda nje vargu me kllapa ti largojm kllapat e jashtme dhe te krijojm nje varg te rregullt te kllapave p.sh. ()()()

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