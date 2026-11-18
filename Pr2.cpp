#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Student {
    int id;
    char name[30];
    float cgpa;
};

int main() {
    Student *s=NULL, temp;
    int n=0, ch, pos, order;

    do {
        cout << "\n1.Add Student";
        cout << "\n2.Display Students";
        cout << "\n3.Bubble Sort by Name";
        cout << "\n4.Selection Sort by CGPA";
        cout << "\n5.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch(ch) {
        case 1:
            s=(Student*)realloc(s,(n+1)*sizeof(Student));
            cout << "Enter ID, Name, CGPA: ";
            cin >> s[n].id >> s[n].name >> s[n].cgpa;
            n++;
            break;

        case 2:
            for(int i=0;i<n;i++)
                cout << s[i].id << " "
                     << s[i].name << " "
                     << s[i].cgpa << endl;
            break;

        case 3:
            // Bubble Sort by Name
            for(int i=0;i<n-1;i++)
                for(int j=0;j<n-i-1;j++)
                    if(strcmp(s[j].name,s[j+1].name)>0) {
                        temp=s[j];
                        s[j]=s[j+1];
                        s[j+1]=temp;
                    }

            cout << "Sorted by Name\n";
            for(int i=0;i<n;i++)
                cout << s[i].name << endl;
            break;

        case 4:
            cout << "1.Ascending  2.Descending: ";
            cin >> order;

            // Selection Sort by CGPA
            for(int i=0;i<n-1;i++) {
                pos=i;

                for(int j=i+1;j<n;j++) {
                    if((order==1 && s[j].cgpa<s[pos].cgpa) ||
                       (order==2 && s[j].cgpa>s[pos].cgpa))
                        pos=j;
                }

                temp=s[i];
                s[i]=s[pos];
                s[pos]=temp;
            }

            cout << "Sorted by CGPA\n";
            for(int i=0;i<n;i++)
                cout << s[i].name << " "
                     << s[i].cgpa << endl;
            break;
        }
    } while(ch!=5);

    free(s);
    return 0;
}