/*
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <stack>

bool parenthesized(std::string input){
	std::stack<char> mystack;
	std::string::iterator strItr;
	int par = 0;	
	for(strItr = input.begin(); strItr != input.end(); ++strItr){
		if(*strItr == '('){
			par++;
		}else if(*strItr == ')'){
			par--;
		}	
	}

	if (par == 0){
		return true;
	}
	return false;
}

int main(){
	std::map<int, int> gquiz1; 
	for (int i = 0; i < 10; i++){
		gquiz1.insert(std::pair<int, int>(i, i*10)); 
	}
	std::map<int, int>::iterator itr;

	for(itr = gquiz1.begin(); itr != gquiz1.end(); ++itr){
		std::cout<<itr->first<<" ";	 // itr first returns the key 
		std::cout<<itr->second<<std::endl;	// itr second returns the value
	}
		
	for (int i = 0; i < 10; i++){
		gquiz1.erase(i); 
	}

	for(itr = gquiz1.begin(); itr != gquiz1.end(); ++itr){
		std::cout<<itr->first<<" ";	 // itr first returns the key 
		std::cout<<itr->second<<std::endl;	// itr second returns the value
	}

	std::set<std::string> myset;
	myset.insert("hello world");
		
	std::set<std::string>::iterator setiterator;

	for(setiterator = myset.begin(); setiterator != myset.end(); ++setiterator){
		std::cout<<*setiterator<<std::endl; // you have to dereferance the set otherwise you cannot use it... it is returning a pointer in the set essentially
	}

	setiterator = myset.begin();
	std::cout<<parenthesized(*setiterator);
}
*/

// this_thread::sleep_for example
#include <iostream>       // std::cout
#include <iomanip>        // std::put_time
#include <thread>         // std::this_thread::sleep_until
#include <chrono>         // std::chrono::system_clock
#include <ctime>          // std::time_t, std::tm, std::localtime, std::mktime

int main() 
{
	using std::chrono::system_clock;
	std::time_t tt = system_clock::to_time_t (system_clock::now());

	struct std::tm * ptm = std::localtime(&tt);
	std::cout << "Current time: " << std::put_time(ptm,"%X") << '\n';

	std::cout << "Waiting for the next minute to begin...\n";
	++ptm->tm_min; ptm->tm_sec=0;
	std::this_thread::sleep_until (system_clock::from_time_t (mktime(ptm)));

	std::cout << std::put_time(ptm,"%X") << " reached!\n";

	return 0;
}
