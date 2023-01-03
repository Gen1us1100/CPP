/*Implement C++ program for expression conversion as infix to
postfix and its evaluation using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input infix expression must be in a desired format.
    Only +, -, * and / operators are expected.*/

/*Infix expression: The expression of the form a operator b (a + b). 
    When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b operator (ab+). 
    When an operator is followed by every pair of operands.*/
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
        stack_array[top]= symbol;//given character is added at top location of stack
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

int precedence(char c){
    if (c == '/' || c== '*')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

void infixtopostfix(string s){
    stack st;
    string result;
    for(int i=0; i<s.length();i++){
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        //if the character in the string is a alphanumeric character i.e an OPERAND
        // then add it directly to the result string
        result += c;

        else if(c == '('|| c == '['|| c == '{'){
        switch(c){
            case ('('): st.push('(');
            case ('['): st.push('[');
            case ('{'): st.push('{');
            }
        }

        else if(c==')' || c == ']' || c == '}'){
            switch(c){
            case (')'):{
                while(st.topp() != '('){//if the char is ')' then add everything to result
            // until a '(' is occured and also pop everything from stack
                result += st.topp();
                st.pop();}
                st.pop();//This will pop the '('
                break;
            }
            case (']'):{
                while(st.topp() != '['){
                result += st.topp();
                st.pop();}
                st.pop();//This will pop the '['
                break;
                }
            case ('}'):{
                while(st.topp() != '{'){
                result += st.topp();
                st.pop();}
                st.pop();//This will pop the '{'
                break;
            }
             
            
            }
        }

        else{//if the precedence of operator in string is <= precedence of operator in top of stack
        // then add it to output result and pop the operator in stack
            while(!st.empty() && precedence(s[i])<=precedence(st.topp())){
                result += st.topp();
                st.pop();
            }
            st.push(c);
        }
    }
    
    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.topp();
        st.pop();
    }
    cout<<result<<endl;
}

int main(){
    string exp;
    cout<<"Enter the expression to convert from Infix to postfix\n: ";
    cin>>exp;
    infixtopostfix(exp);
    return 0;
}