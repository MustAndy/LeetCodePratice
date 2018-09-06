//1509853G-I011-0202  Wang, Jingqing
//It will automatically creat the file lab11-T1.txt in the debug file folder.

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>
using namespace std;

int getFirstData(string temp);
double getSecondData(string temp1);
string getThirdData(string temp2);
int getLineNumber();

int main()
{
	ifstream fin,pin;
	ofstream fout;

    fout.open("./lab11-T1.txt");
	if(fin.fail())
	{
		cout<<"Open fail.";
		exit(1);
	}
	fout<<"1234 10.0 Steve Mark "<<endl<<
		"2345 11.0 Tai Man Chan "<<endl<<
		"8938 17.5 Keith Morrison "<<endl<<
		"4521 35.6 Mark Selby "<<endl<<
		"6169 89.9 Hon Man Wong "<<endl<<
		"7756 23.5 Chi Nin Tang "<<endl;

	fin.open("./lab11-T1.txt",ios::in|ios::out);
	if(fin.fail())
	{
		cout<<"Open fail.";
		exit(1);
	}
	
	string *str1;
	string *str2;
	int *a;
	double *b; 
	int i,j,p;
	p=getLineNumber();
	
	str1=new string[p];
    str2=new string[p];
	a=new int[p];
	b=new double[p];

	for(i=0;i<p;i++)
	{
		getline(fin,str1[i]);
		a[i]=getFirstData(str1[i]);
		b[i]=getSecondData(str1[i]);
        str2[i]=getThirdData(str1[i]);
	}	
    
	for(j=0;j<p;j++)
	{
		
		cout<<str2[j]<<a[j]<<" "<<showpoint<<setprecision(3)<<b[j]<<endl;
	}
	
	fin.close();
	for(;;){}
	return 0;
}

int getFirstData(string temp)
{
	string newtemp;
	int k; 
	k = temp.find(" ");
	newtemp=temp.substr(0,k);
	stringstream ss;
	ss<<newtemp;
	int c;
	ss>>c;
    return c;
}

double getSecondData(string temp1)
{
	string newtemp;
	int k; 
	k = temp1.find(" ");
	temp1.erase(0,k);
	k = temp1.find(" ");
	newtemp=temp1.substr(0,k);
	stringstream ss;
	ss<<temp1;
	double d;
	ss>>d;
    return d;
}

string getThirdData(string temp2)
{
	int k; 
	k = temp2.find(".");
	temp2.erase(0,k);
	k = temp2.find(" ");
	temp2.erase(0,k+1);
	return temp2;
}

int getLineNumber()
{
	char next;
	int q=0;
	
	ifstream qin;

	qin.open("./lab11-T1.txt",ios::in|ios::out);
    if(!qin.is_open())
	{
		cout<<"Open fail.";
		exit(1);
	}
    
	qin.get(next);
	q++;
	for(int i=0;qin.peek() != EOF;i++)
	{
	if(next=='\n')
	{q++;}
		qin.get(next);
	}
	
	qin.close();
	return q;
}