#include <iostream>
using namespace std;

class node{
    node* next=nullptr;
    node *prev=nullptr;
    int value;

    public:
    friend class doublyLinked;

    node() {value = 0;}
    node(int data) : value(data) {};
};

class doublyLinked{
    node *head;
    node *tail;

    public:

    doublyLinked(node *Node) : head(Node), tail(Node) {cout << "Doubly Linked List created with: " << Node->value << endl;}

    void insertFront(node *newNode){
        if (head == NULL){
            head = newNode;
            return;
        }
        newNode->next = head;
        newNode->prev = nullptr;

        head->prev = newNode;
        head = newNode;
    
    }

    void insertEnd(node *newNode){
        if (tail == NULL){
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = nullptr;
        tail = newNode;
    }

    void insertBeforeVal(int searchVal, node *newNode){
        
        if (head->value == searchVal){
            insertFront(newNode);
            return;
        }

        if (head != NULL){
            node *curr = head;
            node *previous = nullptr;
            bool found = false;

            while(curr != NULL){
                if(curr->value == searchVal){
                    found = true;
                    previous->next = newNode;
                    newNode->prev = previous;
                    curr->prev = newNode;
                    newNode->next = curr;
                    return;
                }
                previous = curr;
                curr = curr->next;

            } 
            if(!found){
                cout << "The value you entered was not in the doubly linked List." << endl;
            }
        }
    }

    void insertAfterVal(int searchVal, node *newNode){
         if (tail->value == searchVal){
            insertEnd(newNode);
            return;
        }

        if (head != NULL){
            node *curr = head;
            node *nextNode = head->next;
            bool found = false;

            while(curr != NULL){
                if (curr->value == searchVal){
                found = true;
                nextNode->prev = newNode;
                newNode->next = nextNode;
                curr->next = newNode;
                newNode->prev = curr;
                return;
            }

            curr = curr->next;
            nextNode = curr->next;
            }

            if(!found){
                cout << "The value you entered was not in the doubly linked List." << endl;
            }            
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

    void sortList() {
    if (head == nullptr || head->next == nullptr) {
        return; 
    }

    bool sorted;
    node* current;

    do {
        sorted = true; 
        current = head;

        while (current->next != nullptr) {
            if (current->value > current->next->value) {
    
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;

                sorted = false; 
            }
            current = current->next;
        }
    } while (!sorted); 
}

};

int main(){
    
    node n1(5);
    node n2(91);
    node n3(64);
    node n4(23);
    node n5(81);

    doublyLinked l1(&n1);

    l1.insertAfterVal(5, &n2);
    l1.insertBeforeVal(91, &n3);
    l1.insertFront(&n4);
    l1.insertEnd(&n5);
   
    l1.displayList();

    cout <<"Sorting the list: " << endl;
    l1.sortList();
    l1.displayList();

    return 0;
}
