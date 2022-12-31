/*Queues are frequently used in computer programming and a typical
example is the creation of a job queue by an operating system. If the
operating system does not use priorities, then the jobs are processed in the
order they enter the system. Write C++ program for simulating job queue.
Write functions to add job and delete job from queue.*/

#include<iostream>
using namespace std;
#define MAX 10

class queue{
    int q[MAX];
    int start = -1;
    int finish = -1;

    public:
    int addjob(int x);
    int deljob();
    bool isfull();
    bool isempty();
    void display();
};

bool queue::isfull(){
    if(finish == MAX-1)
    return true;
    else
    return false;
}

bool queue::isempty(){
    if(start == finish)
    return true;
    else
    return false;
}

int queue::addjob(int x){
    if(isfull()){
        cout << "Queue OVERFLOW!"<<endl;
        return 0;
    }
    else{
        q[++finish] = x;//Job is always added at the end of queue 
        return 1;
    }
}

int queue::deljob(){
    if(isempty()){
        cout << "Queue UNDERFLOW!"<<endl;
        return 0;
    }
    else{
        
        return q[++start];// Job is always removed from start of the queue
    }
}

void queue::display(){
    if(isempty())
    cout<<"Job Queue is empty!"<<endl;
    else{
        cout<<"Jobs in the queue: ";
        for(int i=start+1;i<=finish;i++){
            cout<<q[i]<<' ';
        }
        cout<<endl;
    }
}

int main(){
    queue Q;
    int opt,pid,del_pid;
    cout<<"*********************************"<<endl;
    cout<<"         System Job Queue        "<<endl;
    do{
        cout<<"*********************************"<<endl;
        cout<<"Menu\n1.Add job to queue\n2.Delete job from queue\n3.Display the queue\n4.Exit"<<endl;
        cout<<"Your choice: ";
        cin>>opt;
        switch(opt){
            case(1):{
                cout<<"Enter job ID : "<<endl;
                cin>>pid;
                if(Q.addjob(pid))
                cout<<"Job Successfully added to the queue!"<<endl;
                else
                cout<<"Job WAS NOT added to the queue!"<<endl;
                break;
            }
            case(2):{
                del_pid = Q.deljob();
                cout<<"Job deleted from queue: "<<del_pid<<endl;
                break;
            }
            case(3):{
                Q.display();
                break;
            }
            case(4):{
                exit(1);
            }
            default: cout<<"INVALID OPTION!"<<endl;
        }
    }while(opt!=4);
}