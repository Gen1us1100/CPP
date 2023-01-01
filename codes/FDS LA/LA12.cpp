/*Pizza parlor accepting maximum M orders. Orders are served in first come
first served basis. Order once placed cannot be cancelled. Write C++
program to simulate the system using circular queue using array.*/

/*Circular Queue : After last element the pointer at last element of queue comes back to start 
of the queue. Hence unlike normal queue space in the queue is not wasted.*/

#include<iostream>
#include<string>
using namespace std;
#define MAX 5

class Order{
    int order_id;
    string name;
    public:
    void accept_order(){
        cout<<"Enter Order ID: ";
        cin>>order_id;
        cout<<"Enter Orderer Name: ";
        cin>>name;
    }
    void display_order(){
        cout<<order_id<<"\t\t"<<name<<endl;
    }
    friend class Queue;    
};

class Queue{
    public:
    Order q[MAX];//Array of Orders
    int front,rear;
    //public:
    Queue(){
        front=rear=-1;
    }
    void enqueue();
    void dequeue();
    int isfull();
    int isempty();
    void display();
};

int Queue::isfull(){
    //circular queue is full if front is at 1st ele and rear is at last
    // OR when rear is pointing just behind front
    if((rear==MAX-1 && front == 0)||(front == rear+1))
    return 1;
    else
    return 0;
}

int Queue::isempty(){
    if(front == -1 && rear == -1)
    return 1;
    else
    return 0;
}

void Queue::enqueue(){
    if(isfull()){
        cout<<"Can NOT accept the order, The Queue is FULL!"<<endl;
    }
    else{
        //Creates a temporary object and is stored in the Queue
        Order temp;
        temp.accept_order();
        if(rear == MAX-1 && front!=0){//to reuse the leftover space after serving an order
            rear = -1;
        }
        q[++rear] = temp;
        cout<<"Order added to the queue SUCCESSFULLY!"<<endl;
        if(front==-1)
        front++;
    }
}
void Queue::dequeue(){
    if(isempty()){
        cout<<"Can NOT serve the order, The Queue is EMPTY!"<<endl;
    }
    else{
        front++;
        cout<<"Order served SUCCESSFULLY!"<<endl;

        if(front==MAX)
            front = 0;//to bring back front pointer to 1st element
        //if(front-1 == rear)
        if(front == 0 && rear==MAX-1)
            front = rear = -1;//to reset the entire queue 
            /*I sincerely doubt this logic GOTTA TEST */
    }
}

void Queue::display(){
    if(isempty()){
        cout<<"THERE ARE NO ORDERS TO DISPLAY!"<<endl;
    }
    else{
        
        cout<<"*********************************"<<endl;
        cout<<"Order ID\tOrderer Name"<<endl;
        cout<<"*********************************"<<endl;
        if(front<=rear){//to print all elements from front to rear is known as printing the queue
        for(int i = front;i<=rear;i++){
            q[i].display_order();
        }}
        else{
            for(int i = front;i<MAX;i++){
                q[i].display_order();
            }
        }
    }
}

int main(){
    Queue order_q;
    int opt;
    cout<<"*********************************"<<endl;
    cout<<"WELCOME TO PIZZA PARLOUR\t"<<endl;
    do{
        cout<<"*********************************"<<endl;
        cout<<"Menu\n1.Add Order\n2.Serve order\n3.Display Orders\n4.Exit"<<endl;
        cout<<"Your choice: ";
        cin>>opt;
        switch(opt){
            case(1):{
                order_q.enqueue();
                break;
            }
            case(2):{
                order_q.dequeue();
                break;
            }
            case(3):{
                order_q.display();
                break;
            }
            case(4):{
                exit(1);
            }
            default: cout<<"INVALID OPTION!"<<endl;
        }
    }while(opt!=4);
    return 0;
}