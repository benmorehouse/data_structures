#include <iostream>

int main(){
	int count = 0;
	int a[1000][1000];	

	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			a[i][j] =0;
		}
	}

	int n =0;
	std::cin>>n;	
	
	for (int i=1;i<n;i*=2){
		count++;
		for (int j=0;j<i;j++){
			count++;
			a[i][j]= i*j;
		}
	}

	std::cout<<count<<std::endl;
}
