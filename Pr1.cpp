#include <iostream>
#include <cstdlib>
using namespace std;

struct Student {
    int id;
    char name[30];
    float cgpa;
};

int main() {
    Student *s = NULL, temp;
    int n=0, ch, id, found;

    do {
        cout << "\n1.Add Student";
        cout << "\n2.Display Students";
        cout << "\n3.Linear Search";
        cout << "\n4.Binary Search";
        cout << "\n5.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch(ch) {
        case 1:
            s = (Student*)realloc(s,(n+1)*sizeof(Student));
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
            cout << "Enter ID: ";
            cin >> id;
            found=0;

            for(int i=0;i<n;i++) {
                if(s[i].id==id) {
                    cout << "Found: " << s[i].name;
                    found=1;
                    break;
                }
            }
            if(!found) cout << "Not Found";
            break;

        case 4:
            // Sort ID for Binary Search
            for(int i=0;i<n-1;i++)
                for(int j=0;j<n-i-1;j++)
                    if(s[j].id>s[j+1].id) {
                        temp=s[j];
                        s[j]=s[j+1];
                        s[j+1]=temp;
                    }

            cout << "Enter ID: ";
            cin >> id;

            {
                int low=0, high=n-1;
                found=0;

                while(low<=high) {
                    int mid=(low+high)/2;

                    if(s[mid].id==id) {
                        cout << "Found: " << s[mid].name;
                        found=1;
                        break;
                    }
                    else if(s[mid].id<id)
                        low=mid+1;
                    else
                        high=mid-1;
                }
            }
            if(!found) cout << "Not Found";
            break;
        }
    } while(ch!=5);

    free(s);
    return 0;
}