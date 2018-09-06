//1509853G-I011-0202 Wang, Jingqing
#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<sstream>
#include<time.h>
using namespace std;

class CompileFile{
		
public:
	CompileFile(){}
	
	void get_the_file_name();
	void get_the_years();
	void showreport();
	void income_level();	
    void process_file(ifstream&fin);
	void creat_result_file();
	void Find_max_min();
    void linenumber ();

    ifstream& open_file();

	bool checkFile();
	bool checkYear();

private :
	string strname;
	string stryears;
	string *str1;
	string incomeLevel;
	string *maxC;
	string *minC;
	int i,number_of_result,n,m,k,sum,min,max,linenumbers;
	int *Percent_Vaccinated; 

	double average,usetime;
	
	ifstream pin;
	ofstream pout;
	ifstream fin;
	ofstream fout;
	ifstream qin;
};