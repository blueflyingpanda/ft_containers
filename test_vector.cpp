#include "test.hpp"

void test_vector(){
	std::vector<std::string> vec;
	ft::vector<std::string> ft_vec;

	std::cout << "*Check empty (empty)*\n";
	if (vec.empty() == ft_vec.empty())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << vec.empty() << "!=" << ft_vec.empty() << RESET << std::endl;
	}

	std::cout << "*Check max_size*\n";
	if (vec.max_size() == ft_vec.max_size())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << vec.max_size() << "!=" << ft_vec.max_size() << RESET << std::endl;
	}

	// vec.erase(vec.begin()); //double FREE
	// ft_vec.erase(ft_vec.begin()); //SEGFAULT

	vec.push_back("jsuxsux");
	vec.push_back("wontnoticeu");
	vec.push_back("simonsaysnya");
	vec.push_back("oniondorian");

	ft_vec.push_back("jsuxsux");
	ft_vec.push_back("wontnoticeu");
	ft_vec.push_back("simonsaysnya");
	ft_vec.push_back("oniondorian");
	// std::vector<std::string>::iterator tmp;
	// ft::vector<std::string>::iterator ft_tmp;
	// vec.erase(tmp); //SEGFAULT
	// ft_vec.erase(ft_tmp); //SEGFAULT

	std::cout << "*Check size*\n";
	if (vec.size() == ft_vec.size())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << vec.size() << "!=" << ft_vec.size() << RESET << std::endl;
	}

	std::cout << "*Check empty (not empty)*\n";
	if (vec.empty() == ft_vec.empty())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << vec.empty()<< "!=" << ft_vec.empty() << RESET << std::endl;
	}

	std::cout << "*Check front*\n";
	if (vec.front() == ft_vec.front())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << vec.front() << "!=" << ft_vec.front() << RESET << std::endl;
	}

	std::cout << "*Check back*\n";
	if (vec.back() == ft_vec.back())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << vec.back() << "!=" << ft_vec.back() << RESET << std::endl;
	}

	std::vector<std::string>::iterator beg = vec.begin();
	ft::vector<std::string>::iterator ft_beg = ft_vec.begin();
	std::vector<std::string>::iterator fin = vec.end();
	ft::vector<std::string>::iterator ft_fin = ft_vec.end();

	std::cout << "*Check push_back (insert)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*Check erase (one first)*\n";
	std::vector<std::string>::iterator ret = vec.erase(vec.begin());
	ft::vector<std::string>::iterator ft_ret = ft_vec.erase(ft_vec.begin());
	
	beg = vec.begin();
	ft_beg = ft_vec.begin();
	fin = vec.end();
	ft_fin = ft_vec.end();

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

	std::vector<std::string>::iterator last = vec.end();
	ft::vector<std::string>::iterator ft_last = ft_vec.end();
	last--;
	ft_last--;

	ret = vec.erase(last);
	ft_ret = ft_vec.erase(ft_last);

	beg = vec.begin();
	ft_beg = ft_vec.begin();
	fin = vec.end();
	ft_fin = ft_vec.end();

	std::cout << "*Check erase (one last)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	vec.push_back("matrix");
	vec.push_back("skywall");
	vec.push_back("vindigoz");
	vec.push_back("inkognito");

	ft_vec.push_back("matrix");
	ft_vec.push_back("skywall");
	ft_vec.push_back("vindigoz");
	ft_vec.push_back("inkognito");

	last = vec.begin();
	ft_last = ft_vec.begin();
	last++; last++;
	ft_last++; ft_last++;

	ret = vec.erase(last,--vec.end());
	ft_ret = ft_vec.erase(ft_last, --ft_vec.end());

	beg = vec.begin();
	ft_beg = ft_vec.begin();
	fin = vec.end();
	ft_fin = ft_vec.end();

	std::cout << "*Check erase (range)*\n";
	for(; beg != fin; beg++, ft_beg++){
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

	vec.clear();
	ft_vec.clear();

	vec.push_back("Harry");
	vec.push_back("Potter");
	ft_vec.push_back("Harry");
	ft_vec.push_back("Potter");
	

	std::vector<std::string>::iterator second = vec.begin();
	ft::vector<std::string>::iterator ft_second = ft_vec.begin();

	// vec.erase(last, second); //double FREE
	// ft_vec.erase(ft_last, ft_second); //infinite loop

	second++;
	ft_second++;
	ret = vec.insert(second, "James");
	ft_ret = ft_vec.insert(ft_second, "James");

	beg = vec.begin();
	ft_beg = ft_vec.begin();
	fin = vec.end();
	ft_fin = ft_vec.end();

	std::cout << "*Check insert (middle)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	vec.insert(++vec.begin(), 2, "Gryffindor");
	ft_vec.insert(++ft_vec.begin(), 2, "Gryffindor");

	beg = vec.begin();
	ft_beg = ft_vec.begin();
	fin = vec.end();
	ft_fin = ft_vec.end();

	std::cout << "*Check insert (fill)*\n";
	for(; beg != fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::vector<std::string> muggle;
	muggle.push_back("Vernon");
	muggle.push_back("Petunia");
	muggle.push_back("Dudley");
	muggle.push_back("Marge");
	//CHANGE TO PUSH_BACK
	ft::vector<std::string> ft_muggle;
	ft_muggle.push_back("Vernon");
	ft_muggle.push_back("Petunia");
	ft_muggle.push_back("Dudley");
	ft_muggle.push_back("Marge");

	vec.insert(vec.begin(), muggle.begin(), muggle.end());
	ft_vec.insert(ft_vec.begin(), ft_muggle.begin(), ft_muggle.end());
	vec.insert(vec.end(), ++muggle.begin(), --muggle.end());
	ft_vec.insert(ft_vec.end(), ++ft_muggle.begin(), --ft_muggle.end());

	beg = vec.begin();
	ft_beg = ft_vec.begin();
	fin = vec.end();
	ft_fin = ft_vec.end();

	std::cout << "*Check insert (range)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	vec.resize(11);//if size == n does nothing
	ft_vec.resize(11);

	beg = vec.begin();
	ft_beg = ft_vec.begin();
	fin = vec.end();
	ft_fin = ft_vec.end();

	std::cout << "*Check resize (size == n does nothing)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	vec.resize(7);
	ft_vec.resize(7);

	beg = vec.begin();
	ft_beg = ft_vec.begin();
	fin = vec.end();
	ft_fin = ft_vec.end();

	std::cout << "*Check resize (reduce)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::cout << "*Check pop back*\n";
	vec.pop_back();
	ft_vec.pop_back();
	vec.pop_back();
	ft_vec.pop_back();

	beg = vec.begin();
	ft_beg = ft_vec.begin();
	fin = vec.end();
	ft_fin = ft_vec.end();

	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	vec.swap(muggle);
	ft_vec.swap(ft_muggle);

	beg = vec.begin();
	ft_beg = ft_vec.begin();
	fin = vec.end();
	ft_fin = ft_vec.end();

	std::cout << "*Check swap*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	vec.assign(4, "Azkaban");
	ft_vec.assign(4, "Azkaban");

	beg = vec.begin();
	ft_beg = ft_vec.begin();
	fin = vec.end();
	ft_fin = ft_vec.end();

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

	vec.assign(muggle.begin(), muggle.end());
	ft_vec.assign(ft_muggle.begin(), ft_muggle.end());

	beg = vec.begin();
	ft_beg = ft_vec.begin();
	fin = vec.end();
	ft_fin = ft_vec.end();

	std::cout << "*Check assign (range)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	muggle.assign(1, "MACUSA");
	ft_muggle.assign(1, "MACUSA");

	vec = muggle;
	ft_vec = ft_muggle;

	beg = vec.begin();
	ft_beg = ft_vec.begin();
	fin = vec.end();
	ft_fin = ft_vec.end();

	std::cout << "*Check operator=*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}
	
	muggle.push_back("OWL");
	ft_muggle.push_back("OWL");

	beg = vec.begin();
	ft_beg = ft_vec.begin();
	fin = vec.end();
	ft_fin = ft_vec.end();

	std::cout << "*Check operator=(made a copy)*\n";
	for(; ft_beg != ft_fin; beg++, ft_beg++){
		if (*beg == *ft_beg)
			std::cout << GREEN << *beg << std::setw(15) << *ft_beg << RESET << std::endl;
		else
			std::cout << GREEN << *beg << std::setw(15) << RED << *ft_beg << RESET << std::endl;
	}

	std::vector<std::string> wizard(muggle);
	ft::vector<std::string> ft_wizard(ft_muggle);

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

	std::vector<std::string> squib(muggle.begin(), muggle.end());
	ft::vector<std::string> ft_squib(ft_muggle.begin(), ft_muggle.end());

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

	std::vector<std::string> minerva(2, "CAT");
	ft::vector<std::string> ft_minerva(2, "CAT");

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

		std::vector<std::string>::reverse_iterator rebegin = muggle.rbegin();
	ft::vector<std::string>::reverse_iterator ft_rebegin = ft_muggle.rbegin();
	// std::vector<std::string>::reverse_iterator rend = muggle.rend();
	ft::vector<std::string>::reverse_iterator ft_rend = ft_muggle.rend();

	std::cout << "*Check reverse iterator*\n";
	for(; ft_rebegin != ft_rend; rebegin++, ft_rebegin++){
		if (*rebegin == *ft_rebegin)
			std::cout << GREEN << *rebegin << std::setw(15) << *ft_rebegin << RESET << std::endl;
		else
			std::cout << GREEN << *rebegin << std::setw(15) << RED << *ft_rebegin << RESET << std::endl;
	}

	std::cout << "*Check operator==*\n";
	std::vector<std::string> test(vec);
	ft::vector<std::string> ft_test(ft_vec);

	if ((vec == test) == (ft_vec == ft_test))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (vec == test) << "!=" << RED << (ft_vec == ft_test) << RESET << std::endl;
	}

	std::cout << "*Check operator!=*\n";
	if ((vec != muggle) == (ft_vec != ft_muggle))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (vec != test) << "!=" << RED << (ft_vec != ft_test) << RESET << std::endl;
	}

	std::cout << "*Check operator<*\n";
	if ((vec < muggle) == (ft_vec < ft_muggle))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (vec < test) << "!=" << RED << (ft_vec < ft_test) << RESET << std::endl;
	}

	std::cout << "*Check operator>*\n";
	if ((vec > muggle) == (ft_vec > ft_muggle))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (vec > test) << "!=" << RED << (ft_vec > ft_test) << RESET << std::endl;
	}

	std::cout << "*Check operator<=*\n";
	if ((vec <= test) == (ft_vec <= ft_test))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (vec <= test) << "!=" << RED << (ft_vec <= ft_test) << RESET << std::endl;
	}

	std::cout << "*Check operator>=*\n";
	if ((vec >= test) == (ft_vec >= ft_test))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << RESET << std::endl;
		std::cout << std::boolalpha << GREEN << (vec >= test) << "!=" << RED << (ft_vec >= ft_test) << RESET << std::endl;
	}

	// std::cout << "*Check capacity*\n";
	// if (vec.capacity() == ft_vec.capacity())
	// 	std::cout << GREEN << "OK" << RESET << std::endl;
	// else{
	// 	std::cout << RED << "KO" << std::endl;
	// 	std::cout << vec.capacity() << "!=" << ft_vec.capacity() << RESET << std::endl;
	// }

	std::cout << "*Check at (except)*\n";

	try{vec.at(28);}
	catch(std::out_of_range &e){std::cerr << "Поймай меня, если сможешь\n";}
	try{ft_vec.at(28);}
	catch(std::out_of_range &e){std::cerr << "И меня поймай, если сможешь\n";}

	vec.push_back("jsuxsux");
	vec.push_back("wontnoticeu");
	vec.push_back("simonsaysnya");
	vec.push_back("oniondorian");

	ft_vec.push_back("jsuxsux");
	ft_vec.push_back("wontnoticeu");
	ft_vec.push_back("simonsaysnya");
	ft_vec.push_back("oniondorian");

	std::cout << "*Check at*\n";

	if (vec.at(2) == ft_vec.at(2))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << vec.at(2) << "!=" << ft_vec.at(2) << RESET << std::endl;
	}

	std::cout << "*Check operator[]*\n";

	if (vec[2] == ft_vec[2])
		std::cout << GREEN << "OK" << RESET << std::endl;
	else{
		std::cout << RED << "KO" << std::endl;
		std::cout << vec[2] << "!=" << ft_vec[2] << RESET << std::endl;
	}

/*
	std::vector<std::string *> victor;

	std::string *v1 = new std::string("ZAZ");
	std::string *v2 = new std::string("JAZZ");

	victor.push_back(v1);
	victor.push_back(v2);

	*v1 = "POP";

	std::cout << *(victor[0]) << std::endl;

	try{vec.at(28);}
	catch(std::out_of_range &e){std::cerr << "Поймай меня, если сможешь\n";}

	vec.push_back("abc");
	vec.push_back("xyz");
	vec.push_back("def");

	std::sort(vec.begin(), vec.end());

	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
	std::vector<std::string>::iterator beg = vec.begin();
	std::vector<std::string>::iterator las = vec.end();
	las--;
	std::cout << las - beg << std::endl;//only - (returns size_type?)
	std::cout << *(beg + 2) << std::endl;
	std::cout << *(las - 2) << std::endl;
	std::cout << "---------------\n";
	// beg-=las;no viable overload so -= and +=  doesnt work with iterators, only with size_type
	beg+=2;
	las-=2;
	std::cout << *beg << std::endl;
	std::cout << *las << std::endl;
*/
}