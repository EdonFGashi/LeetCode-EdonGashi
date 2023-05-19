/*Ne klasen RecentCounter, jan jepen disa kerkesa, cdo kerkes ka nje koh te caktuar qe jepet ne milisekonda permes variables t
Detyra kerkon qe ta kthejm ti numerojm kerkesat ne 3000 milisekondat e fundit, per cdo kerkes qe behet, duke e perfshir edhe kerkesen e fundit

Brenda klases esht nje funksion ping me parameter t ,qe e merr nje kerkes me kohen e vet, ajo kerkes vendoset ne nje queue me emrin pings
Pastaj testohet nese ajo kerkes i ka kaluar 3000 milisekonda qe nga kerkesa e par   [pings.front() < t - 3000] , nese i kalon ateher kerkesa
largohet nga queue keshtu duke mos e llogaritur. Ne fund pas cdo kontrollimi ktheht si vler numri i anetareve ne queue [return pings.size();]
e qe tregon numrin e kerkesave te 3000 milisekondat e fundit (kerkesat e palarguara paraprakisht)

Ne aspektin kohor ky kod ka kompleksitetin O(n), ku n tregon numrin e kerkesave qe merren si input, sepse sa kerkesa po merren aq her po iterime
po behen loopin while.

Ne aspektin e hapsiror ky kod ka kompleksitetin O(n), ku n tregon numrin e kerkesave ne 3000 milisekondat e fundit, sepse aq kerkesa po ruhen ne
queue, kshtuqe sa esht numri i ketyre thirrjeve, aq do te jet edhe size i queue me emrin pings.
*/

#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
private:
    queue<int> pings;

public:
    RecentCounter() {
    }

    int ping(int t) {
        pings.push(t);

        while (!pings.empty() && pings.front() < t - 3000) {
            pings.pop();
        }

        return pings.size();
    }
};

int main() {
    RecentCounter obj;
    int ping1 = obj.ping(1);
    int ping2 = obj.ping(100);
    int ping3 = obj.ping(3001);
    int ping4 = obj.ping(3002);

    cout << "Number of recent calls: " << ping1 << ", " << ping2 << ", " << ping3 << ", " << ping4 << endl;

    return 0;
}