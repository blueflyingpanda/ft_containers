#include "test.hpp"
#include "myclass.hpp"
#include <unistd.h>

int myClass::inst_id = 0;

#define YELLOW "\x1b[1;33m"
#define BLUE "\x1b[1;34m"


int main(){

	std::cout << YELLOW << "#TEST LIST#\n" << RESET;
	test_list();
	std::cout << YELLOW << "#TEST VECTOR#\n" << RESET;
	test_vector();
	std::cout << YELLOW << "#TEST MAP#\n" << RESET;
	test_map();
	std::cout << YELLOW << "#TEST STACK#\n" << RESET;
	test_stack();
	std::cout << YELLOW << "#TEST QUEUE#\n" << RESET;
	test_queue();
	std::cout << BLUE << "#BONUS TEST SET#\n" << RESET;
	test_set();
	read(0,0,1);
	return 0;
}
