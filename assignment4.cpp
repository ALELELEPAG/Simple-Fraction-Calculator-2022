
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

void fraction_operation (int a, int b, int c, int d, int &top, int &bot,int option);



int main()
{
	
	
	//declare and initialize  variables
	
	
	//call function a,b,c. function c will call function d more than once
	
	
	// display determenant
	


   // initialize the inverse if determenant NOT zero
	
	
   // call function b to display the inverse
	


	return 0;	
} 



//this function calculate  a/b option c/d = top/bot        where option is (1 = +, 2 = -, 3 = *, 4 =/)
void fraction_operation (int a, int b, int c, int d, int &top, int &bot,int option){

	if (option==1){
			// implementing a/b + c/d = (ad + bc)/ bd
			top = a*d +b*c;
			bot = b*d;
			cout<<a<<'/'<<b<<" + "<<c<<'/'<<d<<" = ";
	}
	else if(option==2){
			top = a*d - b*c;
			bot = b*d;
		    cout<<a<<'/'<<b<<" - "<<c<<'/'<<d<<" = ";
	}
	else if(option==3){
			cout<<a<<'/'<<b<<" * "<<c<<'/'<<d<<" = ";
			top = a*c;
			bot = b*d;

	}
	else if(option==4){
			cout<<a<<'/'<<b<<" / "<<c<<'/'<<d<<" = ";
			top = a*d;
			bot = b*c;

			if (bot==0){
				cout<<"\nError can not divide by zero\n\n\n";
				exit(1);
			}
	}
	//simplify fraction
	int min=top;
	if (min>bot)
		min=bot;
	for (int i= min;i>=2; i--){
		if(top%i==0 && bot%i==0){
			top/=i;
			bot/=i;
		}
	}
	//more simplifaction and print out operation result
	if(top==bot)
		cout<<1<<endl;
	else if(top==0)
		cout<<0<<endl;
	else if(bot==1)
		cout<<top<<endl;
	else{
		cout<<top<<"/"<<bot<<endl;
	}
}

