/*detyra kerkon qe ti largojm shkronjat qe perseriten nje pas nje ne nje string
E deklarojm nje stack ku do ti vendosim vlerat qe mbesin te paperseritura
Iterojm ne string me variablen c, nese stack nuk esht i zbrazet ateher e vendosim karakterin e stringut. 
Nese stack nuk esht i zbrazet si dhe nese ai karakter gjendet ne stack ateher e largojm nga stack (stacki.pop())
Pra i largojm elementet qe perseriten, ato qe me heret veq jan vendosur ne stack

Ne fund elementet qe na kan mbetur ne stack i vendosim ne stringun rezultati, per ta kthyer si return

Kompleksiteti kohor i ketij kodi eshte O(n), ku n eshte numri i karaktereve ne stringun hyres s, sepse ne cdo rast permes for loopit
duhet qe te iterojm neper te gjitha ato karaktere per ti krahasuar
Kompleksiteti hapesinor i ketij kodi eshte poashtu O(n) ku n eshte numri i karaktereve te stringut s
sepse stringu rezultati ne rastin me te keq mund te ket karaktere sa vet stringu 
hyres, ne rastin kur nuk ka shkronja qe perseriten
*/

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