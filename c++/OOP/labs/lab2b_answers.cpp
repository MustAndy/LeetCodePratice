
#include<iostream>
#include<stdio.h>
#include<time.h>
#define random(x) (rand()%x)
using namespace std;

int boolean(int i[],int j[], int k){
	int b=0;int c=0;
	
	for(int t=0 ;t<k; t++){
		
		if(i[t]==j[t])c++;}
			
		for(int t=0 ;t<k; t++){
		for(int l=0 ;l<k; l++){
			if(i[t]==j[l]){b++;j[l]=0;break;}
			
			

		}
	}
cout<<"You guess "<<b<<" digit(s) right."<<endl;
for(int i=0;i<c;i++)cout<<"R";

cout<<endl;
if(c==3)return c;
else return 0;


	}
int main(){
	cout<< "Guess Number Game "<< endl;
	cout<< "Enter three digits (1 - 7) separated by a space\n-----------------------------------------------"<<endl;
	int a[4];
	srand((unsigned)time(NULL));
	for(int i=0;i<3;i++){
	 a[i]= ((int)rand()%(7-1) )+ 1;
	}
	a[0]=4; a[1]=4; a[2]=2;
	int b[4];
	
while(1){int u= 0;int z=0;int o=1;
char c;cout<<"Round "<<o<<" Enter Guess:";
while((c=getchar())!='\n'){
if(c>='0'&&c<='9')
{
ungetc(c,stdin);
cin>>b[u++];
}
}
z=boolean(a,b,3);
if(z==3){cout<<"Congratulations! You win in step "<<o;break;}
o++;


}
	return 0;
}


