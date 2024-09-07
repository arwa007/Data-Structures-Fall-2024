#include <iostream>
using namespace std;

class node{
    int value;
    node *next;

    public:
    node():value(0), next(NULL){}
    node(int d) : value(d), next(NULL){}
    friend class list;
};

class list{
    node *head;

    public:
    list() : head(NULL){}
    list(node *n):head(n){}

    void insertStart(node *newNode){

        if (head == NULL){
            head = newNode;

        }else{
        newNode->next = head;
         head = newNode;
        }
    }

    void insertEnd(node *newNode){
          if (head == NULL){
            head = newNode;
        }else{
            node *curr = head;

        while (curr->next != NULL){
            curr = curr->next;
        }

        curr->next = newNode;
        newNode->next = NULL;
        }
     }

     void insertAfterValue(int searchVal, int newVal){
      
       if (head->value == searchVal) {
            node newNode(newVal);
            insertStart(&newNode);
            return;
        }

        if (head != NULL){
            node *curr = head;
            node *newNode = new node(newVal);

            while(curr->value != searchVal){
                curr = curr->next;
            }

            newNode->next = curr->next;
            curr->next = newNode;

        }
     }

     void insertBeforeValue(int searchVal, int newVal) {
    if (head == NULL) return;

    node *newNode = new node(newVal);


    if (head->value == searchVal) {
        newNode->next = head;
        head = newNode;
        return;
    }

    node *curr = head;
    node *prev = NULL;

    while (curr != NULL && curr->value != searchVal) {
        prev = curr;
        curr = curr->next;
    }


    if (curr != NULL) {
        prev->next = newNode;
        newNode->next = curr;
    }
}


    void displayList(){
        node *curr = head;
         while (curr != NULL){
            cout << curr->value << " -> ";
            curr = curr->next;
         }
         cout <<"\n";
    }
    
    void placeEvenbeforeOdd() {
        if (head == nullptr || head->next == nullptr) return;

        node *evenStart = nullptr, *evenEnd = nullptr;
        node *oddStart = nullptr, *oddEnd = nullptr;
        node *curr = head;

        while (curr != nullptr) {
            int val = curr->value;

            if (val % 2 == 0) {  // Even node
                if (evenStart == nullptr) {
                    evenStart = curr;
                    evenEnd = evenStart;
                } else {
                    evenEnd->next = curr;
                    evenEnd = evenEnd->next;
                }
            } else {  // Odd node
                if (oddStart == nullptr) {
                    oddStart = curr;
                    oddEnd = oddStart;
                } else {
                    oddEnd->next = curr;
                    oddEnd = oddEnd->next;
                }
            }

            curr = curr->next;
        }

        // If there are no even nodes, no changes needed
        if (evenStart == nullptr) {
            return;
        }

        // Attach the even list to the odd list
        evenEnd->next = oddStart;

        // If there are odd nodes, terminate the list at the end of the odd list
        if (oddEnd != nullptr) {
            oddEnd->next = nullptr;
        }

        // Update the head to point to the start of the even list
        head = evenStart;
    }
    
};

int main(){
    node n1(5);
    list l1(&n1);
    node n2(53);
    l1.insertStart(&n2);
    node n3(7);
    l1.insertEnd(&n3);
    l1.insertAfterValue(5, 24);
    l1.insertBeforeValue(10, 53);

    l1.displayList();

    cout << "Placing all evens before odds: " << endl;
    l1.placeEvenbeforeOdd();
    l1.displayList();

    return 0;
}
