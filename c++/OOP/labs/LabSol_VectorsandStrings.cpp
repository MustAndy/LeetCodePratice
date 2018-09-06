//
//  main.cpp
//  lab08
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void task1();
void task2();
string trim(string str);
void Calc_GPA();

// Please do not modify the given code in main()
int main()
{
    int number;


    while(true)
    {
        cout << "Please enter a number (1-2) for the tasks (0 to quit):";
        cin >> number;
        
        if ( cin.fail() && !cin.eof() ) {
            cout << "Please input an integer.\n";
            break;  // Skip reading immediately
        }
        
        if(number == 0)
        {
            cout << "Mission completed!" << endl;
            break;
        }
        
        if(number==1)
            task1();
         else if(number==2)
             task2();
         else cout <<"Invalid number, please input again.\n";
        
    }
    
    return 0;
}

// Please do not modify the given code in task1()
void task1()
{
    //task1
    const int MAX_LEN = 1000;
    char buf[MAX_LEN + 1];
    
    cout << "Task1: Trimming whitespaces" << endl;
    cout << "Input your string:" << endl;
    
    cin.clear();
    cin.ignore();
    cin.getline(buf, MAX_LEN);
    
    string str1(buf);
    
    cout << "Before trimming: \"" << str1 << "\"" << endl; // before trimming
    
    cout << "After trimming: \"" << trim(str1)<< "\"" << endl; //after trimming
}

//Please complete your code here
string  trim(string str) {
	int i=0,j=(int)str.length(),x=0;


	for(i=0;i<str.length();i++)
	{   

		if(str[i]!=' ')

			break;
	}
	for(x=j-1;x>0;x--)
	{   

		if(str[x]!=' ')

			break;

	}
	str=str.substr(i,x);
	return str;
}



 // Please do not modify the given code in task2()
 void task2()
 {
 //task2
 cout << "Task 2: GPA Calculator" << endl;
  cout<<"How many courses that you have taken:   ";
     Calc_GPA();

 }
 
 //Please complete your code here
 void Calc_GPA(){
     vector<double> g;
     vector<int> c;
     int n,enterc;
     double gpa=0.0,sum=0.0,GPA=0.0;
     string enterg;
     cin>>n;
     for(int i=1;i<=n;i++){
         cout<<"please input the grade and the credit for course  "<<i<<": "<<endl;
         cin>>enterg>>enterc;
         c.push_back(enterc);
         if(enterg=="A+")g.push_back(4.0);
         if(enterg=="A")g.push_back(3.7);
         if(enterg=="A-")g.push_back(3.3);
         if(enterg=="B+")g.push_back(3.0);
         if(enterg=="B")g.push_back(2.7);
         if(enterg=="B-")g.push_back(2.3);
         if(enterg=="C+")g.push_back(2.0);
         if(enterg=="C")g.push_back(1.7);
         if(enterg=="C-")g.push_back(1.3);
         if(enterg=="D")g.push_back(1.0);
         if(enterg=="F")g.push_back(0.0);
         if(enterg=="O")g.push_back(0.0);
         
         
     }
     for(int i=0;i<n;i++){
     gpa=gpa+g[i]*c[i];
     sum=sum+c[i];
     GPA=gpa/sum;
     }
     cout<<"\n Your total GPA of the above "<<n<<" courses is:"<<GPA<<endl;
     
     
 }
