#include<iostream>
#include<stack>
#include<string>
using namespace std;

 string makeGood(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && abs(st.top() - c) == 32) {
                st.pop();
            }
            else {
                st.push(c);
            }
        }

        string rezultati;
        
        while (!st.empty()) {
            rezultati += st.top();
            st.pop();
        }
      string rezultatifinal = rezultati;
      
      for(int i = 0 ; i < rezultati.length() ; i++){
            rezultatifinal[i] = rezultati[rezultati.length() -1 - i];
      }
        return rezultatifinal;
    }

    int main() {
        string S = "leEeetCode";
        cout << makeGood(S) << endl;
        return 0;
    }