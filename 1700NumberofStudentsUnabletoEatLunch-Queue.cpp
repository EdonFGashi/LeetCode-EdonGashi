/*Kjo detyr kerkon qe te gjendet numri i studenteve te cilet mund te mbesin pa ngrene ne nje radhe !
Nese kemi nje radhe te studenteve dhe te sanwicheve (ku mund te jen me mish ose me djath).
Jepen dy vektor me te dhena, njeri studentet (qe tregon preferencen e studentit per ushqim, 0 per mish dhe 1 per djath) dhe 
tjetri sandwichet, ku secili tregon llojin e sandwishit.
Studentet jan te vendosur ne radhe dhe nese preferenca e studentit nuk korrespondon me sandwichin e kerkuar, ai student do te kaloj ne funnd
te radhes. Kjo vazhdon dhe ne fund disa student do te mbesin pa ushqim

Ne fillim esht krijuar nje variabel numeruesi, qe ka dz vlera, vlera e par do te tregoj numrin e studenteve qe deshirojn me mish
dhe e dyta numrin e studenteve qe deshirojn me djath.Ne fillim i ka vlerat 0 por qe ne for loopin e par inicializohet

Ne loopin e dyt, duhet te plotesohen dy kushte ne menyr qe te ket jo me shum iterime se sa qe esht numri i studenteve, si dhe ne ate kontrollim te 
kushtit, numri i studenteve qe e kerkojn ate ushqim te jet me i madh se zero (pra te ket studet qe e kerkojn ate ushqim ne menzr qe ta marrin ate)
Pastaj nese gjendet studenti qe e merr ate ushqim, ai student largohet nga radha, pra ne numerues zvogelohet vlera per nje,
ndersa rritet numri i iterimeve (numri i studenteve qe po marrin ushqim). Pasi te perfundoj kjo loop, numri total i studenteve minus numrin e 
studenteve qe kan marr ushqim, e paraqet numrin e studemteve qe kan mbetur pa ushqim.
Per keto vlera rezultati duhet te jet 3.

Time: O(n)
Space: O(1)
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int numeruesi[2] = {0}; // Numerimi i preferencave te studentit (0: mish, 1: djath)

        // Inicializimi me vlera i numeruesit te preferences
        for (int preferenca : students) {
            numeruesi[preferenca]++;
        }

        int n = students.size();    //Numri total i studenteve
        int i = 0;    // Studentet qe marrin ushqim

        // Procesi i marrjes se ushqimit
        while (i < n && numeruesi[sandwiches[i]] > 0) {
            numeruesi[sandwiches[i]]--; // Zvogelimi i numrit te studentit, kur ai merr ushqim
            i++;     //Rritja e numrit te studentit kur ai merr ushqim
        }

        return n - i; // Numri i studenteve qe nuk kan marr ushqim
    }

int main() {
    vector<int> studentet ;
    vector<int> sandwichet ;
    studentet.push_back(1);
    studentet.push_back(1);
    studentet.push_back(1);
    studentet.push_back(0);
    studentet.push_back(0);
    studentet.push_back(1);
    sandwichet.push_back(1);
    sandwichet.push_back(0);
    sandwichet.push_back(0);
    sandwichet.push_back(0);
    sandwichet.push_back(1);
    sandwichet.push_back(1);
    cout << countStudents(studentet, sandwichet) << endl;
    return 0;
}