#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

void task1(string file);
void htmlcovertor(string inputname, string outputname);

int main()
{
  //task 1
  string fileq1("d:\\lab10-q1.txt");
  cout << "Task 1: " << endl;
  task1(fileq1);

  //task 2	
  string filename("d:\\lab10-q2input.cpp");
  string outname=filename+".html";
  cout << "Task 2: " << endl;
  htmlcovertor(filename,outname);

  return 0;
}

void task1(string file){
  	int x;
	double d;
	string str;

	ifstream fin(file.c_str());

	while (!fin.eof()) {
		if (fin >> x >> d) {
			if (getline(fin, str)) {
				str.erase(0,1);
				cout << str << " " <<  x << " " << d << endl;
			}
			else
				break;
		}
		else
			break;
	}
	fin.close();

}

void htmlcovertor(string inputname, string outputname){
  char c;
  ifstream inStream;
  ofstream outStream;

  // Open the input file
  inStream.open(inputname.c_str());
  if (inStream.fail())
  {
	  cout << "I/O failure opening file." << endl;
	  exit(1);
  }

  // Create the output file
  outStream.open(outputname.c_str());

  // First, output the <PRE> tag
  outStream << "<PRE>" << endl;

  // Loop through the input file intil nothing else to get
  while (!inStream.eof())
  {
	  if (inStream.get(c)!=NULL)	// Get one character
	  {
		  // Output &lt; or &gt; or original char
		  if (c=='<')
		  {
			  outStream << "&lt;";
		  }
		  else if (c=='>')
		  {
			  outStream << "&gt;";
		  }
		  else outStream << c;
	  }
  }
  // Output end /PRE tag
  outStream << "</PRE>" << endl;

  inStream.close();
  outStream.close();
  cout << "Conversion done.  Results in file " << outputname << endl;

}
