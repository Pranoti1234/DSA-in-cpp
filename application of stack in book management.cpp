//performing basic stack operations on book data
#include <iostream>
using namespace std;
class Book{
    string title;
    string author;
    string isbn;
    public:
        Book(string t = "", string a = "", string i= ""){
            title = t;
            author = a;
            isbn = i;
        }
        string get_title(){
            return title;
        }
        string get_author(){
            return author;
        }
        string get_isbn(){
            return isbn;
        }
};
class stack{
    int top;
    static const int n = 10;
    Book stk[n];
    public:
        stack(){
            top = -1;
        }
        void push(Book b){
            if(top == n-1){
                cout<<"stack overflow can not be pushed more books"<<endl;
                return;
            }
            stk[++top] = b;
        }
        void pop(){
            if(!isEmpty()){
                cout<<stk[top].get_title()<<endl;
                top--;
            }
            else
              cout<<"stack underflow can not pop more elemnts as stack is empty"<<endl;
        }
        
        Book peek(){
            if(top == -1){
                cout<<"Stack is empty"<<endl;
                return Book();
            }
            return stk[top];
        }
        bool isEmpty(){
            if(top == -1)
                return true;
            return false;
        }
};
int main() {
    stack s;
    Book b1{"aaa", "xyz", "123"};
    Book b2{"bbb", "xyz", "456"};
    Book b3{"ccc", "xyz", "1789"};
    Book b4{"ddd", "xyz", "298"};
    
    s.push(b1);
    s.push(b2);
    s.push(b3);
    s.push(b4);
    
    s.pop();
    cout<<"Book at top is : ";
    Book book_at_top = s.peek();
    cout<<"Name : "<<book_at_top.get_title()<<endl;
    cout<<"Author : "<<book_at_top.get_author()<<endl;
    cout<<"isbn : "<<book_at_top.get_isbn()<<endl;
    return 0;
}