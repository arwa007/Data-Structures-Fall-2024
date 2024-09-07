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


    void deleteHead(){
        if (head != NULL){
            node *curr = head;
            head = curr->next;
            delete curr;
        }
    }

    void deleteTail(){
        if (head == NULL) return;

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        node *curr = head;
        node *prev = NULL;

        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
        delete curr;
    }

    void displayList(){
        node *curr = head;
         while (curr != NULL){
            cout << curr->value << " -> ";
            curr = curr->next;
         }
         cout <<"\n";
    }

    void deleteValue(int searchVal){
         if (head == NULL) return;

        if (head->value == searchVal) {
            deleteHead();
            return;
        }

        node *curr = head;
        node *prev = NULL;

        while (curr != NULL && curr->value != searchVal) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL) {
            prev->next = curr->next;
            delete curr;
        }
    }

    int getNodeCount(){
        int count = 0;
        if (head != NULL){
        node *curr = head;
        while (curr != NULL){
            count ++;
            curr = curr->next;
        }
        }
        return count;
    }

    
};

int main(){
    node n1(5);

    cout << "Intializing List with 5 as head: " <<endl;
    list l1(&n1);
    l1.displayList();
   
    node n2(10);
    cout << "Inserting 10 at Start:" << endl;
    l1.insertStart(&n2);
    l1.displayList();

    node n3(7);
    cout << "Inserting 7 at End: " << endl;
    l1.insertEnd(&n3);
    l1.displayList();

    cout << "Inserting 23 after 5: " << endl;
    l1.insertAfterValue(5, 23);
    l1.displayList();

    cout << "Inserting 53 before 10: " << endl;
    l1.insertBeforeValue(10, 53);
    l1.displayList();

    cout << "Deleting head: " << endl;
    l1.deleteHead();
    l1.displayList();

    cout << "Deleting Tail: " << endl;
    l1.deleteTail();
    l1.displayList();

    cout << "Deleting 23: " << endl;
    l1.deleteValue(23);
    l1.displayList();

    cout << "Total Node Count: " << l1.getNodeCount();


    return 0;
}
