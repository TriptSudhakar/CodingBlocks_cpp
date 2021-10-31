/*
Read n and print the below pattern for n =5 :-
    1
   232
  34543
 4567654
567898765
*/

#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int rowno=1;
	while(rowno<=n){


		//spaces print

		int col=1;
		int spaces=n-rowno;
		while(col<=spaces){
			cout<<"  ";
			col=col+1;
		}

		//nos in increasing order


		int i=1;
		int val=rowno;
		while(i<=rowno){
			cout<<val<<" ";
			i=i+1;
			val=val+1;
		}


		//nos in decreasing order
		int k=1;
		int sval=(2*rowno)-2;

		while(k<=rowno-1){
			cout<<sval<<" ";
			sval--;

			k++;
		}

		cout<<endl;

		rowno=rowno+1;
	}

	return 0;
}