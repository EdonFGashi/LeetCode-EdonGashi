#include <iostream>
#include <vector>
#include<stack>
#include<string>
#include <queue>
#include <algorithm>

using namespace std;


//Definimi i listes se lidhur
struct ListNode {
                        int val;
                        ListNode* next;

                        ListNode(int x) : val(x), next(NULL) {}
                    };

// Definimi i pemes binare
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class funksionet{
    public:
/*_____________________________________________________________________________________________________________________________________________*/
/*_____________________________________________________________________________________________________________________________________________*/
/*==================================================================== Linked List ====================================================================
________________________________________________________________________________________________________________________________________________
Detyra 1.
83 Remove Duplicates from Sorted List - LinkedList
*/                    
                    /*
                    Time: O(n)
                    Space O(1)
                    */

                    ListNode* deleteDuplicates(ListNode* head) {
                        if (head == NULL || head->next == NULL) {
                            return head;
                        }

                        ListNode* current = head;
                        while (current->next != NULL) {
                            if (current->val == current->next->val) {
                                ListNode* temp = current->next;
                                current->next = current->next->next;
                                delete temp;
                            } else {
                                current = current->next;
                            }
                        }

                        return head;
                    }

                    void printList(ListNode* head) {
                        ListNode* current = head;
                        while (current != NULL) {
                            cout << current->val << " ";
                            current = current->next;
                        }
                        cout << endl;
                    }


/*=========================================================================================
Detyra 2.
876 Middleof the Linked List - Linked List*/

                    /*
                    Time: O(n)
                    Space O(1)
                    */

                    ListNode* middleNode(ListNode* head) {
                        if (head == NULL || head->next == NULL) {
                            return head;
                        }

                        ListNode* slow = head;
                        ListNode* fast = head;

                        while (fast != NULL && fast->next != NULL) {
                            slow = slow->next;
                            fast = fast->next->next;
                        }

                        return slow;
                    }

                    void printList2(ListNode* head) {
                        ListNode* current = head;
                        while (current != NULL) {
                            cout << current->val << " ";
                            current = current->next;
                        }
                        cout << endl;
                    }


/*_____________________________________________________________________________________________________________________________________________*/
/*_____________________________________________________________________________________________________________________________________________*/
/*==================================================================== Tree ====================================================================
________________________________________________________________________________________________________________________________________________
Detyra 3.
104 Maximum Depthof Binary Tree - Tree*/

                    /*
                    Time: O(n)
                    Space O(n)
                    */

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

/*============================================================================================================================================*/

/*Detyra 4.
111 Minimum Depth of Binary Tree-Tree*/
                    /*
                    Time: O(n)
                    Space O(n)
                    */

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


                                if (node->left == NULL && node->right == NULL) {
                                    return depth;
                                }


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

/*================================================================================================================================================*/

/*Detyra 5.
993 Cousinsin Binary Tree - Tree*/
                    /*
                    Time: O(n)
                    Space O(n)
                    */

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


/*_____________________________________________________________________________________________________________________________________________*/
/*_____________________________________________________________________________________________________________________________________________*/
/*==================================================================== Sort ====================================================================
________________________________________________________________________________________________________________________________________________
Detyra 6.
268 Missing Number - Sort*/

                    /*
                    Time: O(n)
                    Space O(1)
                    */

                    int missingNumber(vector<int>& nums) {
                            int n = nums.size();  //Numri i anetareve ne varg
                            int totalSum = (n * (n + 1)) / 2; // Llogarisim shumen e numrave nga 1 deri ne n
                            
                            
                            int sum = 0;  // Llogarisim shumen e numrave te vargut
                            for (int num : nums) {
                                sum += num;
                            }
                            
                            
                            return totalSum - sum;  // Numri qe mungon do te jet diferenca mes shumes totale dhe shumes se numrave ne varg
                        }


/*==============================================================================================================================================*/

/*Detyra 7.
1365 How Many Numbers Are Smaller Than the Current Number - Sort*/
                    /*
                    Time: O(n)
                    Space O(n)
                    */

                    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
                        int numeruesi[101] = {0};
                        int n = nums.size();

                        for (int i = 0; i < n; i++) {
                            numeruesi[nums[i]]++;
                        }

                        for (int i = 1; i <= 100; i++) {
                            numeruesi[i] += numeruesi[i - 1];
                        }

                        vector<int> rezultati;
                        for (int i = 0; i < n; i++) {
                            if (nums[i] == 0)
                                rezultati.push_back(0);
                            else
                                rezultati.push_back(numeruesi[nums[i] - 1]);
                        }

                        return rezultati;
                        }

/*=================================================================================================================================================*/
/*Detyra 8.
1859 Sorting the Sentence - Sort*/
                    /*
                    Time: O(n)
                    Space O(n)
                    */
                   string sortSentence(string s) {
                        vector<string> fjalia(9); // ne leetcode ceket qe si input mund te ket me se shumri 9 anetar.
                        string fjala;

                    
                        s += ' '; 
                        for (char c : s) {                        //sortimi
                            if (c == ' ') {
                                int pozicioniFjales = fjala.back() - '0';
                                fjala.pop_back();
                                fjalia[pozicioniFjales - 1] = fjala;
                                fjala.clear();
                            } else {
                                fjala += c;
                            }
                        }
                        
                        string result; //ndarja e fjaleve me hapesir
                        for (int i = 0; i < fjalia.size(); ++i) {
                            if (!fjalia[i].empty()) {
                                result += fjalia[i];
                                result += " ";
                            }
                        }
                        result.pop_back();
                        return result;
                        
                    }


/*_____________________________________________________________________________________________________________________________________________*/
/*_____________________________________________________________________________________________________________________________________________*/
/*==================================================================== Queue ====================================================================
________________________________________________________________________________________________________________________________________________
Detyra 9.
387 First Unique Character in a - Queue*/

                    /*
                    Time: O(n)
                    Space O(1)
                    */

                    int firstUniqChar(string s) {
                            int frekuenca[26] = {0}; // ne fillim te gjitha shkronjat e kan frekuencen 0, e pastaj saher qe perdoren inkrementohet per nga nje (line 9)

                            for (char c : s) {
                                frekuenca[c - 'a']++;// per fjalen "leetcode" frekuencat jan a = 0, b = 0 , l = 1, e = 2...
                            }

                            for (int i = 0; i < s.length(); i++) {
                                if (frekuenca[s[i] - 'a'] == 1) {
                                    return i;
                                }
                            }

                            return -1;
                        }

                    int main() {
                        string S = "leetcode";
                        cout << firstUniqChar(S) << endl;
                        return 0;
                    }


/*===============================================================================================================================================*/

/*Detyra 10.
933 Number of Recent Calls - Queue*/
                    /*
                    Time: O(n)
                    Space O(n)
                    */


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

                    RecentCounter counter; // Pasiqe jan te vendosura nje clas brenda clases tjeter, e krijojm nje instanc te klases RecentCounter si anetar publik

                    public:
                        void processPings() {
                            int ping1 = counter.ping(1);
                            int ping2 = counter.ping(100);
                            int ping3 = counter.ping(3001);
                            int ping4 = counter.ping(3002);

                            cout << "Number of recent calls: " << ping1 << ", " << ping2 << ", " << ping3 << ", " << ping4 << endl;
                        }

/*=============================================================================================================================================*/
/*Detyra 11.
1700 Number of Students Unable to Eat Lunch - Queue*/
                    /*
                    Time: O(n)
                    Space O(1)
                    */

                    int countStudents(vector<int>& students, vector<int>& sandwiches) {
                            int numeruesi[2] = {0}; // Numerimi i preferencave te studentit (0: mish, 1: djath)

                            
                            for (int preferenca : students) {   // Inicializimi me vlera i numeruesit te preferences
                                numeruesi[preferenca]++;
                            }

                            int n = students.size();    //Numri total i studenteve
                            int i = 0;    // Studentet qe marrin ushqim

                            
                            while (i < n && numeruesi[sandwiches[i]] > 0) {  // Procesi i marrjes se ushqimit
                                numeruesi[sandwiches[i]]--; // Zvogelimi i numrit te studentit, kur ai merr ushqim
                                i++;     //Rritja e numrit te studentit kur ai merr ushqim
                            }

                            return n - i; // Numri i studenteve qe nuk kan marr ushqim
                        }

/*_____________________________________________________________________________________________________________________________________________*/
/*_____________________________________________________________________________________________________________________________________________*/
/*==================================================================== Greedy ====================================================================
________________________________________________________________________________________________________________________________________________
Detyra 12.
455 Assign Cookies - Greedy*/
                    /*
                    Time: O(n)
                    Space O(1)
                    */
                    int findContentChildren(vector<int>& g, vector<int>& s) {
                        sort(g.begin(), g.end());
                        sort(s.begin(), s.end());

                        int numeruesi = 0;
                        int femija = 0;
                        int biskota = 0;

                        while (femija < g.size() && biskota < s.size()) {
                            if (s[biskota] >= g[femija]) {
                                numeruesi++;
                                femija++;
                                biskota++;
                            } else {
                                biskota++;
                            }
                        }

                        return numeruesi;
                    }


/*==============================================================================================================================================*/
/*Detyra 13.
605 Can Place Flowers - Greedy*/
                    /*
                    Time: O(n)
                    Space O(1)
                    */
                    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
                        int count = 0;
                        int size = flowerbed.size();
                        
                        for (int i = 0; i < size; i++) {
                            if (flowerbed[i] == 0 &&
                                (i == 0 || flowerbed[i - 1] == 0) &&
                                (i == size - 1 || flowerbed[i + 1] == 0)) {
                                flowerbed[i] = 1;
                                count++;
                            }
                        }
                        
                        return count >= n;
                    }

/*==============================================================================================================================================*/

/*Detyra 14.
860 Lemonade Change - Greedy*/
                    /*
                    Time: O(n)
                    Space O(1)
                    */
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

/*==============================================================================================================================================*/







/*_____________________________________________________________________________________________________________________________________________*/
/*_____________________________________________________________________________________________________________________________________________*/
/*==================================================================== Stack ====================================================================
________________________________________________________________________________________________________________________________________________
Detyra 15.
1021 Remove Outer Parentheses - Stack/
                    /*
                    Time: O(n)
                    Space O(n)
                    */

                    string removeOuterParentheses(string s) {
                        stack<char> stack;
                        string rezultati;

                        for (char c : s) {
                            if (c == '(') {
                                if (!stack.empty()) {
                                    rezultati += c;
                                }
                                stack.push(c);
                            }
                            else {
                                stack.pop();
                                if (!stack.empty()) {
                                    rezultati += c;
                                }
                            }
                        }

                        return rezultati;

                    }

/*==============================================================================================================================================*/

/*Detyra 16.
1047 Remove All Adjacent Duplicates In String - Stack*/
                    /*
                    Time: O(n)
                    Space O(n)
                    */

                    string removeDuplicates(string s) {
                            stack<char> stacki;
                            
                            for (char c : s) {
                                if (!stacki.empty() && stacki.top() == c) {
                                    stacki.pop();
                                } else {
                                    stacki.push(c);
                                }
                            }
                            
                            string rezultati;
                            while (!stacki.empty()) {
                                rezultati = stacki.top() + rezultati;
                                stacki.pop();
                            }
                            
                            return rezultati;
                        }

/*==============================================================================================================================================*/

/*Detyra 17.
1544 Make The String Great - Stack/
                    /*
                    Time: O(n)
                    Space O(n)
                    */

                    string makeGood(string s) {
                            stack<char> st;
                            for (char c : s) {
                                if (!st.empty() && abs(st.top() - c) == 32) {
                                    st.pop();
                                }
                                else {
                                    st.push(c);
                                }
                            }

                            string rezultati;

                            while (!st.empty()) {
                                rezultati += st.top();
                                st.pop();
                            }
                        string rezultatifinal = rezultati;
                        
                        for(int i = 0 ; i < rezultati.length() ; i++){
                                rezultatifinal[i] = rezultati[rezultati.length() -1 - i];
                        }
                            return rezultatifinal;
                        }


/*==============================================================================================================================================*/

/*_____________________________________________________________________________________________________________________________________________*/
/*_____________________________________________________________________________________________________________________________________________*/
/*==================================================================== Binary Search ====================================================================
________________________________________________________________________________________________________________________________________________
Detyra 18.
2529 Maximum Count of Positive Integer and Negative Integer - Binary Search*/
                    /*
                    Time: O(n)
                    Space O(1)
                    */

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

/*==============================================================================================================================================*/

/*Detyra 19.
1346 Check If Nand Its Double Exist - Binary Search
                    /*
                    Time: O(n^2)
                    Space O(1)
                    */

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


/*==============================================================================================================================================*/
/*Detyra 20.
1351 Count Negative Numbers in a Sorted Matrix - Binary Search*/
                    /*
                    Time: O(n^2)
                    Space O(1)
                    */

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


/*==============================================================================================================================================*/
};

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/




int main() {

    /*==============================================================  Linked List  =============================================================
Detyra 1.
83 Remove Duplicates from Sorted List - LinkedList
 Definimi i listes se lidhur*/
                
                    
                    // ListNode* head = new ListNode(1);  //Test case
                    // head->next = new ListNode(1);
                    // head->next->next = new ListNode(2);
                    // head->next->next->next = new ListNode(3);
                    // head->next->next->next->next = new ListNode(3);

                    // funksionet deleteDuplicates;
                    // funksionet printList;
                    

                    // cout << "Original list: ";
                    // printList.printList(head);

                    // ListNode* newList = deleteDuplicates.deleteDuplicates(head);

                    // cout << "List after removing duplicates: ";
                    // printList.printList(newList);

                    
                    // ListNode* current = newList;  // E pastrojm memorien
                    // while (current != NULL) {
                    //     ListNode* temp = current;
                    //     current = current->next;
                    //     delete temp;
                    // }


/*===========================================================================================================================================
Detyra 2.
876 Middleof the Linked List - LinkedList*/

// Inicializimi me vlera i listes se lidhur

                    // ListNode* head = new ListNode(1);
                    // head->next = new ListNode(2);
                    // head->next->next = new ListNode(3);
                    // head->next->next->next = new ListNode(4);
                    // head->next->next->next->next = new ListNode(5);

                    // funksionet middleNode;
                    // funksionet printList2;

                    // cout << "Lista origjinale: ";
                    // printList2.printList2(head);

                    // ListNode* middle = middleNode.middleNode(head);

                    // cout << "Nyja e mesit: " << middle->val << endl;

                    
                    // ListNode* current = head;  // Pastrimi i memories
                    // while (current != NULL) {
                    //     ListNode* temp = current;
                    //     current = current->next;
                    //     delete temp;
                    // }

/*=============================================================================================================================================*/
/*_____________________________________________________________________________________________________________________________________________*/
/*=================================================================== Tree =====================================================================
________________________________________________________________________________________________________________________________________________
Detyra 3.
104 Maximum Depthof Binary Tree - Tree*/

/* Pema: [3,9,20,null,null,15,7]*/

                    // TreeNode* root = new TreeNode(3);
                    // root->left = new TreeNode(9);
                    // root->right = new TreeNode(20);
                    // root->right->left = new TreeNode(15);
                    // root->right->right = new TreeNode(7);

                    // funksionet maxDepth;

                    // int maxDepthVal = maxDepth.maxDepth(root);
                    // cout << "Thellsia maksimale e pemes: " << maxDepthVal << endl;




/*==============================================================================================================================================
Detyra 4.
111 Minimum Depth of Binary Tree-Tree*/

                        // TreeNode* root = new TreeNode(3);
                        // root->left = new TreeNode(9);
                        // root->right = new TreeNode(20);
                        // root->right->left = new TreeNode(15);
                        // root->right->right = new TreeNode(7);

                        // funksionet minDepth;

                        // cout << "Minimum depth of the binary tree: " << minDepth.minDepth(root) << endl;

                        // delete root->right->right;
                        // delete root->right->left;
                        // delete root->right;
                        // delete root->left;
                        // delete root;


/*==========================================================================================================================================
Detyra 5.
993 Cousinsin Binary Tree - Tree*/

                        // TreeNode* root = new TreeNode(1);
                        // root->left = new TreeNode(2);
                        // root->right = new TreeNode(3);
                        // root->left->left = new TreeNode(4);
                        // root->right->right = new TreeNode(5);
                         
                        //  funksionet isCousins;
                        // int x = 4;
                        // int y = 5;

                        // if (isCousins.isCousins(root, x, y)) {
                        //     cout << x << " and " << y << " are cousins." << endl;
                        // } else {
                        //     cout << x << " and " << y << " are not cousins." << endl;
                        // }

                        // delete root->right->right;
                        // delete root->left->left;
                        // delete root->right;
                        // delete root->left;
                        // delete root;


/*_____________________________________________________________________________________________________________________________________________*/
/*_____________________________________________________________________________________________________________________________________________*/
/*==================================================================== Sort ====================================================================
________________________________________________________________________________________________________________________________________________
Detyra 6.
268 Missing Number - Sort*/

                        // vector<int> nums = {3, 0, 1};
                        // funksionet missingNumber;
                        // cout << "Numri qe mungon: " << missingNumber.missingNumber(nums) << endl;

/*==============================================================================================================================================*/

/*Detyra 7.
1365 How Many Numbers Are Smaller Than the Current Number - Sort*/

                    // vector<int> nums = {8, 1, 2, 2, 3};
                    // funksionet smallerNumbersThanCurrent;
                    //     vector<int> rezultati = smallerNumbersThanCurrent.smallerNumbersThanCurrent(nums);

                    //     cout << "Result: ";
                    //     for (int num : rezultati) {
                    //         cout << num << " ";
                    //     }
                    //     cout << endl;


/*===========================================================================================================================================*/
/*Detyra 8.
1859 Sorting the Sentence - Sort*/

                        // string s = "is2 sentence4 This1 a3";
                        // funksionet sortSentence;
                        // string sortedSentence = sortSentence.sortSentence(s);
                        
                        // cout << "Fjalia e sortuar: " << sortedSentence << endl;


/*_____________________________________________________________________________________________________________________________________________*/
/*_____________________________________________________________________________________________________________________________________________*/
/*==================================================================== Queue ====================================================================
________________________________________________________________________________________________________________________________________________
Detyra 9.
387 First Unique Character in a - Queue*/
  
                        // string S = "leetcode";
                        // funksionet firstUniqChar;
                        // cout << firstUniqChar.firstUniqChar(S) << endl;

/*============================================================================================================================================*/

   /*Detyra 10.
933 Number of Recent Calls - Queue*/

                        //  funksionet processPings;
                        // processPings.processPings();

/*===============================================================================================================================================*/

/*Detyra 11.
1700 Number of Students Unable to Eat Lunch - Queue*/
                    /*
                    Time: O(n)
                    Space O(1)
                    */

                        // vector<int> studentet ;
                        // vector<int> sandwichet ;

                        // funksionet countStudents;

                        // studentet.push_back(1);
                        // studentet.push_back(1);
                        // studentet.push_back(1);
                        // studentet.push_back(0);
                        // studentet.push_back(0);
                        // studentet.push_back(1);
                        // sandwichet.push_back(1);
                        // sandwichet.push_back(0);
                        // sandwichet.push_back(0);
                        // sandwichet.push_back(0);
                        // sandwichet.push_back(1);
                        // sandwichet.push_back(1);
                        // cout << countStudents.countStudents(studentet, sandwichet) << endl;

/*==============================================================================================================================================*/
/*_____________________________________________________________________________________________________________________________________________*/
/*_____________________________________________________________________________________________________________________________________________*/
/*==================================================================== Greedy ====================================================================
________________________________________________________________________________________________________________________________________________
Detyra 12.
455 Assign Cookies - Greedy*/
                    /*
                    Time: O(n)
                    Space O(1)
                    */

                        // funksionet findContentChildren;
                        // vector<int> g = {1, 2, 3};
                        // vector<int> s = {1, 1};

                        // int rezultati = findContentChildren.findContentChildren(g, s);
                        // cout << "Numri i femijeve qe kan marre biskota: " << rezultati << endl;


/*==============================================================================================================================================*/

/*Detyra 13.
605 Can Place Flowers - Greedy*/
                    /*
                    Time: O(n)
                    Space O(1)
                    */
                        // funksionet canPlaceFlowers;
                        // vector<int> flowerbed = {1, 0, 0, 0, 1};
                        // int n = 1;
                        
                        // if (canPlaceFlowers.canPlaceFlowers(flowerbed, n)) {
                        //     cout << "Po, ne mund ti vendosim lulet." << endl;
                        // } else {
                        //     cout << "Jo, ne nuk mund ti vendosim lulet." << endl;
                        // }

/*===============================================================================================================================================*/

/*Detyra 14.
860 Lemonade Change - Greedy*/

                        // funksionet lemonadeChange;

                        // vector<int> bills = {5,5,5,10,20};
                        
                        // bool canProvideChange = lemonadeChange.lemonadeChange(bills);
                        
                        // if (canProvideChange) {
                        //     cout << "Konsumatoreve mund tu kthehn parat." << endl;
                        // } else {
                        //     cout << "Konsumatoreve nuk mund tu kthehn parat." << endl;
                        // }

/*==============================================================================================================================================*/

/*_____________________________________________________________________________________________________________________________________________*/
/*_____________________________________________________________________________________________________________________________________________*/
/*==================================================================== Stack ====================================================================
________________________________________________________________________________________________________________________________________________
Detyra 15.
1021 Remove Outer Parentheses - Stack*/
                    
                        // funksionet removeOuterParentheses;

                        // string S = "(()())(())";
                        // cout << removeOuterParentheses.removeOuterParentheses(S) << endl;

/*==============================================================================================================================================*/

/*Detyra 16.
1047 Remove All Adjacent Duplicates In String - Stack*/

                        // funksionet removeDuplicates;

                        // string S = "abbaca";
                        // cout << removeDuplicates.removeDuplicates(S) << endl;


/*==============================================================================================================================================*/

/*Detyra 17.
1544 Make The String Great - Stack*/

                        // funksionet makeGood;
                        // string S = "leEeetCode";
                        // cout << makeGood.makeGood(S) << endl;

/*==============================================================================================================================================*/

/*_____________________________________________________________________________________________________________________________________________*/
/*_____________________________________________________________________________________________________________________________________________*/
/*==================================================================== Binary Search ====================================================================
________________________________________________________________________________________________________________________________________________
Detyra 18.
2529 Maximum Count of Positive Integer and Negative Integer - Binary Search*/

                        // funksionet maximumCount;

                        // vector<int> numrat = {-2,-1,-1,1,2,3};
                        // cout<<"Numri maksimal: "<<maximumCount.maximumCount(numrat)<<endl;

/*==============================================================================================================================================*/

/*Detyra 19.
1346 Check If Nand Its Double Exist - Binary Search*/

                        // funksionet checkIfExist;

                        // vector <int> vlerat = {10,2,5,3};
                        // if(checkIfExist.checkIfExist(vlerat)){
                        //     cout<<"Ne varg gjenden vlera te dyfishuara"<<endl;
                        // }else{
                        //     cout<<"Ne varg nuk gjenden vlera te dyfishuara"<<endl;
                        // }

/*==============================================================================================================================================*/

/*Detyra 20.
1351 Count Negative Numbers in a Sorted Matrix - Binary Search*/

                        // funksionet countNegatives;

                        // vector<vector<int>> matrica = {{5,1,0},{-5,-5,-5}};
                        // cout<<"Numri i vlerave negative ne matric: "<< countNegatives.countNegatives(matrica) << endl;

/*==============================================================================================================================================*/
    return 0;
}