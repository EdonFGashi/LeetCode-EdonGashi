/*Jepet nje vektor me disa anetar me vlera 0 ose 1, vargu paraqet disa vazo ku mund te vendosen disa lule, ndersa vlera 1 tregon se ne ate
vazo gjendet nje lule ndersa kur vlera eshte 0 tregon se ne ate vazo nuk ka lule (pra eshte e lire). Jepet nje numer n i cili tregon numrin  
e luleve qe deshirojm ti vendosim, mirepo me kushtin qe lulet te mos jen te ngjitura, pra te ken nga nje hapesir mes tyre.
Ne fund detyra kerkon qe nese eshte e mundur te vendosen lulet, te kthehet vlera true, ne te kunderten te kthehet false.

E inicializojm nje variabel (count) qe ti numeroj se sa lule jan vendosur si dhe variablen (size) e cila tregon numrin e vazove te luleve.
Iterojm neper cdp vazo te luleve dhe permes tri kushteve te if kontrollojm nese vazoja ne poziten (i) ku deshirojm ne vendoset lulja eshte 
e zbrazet dhe nese vazoja paraardhese eshte e zbrazet dhe nese vazoja pasardhese eshte e zbrazet. Nese plotesohet ky kusht, ateher do te thote se
lulja mund te mbillet ne ate vazo kshtuqe ne ate vazo e vendosim vleren 1, si dhe do ta rrisim numrin e luleve te mbjellura (count).
Nese numri i luleve te mbjellura eshte me i madh ose baraz me numrin e luleve qe kemi dashur ti mbjellim ateher e do te thote se te gjitha lulet
jan mbjellur, prandaj kthehet si vler true, ne te kunderten kur ai kusht nuk plotesohet kthehet false.

Kompleksiteti kohor i ketij kodi eshte O(n) ku n eshte numri i vazove, meqe ne do ta kontrollojm cdo vazo ateher do te thote se do te ket aq iterime
sa eshte numri i vazove (ne for loop)
Kompleksiteti hapesinor i ketij kodi eshte  O(1) sepse pergjat ekzekutimit te kodit, ato variabla qe jan deklaruar ne fillim , atyre vetem 
i nderrohen vlerat dhe nuk ndryshon numri i variablave ne varesi te n
*/

#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    int size = flowerbed.size();
    
    for (int i = 0; i < size; i++) {
        if (flowerbed[i] == 0 &&
            (i == 0 || flowerbed[i - 1] == 0) &&
            (i == size - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            count++;
        }
    }
    
    return count >= n;
}

int main() {
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    
    if (canPlaceFlowers(flowerbed, n)) {
        cout << "Po, ne mund ti vendosim lulet." << endl;
    } else {
        cout << "Jo, ne nuk mund ti vendosim lulet." << endl;
    }
    
    return 0;
}