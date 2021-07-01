#include "test.hpp"

void test_map()
{
	std::map<int, std::string> m;
	ft::map<int, std::string> ft_m;

	std::cout << "*Check empty (empty)*\n";
	if (m.empty() == ft_m.empty())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << m.empty() << "!=" << ft_m.empty() << RESET << std::endl;
	}

	std::cout << "*Check max_size*\n";
	if (m.max_size() == ft_m.max_size())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << m.max_size() << "!=" << ft_m.max_size() << RESET << std::endl;
	}

	std::pair<std::map<int, std::string>::iterator, bool>  p = m.insert(std::pair<int, std::string>(2, "abc"));
	std::pair<ft::map<int, std::string>::iterator, bool> ft_p = ft_m.insert(std::pair<int, std::string>(2, "abc"));

	std::cout << "*Check insert return value (success)*\n";
	if (p.first->first == ft_p.first->first && p.first->second == ft_p.first->second && p.second == ft_p.second)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << "key: " << p.first->first << "\t" << "value: " << p.first->second << "\t" << "bool: " << std::boolalpha << p.second << std::endl;
		std::cout << RED << "key: " << ft_p.first->first << "\t"  << "value: " << ft_p.first->second << "\t" << "bool: " << std::boolalpha << ft_p.second << std::endl;
	}

	p = m.insert(std::pair<int, std::string>(2, "puk"));
	ft_p = ft_m.insert(std::pair<int, std::string>(2, "puk"));

	std::cout << "*Check insert return value (fail)*\n";
	if (p.first->first == ft_p.first->first && p.first->second == ft_p.first->second && p.second == ft_p.second)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << "key: " << p.first->first << "\t" << "value: " << p.first->second << "\t" << "bool: " << std::boolalpha << p.second << std::endl;
		std::cout << RED << "key: " << ft_p.first->first << "\t"  << "value: " << ft_p.first->second << "\t" << "bool: " << std::boolalpha << ft_p.second << std::endl;
	}

	
	m.insert(std::pair<int, std::string>(1, "foo"));
	m.insert(std::pair<int, std::string>(3, "def"));
	m.insert(std::pair<int, std::string>(0, "xyz"));
	m.insert(std::pair<int, std::string>(5, "chebubu"));
	m.insert(std::pair<int, std::string>(4, "bar"));
	// m.insert(std::pair<int, std::string>(-1, "sit"));

	ft_m.insert(std::pair<int, std::string>(1, "foo"));
	ft_m.insert(std::pair<int, std::string>(3, "def"));
	ft_m.insert(std::pair<int, std::string>(0, "xyz"));
	ft_m.insert(std::pair<int, std::string>(5, "chebubu"));
	ft_m.insert(std::pair<int, std::string>(4, "bar"));
	// ft_m.insert(std::pair<int, std::string>(-1, "sit"));
	

	std::cout << "*Check size*\n";
	if (m.size() == ft_m.size())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << m.size() << "!=" << ft_m.size() << RESET << std::endl;
	}

	std::cout << "*Check empty (not empty)*\n";
	if (m.empty() == ft_m.empty())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << m.empty() << "!=" << ft_m.empty() << RESET << std::endl;
	}

	std::cout << "*Check insert (single)*\n";
	std::map<int, std::string>::iterator it = m.begin();
	ft::map<int, std::string>::iterator ft_it = ft_m.begin();

	for (; ft_it != ft_m.end(); it++, ft_it++)
	{
		if (it->first != ft_it->first || it->second != ft_it->second)	
			std::cout << RED << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
		else
			std::cout << GREEN << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
	}

	std::cout << "*Check reverse iterator*\n";
	std::map<int, std::string>::reverse_iterator re = m.rbegin();
	ft::map<int, std::string>::reverse_iterator ft_re = ft_m.rbegin();
	
	for (; ft_re != ft_m.rend(); re++, ft_re++)
	{
		if (re->first != ft_re->first || re->second != ft_re->second)	
			std::cout << RED << "key: " << re->first << " value: " << std::setw(10) << re->second << std::setw(10) << "key: " << ft_re->first << " value: " << ft_re->second << RESET << std::endl;
		else
			std::cout << GREEN << "key: " << re->first << " value: " << std::setw(10) << re->second << std::setw(10) << "key: " << ft_re->first << " value: " << ft_re->second << RESET << std::endl;
	}
	std::cout << "*Check from tail to head*\n";
	it = m.end();
	ft_it = ft_m.end();
	it--;
	ft_it--;
	for (; it != m.begin(); it--, ft_it--)
	{
		if (it->first != ft_it->first || it->second != ft_it->second)	
			std::cout << RED << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
		else
			std::cout << GREEN << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
	}

	std::cout << "*Check erase(iterator)*\n";
	m.erase(--(--(--(--(--(--m.end()))))));
	ft_m.erase(--(--(--(--(--(--ft_m.end()))))));
	m.erase(--(--(--(--((m.end()))))));
	ft_m.erase(--(--(--(--((ft_m.end()))))));
	m.erase((((--((m.end()))))));
	ft_m.erase((((--((ft_m.end()))))));
	it = m.begin();
	ft_it = ft_m.begin();
	for (; ft_it != ft_m.end(); it++)
	{
		if (it->first != ft_it->first || it->second != ft_it->second)	
			std::cout << RED << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
		else
			std::cout << GREEN << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
		 ++ft_it;
	}

	m.insert(std::pair<int, std::string>(7, "lucky"));
	ft_m.insert(std::pair<int, std::string>(7, "lucky"));
	m.insert(std::pair<int, std::string>(13, "unlucky"));
	ft_m.insert(std::pair<int, std::string>(13, "unlucky"));
	m.insert(std::pair<int, std::string>(21, "sit"));
	ft_m.insert(std::pair<int, std::string>(21, "sit"));
	m.insert(std::pair<int, std::string>(42, "ft"));
	ft_m.insert(std::pair<int, std::string>(42, "ft"));

	std::cout << "*Check erase(key)*\n";
	m.erase(3);
	ft_m.erase(3);
	it = m.begin();
	ft_it = ft_m.begin();
	for (; it != m.end(); it++, ft_it++)
	{
		if (it->first != ft_it->first || it->second != ft_it->second)	
			std::cout << RED << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
		else
			std::cout << GREEN << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
	}

	std::cout << "*Check erase(key not found)*\n";
	int i = m.erase(3);
	int ft_i = ft_m.erase(3);
	it = m.begin();
	ft_it = ft_m.begin();
	for (; it != m.end(); it++, ft_it++)
	{
		if (it->first != ft_it->first || it->second != ft_it->second || i != ft_i)	
			std::cout << RED << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
		else
			std::cout << GREEN << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
	}

	std::cout << "*Check erase(range)*\n";
	m.erase(--(--(--m.end())), m.end());
	ft_m.erase(--(--(--ft_m.end())), ft_m.end());
	it = m.begin();
	ft_it = ft_m.begin();
	for (; it != m.end(); it++, ft_it++)
	{
		if (it->first != ft_it->first || it->second != ft_it->second)	
			std::cout << RED << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
		else
			std::cout << GREEN << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
	}

	std::cout << "*Check swap*\n";
	std::map<int, std::string> ma;
	ft::map<int, std::string> ft_ma;

	ma.insert(std::pair<int, std::string>(0, "lol"));
	ft_ma.insert(std::pair<int, std::string>(0, "lol"));
	ma.insert(std::pair<int, std::string>(1, "kek"));
	ft_ma.insert(std::pair<int, std::string>(1, "kek"));
	ma.insert(std::pair<int, std::string>(3, "che"));
	ft_ma.insert(std::pair<int, std::string>(3, "che"));
	ma.insert(std::pair<int, std::string>(4, "bu"));
	ft_ma.insert(std::pair<int, std::string>(4, "bu"));
	ma.insert(std::pair<int, std::string>(4, "puk"));
	ft_ma.insert(std::pair<int, std::string>(4, "puk"));
	ma.insert(std::pair<int, std::string>(5, "rek"));
	ft_ma.insert(std::pair<int, std::string>(5, "rek"));

	// m.swap(ma);
	// ft_m.swap(ft_ma);
	std::swap(m, ma);
	ft::swap(ft_m, ft_ma);
	
	it = m.begin();
	ft_it = ft_m.begin();
	for (; it != m.end(); it++, ft_it++)
	{
		if (it->first != ft_it->first || it->second != ft_it->second)	
			std::cout << RED << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
		else
			std::cout << GREEN << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
	}

	std::cout << "*Check swap (second container)*\n";

	it = ma.begin();
	ft_it = ft_ma.begin();
	for (; it != ma.end(); it++, ft_it++)
	{
		if (it->first != ft_it->first || it->second != ft_it->second)	
			std::cout << RED << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
		else
			std::cout << GREEN << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
	}

	std::cout << "*Check copy contructor*\n";
	std::map<int, std::string> map(ma);
	ft::map<int, std::string> ft_map(ft_ma);
	it = map.begin();
	ft_it = ft_map.begin();
	for (; it != map.end(); it++, ft_it++)
	{
		if (it->first != ft_it->first || it->second != ft_it->second)	
			std::cout << RED << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
		else
			std::cout << GREEN << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
	}
	
	std::cout << "*Check made a copy (before)*\n";
	ma.erase(++ma.begin());
	ft_ma.erase(++ft_ma.begin());

	it = ma.begin();
	ft_it = ft_ma.begin();
	for (; it != ma.end(); it++, ft_it++)
	{
		if (it->first != ft_it->first || it->second != ft_it->second)	
			std::cout << RED << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
		else
			std::cout << GREEN << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
	}

	std::cout << "*Check made a copy (after)*\n";

	it = map.begin();
	ft_it = ft_map.begin();
	for (; it != map.end(); it++, ft_it++)
	{
		if (it->first != ft_it->first || it->second != ft_it->second)	
			std::cout << RED << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
		else
			std::cout << GREEN << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
	}
	
	std::cout << "*Check operator[]*\n";

	map[9]="kuku";
	map[4]="puk";
	ft_map[9]="kuku";
	ft_map[4]="puk";

	if (map[1] != ft_map[1])	
		std::cout << RED << std::setw(10) << map[1]<< std::setw(10) << ft_map[1] << RESET << std::endl;
	else
		std::cout << GREEN << std::setw(10) << map[1]<< std::setw(10) << ft_map[1] << RESET << std::endl;
	if (map[4] != ft_map[4])	
		std::cout << RED << std::setw(10) << map[4]<< std::setw(10) << ft_map[4] << RESET << std::endl;
	else
		std::cout << GREEN << std::setw(10) << map[4]<< std::setw(10) << ft_map[4] << RESET << std::endl;
	if (map[7] != ft_map[7])	
		std::cout << RED << std::setw(10) << map[7]<< std::setw(10) << ft_map[7] << RESET << std::endl;
	else
		std::cout << GREEN << std::setw(10) << map[7]<< std::setw(10) << ft_map[7] << RESET << std::endl;
	if (map[9] != ft_map[9])	
		std::cout << RED << std::setw(10) << map[9]<< std::setw(10) << ft_map[9] << RESET << std::endl;
	else
		std::cout << GREEN << std::setw(10) << map[9]<< std::setw(10) << ft_map[9] << RESET << std::endl;

	std::cout << "*Check insert with hint*\n";

	std::map<int, std::string>::iterator ite = map.insert(--(--map.end()), std::pair<int, std::string>(5, "buka"));
	ft::map<int, std::string>::iterator ft_ite = ft_map.insert(--(--ft_map.end()), std::pair<int, std::string>(5, "buka"));

	it = map.begin();
	ft_it = ft_map.begin();
	for (; ft_it != ft_map.end(); it++, ft_it++)
	{
		if (it->first != ft_it->first || it->second != ft_it->second)	
			std::cout << RED << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
		else
			std::cout << GREEN << "key: " << it->first << " value: " << std::setw(10) << it->second << std::setw(10) << "key: " << ft_it->first << " value: " << ft_it->second << RESET << std::endl;
	}

	std::cout << "*Check insert with hint (return value)*\n";

	if (ite->first == ft_ite->first && ite->second == ft_ite->second)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << "key: " << ite->first << "\t" << "value: " << ite->second << std::endl;
		std::cout << RED << "key: " << ft_ite->first << "\t"  << "value: " << ft_ite->second << std::endl;
	}

	std::cout << "*Check find*\n";
	if (map.find(4)->first == ft_map.find(4)->first && map.find(4)->second == ft_map.find(4)->second)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << map.find(4)->first << "\t" << map.find(4)->second << '\t' << RED << ft_map.find(4)->first << '\t' << ft_map.find(4)->second << RESET << std::endl;
	}

	std::cout << "*Check count*\n";

	if (map.count(4) == ft_map.count(4))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << map.count(4) << "\t" << RED << ft_map.count(4) << RESET << std::endl;
	}
	if (map.count(14) == ft_map.count(14))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << map.count(4) << "\t" << RED << ft_map.count(4) << RESET << std::endl;
	}

	std::cout << "*Check lower bound*\n";

	if (map.lower_bound(1)->first == ft_map.lower_bound(1)->first && map.lower_bound(1)->second == ft_map.lower_bound(1)->second)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << map.lower_bound(1)->first << "\t" << map.lower_bound(1)->second << "\t" << RED << ft_map.lower_bound(1)->first << "\t" << ft_map.lower_bound(1)->second << RESET << std::endl;
	}
	if (map.lower_bound(4)->first == ft_map.lower_bound(4)->first && map.lower_bound(4)->second == ft_map.lower_bound(4)->second)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << map.lower_bound(4)->first << "\t" << map.lower_bound(4)->second << "\t" << RED << ft_map.lower_bound(4)->first << "\t" << ft_map.lower_bound(4)->second << RESET << std::endl;
	}
	if (map.lower_bound(9)->first == ft_map.lower_bound(9)->first && map.lower_bound(9)->second == ft_map.lower_bound(9)->second)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << map.lower_bound(9)->first << "\t" << map.lower_bound(9)->second << "\t" << RED << ft_map.lower_bound(9)->first << "\t" << ft_map.lower_bound(9)->second << RESET << std::endl;
	}

	std::cout << "*Check upper bound*\n";

	if (map.upper_bound(1)->first == ft_map.upper_bound(1)->first && map.upper_bound(1)->second == ft_map.upper_bound(1)->second)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << map.upper_bound(1)->first << "\t" << map.upper_bound(1)->second << "\t" << RED << ft_map.upper_bound(1)->first << "\t" << ft_map.upper_bound(1)->second << RESET << std::endl;
	}
	if (map.upper_bound(4)->first == ft_map.upper_bound(4)->first && map.upper_bound(4)->second == ft_map.upper_bound(4)->second)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << map.upper_bound(4)->first << "\t" << map.upper_bound(4)->second << "\t" << RED << ft_map.upper_bound(4)->first << "\t" << ft_map.upper_bound(4)->second << RESET << std::endl;
	}
	if (map.upper_bound(8)->first == ft_map.upper_bound(8)->first && map.upper_bound(8)->second == ft_map.upper_bound(8)->second)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << map.upper_bound(8)->first << "\t" << map.upper_bound(8)->second << "\t" << RED << ft_map.upper_bound(8)->first << "\t" << ft_map.upper_bound(8)->second << RESET << std::endl;
	}

	std::cout << "*Check equal range*\n";
	std::pair<std::map<int,std::string>::iterator,std::map<int,std::string>::iterator> ret;
	std::pair<ft::map<int,std::string>::iterator,ft::map<int,std::string>::iterator> ft_ret;

	ret = map.equal_range(7);
	ft_ret = ft_map.equal_range(7);

	if (ret.first->first == ft_ret.first->first && ret.first->second == ft_ret.first->second && ret.second->first == ft_ret.second->first && ret.second->second == ft_ret.second->second)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	std::cout << "*Check operator==*\n";

	std::map<int,std::string> test1;
	std::map<int,std::string> test2;
	ft::map<int,std::string> ft_test1;
	ft::map<int,std::string> ft_test2;

	test1.insert(std::pair<int,std::string>(0, "a"));
	test1.insert(std::pair<int,std::string>(1, "a"));
	test1.insert(std::pair<int,std::string>(2, "a"));
	test1.insert(std::pair<int,std::string>(3, "a"));
	test1.insert(std::pair<int,std::string>(4, "a"));

	ft_test1.insert(std::pair<int,std::string>(0, "a"));
	ft_test1.insert(std::pair<int,std::string>(1, "a"));
	ft_test1.insert(std::pair<int,std::string>(2, "a"));
	ft_test1.insert(std::pair<int,std::string>(3, "a"));
	ft_test1.insert(std::pair<int,std::string>(4, "a"));

	test2.insert(std::pair<int,std::string>(2, "a"));
	test2.insert(std::pair<int,std::string>(1, "a"));
	test2.insert(std::pair<int,std::string>(3, "a"));
	test2.insert(std::pair<int,std::string>(0, "a"));
	test2.insert(std::pair<int,std::string>(4, "a"));

	ft_test2.insert(std::pair<int,std::string>(2, "a"));
	ft_test2.insert(std::pair<int,std::string>(1, "a"));
	ft_test2.insert(std::pair<int,std::string>(3, "a"));
	ft_test2.insert(std::pair<int,std::string>(0, "a"));
	ft_test2.insert(std::pair<int,std::string>(4, "a"));

	if ((test1 == test2) == (ft_test1 == ft_test2))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	if ((test1 == map) == (ft_test1 == ft_map))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	std::cout << "*Check operator!=*\n";

	if ((test1 != test2) == (ft_test1 != ft_test2))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	if ((test1 != map) == (ft_test1 != ft_map))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	std::cout << "*Check operator<*\n";

	if ((test1 < test2) == (ft_test1 < ft_test2))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	if ((test1 < map) == (ft_test1 < ft_map))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	std::cout << "*Check operator>*\n";

	if ((test1 > test2) == (ft_test1 > ft_test2))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	if ((test1 > map) == (ft_test1 > ft_map))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	std::cout << "*Check operator>=*\n";

	if ((test1 >= test2) == (ft_test1 >= ft_test2))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	if ((test1 >= map) == (ft_test1 >= ft_map))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	std::cout << "*Check operator<=*\n";

	if ((test1 <= test2) == (ft_test1 <= ft_test2))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	if ((test1 <= map) == (ft_test1 <= ft_map))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

}	