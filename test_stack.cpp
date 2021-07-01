#include "test.hpp"

using std::string;

void test_stack(){
	std::stack<string> s;
	ft::stack<string> ft_s;

	std::cout << "*Check empty (empty)*\n";
	if (s.empty() == ft_s.empty())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << s.empty() << "!=" << ft_s.empty() << RESET << std::endl;
	}

	std::cout << "*Check size (empty)*\n";
	if (s.size() == ft_s.size())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << s.size() << "!=" << ft_s.size() << RESET << std::endl;
	}

	s.push("hooli");
	s.push("piedpiper");
	s.push("amazon");
	s.push("oracle");
	s.push("yandex");
	s.push("google");
	s.push("facebook");
	s.push("apple");

	ft_s.push("hooli");
	ft_s.push("piedpiper");
	ft_s.push("amazon");
	ft_s.push("oracle");
	ft_s.push("yandex");
	ft_s.push("google");
	ft_s.push("facebook");
	ft_s.push("apple");

	std::cout << "*Check empty*\n";
	if (s.empty() == ft_s.empty())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << s.empty() << "!=" << ft_s.empty() << RESET << std::endl;
	}

	std::cout << "*Check size*\n";
	if (s.size() == ft_s.size())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << s.size() << "!=" << ft_s.size() << RESET << std::endl;
	}

	std::cout << "*Check top*\n";
	if (s.top() == ft_s.top())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << s.top() << "!=" << ft_s.top() << RESET << std::endl;
	}

	std::cout << "*Check pop*\n";

	s.pop();
	ft_s.pop();

	std::cout << "size\n";
	if (s.size() == ft_s.size())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << s.size() << "!=" << ft_s.size() << RESET << std::endl;
	}

	std::cout << "top\n";
	if (s.top() == ft_s.top())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << s.top() << "!=" << ft_s.top() << RESET << std::endl;
	}

	std::cout << "*Check copy contructor*\n";
	ft::stack<string> ft_c(ft_s);

	std::cout << "size\n";
	if (ft_c.size() == ft_s.size())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << ft_c.size() << "!=" << ft_s.size() << RESET << std::endl;
	}

	std::cout << "top\n";
	if (ft_c.top() == ft_s.top())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << ft_c.top() << "!=" << ft_s.top() << RESET << std::endl;
	}

	std::cout << "*Check operator=*\n";
	ft_c.pop();
	std::cout << "top: " << ft_c.top() << "\tsize: " << ft_c.size() << std::endl;
	ft_c = ft_s;
	std::cout << "top: " << ft_c.top() << "\tsize: " << ft_c.size() << std::endl;
	std::cout << "size\n";

	if (ft_c.size() == ft_s.size())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << ft_c.size() << "!=" << ft_s.size() << RESET << std::endl;
	}

	std::cout << "top\n";
	if (ft_c.top() == ft_s.top())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << ft_c.top() << "!=" << ft_s.top() << RESET << std::endl;
	}

	std::cout << "*Check operator==*\n";
	std::stack<string> c(s);

	if ((c == s) == (ft_c == ft_s))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (c == s) << "!=" << RED << (ft_c == ft_s) << RESET << std::endl;
	}

	std::cout << "*Check operator!=*\n";
	if ((c != s) == (ft_c != ft_s))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (c != s) << "!=" << RED << (ft_c != ft_s) << RESET << std::endl;
	}

	std::cout << "*Check operator>*\n";
	if ((c > s) == (ft_c > ft_s))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (c > s) << "!=" << RED << (ft_c > ft_s) << RESET << std::endl;
	}

	std::cout << "*Check operator>=*\n";
	if ((c >= s) == (ft_c >= ft_s))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (c >= s) << "!=" << RED << (ft_c >= ft_s) << RESET << std::endl;
	}

	std::cout << "*Check operator<*\n";
	if ((c < s) == (ft_c < ft_s))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (c < s) << "!=" << RED << (ft_c < ft_s) << RESET << std::endl;
	}

	std::cout << "*Check operator<=*\n";
	if ((c <= s) == (ft_c <= ft_s))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (c <= s) << "!=" << RED << (ft_c <= ft_s) << RESET << std::endl;
	}
}