/*Detyra jep nje varg me vlera dhe kerkon qe te kthejm nje pergjigje nese ate varg gjenden vlera te dyfishuara, psh nese ne varg 
eshte numri 5 ta kthejm nje true nese ne varg gjendet numri 10.

Ne fillim iterojm ne secilin element te vargut dhe secilin e shumezojm me 2, dukse e ruajtur ne nje variabel dyfishi dhe me nje for loop tjeter, 
kontrollojm nese secili element i vargut eshte i barabart me ate vler te dyfishuar (perveq krahasimit me vetvehten).
Dhe elementi i pare i dyfishuar qe gjenet kthehet nje true dhe perfundon programi, ne te kunderten kthehet false.

Kompleksiteti kohor i ketij kodi eshte O(n^2) ku n eshte numri i anetareve ne varg, sepse kemi dy for loopa, njera iteron dhe i 
dyfishon n elementet e vargut, dhe prap secili element krahasohet me n elementet tjera te vargut
Kompleksiteti hapesinor i ketij kodi, eshte O(1) sepse nuk nevojitet hapesir shtese per te ruajtur variabla te reja, perveq variables
dyfishi.
*/

#include <vector>
#include <iostream>
using namespace std;

bool checkIfExist(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int dyfishi = arr[i] * 2;

        for (int j = 0; j < arr.size(); j++) {
            if (j != i && arr[j] == dyfishi) {
                return true;
            }
        }
    }

    return false;
}

int main (){
    vector <int> vlerat = {10,2,5,3};
    if(checkIfExist(vlerat)){
        cout<<"Ne varg gjenden vlera te dyfishuara"<<endl;
    }else{
        cout<<"Ne varg nuk gjenden vlera te dyfishuara"<<endl;
    }
    return 0;
}