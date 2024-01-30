#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

enum AmortEnum{
    YR_OUT = 2,
    MN_OUT = 2,
    CUM_MN_OUT = 3,
    PAYMENT_OUT = 12,
    INTEREST_OUT = 12,
    PRINCIPAL_OUT = 12,
    BALANCE_OUT = 16

};

string AmortHeader[]{
    "Yr",
    "Mn",
    "CumMn",
    "Payment",
    "Interest",
    "Principal",
    "Balance"

};

void printAmortHeader(){
    cout<<
        endl << 
        setw(YR_OUT) << AmortHeader[0] << " " <<
        setw(MN_OUT) << AmortHeader[1] << " " <<
        setw(CUM_MN_OUT) << AmortHeader[2] << "" <<
        setw(PAYMENT_OUT) << AmortHeader[3] << "" <<
        setw(INTEREST_OUT) << AmortHeader[4] << " " <<
        setw(PRINCIPAL_OUT) << AmortHeader[5] << " " <<
        setw(BALANCE_OUT) << AmortHeader[6] << 
        endl<<
        endl;

}

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
    int year = 1;
    int switchYear = 0;
    int yearMonth = 1;
    currBalance = principal;

    while(currentLoanMonth<=monthsOfLoan){

        if(switchYear != year){
            switchYear = year;
            printAmortHeader();
        }

        currInterestPayment = currBalance*monthInterest;
        currPrincipalPayment= payment - currInterestPayment;
        currBalance = currBalance - currPrincipalPayment;

        cout<< 
            setw(YR_OUT) << year << " " <<
            setw(MN_OUT) << yearMonth << " " <<
            setw(CUM_MN_OUT) << currentLoanMonth << " " <<
            setw(PAYMENT_OUT) << payment << " " <<
            setw(INTEREST_OUT) << currInterestPayment << " " <<
            setw(PRINCIPAL_OUT) << currPrincipalPayment << " " <<
            setw(BALANCE_OUT) << abs(currBalance) << endl;

        yearMonth++;

        if(yearMonth>12){
            yearMonth = 1;
            year++;
        }

        currentLoanMonth++;

    }

    cout << endl <<
     "loan payments complete" <<
      endl <<
      endl;

    return 0;
}