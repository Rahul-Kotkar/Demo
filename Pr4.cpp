#include <iostream>
using namespace std;

int q[5], front=-1, rear=-1;

void insert(int x) {
    if((front==0 && rear==4) || front==rear+1) {
        cout<<"Queue Overflow\n";
        return;
    }

    if(front==-1)
        front=rear=0;
    else
        rear=(rear+1)%5;

    q[rear]=x;
}

void deleteQ() {
    if(front==-1) {
        cout<<"Queue Underflow\n";
        return;
    }

    cout<<"Deleted: "<<q[front]<<endl;

    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%5;
}

void display() {
    if(front==-1) {
        cout<<"Queue is Empty\n";
        return;
    }

    int i=front;
    cout<<"Queue elements: ";

    while(true) {
        cout<<q[i]<<" ";
        if(i==rear) break;
        i=(i+1)%5;
    }
    cout<<endl;
}

int main() {
    int ch,x;

    do {
        cout<<"\n1.Insert\n2.Delete";
        cout<<"\n3.Display\n4.Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch) {
            case 1:
                cout<<"Enter value: ";
                cin>>x;
                insert(x);
                break;

            case 2:
                deleteQ();
                break;

            case 3:
                display();
                break;

            case 4:
                cout<<"Exit";
                break;

            default:
                cout<<"Invalid choice";
        }
    } while(ch!=4);

    return 0;
}