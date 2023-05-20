/*Detyra kerkon qe ne nje string me nje fjali te parregullt, ti ndrrojm vendet fjaleve ne mnyr qe fjalia te ket kuptim, nderkoh qe
 secila fjal e ka ne fund nje numer (qe tregon numrin rendor qe duhet ra ket) dhe ne baz te atyre numrave duhet ta bejm renditjen
 
 Krijohet nje vektor me emrin fjalia qe do te ket 9 anetar, si dhe krijohet nje string me emrin fjala. 
 Stringut i shtohet nje hapesir, ne fund per ta shfrytezuar si kusht qe ka perfunduar edhe fjala e fundit.
 iterojm ne secilin element te stringut, deri sa nuk arrijm deri tek nje hapesir, c == ' '  , ekzekutohet pjesa e else, dmth qe shkronjat e 
 fjales se par vendosen ne stringun fjala (fjala += c;) , posa arrijm tek nje hapesir, ateher i japim variables pozicioniFjales 
 (qe tregon poziten ku do ta vendosim fjalen ne vargun e sortuar)
 vleren e fundit te fjales ne mnyr qe ajo fjal te vendoset ne ate pozit ne vektorin fjalia, fjales i largojm numrin e fundit (fjala.pop_back();)
 dhe ne poziten per nje me te vogel sesa numri rendites vendoset ne vektorin fjalia (sepse ne vektor numerimi i pozitave fillon nga 0)
 stringu fjala zbrazet (fjala.clear();) per te marr fjalen tjeter...
 Pasi qe fjalet (tashme te sortuara) jan te vendosura ne vektorin fjalia ato vendosen ne nje string result (i cili do te kthehet si rezultat)
 mirepo duhet qe te kujdesemi, qe ti ndajm fjalet me nga nje hapesir, ne fund e hjekim elementin e fundit ne string (e qe eshte hapesira qe e kemi
 shtuar ne fillim, (s += ' '; ) per ta ndare edhe fjalen e fundit) dhe e kthejm rezultatin
 
Kompleksiteti kohor i ketij kodi eshte O(n) ku n eshte numri i fjaleve qe hyjn si input, sepse aq iterime do te ken for loopat, 
per ti vendosuar n-fjalet e sortuara ne vektorin fjalia
Kompleksiteti hapesinor eshte poashtu O(n) sepse kodi krijon stringun fjala dhe result qe kerkojn hapesir ne varesi te n (aq sa fjal jan si 
input hyres)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string sortSentence(string s) {
    vector<string> fjalia(9); // ne leetcode ceket qe si input mund te ket me se shumri 9 anetar.
    string fjala;

//sortimi
    s += ' '; 
    for (char c : s) {                        //
        if (c == ' ') {
            int pozicioniFjales = fjala.back() - '0';
            fjala.pop_back();
            fjalia[pozicioniFjales - 1] = fjala;
            fjala.clear();
        } else {
            fjala += c;
        }
    }
    //ndarja e fjaleve me hapesir
    string result;
    for (int i = 0; i < fjalia.size(); ++i) {
        if (!fjalia[i].empty()) {
            result += fjalia[i];
            result += " ";
        }
    }
    result.pop_back();
    return result;
    
}

int main() {
    string s = "is2 sentence4 This1 a3";
    string sortedSentence = sortSentence(s);
    
    cout << "Fjalia e sortuar: " << sortedSentence << endl;
    
    return 0;
}
