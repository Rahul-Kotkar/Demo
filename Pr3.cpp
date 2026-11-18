#include <iostream>
#include <cctype>
using namespace std;

struct Node {
    char data;
    Node *next;
};

Node *top=NULL;

void push(char x) {
    Node *t=new Node{x,top};
    top=t;
}

char pop() {
    if(top==NULL) return '\0';
    Node *t=top;
    char x=t->data;
    top=top->next;
    delete t;
    return x;
}

int priority(char x) {
    if(x=='+' || x=='-') return 1;
    if(x=='*' || x=='/') return 2;
    return 0;
}

void postfix() {
    char exp[50];
    cout<<"Enter expression: ";
    cin>>exp;

    for(int i=0; exp[i]!='\0'; i++) {
        char x=exp[i];

        if(isalnum(x)) cout<<x;
        else if(x=='(') push(x);
        else if(x==')') {
            while(top && top->data!='(')
                cout<<pop();
            if(top) pop();
        }
        else {
            while(top && top->data!='(' &&
                  priority(top->data)>=priority(x))
                cout<<pop();
            push(x);
        }
    }

    while(top) cout<<pop();
    cout<<endl;
}

int main() {
    int ch;
    do {
        cout<<"\n1.Infix to Postfix";
        cout<<"\n2.Exit\nChoice: ";
        cin>>ch;

        if(ch==1) {
            cout<<"Postfix: ";
            postfix();
        }
    } while(ch!=2);

    return 0;
}