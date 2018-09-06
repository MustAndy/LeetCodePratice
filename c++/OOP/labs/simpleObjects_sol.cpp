#include < iostream >
using namespace std;
 
class Account {
    public :
    //Constructor
    Account() {
        balance = interestRate = 0.0;
        term = 0;
    }
    Account(double b, double r, int t);
 
    //Accessor
    double getBalance() {
        return balance;
    }
    double getInterestRate() {
        return interestRate;
    }
    int getTerm() {
        return term;
    }
 
    //Mutator
    void Deposit(double amount);
    int WithDraw(double amount);
    void AdjustRate(double newRate);
    void SetTerm(int newTerm);
    void CalBalanceMaturity();
 
    private :
    double balance;
    double balanceMaturity;
    double interestRate;
    int term;
};
 
Account::Account(double b, double r, int t) {
    balance = b;
    interestRate = r;
    term = t;
}
 
void PrintAccount(Account & account) {
    cout << "Your account has MOP " << account.getBalance() << endl;
    cout << "The current interest rate is " << account.getInterestRate() << endl;
    cout << "The deposite term is " << account.getTerm() << endl;
}
 
void Account::Deposit(double amount) {
    balance += amount;
}
 
int Account::WithDraw(double amount) {
    if (amount > balance) {
        cout << "Not enough money in your account" << endl;
        return -1;
    } else {
        balance -= amount;
        return 0;
    }
}
 
void Account::AdjustRate(double newRate) {
    interestRate = newRate;
}
 
void Account::SetTerm(int newTerm) {
    term = newTerm;
}
 
void Account::CalBalanceMaturity() {
    double rateFraction = interestRate / 100.0;
    double interest;
 
    interest = balance * (rateFraction * (term / 12.0));
    balanceMaturity = balance + interest;
 
    cout << "After the term of " << term << " months" << endl;
    cout << "Your account will have a balance (Maturity) of MOP " << balanceMaturity << endl;
}
 
int main() {
    Account HenryAcc;
    Account RaymondAcc(10000, 3, 18);
 
    cout << "-----Operations on Henry's Account-----" << endl;
    PrintAccount(HenryAcc);
    HenryAcc.CalBalanceMaturity();
    HenryAcc.Deposit(5000);
    HenryAcc.AdjustRate(1.5);
    HenryAcc.SetTerm(6);
    PrintAccount(HenryAcc);
    HenryAcc.CalBalanceMaturity();
    cout << "-----End of Operations on Henry's Account-----" << endl;
 
    cout << endl;
 
    cout << "-----Operations on Raymond's Account-----" << endl;
    PrintAccount(RaymondAcc);
    RaymondAcc.CalBalanceMaturity();
    RaymondAcc.WithDraw(2000);
    PrintAccount(RaymondAcc);
    RaymondAcc.CalBalanceMaturity();
    cout << "-----End of Operations on Raymond's Account-----" << endl;
 
    return 0;
}