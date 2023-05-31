/*Detyra jep nje pem jo komplete dhe kerkon qe ta kthejm thellsin e asaj peme. Ne fillim e krijojm nje pem si struktur dhe i deklarojm 
pointerat e majt dhe te djatht. Ne fillim kontrollojm nese nyja kryesore nuk ka vler(pra nese pema nuk ka elemente fare) pastaj e krijojm nje
queue me emrin q dhe e vendosim ne te nyjen kryesore qe vjen si input hyres, si dhe inicializojm me vler 0 nje variabel me emrin depth.
Iterojm neper secilin element te queues derisa ajo te mbetet e zbrazet. E marrim gjatesin e queues ne mnyr qe permes nje forloopi ta kontrollojm
cdo anetar qe vendoset. Si rrenj aktuale e vendosim anetarin qe
gjendet ne fillim te queues dhe ate anetar e largojm nga queue per ti vendosur femijet e rrenjes qe u vendos permes dy kushteve if. Nese ajo nyje
ka femij te majt e vendosim ne queue, ose nese ka edhe femij te djatht edhe ate e vendosim ne queue, nese njeri prej ketyre kushteve plotesohet
dmth qe kemi kaluar ne nje nivel me te thell kshtuqe inkrementohet thellsia. Ne fund kthehet vlera e thellsis

Kompleksiteti kohor i ketij kodi eshte O(n) ku n eshte numri i elementeve te pemes, sepse ne e vizitojm secilin prej tyre 
Kompleksiteti hapesinor poashtu eshte O(n) ku n eshte numri maksimal i femijeve ne nje nivel sepse aq elemente po nevojitet qe ti ruajm ne queue*/

#include <iostream>
#include <queue>
using namespace std;

// Definimi i pemes binare
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }

        depth++;
    }

    return depth;
}

int main() {
    // Pema: [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int maxDepthVal = maxDepth(root);
    cout << "Thellsia maksimale e pemes: " << maxDepthVal << endl;

    return 0;
}
