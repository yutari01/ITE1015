// file: the-starry-night.cc
#include <iostream>

int main() {
    int N;
    std::cin >> N;
    
    // your code here
    for (int i =1; i <= N; i++) {
    	for (int j =1; j <= i; j++) {
    		std::cout << "*" ;
    	}
    	std::cout << "\n" ;
    }
    
    return 0;
}
