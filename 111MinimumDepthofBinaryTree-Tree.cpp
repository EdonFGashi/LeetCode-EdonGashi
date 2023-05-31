/*Detyra jep nje pem dhe kerkon qe ta kthejm thellsin minimale qe mund ta ket. Ne fillim e krijojm nje pem si struktur dhe i deklarojm 
pointerat e majt dhe te djatht. Ne fillim kontrollojm nese nyja kryesore nuk ka vler(pra nese pema nuk ka elemente fare) pastaj e krijojm nje
queue me emrin q dhe e vendosim ne te nyjen kryesore qe vjen si input hyres, si dhe inicializojm me vler 1 nje variabel me emrin depth
(sepse nese ka rrenj pema dmth qe thellsia e saj minimal veq eshte 1), 
Iterojm neper secilin element te queues derisa ajo te mbetet e zbrazet. E marrim gjatesin e queues ne mnyr qe permes nje forloopi ta kontrollojm
cdo anetar qe vendoset. Si rrenj aktuale e vendosim anetarin qe
gjendet ne fillim te queues dhe ate anetar e largojm nga queue per ti vendosur femijet e rrenjes qe u vendos permes dy kushteve if. Nese
ne njeren nga nyjet pema nuk ka femij e kthejm menjeher vleren e thellsis, e nese ka femij te tjer vazhdojm ti vendosim ne queue, si dhe e rrisim
vleren e thellsis per nje.

Kompleksiteti kohor i ketij kodi eshte O(n) ku n eshte numri i elementeve te pemes, sepse ne e vizitojm secilin prej tyre 
Kompleksiteti hapesinor poashtu eshte O(n) ku n eshte numri maksimal i femijeve ne nje nivel sepse aq elemente po nevojitet qe ti ruajm ne queue*/

#include <iostream>
#include <queue>

using namespace std;

// Definojm pemen binare
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    queue<TreeNode*> q;
    q.push(root);
    int depth = 1;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            // kontrollojm nese ka ndonje rrenj pa ndonje femij
            if (node->left == NULL && node->right == NULL) {
                return depth;
            }

            // Nese jo ateher i shtojm femijet ne queue
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }

        depth++;
    }

    return depth;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Minimum depth of the binary tree: " << minDepth(root) << endl;

    // E fshijm memorien qe mos te kemi rrjedhje te saj
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
