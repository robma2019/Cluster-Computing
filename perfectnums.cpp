#include<iostream>
using namespace std;

void PerfectNums(int n);

int main(){
	int end;
	//cout << "Enter the starting number" << endl;
	//cin >> start;
	
	cout << "Enter the upper bound" << endl;
	cin >> end;
	
	PerfectNums(end);

	return 0;
}

void PerfectNums(int n){
	int start=0;
	for(int i=start; i<=n; i++){
		int last_divisor=i/2;
		//divisors of any number cannot be greater than half of  a  number but 1 is the only exception
		if(i==1){
			last_divisor=1;// otherwise last_divisor variable would have become 0 (1/2)
		} 
		
		int sum=0;
		
		for(int  j=1; j<=last_divisor; j++ ){
			if(i%j==0){
				sum+=j;
			}
		}//inner for loop
		
		if(sum==i){
			cout << i << endl;
		}
			
	}//outer for loop
}
