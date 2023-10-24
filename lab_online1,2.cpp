#include <iostream>
using namespace std;

int main()
{
    int id[10];
    int joiningYear[10];
    double salary[10];

    for (int i = 0; i < 10; i++) {
        cout << "Enter Employee ID: ";
        cin >> id[i];
        cout << "Enter Joining Year: ";
        cin >> joiningYear[i];
        cout << "Enter Salary: ";
        cin >> salary[i];
    }

    cout << "Employees who joined before 2009:" << endl;
    for (int i = 0; i < 10; i++) {
        if (joiningYear[i] < 2009) {
            cout << "Employee ID: " << id[i] << endl;
        }
    }

    cout << "Employees with salary > 20,000:" << endl;
    for (int i = 0; i < 10; i++) {
        if (salary[i] > 20000) {
            cout << "Employee ID: " << id[i] << endl;
        }
    }

    return 0;
}
