/*Detyra jep dy vektor me te dhena, njeri paraqet femijet dhe tjetri paraqet disa pako me biskota. Ve vektorin e par, secila vler tregon se 
me sa biskota e deshiron pakon femija, ndersa e dyta tregon se sa biskota ka njera pako brenda. Ne duhet ti japim femijeve pakon qe deshirojn.
Ne fund duhet ta kthejm si rezultat se sa femijeve kemi arritur te ju japim biskota.

Ne fillim, duke perdorur librarin <algorithm> i sortojm te dy vektoret nga vlera me e vogel tek vlera me e madhe, ne mnyr qe te femijeve me 
tu pershtaten kerkesat nga vlerat me te vogla.
Pastaj i inicializojm variablat  numeruesi (i cili numeron se sa femijeve u kemi dhene biskota), femija(qe tregon se sa femijeve u kemi dhene
biskota), si dhe biskota (i cili tregon se sa eshte numri i biskotave qe kemi dhene), keto tri variabla do te perdoren per te testuar kushtin
kemi ende femij pa ju dhene biskota, si dhe kur kemi ende pako me biskota.
Nje while loop do te ekzekutohet derisa te kemi femij pa ju dhene biskota si dhe deri sa te kemi pako te biskotave pa dhene ende. 
Pastaj kontrollohet nje kusht kur numri i biskotave ne pakon aktuale eshte me i madh ose baraz me numrin e biskotave qe kerkon femija aktual.
Nese ky kusht plotesohet ateher do ta rrisim variablen numeruesi, femija dhe biskota (qe dmth nje femije i dham nje biskot, kalojm tek
femija tjeter si dhe kalojm tek pakoja tjeter) kurse nese ky kusht nuk plotesohet ateher vetem vazhdojm ne pakon e ardhshme te biskotes.
Ne fund e kthejm si rezultat numrin e femijeve qe u kemi dhene pako me biskota

Kompleksiteti kohor i ketij kodi eshte O(n) ku n eshte numri i femijeve apo biskotave sepse while loopi do te ekzekutohet n here.
Kompleksiteti hapesinor i ketij kodi eshte O(1) sepse kodi ekzekutohet deri ne fund pa shtuar variabla te reja ne varesi te n
pra deri ne fund shfrytezohen vetem variablat numeruesi, femija dhe biskota.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int numeruesi = 0;
    int femija = 0;
    int biskota = 0;

    while (femija < g.size() && biskota < s.size()) {
        if (s[biskota] >= g[femija]) {
            numeruesi++;
            femija++;
            biskota++;
        } else {
            biskota++;
        }
    }

    return numeruesi;
}

int main() {
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    int rezultati = findContentChildren(g, s);
    cout << "Numri i femijeve qe kan marre biskota: " << rezultati << endl;

    return 0;
}