/*Detyra kerkon qe brenda nje liste te lidhur ta kthejm nyjen e mesit. Ne fillim e definojm listen e lidhur si struktur me elementet e veta.
Pastaj e krijojm nje funksion te tipit ListNode ku brenda tij njeher kontrollojm nese ka vetem nje anetar ose nuk ka anetar fare, ne ate rast
e kthejm nyjen e par (head). Pastaj i deklarojm dy pointera slow dhe fast te cilet do te iterojn ne elementet e listes, mirepo pointeri i pare
iteron secilin element nje pas nje, ndersa pointeri i dyte iteron duke i kaluar nga dy elemente pernjeher, dmth eshte me i shpejt, dhe kjo 
ndodh ne ate menyr qe kur pointeri fast ndodhet ne fund te listes, pointeri slow qe kalon nga nje hap gjendet ne mes te listes, posa te arrihet kjo
e kthejm si rezultat pointerin slow.
Permes nje funksioni e bejm printimin e listes.

Kompleksiteti kohor i ketij kodi eshte O(n) ku n eshte numri i elementeve te listes se lidhur, sepse ne rastin me te keq duhet qe ta 
vizitojm secilin element me while loop, ku pointeri fast duhet te shkoj deri tek anetari i fundit i listes\
Kompleksiteti hapesinor i ketij kodi eshte O(1) sepse per cfardo rasti i perdor vetem disa variabla (slow, fast...)
*/

#include <iostream>

using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

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

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Inicializimi me vlera i listes se lidhur
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Lista origjinale: ";
    printList(head);

    ListNode* middle = middleNode(head);

    cout << "Nyja e mesit: " << middle->val << endl;

    // Pastrimi i memories
    ListNode* current = head;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
