// file: contacts.cc
#include <iostream>

struct student_t {
    int id;
    std::string name;
    std::string phone;
};

int main() {
    int N, M;
    std::cin >> N;
    
    // write code here
    // You need to declare student_type as an array.
    student_t space[101];
        
        
    // run N-loops 
    for (int i = 0; i < N; i++) {
        int input_id;
        std::string input_name;
        std::string input_phone;
        
        std::cin >> input_id;
        std::cin >> input_name;
        std::cin >> input_phone;
        
    // write code here
    // put the entered information into the declared student information.
	space[i].id = input_id;
    	space[i].name = input_name;
    	space[i].phone = input_phone;
    }
    
    std::cin >> M;
    
    // write code here
    // run M-loops
    // and print out student information after input student id
    
    int std_id;
 
    for (int i = 0; i < M; i++) {
    	std::cin >> std_id;
   	int count = 0;
    	for(int j = 0; j < N; j++) {
		if(std_id == space[j].id) {
        		std::cout << space[j].name << "," << space[j].phone << std::endl;
        		count++;
      		}
    	}
    	if(count==0) {
		std::cout << "Unknown" << std::endl;
  	}
    }

    return 0;
}
