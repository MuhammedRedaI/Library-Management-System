#include <iostream>
using namespace std;

struct node{
        string title;
        int ID;
        bool isAvailable;
        node* next;
};

node* createBook(string title, int ID, bool isAvailable) {
    node* newBook = new node;
    newBook->title = title;
    newBook->ID = ID;
    newBook->isAvailable = isAvailable;
    newBook->next = nullptr;
    return newBook;
}


void addBook(node*& head, string title, int ID, bool isAvailable) {
    node* newBook = createBook(title, ID, isAvailable);
    if (head == nullptr) {
        head = newBook;  
    } else {
        node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;  
        }
        curr->next = newBook;  
    }
}

void initializeLibrary(node*& head) {
    for (int i = 1; i <= 100; ++i) {
        addBook(head, "Book " + to_string(i), i, true);  
    }
}


node* Search(node* &head, int ID, string title){
    if(head == nullptr){
        return nullptr; // for now
    }
    node* curr  = head;
    while(curr != nullptr){
        if (curr->title == title || curr->ID == ID){
            return curr;}
        curr = curr->next;
    }       
    return nullptr;
}

void Delete(node* &head, string title, int ID){
    if (head == nullptr){
        cout<<"the library is empty; no books to delete!"<<endl;
        return;
    }

    node* target = Search(head,ID, title);
    
    if (target == nullptr){
        cout<<"the book is nowhere to be found!"<<endl;
        return;
    }
    if (target == head){
        head = head->next;
        cout<<target->title <<" "<<"Book deleted successfully!"<<endl;
        delete target;
        return; 
    }
    node* curr = head;
    while(curr->next != target){
        curr = curr->next;
    }
    curr->next = target->next;
    cout<<target->title<<" "<<"Book deleted successfully!"<<endl;
    delete target;
    
}


int main(){

node* head = nullptr;
initializeLibrary(head);


    return 0;
}