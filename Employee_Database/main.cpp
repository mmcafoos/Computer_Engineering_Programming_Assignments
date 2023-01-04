#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    
    vector<string> Name;
    vector<string> Title;
    vector<double> Wage;
    int userNum;
    string userString;
    
    cout << "Welcome to the Employee Database" << endl;
    do{
    cout << "1. Print List of Employees" << endl;
    cout << "2. Calculate Total Wages" << endl;
    cout << "3. Add New Employee" << endl;
    cout << "4. Exit Application" << endl;
    cout << "Please select your option by entering the corresponding number: ";
    
    cin >> userString;
    
    userNum = atoi(userString.c_str());
    while(userNum < 1 || userNum > 4){
        cout << "Invalid input!" << endl;
        cout << "Please select your option by entering the corresponding number: ";
        cin >> userString;
        userNum = atoi(userString.c_str());
    }
    
    if(userNum == 1){
        // Print List of Employees
        for(int i = 0; i < Name.size(); i++){
            cout << "Employee Number: " << i+1 << endl;
            cout << "Employee Name: " << Name.at(i) << endl;
            cout << "Employee Title: " << Title.at(i) << endl;
            cout << "Employee Hourly: " << Wage.at(i) << endl;
        }
    }
    if(userNum == 2){
        //Calculate Total Wages
        double grandWage = 0;
        double hoursWorked;
        double tempHours;
        double tempTotal;
        for (int i = 0; i < Name.size(); i++){
            
            cout << "Please enter the hours worked for: " << Name.at(i) << endl;
            cin >> tempHours;
            while(!cin || tempHours < 0){
                cout << "Please enter a valid hours worked: ";
                cin.clear();
                cin.ignore();
                cin >> tempHours;
            }
            
            tempTotal = tempHours * Wage.at(i);
            grandWage = grandWage + tempTotal;
        }
        cout << "Total Wage for All Employees: " << grandWage << endl;
    }
    if(userNum == 3){
       //Add New Employee
       cout << "Please Enter Employee Name: ";
       string tempName;
       cin.ignore();
       getline(std::cin, tempName);
       Name.push_back(tempName);
       cout << "Please Enter Employee Title: ";
       string tempTitle;
       getline(std::cin, tempTitle);
       Title.push_back(tempTitle);
       cout << "Please Enter Employee Hourly Rate: ";
       double tempWage;
       cin >> tempWage;
       while(!cin || tempWage < 0){
          cout << "Please enter a valid wage: ";
          cin.clear();
          cin.ignore();
          cin >> tempWage;
       }
       Wage.push_back(tempWage);
    }
    }while(userNum != 4);
    cout << "Goodbye!" << endl;
    
    return 0;
    
}
