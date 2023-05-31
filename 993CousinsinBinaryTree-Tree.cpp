/*Detyra kerkon qe brenda nje peme ti gjejm dy anetar qe jan "kusherinj". Dy anetar quhen te till nese jan ne te njejten thellsi por
nuk e kan prindin e njejt. Ne fillim e krijojm nje pem si struktur dhe i deklarojm 
pointerat e majt dhe te djatht. Ne fillim kontrollojm nese nyja kryesore nuk ka vler(pra nese pema nuk ka elemente fare) pastaj e krijojm nje
queue me emrin q dhe e vendosim ne te nyjen kryesore qe vjen si input hyres. Permes nje while loopi iterojm ne secilin element, derisa te 
mbetet queue pa anetar, i deklarojm dy variabla te tipit bool me vlera false. Iterojm neper secilin element ne queues ku ne fillim kontrollojm 
nese kontrollojm nese x ose y jan ne te njejtin nivel (te nodes) mirepo jan femiij te te njejtit prind ne ate rast kthehet vlera false.
Pastaj kontrollojm nese vlera e nyjes eshte e barabart me X, ku merret vlera true, njejt veprojm edhe per y. Pastj kontrollojm nese ka elemente tjera
femij ateher ato vendosen ne queue. Ne fund nese te dy vlerat i kemi true ateher e kthejm kthejm si pergjigje true dhe perfundon programi

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

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isCousins(TreeNode* root, int x, int y) {
    if (root == NULL) {
        return false;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        bool foundX = false;
        bool foundY = false;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left != NULL && node->right != NULL) {
                // Kontrollojm nese x ose y jan femiij te te njejtit prind
                if ((node->left->val == x && node->right->val == y) ||
                    (node->left->val == y && node->right->val == x)) {
                    return false;
                }
            }

            if (node->val == x) {
                foundX = true;
            } else if (node->val == y) {
                foundY = true;
            }

            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }

        if (foundX && foundY) {
            return true;
        }
    }

    return false;
}

int main() {
    // Test case
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    int x = 4;
    int y = 5;

    if (isCousins(root, x, y)) {
        cout << x << " and " << y << " are cousins." << endl;
    } else {
        cout << x << " and " << y << " are not cousins." << endl;
    }

    // E fshijm memorien qe mos te kemi rrjedhje te saj
    delete root->right->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
