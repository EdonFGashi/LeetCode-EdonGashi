/*Detyra jep nje vektor me emrin nums, e ku kerkohet qe ne ate vektor te gjindet numri i anetareve me te vogel per secilin element.
P.sh. ne vektorin {8, 1, 2, 2, 3}, 
numri 8 i ka 4 numra tjer me te vogel (numrat 1, 2, 2, 3)
numri 1 i ka 0 numra tjer me te vogel,
numri 2 e ka vetem nje numer me te vogel (numri 1),
numri 3 i ka 3 numra tjer me te vogel (numri 1, 2, 2)
Dmth rezultati final do te ishte [4,0,1,1,3]

Zgjidhja: E marrim nje varg me emrin numeruesi i cili do te numeroj secilin element te vargut input se sa her po perseritet,
eshte i tipit int me gjatesi 101 (sepse leetcode ne problem e cek qe numri maksimal i inputit mund te jet 100) dhe i inicializojm
te gjitha me vleren 0. 
Ne for loop te pare i inkrementojm vlerat e vargut numeruesi, ne indeksat perkates per aq sa her qe perseriten vlerat hyrese ne nums (e gjejm
frekuencen e perseritjes).
Ne loop te dyt, secilit element te vargut numeruesi (qe tashme esht inicializuar me vlerat 0,1,2,1,0,0,0,0,1,0,0,0...) i shtojm elementin e mepareshem
dhe kjo do ti jap vlerat e tilla te rritura per nje (ne indeksat perkates), per numrat me te vogel te kerkuar
(0,1,3,4,4,4,4,4,5,5,5,5,...).
E deklarojm nje vektor rezultati ku do te vendosen vlerat e kerkuara, permes nje for loop-i iterojm ne cdo element te inputit, 
ne rastin e pare e specifikojm rastin kur shifra esht 0 dhe e shtojm ne rezultat numrin 0 (sepse nuk ekziston numer pozitiv me i vogel se 0)
ndersa per numra tjer, vleren ne indeksin perkates i ne vargun numeruesi,  e zvogelojm per nje dhe qe tregon numrin e sakt te vlerave me te vogla...
Ne fund e kthejm si rezultat, vektorin rezultati

Kompleksiteti kohor i ketij kodi eshte, O(n), sepse ne loopin e pare dhe te tret ka n iterime (ku n eshte numri i inputeve ne nums), nderse vetem
ne loopin e dyt kemi nje numer te caktuar iterimesh (O(100))
Kompleksiteti hapesinor eshte poashti O(n) sepse vektori rezultati po merr aq vlera sa eshte numri i hyrjeve (inputit te nums)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int numeruesi[101] = {0};
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        numeruesi[nums[i]]++;
    }

    for (int i = 1; i <= 100; i++) {
        numeruesi[i] += numeruesi[i - 1];
    }

    vector<int> rezultati;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0)
            rezultati.push_back(0);
        else
            rezultati.push_back(numeruesi[nums[i] - 1]);
    }

    return rezultati;
    }

int main() {
    vector<int> nums = {8, 1, 2, 2, 3};
    vector<int> rezultati = smallerNumbersThanCurrent(nums);

    cout << "Result: ";
    for (int num : rezultati) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}