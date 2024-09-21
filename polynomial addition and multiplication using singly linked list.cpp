#include<iostream>
using namespace std;
struct Node{
	int coe;
	int power;
	Node* next;
};
class Polynomial{
	Node* head;
	public:
	   Polynomial(){
	      head = NULL;
	   }
	   Node* get_head(){
	      return head;
	   }
	   //function to add a term i.e.node at end
	   void insert_at_end(int c, int p){
		Node* nn = new Node;
		nn->coe = c;
		nn->power = p;
		nn->next = NULL;
		if(head == NULL){
		   head = nn;
		}
		else{
		   Node* temp = head;
		   while(temp->next != NULL){
		   temp = temp->next;
	      	}
		temp->next = nn;
		}
	}
	//funstion for printing polynomial expression
	void display(){
	  Node* temp = head;
	  while(temp != NULL){
	     cout<<temp->coe<<"x^"<<temp->power;
	     if (temp->next != NULL) {
                cout << " + ";
            }
	     temp = temp->next;
	  }
	}
	
	//function for addition of two polynmial expressions
	void add_polynomial(Polynomial p, Polynomial p1,Polynomial &result){
		 Node* t1 = p.get_head();
		 Node* t2 = p1.get_head();
		 
		 //for adding the term with highest power first in the result linked list
		 while(t1 != NULL && t2 != NULL) {
		    if(t1->power > t2->power){
		    	result.insert_at_end(t1->coe,t1->power);
		    	t1 = t1->next;
			}
			
		    else if(t1->power < t2->power){
		    	result.insert_at_end(t2->coe, t2->power);
		    	t2 = t2->next;
		    }
		    else{
		        result.insert_at_end(t1->coe+t2->coe, t1->power);
		        t1 = t1->next;
		        t2 = t2->next;
		    }
	       }
	       //if any terms from first expression are remaining
	       while(t1 != NULL){
	          result.insert_at_end(t1->coe,t1->power);
	     	  t1 = t1->next;
	       }
	        //if any terms from second expression are remaining
	       while(t2 != NULL){
	          result.insert_at_end(t2->coe,t2->power);
		      t2 = t2->next;
	       }
	}
	//function for multiplication
	void multiply(Polynomial p, Polynomial p1, Polynomial &r){ 
		Node* t1 = p.get_head();
		
		while(t1 != NULL){
	            Node* t2 = p1.get_head();
		    while(t2 != NULL){
		       int a = t1->coe * t2->coe;
		       int b = t1->power + t2->power;
		       //combine the terms with same power
	             Node* temp = r.get_head();
	             Node* prev = NULL;
	             int flag = 0;
	             while(temp != NULL){
	               if(temp->power == b){
	                   temp->coe += a;
	                   flag = 1;
	                   break;
	               }
	               else{
	                   prev = temp;
	                   temp = temp->next;
	               }
	           
	           }
	           //if not having same power then add as seperate node
	            if(flag == 0){
	               r.insert_at_end(a,b);
	            }
		       t2 = t2->next;
		    }
		    t1 = t1->next;
	    }
	}
};
int main(){
    //for first polynomil expression
    Polynomial p;
    p.insert_at_end(7,7);
    p.insert_at_end(1,3);
    p.insert_at_end(4,2);
    p.display();
    cout<<endl;
    
    //for second polynomial operation
    Polynomial p1;
    p1.insert_at_end(9,12);
    p1.insert_at_end(5,7);
    p1.insert_at_end(1,6);
    p1.insert_at_end(1,5);
    p1.display();
    cout<<endl;
    
    //for storing result of addition
    Polynomial result;
    result.add_polynomial(p,p1,result);
    cout<<"Addition is : ";
    result.display();
    cout<<endl;
    
    //for storing result of multiplication
    Polynomial r;
    r.multiply(p,p1,r);
    cout<<"Multiplication is : ";
    r.display();

return 0;
}
