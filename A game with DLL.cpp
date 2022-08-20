#include<stdio.h>
#include <iostream>
#include<cstdlib>

using namespace std;

class ListNode {

    public:
        int item;
        ListNode* next;
        ListNode* previous;
    };


    class LinkedListDoubly {

        ListNode* head;
        ListNode* tail;
        int length;

        public:

            //INITIALIZING CONSTRUCTOR
            LinkedListDoubly() {
                head = tail = NULL;  // initially set to NULL
                length = 0;
            }


            //GET LENGTH FUNCTION
            int getLength() const {
                return length;
            }

            //SEARCHHING FUNCTION
            ListNode* searchItem(int item) const {
                ListNode* temp = head; // start at the beginning

                while(temp != NULL) {
                    if (temp->item == item) {
                        return temp;
                    }

                    temp = temp->next ; // move to next node
                }

                return NULL;
            }


            //COUNT HOW MANY
            int countItem(int item){
                int count = 0;

                ListNode* temp = head;
                while(temp != NULL) {
                    if (temp->item == item) {
                        count++;
                    }
                    temp = temp->next ; // move to next node
                }

                return count;
            }


            //INSERTING FUNCTIONS
            int insertFirst(int item) {// insert at the beginning
                ListNode* newNode = new ListNode();
                newNode->item = item;

                newNode->next = head;
                newNode->previous = NULL;

                if(head == NULL) {
                    // inserting the first item
                    head = tail = newNode;
                }
                else {
                    head->previous = newNode;
                    head = newNode;
                }

                length++;
                return item ;
            }
            int insertLast(int item) {// insert at the last
                ListNode* newNode = new ListNode();

                newNode->item = item;
                newNode->next = NULL;
                newNode->previous = tail;

                if(tail == NULL) {
                    head = tail = newNode;
                }
                else {
                    tail->next = newNode;
                    tail = newNode;
                }

                length++;
                return item;
            }



            //DELETING FUNCTIONS
            void deleteFirst() {
                if(head!=NULL){
                    head = head->next;
                    // length--;
                }
            }
            void deleteLast() {
                ListNode* temp = head;

                if(head!=NULL){
                    while(temp != NULL) {
                        if(temp->next->next == NULL) break;
                        temp = temp->next ;
                    }
                    temp->next = NULL; // deleting
                    // length--;
                }
            }
            int deleteValue(int item){
                ListNode* p = NULL;
                ListNode* n = NULL;
                ListNode* temp = searchItem(item);

                if(temp!=NULL){
                    // 1 -> 2 -> 3 -> 2 -> 5 -> NULL

                    if(temp == head) deleteFirst(); // if we search 1
                    else if(temp == tail) deleteLast(); // if we seach 5
                    else{
                        // if we search 2
                        p = temp->previous; // 1
                        n = temp->next; // 3

                        p->next = n;
                        n->previous = p;

                    }

                }
                length--;
                return item;
            }


            //TRAVERSING FUNCTIONS
            // void traverseDLL(){
            //     cout << "\nTraversing The DLL\n";
            //     ListNode* temp = head; // start at the beginning

            //     while(temp != NULL) {
            //         cout << temp->item;
            //         if(temp->next != NULL) cout << "->";

            //         temp = temp->next ; // move to next node
            //     }

            //     cout << "\n\n";

            // }


            /*ADDED*/
            ~LinkedListDoubly() {
                while(length != 0) {
                    deleteLast();
                }
            }
};


int main(void) {
    LinkedListDoubly ll;

    int n, response=-1;
    cout << "Insert The value of N : ";
    cin >> n;

    // int arr[n+1];
    // for(int i=0; i<n ; ++i) cin >> arr[i];



    for(int i=0; i<n ; ++i){

        int random = rand() % 101; if(random==0) random++;


        // geting the item count
        int itemCount = ll.countItem(random);

        if(itemCount == 0){ // if no item
            response = ll.insertFirst(random);
            cout << response << " inserted at head\n";
        }
        else if(itemCount == 1){ // if 1 item available
            response = ll.insertLast(random);
            cout << response << " inserted at last\n";
        }
        else if (itemCount == 2){ // if 2 available
            response = ll.deleteValue(random);
            cout << response << " deleted\n";
        }
    }


    //ll.traverseDLL();

    return 0;
}
