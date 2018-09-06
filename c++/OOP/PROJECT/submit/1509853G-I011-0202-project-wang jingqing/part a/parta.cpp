//1509853G-I011-0202  Wang, Jingqing

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	ifstream fin,pin;
	ofstream fout;

	fin.open("./measles.txt");
	if(fin.fail())
	{
		cout<<"Open fail.";
		exit(1);
	}

	fout.open("./result.txt");
	if(fout.fail())
	{
		cout<<"Open fail.";
		exit(1);
	}
	
	string str0;
	cout<<"please input the years keyword: ";
	cin>>str0;
	cout<<endl<<"The output will store in file result.txt"<<endl;
	string str1[10000];
	int i,n;
	n=str0.length();	

	for(i=0;fin.peek() != EOF;i++)
	{
		getline(fin,str1[i]);
		if(str1[i].substr(88,n) == str0)
		{
		fout<<str1[i]<<endl;}
		else if(str0==""||str0=="all"||str0=="ALL")
		{
		fout<<str1[i]<<endl;}
	}	


	pin.open("./result.txt");	
	if(pin.fail())
	{
		cout<<"Open fail.";
	}
	if(pin.get()==EOF)
	   cout<<"No matching options";	
	else
		cout<<"Success !";

	pin.close();
	fin.close();
	fout.close();

	return 0;
}