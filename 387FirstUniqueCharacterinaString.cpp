#include<iostream>
#include<string>
using namespace std;

int firstUniqChar(string s) {
        int frekuenca[26] = {0}; // ne fillim te gjitha shkronjat e kan frekuencen 0, e pastaj saher qe perdoren inkrementohet per nga nje (line 9)

        for (char c : s) {
            frekuenca[c - 'a']++;// per fjalen "leetcode" frekuencat jan a = 0, b = 0 , l = 1, e = 2...
        }

        for (int i = 0; i < s.length(); i++) {
            if (frekuenca[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }

int main() {
    string S = "leetcode";
    cout << firstUniqChar(S) << endl;
    return 0;
}