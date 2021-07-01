#ifndef myClass_H
#define myClass_H

#include <iostream>

class myClass
{
private:
	myClass();
	myClass(const myClass &arg);
	myClass &operator=(const myClass &arg);
public:
	int value;
	int id;
	static int inst_id;
	myClass(int val) : value(val), id(inst_id) {
		inst_id++;
		std::cout << "id: " << id << "\t" << "value: " << value << "\t" << "created\n";
	}
	~myClass(){
		std::cout << "id: " << id << "\t" << "value: " << value << "\t" << "destoyed\n";
	}
};

#endif