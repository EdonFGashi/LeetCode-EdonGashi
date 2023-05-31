/*Detyra jep nje varg me vlera dhe kerkon qe ta kthejm si rezultat numrin maksimal te anetareve pozitiv ose negativ ne ate varg.
I deklarojm dy variabla me vlera zero numratPozitiv dhe numratNegativ, me nje for loop iterojm neper secilin element te vargut
dhe nese ajo vler eshte me e madhe se zero ateher inkrementohet madhesia numratPozitiv ne te kunderten inkrementohet madhesia numratNegativ
ne fund kthehet si rezultat maksimumi varesisht se a ka me shum numra pozitiv apo negativ

Kompleksiteti kohor i ketij kodi eshte O(n) ku n eshte numri i elementeve ne varg sepse aq iterime i ben for loopi i par
Kompleksitei hapesinor i ketij kodi eshte O(1) sepse i kemi si varibla te reja vetem numratPozitiv dhe numratNegativ*/

#include <iostream>
#include <vector>

using namespace std;

int maximumCount(vector<int>& nums) {
        int numratPozitiv = 0;
        int numratNegativ = 0;

        for (int numri : nums) {
            if (numri > 0) {
                numratPozitiv++;
            } else if (numri < 0) {
                numratNegativ++;
            }
        }

        return max(numratPozitiv, numratNegativ);
    }

    int main(){
        vector<int> numrat = {-2,-1,-1,1,2,3};
        cout<<"Numri maksimal: "<<maximumCount(numrat)<<endl;
        return 0;
    }