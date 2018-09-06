#include <iostream>
#include <string>
using namespace std;

// Here are the function prototypes
int StringtoInt(string & s);
void tokenize(string &str, string &sub);

// Please do not modify the given code in task1()
void task1()
{
    //task1
	string str_hex;

	cout << "Task1: hexadecimal number conversion" << endl;
	cout << "Please input your hexadecimal number (in a string):" << endl;

	cin.clear();
	cin.ignore(); 
	getline(cin,str_hex);
 
	cout << "The decimal number of \"" <<str_hex << "\" is " << StringtoInt(str_hex) << endl;     
	
}

// Please do not modify the given code in task2()
void task2()
{
    //task1
	const int MAX_LEN = 1000;
	char buf[MAX_LEN + 1];
	string token;
	
	cout << "Task2: Tokenizing strings" << endl;
	cout << "Please input your string going to be tokenized:" << endl;

	cin.clear();
	cin.ignore(); 
	cin.getline(buf, MAX_LEN);

  	string str1(buf);

	cout << "Please input your token (a string)" << endl;
    cin >> token;


	cout << "The original string: \"" << str1 << "\"" << endl; // before tokenizing
    cout << "After tokenizing" << endl; //after tokenizing

	tokenize(str1,token);
}

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


void tokenize(string &str, string &sub){

  string tmp;
  int i=1;
  int len;
  
  len = sub.length();
  string::size_type loc = 0;
    
  while(loc!= string::npos ){
	  loc = str.find(sub,0);
      tmp = str.substr(0,loc);
	  cout << "No. " << i << " : " << tmp << endl; 
        
      str.erase(0,loc+len);
	  i++;
  }
}

int StringtoInt(string & s) {

    int tmp = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
      if (s[i] >= '0' && s[i] <= '9')
        tmp = tmp * 16 + (s[i] - '0');
      else
        tmp = tmp * 16 + (s[i] - 'A' + 10);
    }
    return tmp;
}

