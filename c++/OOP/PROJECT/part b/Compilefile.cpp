//1509853G-I011-0202 Wang, Jingqing
#include"CompileFile.h"

/*
    This function is to asked user to input the name of file.

    After user input the file name, it will add the relative path 
	to the file name. Then,it will call the open_file()
    function to open the file.
*/

void CompileFile::get_the_file_name()
{
	usetime =0;
	string newname;
	cout<<"please input the file name: ";
	cin>>newname;
	
    clock_t start_time=clock();
	{
	strname="./"+newname;//"../Debug\\"+newname;
    open_file();
    }
	clock_t end_time=clock();
	usetime+=static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000;
}

/*
    This function is used to open the file.
    It use the ifstream as reference, and it
	will return the ifstream fin after open
	the file that user input.

*/

ifstream & CompileFile::open_file()
{
	clock_t start_time=clock();
	{
	fin.open(strname.c_str(),ios::in|ios::out);
    }
	clock_t end_time=clock();
    usetime+=static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000;
	return fin;
}

/*
    This function is to check the file that user input if 
	exist and correct. In the main function, it was used to
	control the loop.
	If the file doesn't exist, it will asked user to input 
	again until user input the correct file name.
	
	The return type is boolean.
*/

bool CompileFile::checkFile()
{
	
	if(!fin.is_open())
	{
		cout<<"open file unsuccessful,please input the correct file name"<<endl;
	    fin.close();
	    return false;
	}
	else
	{return true;}
}

/*
    This function is to creat the result_file
	for the search years part.

*/

void CompileFile::creat_result_file()
{
	clock_t start_time=clock();
	{
	fout.open("./result.txt");
	fout.close();
    }
	clock_t end_time=clock();
    usetime+=static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000;
}

/*
    This function use ofstream to creat or write
	the result into the file named result.txt.
	In the middle, it use seekg function to locate 
	the pointer of ifstream.
	Then, it use string array to store every line of
	the file measles.txt. At the same time, it will 
	check the specific substring in every element of
	string array to select the line that meet the user
	search condition.

*/

void CompileFile::get_the_years()
{
	
	
	cout<<"please input the year: ";
	cin>>stryears;
    clock_t start_time=clock();
	{
		
		
		fout.open("./result.txt",ios::in|ios::out);
	if(!fout.is_open())
	{
		cout<<"Open fail.";
		exit(1);
	}
		n=stryears.length();

	fin.seekg(0,ios::beg);

	for(i=0;fin.peek() != EOF;i++)
	{   
		getline(fin,str1[i]);
		if(str1[i].substr(88,n) == stryears)
		{
		fout<<str1[i]<<endl;}
		else if(stryears==""||stryears=="all"||stryears=="ALL")
		{
		fout<<str1[i]<<endl;}
	}	
	
	fin.close();
	fout.flush();
	fout.close();

    }
	clock_t end_time=clock();
    usetime+=static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000;
}

/*
    This function is to check if the user
	input the correct years' search condition.
	Whatever user inputted, the get_the_years() function
	will search in the file measles.txt, but if 
	the user input incorrect years, the resule file
	will be empty. This checkYear function control the loop
	in the main.

	It returns boolean type.
*/

bool CompileFile::checkYear()
{
	pin.open("./result.txt",ios::in|ios::out);	
	if(!pin.is_open())
	{
		cout<<"Open fail.";
	}
	if(pin.get()==EOF)
	{
	cout<<"No matching options,please input again."<<endl;
	fin.open(strname.c_str(),ios::in|ios::out);
	pin.clear();
	pin.close();
	return false;
	}
	else return true;

}

/*
    This function is to asked user to input
	the income level he want to search. It will
	show that which number corresponds to which level.

	After it gets the input from user, it will use ifstream
	to open resule.txt to search the condition that meets
	user's input. Then, using ofstream to output the resule
	to another file named finalresult.txt.

	At last, it will call process_file() function.

*/

void CompileFile::income_level()
{
	
    int p;
	number_of_result=0;
	incomeLevel="0"	;
	while(incomeLevel=="0")
	{
		cout<<"please input the income level you want to find : "
			<<endl<<"1 stand for low-income"
			<<endl<<"2 stand for lower-middle-income"
			<<endl<<"3 stand for upper-middle-income"
			<<endl<<"4 stand for high-income"
			<<endl<<"5 stand for All."
			<<endl;

	cin>>p;
	switch(p)
	{	
	case 1:
		{incomeLevel="WB_LI";break;}
	case 2:
		{incomeLevel="WB_LMI";break;}
	case 3:
		{incomeLevel="WB_UMI";break;}
	case 4:
		{incomeLevel="WB_HI";break;}
	case 5:
        {incomeLevel="ALL";break;}
    default:
		cout<<"please input the correct income level."<<endl;
	}
	}
clock_t start_time=clock();
	{
    pin.close();
	pin.open("./result.txt");
	if(!pin.is_open())
	{
		cout<<"Open fail.";
		exit(1);
	}

	fout.open("./finalresult.txt");
	if(!fout.is_open())
	{
		cout<<"Open fail.";
		exit(1);
	}
	
    n=incomeLevel.length();
	pin.seekg(0,ios::beg);
	for(i=0;pin.peek() != EOF;i++)
	{
		getline(pin,str1[i]);
		if(str1[i].substr(51,n) == incomeLevel)
		{
		fout<<str1[i]<<endl;
		number_of_result++;
		}
		if(incomeLevel=="ALL")
		{
		fout<<str1[i]<<endl;
		number_of_result++;
		}
	}	
	fout.flush();
	fout.close();
	fin.open("./finalresult.txt");
	process_file(fin);
	
	}
 	clock_t end_time=clock();
    usetime+=static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000;
}

/*
    This process_file function is to process the
	data that selected by the user search condition input.
	It will extract the substring that stand for percent vaccinated
	and store in the file named percent.txt.

	At the same time, it transform the char to the int as 
	well as store in the int array, and caculate the sum 
	,average of the percent.

	After all above, it call Find_max_min() function.

*/

void CompileFile::process_file(ifstream&fin)
{
	sum=0;
	Percent_Vaccinated=new int[number_of_result];
	fout.open("./percent.txt");
	if(!fout.is_open())
	{
		cout<<"Open fail.";
		exit(1);
	}
	fin.seekg(0,ios::beg);
	for(i=0;fin.peek() != EOF;i++)
	{
		getline(fin,str1[i]);

		fout<<str1[i].substr(59,2)<<endl;
		Percent_Vaccinated[i]=atoi(str1[i].substr(59,3).c_str());
		sum+=Percent_Vaccinated[i];
	}
	fin.close();
	average=sum/i;
	Find_max_min();

}

/*
    This function is to find the maximum and the minimum 
	of percent in the finalresult.txt. It use the int 
	array to compara the number of percent, then out put
	the whole line of that number.

*/

void CompileFile::Find_max_min()
{    
	m=k=0;
    min=Percent_Vaccinated[0];
	max=Percent_Vaccinated[0];

 	for(i=1;i<number_of_result;i++)
	{
		if(max<Percent_Vaccinated[i])
		{max=Percent_Vaccinated[i];
		}

		if(min>Percent_Vaccinated[i])
		{min=Percent_Vaccinated[i];
		}
	}

	stringstream ss;
    
    string maxS,minS;
    ss<<max;
    ss>>maxS;

	stringstream ssr;
	ssr<<min;
	ssr>>minS;

	fin.open("./finalresult.txt");
	if(!fin.is_open())
	{
		cout<<"Open fail.";
		exit(1);
	}
	fin.seekg(0,ios::beg);

	for(i=0;fin.peek() != EOF;i++)
	{
		getline(fin,str1[i]);
		if(str1[i].substr(59,maxS.length()) == maxS)
			{maxC[m]=str1[i];m++;}
		if(str1[i].substr(59,minS.length()) == minS)
		{minC[k]=str1[i];k++;}
		if(str1[i].substr(59,minS.length()) == " "&&str1[i].substr(60,minS.length()) == minS)
		{minC[k]=str1[i];k++;}
	}
	

}

/*
   This function is to calculate the amount of the line
   in the file measles.txt. Then redefine the Dynamic string
   array.
*/
void CompileFile::linenumber ()
{
	clock_t start_time=clock();
	{
	char next;
	int q=0;
	
	qin.open(strname.c_str(),ios::in|ios::out);
    if(!qin.is_open())
	{
		cout<<"Open fail.";
		exit(1);
	}
    
	qin.get(next);
	q++;
	for(i=0;qin.peek() != EOF;i++)
	{
	if(next=='\n')
	{q++;}
		
       qin.get(next);
	}
	linenumbers=q;
	str1=new string[linenumbers];
    maxC=new string[linenumbers];
    minC=new string[linenumbers];

	qin.clear ();
	qin.close();
	
	}
	clock_t end_time=clock();
    usetime+=static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000;
}
/*
    This function is to show the result of
	the searching.
*/

void CompileFile::showreport()
{
	clock_t start_time=clock();
	{
	cout<<"There are "<<number_of_result<<" files that match your criteria. "<<endl<<endl;
	cout<<"The average percentage for those record is "<<average<<endl;
	cout<<endl<<"The country with the lowest percentage is/are: "<<endl;
	for(i=0;i<k;i++){ cout<<minC[i]<<endl;}
	cout<<endl<<"The country with the highest percentage is/are: "<<endl;
	for(i=0;i<m;i++) {cout<<maxC[i]<<endl;}
    }
	clock_t end_time=clock();
    usetime+=static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000;
	cout<<endl<<"The time for searching is :"<<usetime<<endl;
}