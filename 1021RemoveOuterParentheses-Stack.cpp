/*Detyra kerkon qe brenda nje vargu me kllapa ti largojm kllapat e jashtme dhe te krijojm nje varg te rregullt te kllapave p.sh. ()()()
Ne fillim e krijojm nje funksion removeOuterParentheses te tipit string, nje stack qe ruan karaktere si dhe nje string rezultati. Permes nje
for loopi iterojm ne secilin element te inputit hyres (ku ka kllapa) dhe nese e gjejm nje kllap hapese ateher e shtojm ne stack, mirepo
nese stacki nuk eshte i zbrazet e shtojm edhe ne rezultat. Perndryshe nese nuk kemi kllap hapese atehere largojm nga stacki kllapen e fundit
si dhe nese stacki nuk eshte i zbrazet i vendosim ne rezultat, ne fund e kthejm rezultatin.

Kompleksiteti kohor i ketij kodi eshte O(n), ku n eshte numri i karaktereve ne stringun hyres si input pra eshte gjatesia e stringut s, sepse
permes for loopit na duhet qe te iterojm neper secilin karakter.
Kompleksiteti hapesinor i ketij kodi eshte poashtu O(n) ku n eshte numri i karaktereve te stringut s
sepse stringu rezultati ne rastin me te keq mund te ket karaktere sa vet stringu 
hyres, ne rastin kur kllapat veq se jan te balancuara
*/
#include<iostream>
#include<stack>
using namespace std;

string removeOuterParentheses(string s) {
    stack<char> stack;
    string rezultati;

    for (char c : s) {
        if (c == '(') {
            if (!stack.empty()) {
                rezultati += c;
            }
            stack.push(c);
        }
        else {
            stack.pop();
            if (!stack.empty()) {
                rezultati += c;
            }
        }
    }

    return rezultati;

}

int main() {
    string S = "(()())(())";
    cout << removeOuterParentheses(S) << endl;
    return 0;
}