//Detyra kerkon qe brenda nje vargu me vlera, te gjendet numri qe munngon, vargu perman numra rendor nga zero deri ne n
/*Ne fillim e llogarisim numrin e anetareve te vargut, dhe e llogarisim shumen e numrave nga zero deri ne n, e pastaj e llogarisim 
shumen e anetareve te vargut ne for loopin e par. Diferenca mes shumes totale dhe shumes se anetareve te vargut

Kompleksiteti kohor i ketij vargu eshte O(n) sepse per te llogaritur shumen e numrave te vargut nevojiten n iterime ne n
Kompleksiteti hapesinor i ketij kodi eshte O(1) sepse pergjat tere kodit perdoret hapesir e njejt e memories.*/

#include <iostream>
#include <vector>

using namespace std;

 int missingNumber(vector<int>& nums) {
        int n = nums.size();  //Numri i anetareve ne varg
        int totalSum = (n * (n + 1)) / 2; // Llogarisim shumen e numrave nga 1 deri ne n
        
        // Llogarisim shumen e numrave te vargut
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        // Numri qe mungon do te jet diferenca mes shumes totale dhe shumes se numrave ne varg
        return totalSum - sum;
    }

    int main() {
    vector<int> nums = {3, 0, 1};
    cout << "Numri qe mungon: " << missingNumber(nums) << endl;
    return 0;
}