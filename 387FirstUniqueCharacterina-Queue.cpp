/*Detyra kerkon qe ta gjejm indeksin e shkronjes se pare qe nuk perseritet ne nje string
Per kete e marrim nje varg me 26 vlera(qe paraqesin numrin e shkonjave te alfabetit), ku do te paraqesin frekuencen e perseritjes
se shkronjave ne string, ne fillim te gjitha frekuencat jan 0.
Pastaj ne for loopin e par iterojm ne secilen shkronj te stringut dhe persecilen shkronj qe e shhqyrtojm e rrisim frekuencen per nje (++);
meqe po punojm me varg dhe numerimi fillon nga 0 ateher shkronjes se stringut (qe reprezentohet me variablen c) zvogelohet per a (qe ka vler 0), 
kshtuqe ky veprim do te ktheje si vler nje numer e qe paraqet nje indeks te shkronjes perkatese ne vargun frekuenca i cili indeks rritet per nje dhe
tregon qe shkronja u perdor nje her. Kshtu per te gjitha shkronjat e stringut e paraqesim se sa her jan perseritur

Ne fund permes nje for loopi kontrollojm se cila esht shkronja e par qe e ka frekuencen 1 pra qe esht perseritur nje her dhe e kthejm ate indeks
Nese ajo nuk gjendet e kthejm vleren -1
*/

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