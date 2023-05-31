/*Detyra kerkon qe brenda nje matrice me numra te plot, ti kthejm numrin e vlerave qe jan negative
Prandaj me dy for loopa iterojm neper secilen element dhe e krahasojm e zero

Kompleksiteti kohor i ketij kodi eshte O(n^2) sepse kemi dy for loopa brenda njeri tjetrit
Ndersa kompleksiteti hapesinor i ketij kodi eshte O(1) sepse nuk ka ndonje hapsir tjeter te nevojshme gjat ekzekutimit*/

#include <iostream>
#include <vector>
using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int numratNegativ = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] < 0){
                    numratNegativ++;
            }
        }
        
        }
    return numratNegativ;
}

int main(){
    vector<vector<int>> matrica = {{5,1,0},{-5,-5,-5}};
    cout<<"Numri i vlerave negative ne matric: "<< countNegatives(matrica) << endl;
    return 0;
}