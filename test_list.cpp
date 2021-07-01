#include "test.hpp"

bool hasBigA(const std::string &s){
	for (size_t i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 'A')
			return true;
	}
	return false;
}

bool startsWithTheSameLetter(const std::string &n, const std::string &f){
	return f[0] == n[0];
}

bool caseInsensitiveFirstCharCompare(const std::string &f, const std::string &s){
	return std::tolower(f[0]) < std::tolower(s[0]);
}

bool luckyNumber(const std::string &n, const std::string &f){
	if (f[0] == '7' && f[0] != n[0])
		return true;
	if (n[0] == '7' && f[0] != n[0])
		return false;
	return n[0] < f[0];
}

void test_list(){
	std::list<std::string> lst;
	ft::list<std::string> ft_lst;

	std::cout << "*Check empty (empty)*\n";
	if (lst.empty() == ft_lst.empty())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << lst.empty() << "!=" << ft_lst.empty() << RESET << std::endl;
	}

	std::cout << "*Check max_size*\n";
	if (lst.max_size() == ft_lst.max_size())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << lst.max_size() << "!=" << ft_lst.max_size() << RESET << std::endl;
	}

	// lst.erase(lst.begin()); //double FREE
	// ft_lst.erase(ft_lst.begin()); //SEGFAULT

	lst.push_back("Albus");
	lst.push_back("Percival");
	lst.push_back("Wulfric");
	lst.push_back("Brian");
	lst.push_back("Dumbledore");

	//CHANGE TO PUSH_BACK
	// ft_lst.insert(ft_lst.end(), "Albus");
	// ft_lst.insert(ft_lst.end(), "Percival");
	// ft_lst.insert(ft_lst.end(), "Wulfric");
	// ft_lst.insert(ft_lst.end(), "Brian");
	// ft_lst.insert(ft_lst.end(), "Dumbledore");

	ft_lst.push_back("Albus");
	ft_lst.push_back("Percival");
	ft_lst.push_back("Wulfric");
	ft_lst.push_back("Brian");
	ft_lst.push_back("Dumbledore");

	// lst.erase(lst.end()); //double FREE
	// ft_lst.erase(ft_lst.end()); //SEGFAULT

	// std::list<std::string>::iterator tmp;
	// ft::list<std::string>::iterator ft_tmp;
	// lst.erase(tmp); //SEGFAULT
	// ft_lst.erase(ft_tmp); //SEGFAULT

	std::cout << "*Check size*\n";
	if (lst.size() == ft_lst.size())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << lst.size() << "!=" << ft_lst.size() << RESET << std::endl;
	}

	std::cout << "*Check empty (not empty)*\n";
	if (lst.empty() == ft_lst.empty())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << lst.empty()<< "!=" << ft_lst.empty() << RESET << std::endl;
	}

	std::cout << "*Check front*\n";
	if (lst.front() == ft_lst.front())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << lst.front() << "!=" << ft_lst.front() << RESET << std::endl;
	}

	std::cout << "*Check back*\n";
	if (lst.back() == ft_lst.back())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << lst.back() << "!=" << ft_lst.back() << RESET << std::endl;
	}

	std::list<std::string>::iterator beg = lst.begin();
	ft::list<std::string>::iterator ft_beg = ft_lst.begin();
	std::list<std::string>::iterator fin = lst.end();
	ft::list<std::string>::iterator ft_fin = ft_lst.end();

	std::cout << "*Check push_back (insert)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*Check erase (one first)*\n";
	std::list<std::string>::iterator ret = lst.erase(lst.begin());
	ft::list<std::string>::iterator ft_ret = ft_lst.erase(ft_lst.begin());
	
	

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();

	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*Check erase (one first) return value*\n";
	if (*ret == *ft_ret)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << *ret << "!=" << *ft_ret << RESET << std::endl;
	}

	std::list<std::string>::iterator last = lst.end();
	ft::list<std::string>::iterator ft_last = ft_lst.end();
	last--;
	ft_last--;

	ret = lst.erase(last);
	ft_ret = ft_lst.erase(ft_last);

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();

	std::cout << "*Check erase (one last)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	last = lst.end();
	ft_last = ft_lst.end();
	last--;
	ft_last--;

	ret = lst.erase(lst.begin(), last);
	ft_ret = ft_lst.erase(ft_lst.begin(), ft_last);

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();

	std::cout << "*Check erase (range)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*Check erase (range) return value*\n";
	if (*ret == *ft_ret)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << *ret << "!=" << *ft_ret << RESET << std::endl;
	}

	lst.clear();
	ft_lst.clear();

	lst.push_back("Harry");
	lst.push_back("Potter");
	ft_lst.push_back("Harry");
	ft_lst.push_back("Potter");
	
	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();
	last = lst.end();
	ft_last = ft_lst.end();
	last--;
	ft_last--;

	std::list<std::string>::iterator second = lst.begin();
	ft::list<std::string>::iterator ft_second = ft_lst.begin();

	// lst.erase(last, second); //double FREE
	// ft_lst.erase(ft_last, ft_second); //infinite loop

	second++;
	ft_second++;
	ret = lst.insert(second, "James");
	ft_ret = ft_lst.insert(ft_second, "James");
	std::cout << "*Check insert (middle)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}
	
	std::cout << "*Check insert (middle) return value*\n";
	if (*ret == *ft_ret)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << *ret << "!=" << *ft_ret << RESET << std::endl;
	}
	

	// lst.insert(lst.end(), -3, "Gryffindor");//infinite loop
	// ft_lst.insert(ft_lst.end(), -3, "Gryffindor");//infinite loop
	// lst.insert(lst.end(), 0, "Gryffindor");//does nothing
	// ft_lst.insert(ft_lst.end(), 0, "Gryffindor");//does nothing
	lst.insert(lst.end(), 2, "Gryffindor");
	ft_lst.insert(ft_lst.end(), 2, "Gryffindor");

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();

	std::cout << "*Check insert (fill)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::list<std::string> muggle;
	muggle.push_back("Vernon");
	muggle.push_back("Petunia");
	muggle.push_back("Dudley");
	//CHANGE TO PUSH_BACK
	ft::list<std::string> ft_muggle;
	ft_muggle.push_back("Vernon");
	ft_muggle.push_back("Petunia");
	ft_muggle.push_back("Dudley");

	lst.insert(lst.begin(), muggle.begin(), muggle.end());
	ft_lst.insert(ft_lst.begin(), ft_muggle.begin(), ft_muggle.end());
	lst.insert(lst.end(), muggle.begin(), muggle.end());
	ft_lst.insert(ft_lst.end(), ft_muggle.begin(), ft_muggle.end());

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();

	std::cout << "*Check insert (range)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	lst.resize(11);//if size == n does nothing
	ft_lst.resize(11);

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();

	std::cout << "*Check resize (size == n does nothing)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	lst.resize(7);
	ft_lst.resize(7);

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();

	std::cout << "*Check resize (reduce)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	lst.push_front("Voldy");
	ft_lst.push_front("Voldy");

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();

	std::cout << "*Check push front*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	lst.pop_back();
	ft_lst.pop_back();

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();

	std::cout << "*Check pop back*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	lst.pop_front();
	ft_lst.pop_front();

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();

	std::cout << "*Check pop front*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}	

	lst.swap(muggle);
	ft_lst.swap(ft_muggle);

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();

	std::cout << "*Check swap*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	lst.assign(4, "Azkaban");
	ft_lst.assign(4, "Azkaban");

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();

	std::cout << "*Check assign (fill)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	muggle.clear();
	ft_muggle.clear();

	muggle.push_back("Weasley");
	muggle.push_back("Hermione");

	ft_muggle.push_back("Weasley");
	ft_muggle.push_back("Hermione");

	lst.assign(muggle.begin(), muggle.end());
	ft_lst.assign(ft_muggle.begin(), ft_muggle.end());

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();

	std::cout << "*Check assign (range)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	muggle.assign(1, "MACUSA");
	ft_muggle.assign(1, "MACUSA");

	lst = muggle;
	ft_lst = ft_muggle;

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();

	std::cout << "*Check operator=*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}
	
	muggle.push_back("OWL");
	ft_muggle.push_back("OWL");

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();

	std::cout << "*Check operator=(made a copy)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::list<std::string> wizard(muggle);
	ft::list<std::string> ft_wizard(ft_muggle);

	beg = wizard.begin();
	ft_beg = ft_wizard.begin();
	fin = wizard.end();
	ft_fin = ft_wizard.end();

	std::cout << "*Check copy constructor*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	muggle.push_back("GOAT");
	ft_muggle.push_back("GOAT");
	
	beg = wizard.begin();
	ft_beg = ft_wizard.begin();
	fin = wizard.end();
	ft_fin = ft_wizard.end();

	std::cout << "*Check copy constructor(made a copy)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::list<std::string> squib(muggle.begin(), muggle.end());
	ft::list<std::string> ft_squib(ft_muggle.begin(), ft_muggle.end());

	beg = squib.begin();
	ft_beg = ft_squib.begin();
	fin = squib.end();
	ft_fin = ft_squib.end();

	std::cout << "*Check range constructor*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	muggle.push_back("TOAD");
	ft_muggle.push_back("TOAD");
	
	beg = squib.begin();
	ft_beg = ft_squib.begin();
	fin = squib.end();
	ft_fin = ft_squib.end();

	std::cout << "*Check range constructor(made a copy)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::list<std::string> minerva(2, "CAT");
	ft::list<std::string> ft_minerva(2, "CAT");

	beg = minerva.begin();
	ft_beg = ft_minerva.begin();
	fin = minerva.end();
	ft_fin = ft_minerva.end();

	std::cout << "*Check fill constructor*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::list<std::string>::reverse_iterator rebegin = muggle.rbegin();
	ft::list<std::string>::reverse_iterator ft_rebegin = ft_muggle.rbegin();
	// std::list<std::string>::reverse_iterator rend = muggle.rend();
	ft::list<std::string>::reverse_iterator ft_rend = ft_muggle.rend();

	std::cout << "*Check reverse iterator*\n";
	for(; ft_rebegin != ft_rend; rebegin++, ft_rebegin++){
		if (*rebegin == *ft_rebegin)
			std::cout << GREEN << *rebegin << std::setw(15) << *ft_rebegin << RESET << std::endl;
		else
			std::cout << GREEN << *rebegin << std::setw(15) << RED << *ft_rebegin << RESET << std::endl;
	}

	
	std::cout << "*Check operator==*\n";
	std::list<std::string> test(lst);
	ft::list<std::string> ft_test(ft_lst);

	if ((lst == test) == (ft_lst == ft_test))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (lst == test) << "!=" << RED << (ft_lst == ft_test) << RESET << std::endl;
	}

	std::cout << "*Check operator!=*\n";
	if ((lst != muggle) == (ft_lst != ft_muggle))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (lst != test) << "!=" << RED << (ft_lst != ft_test) << RESET << std::endl;
	}

	std::cout << "*Check operator<*\n";
	if ((lst < muggle) == (ft_lst < ft_muggle))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (lst < test) << "!=" << RED << (ft_lst < ft_test) << RESET << std::endl;
	}

	std::cout << "*Check operator>*\n";
	if ((lst > muggle) == (ft_lst > ft_muggle))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (lst > test) << "!=" << RED << (ft_lst > ft_test) << RESET << std::endl;
	}

	std::cout << "*Check operator<=*\n";
	if ((lst <= test) == (ft_lst <= ft_test))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (lst <= test) << "!=" << RED << (ft_lst <= ft_test) << RESET << std::endl;
	}

	std::cout << "*Check operator>=*\n";
	if ((lst >= test) == (ft_lst >= ft_test))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (lst >= test) << "!=" << RED << (ft_lst >= ft_test) << RESET << std::endl;
	}

	std::cout << "*check splice all*\n";

	lst.splice(lst.begin(), minerva, minerva.begin(), minerva.end());
	ft_lst.splice(ft_lst.begin(), ft_minerva, ft_minerva.begin(), ft_minerva.end());

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();
	
	for(; beg != fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	beg = minerva.begin();
	ft_beg = ft_minerva.begin();
	fin = minerva.end();
	ft_fin = ft_minerva.end();

	std::cout << "*check second container after splice* (should print nothing)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}
	
	std::list<std::string>::iterator iter = muggle.begin();
	ft::list<std::string>::iterator ft_iter = ft_muggle.begin();
	iter++;
	ft_iter++;

	std::cout << "*second container before splice*\n";

	beg = muggle.begin();
	ft_beg = ft_muggle.begin();
	fin = muggle.end();
	ft_fin = ft_muggle.end();

	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*check splice one*\n";

	lst.splice(++lst.begin(), muggle, iter);
	ft_lst.splice(++ft_lst.begin(), ft_muggle, ft_iter);

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();
	
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*check second container after splice*\n";

	beg = muggle.begin();
	ft_beg = ft_muggle.begin();
	fin = muggle.end();
	ft_fin = ft_muggle.end();

	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*check splice range*\n";

	iter = lst.begin();
	iter++;
	iter++;

	ft_iter = ft_lst.begin();
	ft_iter++;
	ft_iter++;

	lst.splice(lst.begin(), lst, iter, lst.end());
	ft_lst.splice(ft_lst.begin(), ft_lst, ft_iter, ft_lst.end());

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();
	
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*Check remove (CAT)*\n";
	lst.remove("CAT");
	ft_lst.remove("CAT");

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();
	
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*Check remove_if*\n";

	lst.push_back("CAT");
	ft_lst.push_back("CAT");

	lst.remove_if(hasBigA);
	ft_lst.remove_if(hasBigA);

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();
	
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*Check unique*\n";

	lst.push_back("PHOENIX");
	ft_lst.push_back("PHOENIX");
	lst.push_back("PHOENIX");
	ft_lst.push_back("PHOENIX");
	lst.push_back("SNAKE");
	ft_lst.push_back("SNAKE");
	lst.push_back("OWL");
	ft_lst.push_back("OWL");

	lst.unique();
	ft_lst.unique();

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();
	
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*Check unique with condition (before)*\n";

	lst.insert(++lst.begin(), "PEGASUS");
	ft_lst.insert(++ft_lst.begin(), "PEGASUS");
	lst.insert(++lst.begin(), "PONY");
	ft_lst.insert(++ft_lst.begin(), "PONY");

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();
	
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	lst.unique(startsWithTheSameLetter);
	ft_lst.unique(startsWithTheSameLetter);

	std::cout << "*Check unique with condition (after)*\n";

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();
	
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*Check merge*\n";

	lst.clear();
	muggle.clear();
	ft_lst.clear();
	ft_muggle.clear();

	lst.push_back("A");
	lst.push_back("B");
	lst.push_back("E");

	ft_lst.push_back("A");
	ft_lst.push_back("B");
	ft_lst.push_back("E");

	muggle.push_back("B");
	muggle.push_back("D");
	muggle.push_back("F");
	muggle.push_back("G");

	ft_muggle.push_back("B");
	ft_muggle.push_back("D");
	ft_muggle.push_back("F");
	ft_muggle.push_back("G");

	lst.merge(muggle);
	ft_lst.merge(ft_muggle);

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();
	
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}
	
	std::cout << "*Check second container after merge (should print nothing)*\n";

	beg = muggle.begin();
	ft_beg = ft_muggle.begin();
	fin = muggle.end();
	ft_fin = ft_muggle.end();

	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*Check merge with condition*\n";

	muggle.push_back("a");
	muggle.push_back("b");
	muggle.push_back("c");
	muggle.push_back("d");
	
	ft_muggle.push_back("a");
	ft_muggle.push_back("b");
	ft_muggle.push_back("c");
	ft_muggle.push_back("d");

	lst.merge(muggle, caseInsensitiveFirstCharCompare);
	ft_lst.merge(ft_muggle, caseInsensitiveFirstCharCompare);

	// lst.merge(muggle);
	// ft_lst.merge(ft_muggle);

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();
	
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}
	
	std::cout << "*Check second container after merge (should print nothing)*\n";

	beg = muggle.begin();
	ft_beg = ft_muggle.begin();
	fin = muggle.end();
	ft_fin = ft_muggle.end();

	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*Check sort*\n";

	lst.clear();
	ft_lst.clear();

	lst.push_back("8");
	ft_lst.push_back("8");
	lst.push_back("3");
	ft_lst.push_back("3");
	lst.push_back("5");
	ft_lst.push_back("5");
	lst.push_back("1");
	ft_lst.push_back("1");
	lst.push_back("4");
	ft_lst.push_back("4");
	lst.push_back("6");
	ft_lst.push_back("6");
	lst.push_back("9");
	ft_lst.push_back("9");
	lst.push_back("2");
	ft_lst.push_back("2");
	lst.push_back("7");
	ft_lst.push_back("7");
	lst.push_back("0");
	ft_lst.push_back("0");

	lst.sort();
	ft_lst.sort();

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();
	
	for(; beg != fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*Check sort with comp*\n";

	lst.clear();
	ft_lst.clear();

	lst.push_back("8");
	ft_lst.push_back("8");
	lst.push_back("3");
	ft_lst.push_back("3");
	lst.push_back("5");
	ft_lst.push_back("5");
	lst.push_back("1");
	ft_lst.push_back("1");
	lst.push_back("4");
	ft_lst.push_back("4");
	lst.push_back("6");
	ft_lst.push_back("6");
	lst.push_back("9");
	ft_lst.push_back("9");
	lst.push_back("2");
	ft_lst.push_back("2");
	lst.push_back("7");
	ft_lst.push_back("7");
	lst.push_back("0");
	ft_lst.push_back("0");

	lst.sort(luckyNumber);
	ft_lst.sort(luckyNumber);

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();
	
	for(; beg != fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*Check reverse*\n";

	lst.reverse();
	ft_lst.reverse();

	beg = lst.begin();
	ft_beg = ft_lst.begin();
	fin = lst.end();
	ft_fin = ft_lst.end();
	
	for(; beg != fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}
	
	// std::list<std::string>::reverse_iterator jsux = lst.rend();
	// jsux--;
	// ft::list<std::string>::reverse_iterator ft_jsux = ft_lst.rend();
	// ft_jsux--;

	// std::cout << "_____________________\n";
	// std::cout << *jsux << "\t" << *ft_jsux << std::endl;
	// std::cout << "_____________________\n";
	// lst.insert(jsux, "o");//doesnt work with reverse iterator
	
	// std::cout << "*Check const_iterator*\n";

	// const std::list<std::string> lol;
	// const ft::list<std::string> ft_lol;

	// std::list<std::string>::const_iterator cbeg = lol.begin();
	// std::list<std::string>::const_reverse_iterator crbeg = lol.rbegin();
	// ft::list<std::string>::const_iterator cft_beg = ft_lol.begin();
	// ft::list<std::string>::const_iterator cft_end = ft_lol.end();
	// ft::list<std::string>::const_reverse_iterator crft_beg = ft_lol.rbegin();
	// ft::list<std::string>::const_reverse_iterator crft_end = ft_lol.rend();

	// *cbeg = "123";
	// *cft_beg = "123";

}