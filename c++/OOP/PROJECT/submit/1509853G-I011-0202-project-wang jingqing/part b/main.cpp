//1509853G-I011-0202 Wang, Jingqing
#include"CompileFile.h"

int main()
{
	
	while(1)
	{
		
	CompileFile newfile;

	/*
	This do...while loop is to let user input the file name, and 
	open the file which was put in the folder of the project.
	After user input, the function checkFile will check if the file
	exist.
	*/

	do {
		newfile.get_the_file_name();
		
	}while(newfile.checkFile()==false);

	newfile.creat_result_file();//creat a middle transit file

    /*
	This function is to calculate the line in opening file
	*/

	newfile.linenumber();

	/*
	This do...while loop is to let user input the years he
	wants to search. The function checkYear is to check if the 
	user input the correct years.
	*/
    
	do{
		newfile.get_the_years();
		
	}
	while(newfile.checkYear()==false);
    
	/*
    This income_level function is to let user input the income
	level he want to search. There are a switch loop in function
	to check if user input correct income level.
	*/

	newfile.income_level();

    /*
	This showreport function is to show the result of the search.
	*/

	newfile.showreport();
		
	/*
	This is the exit controller.
	*/

	int u;
    cout<<"Press 1 to continue for searching, Press 2 to exit..."<<endl;
		cin>>u;
	if(u==1)continue;
	else if (u==2)break;
	}

 	return 0;
}
