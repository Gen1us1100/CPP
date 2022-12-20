/*The ticket booking system of Cinemax theater has to be implemented using C++ program.
There are 10 rows and 7 seats in each row. Doubly circular linked list has to be
maintained to keep track of free seats at rows. Assume some random booking to start
with. Use array to store pointers (Head pointer) to each row. On demand
a) The list of available seats is to be displayed
b) The seats are to be booked
c) The booking can be cancelled.*/

/*This program will mainly consist of two things
1. Node class or struct 
2. Cinemax class with respective functions

*/

#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
    public:
    int seat; //will store seat no. 
    Node *next,*prev;//std pointers for DCLL
    int status;//if 0 -- not booked if 1 -- booked
    string id;//to store id of the user
};

class cinemax{//class for the cinemax
    public:
    Node *head,*tail,*temp;
    cinemax(){
        head = NULL;
    }


    void create_list(); // used to create the DCLL using Node object
    void display();// used to display the theatre
    void book(); // used to book seats 
    void cancel(); // used to cancel seats
};

void cinemax::create_list(){//MOST IMP function if done properly;
    
    /*Next 4 lines will create a single node and set respective properties and line 47 will 
    set it's head pointer and tail pointer to itself as it is only node in the list*/
    temp = new Node;
    temp -> seat = 1;
    temp -> status = 0;
    temp -> id = "NULL";
    head = tail = temp;
    //this loop will create remaining 69 seats and set their properties
    for(int i=2; i<=70;i++){
        Node *p; 
        // The pointer p will always point to the current node and tail will point at theoretical last node of list
        p = new Node;
        p->seat = i;
        p-> status = 0;
        p-> id = "NULL";\
        /*most imp logic line 58- 62 
        so for each new created node we will set its pointers corresponding to tail node
        as we are adding the new node at the end of the list*/
        tail->next = p;
        p->prev = tail;
        tail = p;
        tail->next=head;
        head->prev = tail;
    }

    }

void cinemax::display(){//This functions displays the theatre
    int row=1 ; //counts the row number
    int count=0 ; // counts the seat no.
    Node *temp;
    temp = head;
    cout<<"                 WELCOME TO THE CINEMAX THEATRE               "<<endl;
    cout<<"=============================================================="<<endl;
    cout<<"                     ALL EYES THIS WAY                        "<<endl;
    cout<<"=============================================================="<<endl;
    do{
        
        if(temp->seat/10 == 0){
            if(temp->status == 1)
            cout<<"S0"<<temp->seat<<"|_B_|"<<" ";
            else
            cout<<"S0"<<temp->seat<<"|___|"<<" ";
            
        }
        else{
            if(temp->status == 1)
            cout<<"S"<<temp->seat<<"|_B_|"<<" ";
            else
            cout<<"S"<<temp->seat<<"|___|"<<" ";
            
        }
        count++;
        if(count%7==0){
            
            row++;
            cout<<endl;
        }
            
        temp = temp->next;
    }while(temp!=head);//THIS CONDITION IS IMP to print 70th seat
    cout<<"=============================================================="<<endl;
}

void cinemax::book(){
    int x;
    string y;
    Node *temp;
    temp = head;
    while(x<=0||x>70){
   
    cout<<"ENTER THE SEAT NO. TO BE BOOKED(1-70): ";
    cin>>x;
    if(x<=0||x>70)
    cout<<"ENTER VALID SEAT NO!"<<endl;
}
    cout<<"ENTER YOUR ID: ";
    cin>>y;
    while(temp->seat != x){
        temp = temp->next; //Here we are traversing to find the node of seat
        }
        
        if(temp->status==1)
            cout<<"SEAT ALREADY BOOKED!"<<endl;
            else{
            temp->status = 1;
            temp->id = y;
            cout<<"SEAT BOOKED SUCCESSFULLY!"<<endl;
    }

}

void cinemax::cancel(){
    int x;
    string y;
    Node *temp;
    temp = head;
    while(x<=0||x>70){
   
    cout<<"ENTER THE SEAT NO. TO BE CANCELLED(1-70): ";
    cin>>x;
    if(x<=0||x>70)
    cout<<"ENTER VALID SEAT NO!"<<endl;
}
    tryagain:
    cout<<"ENTER YOUR ID: ";
    cin>>y;
    while(temp->seat != x){
        temp = temp->next; //Here we are traversing to find the node of seat
        }
    if(temp->status==0)
            cout<<"SEAT NOT BOOKED YET!"<<endl;
    else{
        if(temp->id != y){
        cout<<"ID MISMATCH! TRY AGAIN."<<endl;
        goto tryagain;
        }
        temp->status = 0;
        temp->id = "NULL";
        cout<<"SEAT CANCELLED SUCCESSFULLY!"<<endl;
    
    
    }
    
    
    
}
void menu(cinemax &obj){
    obj.create_list();
    int opt;
    char ch = 'y';
    
    cout<<"WELCOME TO THE CINEMAX THEATRE TICKET BOOKING SYSTEM!"<<endl;
    again:
    while(ch=='y'){
    cout<<"PLEASE ENTER OPTION NUMBER:\n1.Display Seats\n2.Book a seat\n3.Cancel a seat\n4.Exit"<<endl;
    cout<<"YOUR CHOICE: ";
    cin>>opt;
    switch(opt){
        case 1: obj.display();
                break;
        case 2: obj.book();
                obj.display();
                break;
        case 3: obj.cancel();
                obj.display();
                break;
        case 4 : cout<<"THANK YOU FOR USING OUR TICKET BOOKING SYSTEM!";
                 exit(0);
        default:
            cout<<"INVALID OPTION! TRY AGAIN!"<<endl;
            goto again;
    }
    cout<<"Do you want perform any other operation?(y/n)"<<endl;
    cin>>ch;
    if(ch=='n')
    cout<<"THANK YOU FOR USING OUR TICKET BOOKING SYSTEM!";
    }
}
int main(){
    char op;
    cinemax obj1;
    menu(obj1);  
    return 0;
}