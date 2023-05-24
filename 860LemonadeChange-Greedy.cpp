/*Ne nje dyqan limonadash, nje e till kushton 5$, klientet mund ta blejn vetem nje limonad ne te njejten koh. Per pages ata mund te japim
5$, 10$ dhe 20$. Mirepo shitesi duhet qe edhe ti kthej kusurin, me ato para qe ka mbledhur deri tani.
Nese ne arke ka para te mjaftueshme per ta kthyer kusurin, duhet qe te kthejm si rezultat true, ne te kunderten e kthejm false.

Kompleksiteti kohor i ketij kodi eshte O(n) ku n eshte numri i pagesave qe kan bere klientet sepse, ne for loop kemi aq iterime sa eshte n
Kompleksiteti hapesinor i ketij kodi eshte O(1) sepse kodi gjat ekzekutimit i perdor te njejtat variabla (per numerim) pavaresisht
numrit te hyrjeve si input
*/

#include <iostream>
#include <vector>

using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int count5 = 0; // numri i pagesave 5$
    int count10 = 0; // numri i pagesave 10$
    
    for (int bill : bills) {
        if (bill == 5) {
            count5++;
        } else if (bill == 10) {
            if (count5 == 0) {
                return false;
            }
            count5--;
            count10++;
        } else { // pagesa == 20
            if (count5 > 0 && count10 > 0) {
                count5--;
                count10--;
            } else if (count5 >= 3) {
                count5 -= 3;
            } else {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    vector<int> bills = {5, 5, 5, 10, 20};
    if (lemonadeChange(bills)) {
        cout << "Ne mund te kthejm kusurin." << endl;
    } else {
        cout << "Ne nuk mund te kthejm kusurin." << endl;
    }
    return 0;
}