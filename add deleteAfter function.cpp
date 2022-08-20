#include<stdio.h>
#include <iostream>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

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

    LinkedListDoubly() {
        head = tail = NULL;  // initially set to NULL
        length = 0;
    }

    int getLength() const {
        return length;
    }

    int insertFirst(int item) {
        // insert at the beginning

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
        return SUCCESS_VALUE ;
    }

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

    void printListForward() const {
        ListNode* temp = head;

        while(temp != NULL) {
            printf("%d->", temp->item);
            temp = temp->next;
        }

        printf("\nLength: %d\n", length);
    }

    int insertLast(int item) {
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
        return SUCCESS_VALUE;
    }

    void deleteLast() {
        ListNode* temp = head; // start at the beginning

        if(head!=NULL){
            // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
            while(temp != NULL) {
                if(temp->next->next == NULL) break;
                temp = temp->next ; // move to next node
            }
            temp->next = NULL; // deleting
            --length;
        }
    }

    void deleteAfter(int item){
        ListNode* tergetedNode = NULL;
        ListNode* temp = searchItem(item);

        if(temp!=NULL && temp->next!=NULL){
            // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
            if(temp->next->next == NULL){
                // 4 ke search korle 
                // 5 er pore kew nai interchange korar moto
                // that means just delete last
                deleteLast();
            }
            else{
                // temp = 2

                // 1 -> 2 -> 3 -> 4 -> 5
                // 2 ke find kortesilam, tarmane dlt hobe 3

                tergetedNode = temp->next->next; //tergetedNode = 4

                // 2 er next e 4
                // 4 er prev 2

                temp->next = tergetedNode;
                tergetedNode->previous = temp;
                length--;
            }


        }
    }

    void printListBackward() const {
        ListNode* temp = tail;

        while(temp != NULL) {
            printf("%d->", temp->item);
            temp = temp->previous;
        }

        printf("\nLength: %d\n", length);
    }

    /*ADDED*/
    ~LinkedListDoubly() {
        while(length != 0) {
            deleteLast();
        }
    }
};


int main(void) {
    LinkedListDoubly ll;
    int choice, item;

    while(1) {
        printf("1. Insert item (First)\n2. Inset item (Last)\n");
        printf("3. Delete item (Last)\n");
        printf("4. Search item\n5. Print list forward\n6. Print list backward\n7. exit\n");
        printf("8. deleteAfter a item\n");

        printf("\nEnter choice: ");
        scanf("%d",&choice);

        if(choice == 1) {
            printf("\nEnter item: ");
            scanf("%d", &item);

            ll.insertFirst(item);
        }
        else if(choice == 2){
            printf("\nEnter item: ");
            scanf("%d", &item);

            ll.insertLast(item);
        }
        else if(choice == 3) {
            ll.deleteLast();
        }
        else if(choice == 4) {
            printf("\nEnter item: ");
            scanf("%d", &item);

            ListNode* returnNode = ll.searchItem(item);

            if(returnNode != NULL) {
                printf("\nItem found\n");
            }
            else {
                printf("\nItem not found\n");
            }
        }
        else if(choice == 5) {
            ll.printListForward();
        }
        else if(choice == 6) {
            ll.printListBackward();
        }
        else if(choice == 7) {
            break;
        }
        else if(choice == 8){
            printf("\nEnter item to delete after: ");
            scanf("%d", &item);

            ll.deleteAfter(item);
        }
        else {
            printf("\nInvalid choice\n");
        }

        printf("\n---------------------------------------------\n\n");
    }

    return 0;
}
