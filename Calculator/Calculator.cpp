#include<iostream>
#include<cmath>
#include<string>

using namespace std;

//Class-1
class Simplecalculator{
    protected:
        double num1, num2, result;
    public:
        double sum(double, double);
        double sub(double, double);
        double mul(double, double);
        double divide(double, double);
        // void display1(void){
        //     cout<<"Result: "<<result<<endl;
        // }
};
double Simplecalculator :: sum(double a, double b){
    num1=a;
    num2=b;
    result=num1 + num2;
    return result;
}
double Simplecalculator :: sub(double a, double b){
    num1=a;
    num2=b;
    result= num1 - num2;
    return result;
}
double Simplecalculator :: mul(double a, double b){
    num1=a;
    num2=b;
    result=num1 * num2; 
    return result;
}
double Simplecalculator :: divide(double a, double b){
    num1=a;
    num2=b;
    result=num1 / num2 ;
    return result;
}

//Class-2
class ScientificCalculator{
    protected:
        double num1, num2, result;
    public:
        double GetLog(double);
        double GetLn(double);
        double GetPower(double, double);
        double GetSquareRoot(double);
        // void display2(void){
        //     cout<<"Result: "<<result<<endl;
        // }
};

double ScientificCalculator :: GetLog(double a){
    num1=a;
    result=log(num1);
    return result;
}

double ScientificCalculator :: GetLn(double n){
   double num, mul, cal, sum = 0;
    num = (n - 1) / (n + 1);
    for (int i = 1; i <= 1000; i++) {
        mul = (2 * i) - 1;
        cal = pow(num, mul);
        cal = cal / mul;
        sum = sum + cal;
    }
    sum = 2 * sum;
    result=sum;
    return result;
}

double ScientificCalculator :: GetPower(double a, double b){
    num1=a;
    num2=b;
    result=pow(num1, num2);
    return result;
}
double ScientificCalculator :: GetSquareRoot(double a){
    num1=a;
    result=sqrt(num1);
    return result;
}

class HybridCalculator : public Simplecalculator, public ScientificCalculator{
    double value;
    public:
        int setdataSimpleCalculator(double, double, char);
        double setdataScientificCalculator(double, char, double);
        void display(void){
            cout<<"Result: "<<value<<endl;
        }
};
int HybridCalculator :: setdataSimpleCalculator(double a, double b, char x){
    //Simple calculator
    switch(x){
        case 'A':
        value=sum(a, b);
        break;
        
        case 'B':
        value=sub(a, b);
        break;
        
        case 'C':
        value=mul(a, b);
        break;
        
        case 'D':
        value=divide(a, b);
        break;
        
        default:
        cout<<"Invalid operation for simple calculator"<<endl;
        break;
    }
return value;
}
double HybridCalculator :: setdataScientificCalculator(double a, char x, double b=0){
    switch(x){
        case 'a':
        value= GetLog(a);
        break;
        
        case 'b':
        value= GetLn(a);
        break;
        
        case 'c':
        value= GetPower(a,b);
        break;
        
        case 'd':
        value= GetSquareRoot(a);
        break;
        
        default:
        cout<<"Invalid operation of scientific calculator"<<endl;
        break;
    }
return value;
}
int main(void) {
    cout << "***** Welcome to my Calculator *****" << endl;

    HybridCalculator hc1, hc2;
    int num1, num2;

    cout << "Enter two numbers: " << endl;
    cin >> num1 >> num2;
    cout << endl;

    cout << "Simple calculator options: " << endl
         << "Enter 'A' for addition" << endl
         << "Enter 'B' for subtraction" << endl
         << "Enter 'C' for multiplication" << endl
         << "Enter 'D' for division" << endl
         << endl;

    cout << "Scientific calculator options: " << endl
         << "Enter 'a' for Log" << endl
         << "Enter 'b' for ln" << endl
         << "Enter 'c' for power" << endl
         << "Enter 'd' for Square root" << endl
         << endl;

    cout << "Enter the preferred option: " << endl;
    
    string input;
    cin >> input;

    // Validate that only one character was entered
    if (input.length() != 1) {
        cout << "You have pressed an invalid character!!" << endl;
        return 0;
    }

    char c = input[0];  // Extract the character

    if (c >= 'A' && c <= 'Z') {
        hc1.setdataSimpleCalculator(num1, num2, c);
        hc1.display();
    } else if (c >= 'a' && c <= 'z') {
        hc2.setdataScientificCalculator(num1, c, num2);
        hc2.display();
    } else {
        cout << "You have pressed an invalid character!!" << endl;
    }

    return 0;
}
