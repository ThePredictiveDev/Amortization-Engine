#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int main(){

    const int MONTHS_IN_YEAR = 12;
    const int percentDenominator = 100;

    double principal = 0.0;
    cout<<"Enter The principal amount: "<<endl;
    cin>>principal;

    double humanInterest = 0.0;
    cout<<"Enter The interest rate: "<<endl;
    cin>>humanInterest;
    double interest = humanInterest/percentDenominator;

    int yearsOfLoan = 0;
    cout<<"Enter The years of loan: "<<endl;
    cin>>yearsOfLoan;

    double monthInterest = interest/MONTHS_IN_YEAR;
    long monthsOfLoan = yearsOfLoan*MONTHS_IN_YEAR;

    double payment = 0.0;
    payment = principal*(monthInterest/(1-(pow((double)1+monthInterest, (double)-monthsOfLoan))));
    cout << "Payment: "<< setiosflags(ios::fixed) << setprecision(2) << payment << endl;

    double currInterestPayment = 0.0;
    double currPrincipalPayment = 0.0;
    double currBalance = 0.0;
    long currentLoanMonth = 1;

    currBalance = principal;

    while(currentLoanMonth<=monthsOfLoan){
        currInterestPayment = currBalance*monthInterest;
        currPrincipalPayment= payment - currInterestPayment;
        currBalance = currBalance - currPrincipalPayment;

        cout<< "CM: " << currentLoanMonth << " CI:  "<< currInterestPayment << " CP: " << currPrincipalPayment << " Bal: " << currBalance<< endl;

        currentLoanMonth++;

    }

    cout << "loan payments complete" << endl;

    return 0;
}