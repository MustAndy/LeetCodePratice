//1509853G-I011-0202   Lab4  Wang jingqing
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include <iomanip>
using namespace std;


class Account
{
public:  //Constructor
     Account()
   {
	balance = interestRate = 0.0; term = 0;
   } 
     Account(double b, double r, int t); 
 
 //Accessor 
	double getBalance()
   {
	return balance;
   } 

	double getInterestRate()
   { 
	return interestRate;
   } 

	double getTerm()
   { 
	return term;
   }  

 //Mutator
	void Deposit(); //save money
	void WithDraw();//get money
	void AdjustRate(); //tiao  zheng hui lv
	void SetTerm(); // she zhi nian fen
	void CalBalanceMaturity();  //dao  qi  zong e
    void output();
	void TodayRate();
private: 
	double balance;
	double balanceMaturity;
	double interestRate;
	double term; 
}; 

int main()
{   
	while(1){
	char a;
    string b;
	cout<<"Please input your name:";
	cin>>b;
	Account Guest(10000,3,18);
	Guest.TodayRate();
	cout<<"-----Operations on "<<b<<"'s Account----- "<<endl;
	cout<<"The balance of your account is as follow: "<<endl;
	Guest.output();	
	cout<<"Do you need to save money?(Y/N)"<<endl;
	cin>>a;
	if(a=='Y')
	Guest.Deposit();	
	cout<<"Do you need to take out money?(Y/N)"<<endl;
	cin>>a;
	if(a=='Y')
	Guest.WithDraw();
	cout<<"Do you need to Reset the term?(Y/N)"<<endl;
	cin>>a;
	if(a=='Y')
    Guest.SetTerm();

	cout<<"The newest balance of your account is as follow: "<<endl;
	Guest.output();

    cout<<"-----End of Operations on "<<b<<"'s Account-----"<<endl; 
	
	cout<<"Do you want to exit?(Y/N)"<<endl;
	cin>>a;
	if(a=='Y')
    break;
	}
	return 0;
}

Account::Account(double b, double r, int t)
{
	balance=b;
	interestRate=r;
	term=t;
}
void Account::output()
{
	cout<<"Your account has MOP "<<balance<<endl;
	
	cout<<"The current interest rate is "<<interestRate<<endl;

	cout<<"The deposit term is "<<term<<endl;

	cout<<"After the term of "<<term<<" month"<<endl;
	CalBalanceMaturity();
    cout<<"Your account will have a balance (Maturity) of MOP "<<balanceMaturity<<endl<<endl;

}
void Account::Deposit()
{   double amount;
	cout<<"Please input the money you want to save: ";
	cin>>amount;
	balance+=amount;
	cout<<"You have saved "<<amount<<"MOP"<<endl;
	cout<<"Now your balance is"<<balance<<"MOP"<<endl<<endl;
}

void Account::WithDraw()
{   double amount;
	while(1)
	{
		cout<<"Please input the money you want to withdraw: ";
	    cin>>amount;
	if(amount<balance)
	  {
		balance-=amount;
		cout<<"Now your balance is"<<balance<<"MOP"<<endl<<endl;
		break;
	   }
	else 
	  {
		cout<<"Sorry, your balance is running low, please input again"<<endl;
		continue;
	   }
	}
	
}

void Account::SetTerm()
{
    double newTerm;
		while(1)
		{
			cout<<"Please input the Term you want to apply(in month); ";
	        cin>>newTerm;

	if(newTerm<1)
	{
		cout<<"Sorry, the term should be at lease one month, please input again"<<endl;
		continue;}
	else 
	{
		term=newTerm;
		break;
	     }
	}
}

void Account::CalBalanceMaturity()
{
	balanceMaturity=balance+balance*(interestRate/100)*(term/12);
} 

void Account::AdjustRate()
{
    if(balance<5000)
		interestRate=2;
	else if (interestRate=5000)
        interestRate=2.5;
	else if ((interestRate>5000)&&(interestRate<10000))
	    interestRate=2.5;	
	else if(interestRate=10000)
		interestRate=3;
	else if((interestRate>10000)&&(interestRate<15000))
		interestRate=3;	
	else if(interestRate=15000)
		interestRate=3.5;
	else if((interestRate>15000)&&(interestRate<20000))
		interestRate=3.5;	
    else if(interestRate=20000)
		interestRate=5;
	else if(balance>20000)
        interestRate=5;
}

void Account::TodayRate()
{
	cout<<"Today's rates are as follow : "<<endl;
	cout<<"Balance<5000:"<<setw(13)<<"2%"<<endl;
	cout<<"5000<=Balance<10000:"<<setw(7)<<"2.5%"<<endl;
	cout<<"10000<=Balance<15000:"<<setw(5)<<"3%"<<endl;
    cout<<"15000<=Balance<20000:"<<setw(6)<<"3.5%"<<endl;
	cout<<"20000<=Balance:"<<setw(11)<<"5%"<<endl<<endl;
}

