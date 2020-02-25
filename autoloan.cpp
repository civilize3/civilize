#include <iostream>
using namespace std;

class AutoLoan{
public:
    double interestRate(double price, double monthlyPayment, int loanTerm);
};

double AutoLoan::interestRate(double price, double monthlyPayment, int loanTerm) {
    double interest;
    double marginMax = 100.0;
    double marginMin = 0.0;
    double priceLeft = 100.0;
    
    while (-0.0001 > priceLeft || priceLeft > 0.0001) {
        priceLeft = price;
        interest = (marginMax + marginMin) / 2;
        for (int i = 0 ; i < loanTerm ; i++)
            priceLeft = priceLeft * (100 + interest / 12) / 100 - monthlyPayment;
        
        if (priceLeft < 0) marginMin = (marginMax + marginMin) / 2;
        else marginMax = (marginMax + marginMin) / 2;
    }
    return interest;
}
