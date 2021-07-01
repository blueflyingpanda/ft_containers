#include "test.hpp"

void test_set(){
	std::set<std::string> m;
	ft::set<std::string> ft_m;

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

	std::pair<std::set<std::string>::iterator, bool>  p = m.insert("abc");
	std::pair<ft::set<std::string>::iterator, bool> ft_p = ft_m.insert("abc");

	std::cout << "*Check insert return value (success)*\n";
	if (*(p.first) == *(ft_p.first))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << "value: " << *(p.first) << "\t" << "bool: " << std::boolalpha << p.second << std::endl;
		std::cout << RED << "value: " << *(ft_p.first) << "\t" << "bool: " << std::boolalpha << ft_p.second << std::endl;
	}

	p = m.insert("abc");
	ft_p = ft_m.insert("abc");

	std::cout << "*Check insert return value (fail)*\n";
	if (*(p.first) == *(ft_p.first))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << "value: " << *(p.first) << "\t" << "bool: " << std::boolalpha << p.second << std::endl;
		std::cout << RED << "value: " << *(ft_p.first) << "\t" << "bool: " << std::boolalpha << ft_p.second << std::endl;
	}

	p = m.insert("foo");
	p = m.insert("def");
	p = m.insert("xyz");
	p = m.insert("chebubu");
	p = m.insert("bar");
	ft_p = ft_m.insert("foo");
	ft_p = ft_m.insert("def");
	ft_p = ft_m.insert("xyz");
	ft_p = ft_m.insert("chebubu");
	ft_p = ft_m.insert("bar");

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
	std::set<std::string>::iterator it = m.begin();
	ft::set<std::string>::iterator ft_it = ft_m.begin();

	for (; it != m.end(); it++, ft_it++){
		if (*it != *ft_it)	
			std::cout << RED << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
		else
			std::cout << GREEN << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
	}

	std::cout << "*Check reverse iterator*\n";
	std::set<std::string>::reverse_iterator rit = m.rbegin();
	ft::set<std::string>::reverse_iterator ft_rit = ft_m.rbegin();

	for (; rit != m.rend(); rit++, ft_rit++){
		if (*rit != *ft_rit)	
			std::cout << RED << "value: " << std::setw(10) << *rit << std::setw(10) << "value: " << *ft_rit << RESET << std::endl;
		else
			std::cout << GREEN << "value: " << std::setw(10) << *rit << std::setw(10) << "value: " << *ft_rit << RESET << std::endl;
	}
	std::cout << "*Check from tail to head*\n";
	it = m.end();
	ft_it = ft_m.end();
	it--;
	ft_it--;
	for (; it != m.begin(); it--, ft_it--){
		if (*it != *ft_it)	
			std::cout << RED << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
		else
			std::cout << GREEN << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
	}

	std::cout << "*Check erase(iterator)*\n";
	m.erase(((--(--((m.end()))))));
	ft_m.erase(((--(--((ft_m.end()))))));
	it = m.begin();
	ft_it = ft_m.begin();
	for (; ft_it != ft_m.end(); it++, ft_it++){
		if (*it != *ft_it)	
			std::cout << RED << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
		else
			std::cout << GREEN << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
	}
	std::cout << "*Check erase(value)*\n";
	m.erase("chebubu");
	ft_m.erase("chebubu");
	it = m.begin();
	ft_it = ft_m.begin();
	for (; ft_it != ft_m.end(); it++, ft_it++){
		if (*it != *ft_it)	
			std::cout << RED << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
		else
			std::cout << GREEN << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
	}

	std::cout << "*Check erase(value not found)*\n";
	m.erase("chebubu");
	ft_m.erase("chebubu");
	it = m.begin();
	ft_it = ft_m.begin();
	for (; ft_it != ft_m.end(); it++, ft_it++){
		if (*it != *ft_it)	
			std::cout << RED << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
		else
			std::cout << GREEN << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
	}

	std::cout << "*Check erase(range)*\n";
	m.erase(--(--(--m.end())), --m.end());
	ft_m.erase(--(--(--ft_m.end())), --ft_m.end());
	it = m.begin();
	ft_it = ft_m.begin();
	for (; it != m.end(); it++, ft_it++){
		if (*it != *ft_it)	
			std::cout << RED << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
		else
			std::cout << GREEN << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
	}

	std::cout << "*Check swap*\n";
	std::set<std::string> s;
	ft::set<std::string> ft_s;
	
	s.insert("kuku");
	s.insert("nya");
	s.insert("meow");
	ft_s.insert("kuku");
	ft_s.insert("nya");
	ft_s.insert("meow");

	std::swap(m, s);
	ft::swap(ft_m, ft_s);

	it = m.begin();
	ft_it = ft_m.begin();
	for (; it != m.end(); it++, ft_it++){
		if (*it != *ft_it)	
			std::cout << RED << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
		else
			std::cout << GREEN << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
	}

	std::cout << "*Check swap (second container)*\n";

	it = s.begin();
	ft_it = ft_s.begin();
	for (; it != s.end(); it++, ft_it++){
		if (*it != *ft_it)	
			std::cout << RED << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
		else
			std::cout << GREEN << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
	}

	std::cout << "*Check copy contructor*\n";
	std::set<std::string> c(m);
	ft::set<std::string> ft_c(ft_m);

	it = c.begin();
	ft_it = ft_c.begin();
	for (; it != c.end(); it++, ft_it++){
		if (*it != *ft_it)	
			std::cout << RED << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
		else
			std::cout << GREEN << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
	}

	std::cout << "*Check insert with hint*\n";

	c.insert(c.begin(), "allo");
	ft_c.insert(ft_c.begin(), "allo");

	it = c.begin();
	ft_it = ft_c.begin();
	for (; it != c.end(); it++, ft_it++){
		if (*it != *ft_it)	
			std::cout << RED << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
		else
			std::cout << GREEN << "value: " << std::setw(10) << *it << std::setw(10) << "value: " << *ft_it << RESET << std::endl;
	}

	std::cout << "*Check find*\n";
	if (*(c.find("allo")) == *(ft_c.find("allo")))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << *(c.find("allo")) << '\t' << RED << *(ft_c.find("allo")) << RESET << std::endl;
	}

	std::cout << "*Check count*\n";

	if (c.count("allo") == ft_c.count("allo"))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << c.count("allo") << "\t" << RED << ft_c.count("allo") << RESET << std::endl;
	}
	if (c.count("allah") == ft_c.count("allah"))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << c.count("allah") << "\t" << RED << ft_c.count("allah") << RESET << std::endl;
	}

	std::cout << "*Check lower bound*\n";

	if (*(c.lower_bound("kuku")) == *(ft_c.lower_bound("kuku")))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << *(c.lower_bound("allo")) << "\t" << RED << *(ft_c.lower_bound("allo")) << RESET << std::endl;
	}

	std::cout << "*Check upper bound*\n";

	if (*(c.upper_bound("meow")) == *(ft_c.upper_bound("meow")))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << *(c.upper_bound("meow")) << "\t" << RED << *(ft_c.upper_bound("meow")) << RESET << std::endl;
	}

	std::cout << "*Check equal range*\n";

	if (*(c.equal_range("meow").first) == *(ft_c.equal_range("meow").first) && *(c.equal_range("meow").second) == *(ft_c.equal_range("meow").second))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
		std::cout << GREEN << *(c.equal_range("meow").first) << "\t" << RED << *(ft_c.equal_range("meow").first) << RESET << std::endl;
		std::cout << GREEN << *(c.equal_range("meow").second) << "\t" << RED << *(ft_c.equal_range("meow").second) << RESET << std::endl;
	}

	if ((s == m) == (ft_s == ft_m))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	if ((s == c) == (ft_s == ft_c))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	std::cout << "*Check operator!=*\n";

	if ((s != m) == (ft_s != ft_m))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	if ((s != c) == (ft_s != ft_c))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	std::cout << "*Check operator<*\n";

	if ((s < m) == (ft_s < ft_m))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	if ((s < c) == (ft_s < ft_c))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	std::cout << "*Check operator>*\n";

	if ((s > m) == (ft_s > ft_m))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	if ((s > c) == (ft_s > ft_c))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	std::cout << "*Check operator>=*\n";

	if ((s >= m) == (ft_s >= ft_m))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	if ((s >= c) == (ft_s >= ft_c))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	std::cout << "*Check operator<=*\n";

	if ((s <= m) == (ft_s <= ft_m))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}

	if ((s <= c) == (ft_s <= ft_c))
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
	{
		std::cout << RED << "KO" << std::endl;
	}
}