#include<iostream>
#include<stack>
#include<string>
using namespace std;

  string removeDuplicates(string s) {
        stack<char> stacki;
        
        for (char c : s) {
            if (!stacki.empty() && stacki.top() == c) {
                stacki.pop();
            } else {
                stacki.push(c);
            }
        }
        
        string rezultati;
        while (!stacki.empty()) {
            rezultati = stacki.top() + rezultati;
            stacki.pop();
        }
        
        return rezultati;
    }

int main() { 
    string S = "abbaca";
    cout << removeDuplicates(S) << endl;
    return 0;
}