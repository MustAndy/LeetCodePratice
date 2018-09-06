//1509853G-I011-0202  Wang, Jingqing
//It will automatically creat the file t2_input1.cpp in the debug file folder.

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
	ifstream fin,pin;
	ofstream fout;
    string inputname;

	cout<<"Task2: Html Convertor"<<endl;

    fout.open("./t2_input1.cpp");
	if(!fout.is_open())
	{
		cout<<"Open fail.";
		exit(1);
	}
 
	fout<<"#include <iostream>"<<endl<<
		"using namespace std;"<<endl<<
		"int funtion() "<<endl<<endl<<
		"{"<<endl<<
		"    int x=4; "<<endl<<
		"    if (x < 3)"<<endl<<
		"    x++;"<<endl<<
		"    cout << x << endl; "<<endl<<
		"    return 0;"<<endl<<
		"}"<<endl;

	
	fout.close();

	while(1)
	{
	cout<<"please input the file name:";
	getline(cin,inputname);

	fin.open(inputname.c_str(),ios::in|ios::out);
	if(!fin.is_open())
	 {
		cout<<"I/O failure opening file,please input again."<<endl;
		fin.close();
	 }
	else break;
		}
	cout<<"Task2: "<<endl<<"Conversion done.  Results in file t2_input1.cpp.html"<<endl;
	fout.open("./t2_input1.cpp.html ");
		if(!fout.is_open())
	  {
		cout<<"Open fail.";
		exit(1);
	  }

	char next;
	
	fout<<"<PRE>"<<endl;
	fin.seekg(0,ios::beg);
    
	while(fin.peek() != EOF)
	{
		fin.get(next);
		if(next=='<')
			fout<<"&lt;";
		else if(next=='>')
			fout<<"&gt;";
		else
			fout<<next;		
	}

    fout<<"<PRE>"<<endl;
	
	fin.close();
	fout.close();
	for(;;){}
	return 0;
}
