#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct single_linked_list{

    node *head;

    single_linked_list(){
        head = NULL;
    }

    node* search_in_list(int val){
        node *temp = head;

        while(temp->next!=nullptr){
            if(temp->data==val)
                return temp;
            else
                temp = temp->next;
        }
        return nullptr;
    }


    void insert_first(int val){
        //1st step
        node *temp = new node;
        temp->data = val;
        //2nd step
        temp->next = head;
        //3rd step
        head = temp;

    }
    void insert_last(int val)
    {
        //1st step
        node *temp = new node;
        temp->data = val;

        //2nd step
        node *last = head;
        while(last->next!=nullptr)
        {
            last = last->next;
        }

        //3rd step
        last->next = temp;

        //4th step
        temp->next = NULL;

    }

    void insert_middle(int new_val, int prev_val){

        node *prevNode = search_in_list(prev_val);


        node *temp = new node;
        temp->data = new_val;
        //2nd step
        temp->next = prevNode->next;


        //3rd step
        prevNode->next = temp;

    }


    void insert_in_order(int val){
        node *temp = head;
        node *save = head;

        while( temp->data < val ){ 
            save = temp; //save->data = 1
            temp = temp->next; //temp->data = 3
        }

        //Linked_List:1->3->4->5 ->nullptr
        //val:2
        // 2 er ager value save e thakbe 
        // 2 er porer value temp er modde thakbe
        //Output: 1->2->3->4->5 


        if(temp==head){
            insert_first(val);
        }
        else if(temp==nullptr){
            insert_last(val);
        }
        else {
            // (new value , prev data)
            insert_middle(val,save->data);
        }
    }

    void sum(){
        int sum = 0;

        node *temp = head;
        while(temp!=NULL){
            sum = sum + temp->data;
            temp = temp->next;
        }

        cout << "summation of all the datas are = " << sum << endl;
    }

    void deleteitem(int val){
        //Linked_List:1->2->3->4->5->nullptr
        //val:5
        //Output: 1->2->4->5

        node *temp = head;
        node *prev = head;
        node *nextt = head;


        while( temp->data != val ){ 
            prev = temp; //prev->data = 4
            temp = temp->next; //temp->data = 5
            nextt = temp->next; // nextt->data = Null nextt->next = nullptr
        }

        // prev er modde ase delete howa datar ager data
        // (temp er next) er modde 4 er data ase

        //prev er next er modder 4 er data rakha

        if(prev == head){
            deletefirst() ;
        }
        else if(nextt == nullptr){
            deletelast() ;
        }
        else{
            prev->next =  temp->next;
        }

    }



    void deletefirst()    //delete the first element
    {
        node* cur;
        if(head==NULL)
            printf("list is empty and nothing to delete\n");
        cur=head;
        head=head->next;
        free(cur);
    }
    void deletelast()   //delete the last element
    {
        if(head==NULL)
        {
            printf("list is empty and nothing to delete\n");
        }
        node* cur=head;
        node* prev=NULL;
        while(cur->next!=NULL)
        {
            prev=cur;
            cur=cur->next;
        }
        if(prev->next!=NULL)
            prev->next=NULL;
        free(cur);
    }
    void show_list()
    {
        cout << endl;

        node *temp = head;
        while(temp!=NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << endl;

        cout << endl;
    }


};
int main()
{
    single_linked_list linked_list;
    int ch;
    int val, prev_val;
    node *y = new node;

    while(1)
    {
        cout << "---MENU---" << endl;
        cout << "1. Insert First" << endl;
        cout << "2. Show All " << endl;
        cout << "3. Search " << endl;
        cout << "4. Insert Last " << endl;
        cout << "5. Insert Middle " << endl;
        cout << "6. Insert In Order " << endl;
        cout << "7. Exit " << endl;
        cout<<"8. Delete First "<<endl;
        cout<< "9. Delete Last " << endl;

        cout<< "10. Delete item " << endl;
        cout<< "11. Sum " << endl;

        cin >> ch;

        switch(ch)
        {
        case 1:
            cout << "Enter the value of data: ";

            cin >> val;
            linked_list.insert_first(val);
            break;

        case 2:
            linked_list.show_list();
            break;

        case 3:
            cout << "Enter a value to search in the list: ";

            cin >> val;

            y = linked_list.search_in_list(val);
            if(y!=nullptr)
            {
                cout << "Node found!" << endl;
                cout << y->data << endl;
            }
            else
            {
                cout << "Node not found!" << endl;
            }
            break;

        case 4:
            cout << "Enter the value of data: ";
            cin >> val;
            linked_list.insert_last(val);
            break;

        case 5:
            cout << "Enter the new value of data: ";
            cin >> val;
            cout << "Enter the prev value of data: ";
            cin >> prev_val;
            linked_list.insert_middle(val, prev_val);
            break;

        case 6:
            cout << "Enter the value of data: ";
            cin >> val;
            linked_list.insert_in_order(val);
            break;

        case 7:
            return 0;
            break;
        case 8:

            linked_list.deletefirst();
            break;
        case 9:

            linked_list.deletelast();
            break;

        case 10:
            cout << "Enter the new value of data you want to delete: ";
            cin >> val;
            linked_list.deleteitem(val);
            break;

        case 11:
            linked_list.sum();
            break;



        default:
            cout << "Wrong input!" << endl;
        }
    }

    return 0;
}