/*Detyra kerkon qe brenda nje liste te lidhur ti fshijm elementet e perseritura. 
Ne fillim e definojm listen e lidhur si struktur me elementet e veta. Pastaj e krijojm funksionin deleteDuplicates te tipit ListNode.
Ne fillim kontrollojm nese dy elementet qe perseriten jan ne fillim te listes, nese kjo eshte ateher e kthejm si rezultat elemenrtin e par.
Pastaj iterojm ne secilin element te listes duke filluar nga koka dhe permes nje kushti if kontrollojm nese anetari aktual eshte i njejte
me anetarin e ardhshem, nese ky kusht plotesohet ateher elementi i radhes ruhet ne nje variabel temp te ndersa ate element te ardhshem e 
zavendsojm me elementit e dyte te radhes e ne fund variablem temp e fshijm. Ne te kunderten nese ky kusht plotesohet ateher kalojm ne anetarin
e radhes. Permes nje funksioni printList e printojm listen me elemente te rregulluara.
Ne fund e pastrojm memorien nga elementet e listes qe te mos kemi rrjedhje te memories

Kompleksiteti kohor i ketij kodi eshte O(n) ku n eshte numri i elementeve te listes se lidhur, sepse ne rastin me te keq duhet qe ta 
vizitojm secilin element
Kompleksiteti hapesinor i ketij kodi eshte O(1) sepse per cfardo rasti i perdor vetem 2 variabla */

#include <iostream>

using namespace std;

// Definimi i listes se lidhur
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

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

int main() {
    // Test case
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    cout << "Original list: ";
    printList(head);

    ListNode* newList = deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(newList);

    // E pastrojm memorien
    ListNode* current = newList;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
