#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* insert(Node* r, int x) {
    if(r==NULL) {
        Node* t=new Node{x,NULL,NULL};
        return t;
    }
    if(x<r->data) r->left=insert(r->left,x);
    else if(x>r->data) r->right=insert(r->right,x);
    else cout<<"Duplicate value!";
    return r;
}

Node* search(Node* r, int x) {
    if(r==NULL || r->data==x) return r;
    if(x<r->data) return search(r->left,x);
    return search(r->right,x);
}

Node* minimum(Node* r) {
    while(r->left!=NULL) r=r->left;
    return r;
}

Node* deleteNode(Node* r, int x) {
    if(r==NULL) return r;

    if(x<r->data) r->left=deleteNode(r->left,x);
    else if(x>r->data) r->right=deleteNode(r->right,x);
    else {
        if(r->left==NULL) return r->right;
        if(r->right==NULL) return r->left;

        Node* t=minimum(r->right);
        r->data=t->data;
        r->right=deleteNode(r->right,t->data);
    }
    return r;
}

void inorder(Node* r) {
    if(r) {
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }
}

int depth(Node* r) {
    if(r==NULL) return 0;
    int l=depth(r->left);
    int h=depth(r->right);
    return 1+(l>h?l:h);
}

void mirror(Node* r) {
    if(r) {
        mirror(r->right);
        cout<<r->data<<" ";
        mirror(r->left);
    }
}

Node* copyTree(Node* r) {
    if(r==NULL) return NULL;
    Node* t=new Node{r->data,NULL,NULL};
    t->left=copyTree(r->left);
    t->right=copyTree(r->right);
    return t;
}

void parents(Node* r) {
    if(r) {
        if(r->left || r->right) {
            cout<<r->data<<" : ";
            if(r->left) cout<<r->left->data<<" ";
            if(r->right) cout<<r->right->data;
            cout<<endl;
        }
        parents(r->left);
        parents(r->right);
    }
}

void leaves(Node* r) {
    if(r) {
        if(!r->left && !r->right)
            cout<<r->data<<" ";
        leaves(r->left);
        leaves(r->right);
    }
}

void levelWise(Node* r) {
    if(!r) return;
    queue<Node*> q;
    q.push(r);

    while(!q.empty()) {
        Node* t=q.front();
        q.pop();
        cout<<t->data<<" ";

        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
    }
}

int main() {
    Node* root=NULL;
    Node* copy=NULL;
    int ch,x;

    do {
        cout<<"\n1.Insert  2.Delete  3.Search";
        cout<<"\n4.Traversal  5.Depth  6.Mirror";
        cout<<"\n7.Copy  8.Parent-Child";
        cout<<"\n9.Leaf Nodes  10.Level Wise";
        cout<<"\n11.Exit\nChoice: ";
        cin>>ch;

        switch(ch) {
        case 1:
            cout<<"Enter value: ";
            cin>>x;
            root=insert(root,x);
            break;

        case 2:
            cout<<"Enter value: ";
            cin>>x;
            root=deleteNode(root,x);
            break;

        case 3:
            cout<<"Enter value: ";
            cin>>x;
            cout<<(search(root,x)?"Found":"Not Found");
            break;

        case 4:
            inorder(root);
            break;

        case 5:
            cout<<"Depth: "<<depth(root);
            break;

        case 6:
            mirror(root);
            break;

        case 7:
            copy=copyTree(root);
            cout<<"Copied Tree: ";
            inorder(copy);
            break;

        case 8:
            parents(root);
            break;

        case 9:
            leaves(root);
            break;

        case 10:
            levelWise(root);
            break;
        }
        cout<<endl;
    } while(ch!=11);

    return 0;
}