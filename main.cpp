#include "test.hpp"
#include "myclass.hpp"
#include <unistd.h>

int myClass::inst_id = 0;

#define YELLOW "\x1b[1;33m"
#define BLUE "\x1b[1;34m"

void ProcessConstIteratorTests(std::list<int> const &lst, ft::list<int> const &ftlst) {
  auto itlst = lst.begin();
  auto itftlst = ftlst.begin();

  for (int i = 0; itlst != lst.end() && itftlst != ftlst.end() && i < (int) lst.size(); ++itlst, ++itftlst, ++i) {
	*itlst = 10;
    *itftlst = 10;
  }
}

void TestConstIterator() {
  std::vector<int> v{2, 4, 6, 1, -5, -6, -1, 3, 7, 0, 0, 0, 4, 2, 1, -3, 5, 8, 10, 10, 11, -10, -10, 22, 21};
  std::list<int> lst(v.begin(), v.end());
  ft::list<int> ftlst(v.begin(), v.end());

  ProcessConstIteratorTests(lst, ftlst);
}

int main(){

	// std::cout << YELLOW << "#TEST LIST#\n" << RESET;
	// test_list();
	// std::cout << YELLOW << "#TEST VECTOR#\n" << RESET;
	// test_vector();
	// std::cout << YELLOW << "#TEST MAP#\n" << RESET;
	// test_map();
	// std::cout << YELLOW << "#TEST STACK#\n" << RESET;
	// test_stack();
	// std::cout << YELLOW << "#TEST QUEUE#\n" << RESET;
	// test_queue();
	// std::cout << BLUE << "#BONUS TEST SET#\n" << RESET;
	// test_set();
	TestConstIterator();
	// read(0,0,1);
	return 0;
}
