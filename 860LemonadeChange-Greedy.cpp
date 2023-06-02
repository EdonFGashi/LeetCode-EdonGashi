/*Time: O(n)
Space: O(1)
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
    
    vector<int> bills = {5,5,5,10,20};
    
    bool canProvideChange = lemonadeChange(bills);
    
    if (canProvideChange) {
        cout << "Konsumatoreve mund tu kthehn parat." << endl;
    } else {
        cout << "Konsumatoreve nuk mund tu kthehn parat." << endl;
    }
    
    return 0;
}