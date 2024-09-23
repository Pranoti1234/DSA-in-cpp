// Text editor application using doubly linked list
#include <iostream>
using namespace std;
struct Node{
    string data;
    Node* next;
    Node* prev;
};

class Text_Editor{
    Node* head;
    public:
        Text_Editor(){
            head = NULL;
        }
        //function to insert a new value in the text editor
        void insert(string s){
            Node* nn = new Node;
            Node* temp = head;
            nn->data = s;
            //Inserting at head
            if(head == NULL){
                nn->prev = NULL;
                head = nn;
                nn->next = NULL;
            }
            //inserting at end 
            else{
                while(temp->next){
                    temp = temp->next;
                }
                nn->prev = temp;
                nn->next = NULL;
                temp->next = nn;
            }
        }
        //fuction to delete a text from text editor
        void delete_text(string s){
            Node* temp = head;
            int flag = 0;
            while(temp){
                //check if value to delete is present in list or not
                if(temp->data == s){
                    flag = 1;
                    if(temp->prev){
                        temp->prev->next = temp->next;
                    }
                    else {
                        temp->next->prev = NULL;
                        head = temp->next;
                    }
                   if(temp->next){
                        temp->next->prev = temp->prev;
                   }
                   else{
                       temp->prev->next = NULL;
                   }
                    Node* ntbd = temp;
                    delete ntbd;
                }
                temp = temp->next;
            }
            if(flag == 0)
                cout<<"Text that you want to delete is not in the list and the given text editor contains following item : "<<endl;
            
        }
        //function to display items of text editor
        void display(){
            Node* temp = head;
            while(temp){
                cout<<temp->data<<endl;;
                temp = temp->next;
            }
        }
        
        //function for searching a given value
        void search(string s){
            Node* temp = head;
            int flag = 0;
            while(temp){
                if(temp->data == s){
                    cout<<s<<" found in the given linked list!!"<<endl;
                    flag = 1;
                    return;
                }
                else{
                    temp = temp->next;
                }
            }
            if(flag == 0){
                cout<<s<<" not found in the linked list!!"<<endl;
            }
        }
        
        //function to print content of text editor in reverse order
        void print_reverse(){
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            cout<<"Printing in reverse order : "<<endl;
            while(temp){
                cout<<temp->data<<endl;
                temp = temp->prev;
            }
        }
        
};

int main() {
    Text_Editor t;
    t.insert("abc");
    t.insert("bbb");
    t.insert("ccc");
    t.insert("ddd");
    t.display();
    
    t.search("abc");
    t.search("yu");
    
    t.print_reverse();
    
    t.delete_text("ccc");
    cout<<"After deleting a given text"<<endl;
    t.display();
    
    t.delete_text("ttt");
    t.display();
    
    return 0;
}