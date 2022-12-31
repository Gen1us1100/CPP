/*In any language program mostly syntax error occurs due to unbalancing
delimiter such as (), {}, []. Write C++ program using stack to check
whether given expression is well parenthesized or not.*/

#include<iostream>
#include<string>
using namespace std;


class stack{
    public:
    char stack_array[50];
    int top; //points at top element in the stack
    stack(){
        top = -1;
    } // top is set to -1 everytime a new stack is declared

        void push(char symbol);
        char pop();
        int full();
        int empty();
        char topp();
};

void stack::push(char symbol){
    if (full())
    cout<<"STACK IS FULL!"<<endl;
    else{
        top++;
        stack_array[top]= symbol;//given character is added at top(theoretically last) location of stack
    }
}

char stack::pop(){
    if(!empty())
    {
        return (stack_array[top--]); //
    }
    else
    cout<<"STACK IS EMPTY!"<<endl;
    return ('#');
}

char stack::topp(){
    return (stack_array[top]);
}
int stack::full(){
    if(top==49)
    return 1;
    else
    return 0;
}

int stack::empty(){
    if(top==-1)
    return 1;
    else
    return 0;
}

void checkparenthesis(string s){
    stack st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch=='(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else if(ch == ')'||ch == '}'||ch == ']'){
            if(st.empty()){
            cout<<"Expression is NOT well parenthesized.";
            return ;
            }
            else{
                switch(ch){
                    case (')'):{
                        if(st.topp()!= '('){
                        cout<<"Expression is NOT well parenthesized.";
                        return ;}
                        else
                        break;
                    }
                    case ('}'):{
                        if(st.topp()!= '{'){
                        cout<<"Expression is NOT well parenthesized.";
                        return ;}
                        else
                        break;
                    }
                    case (']'):{
                        if(st.topp()!= '['){
                        cout<<"Expression is NOT well parenthesized.";
                        return;}
                        else
                        break;
                    }
                }
            }
            st.pop();
        }
    }
    if(st.empty())
    cout<<"Expression is well parenthesized.";
    else
    cout<<"Expression is NOT well parenthesized.";
}

int main(){
    string exp;
    cout<<"Enter the expression to check parenthesis\n: ";
    cin>>exp;
    checkparenthesis(exp);
    return 0;
}