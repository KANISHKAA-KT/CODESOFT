#include <iostream>
#include <vector>
#include<string.h>
#include <cmath>
using namespace std;
class Calculator{
    private:
      double operand1;
      double operand2;
      char operation;
      vector<string>history;
      
    public:
    
    Calculator(){//defaultconstructor
        operand1=0;
        operand2=0;
        operation='+';
    }
      
   void getValues(bool usePreviousResult, double previousResult) {//get the values
    if (usePreviousResult) {
        operand1 = previousResult;
        cout << "Using previous result as Operand 1: " << operand1 << endl;
    } else {
        cout << "Enter operand 1: ";
        cin >> operand1;
    }
    cout << "Enter operand 2: ";
    cin >> operand2;
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
}
      
     ~Calculator(){// destructor
         cout<<"\n"<<"your memory is destroyed"<<endl;;
     }
     double performOperation(){//arithmetic operation
         double result;
         switch(operation){
             case '+':{
              return operand1+operand2;
              break;}
            case '-':
             {return operand1-operand2;
             break;}
            case'*':
            {
             return operand1*operand2;
             break;
             }
             case '/':
              {
                  if(operand2!=0){
                  return operand1/operand2;
              }
              else{
                 cerr << "Error! Division by zero is undefined." << endl;
                  return NAN;
              }}
             default:{
               cerr<<"Invalid Operation"<<endl;;
               return NAN;}
         }
         savetoHistory(result);
         return result;
     }
     void savetoHistory(double result){//to save previous record to the history
         string record=to_string(operand1)+" "+to_string(operand2)+ "="+ to_string(result);
         history.push_back(record);
     }
      void displayHistory() {//to display the History
        for (const string& record : history) {
            cout << record << endl;
        }
}
};

int main() {
    Calculator c1;
    char choice;
    double previousResult = 0;
    bool usePreviousResult = false;

    do {
        c1.getValues(usePreviousResult, previousResult);
        double result = c1.performOperation();
        if (result) {
            cout << "Result: " << result << endl;
            previousResult = result;
            usePreviousResult = true;
        } else {
            usePreviousResult = false;
        }

        cout << "\nDo you want to perform? (y/n): ";
        cin >> choice;
       
    } while (choice == 'y' || choice == 'Y');
    return 0;
}