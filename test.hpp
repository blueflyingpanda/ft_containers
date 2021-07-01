#ifndef TEST_H
#define TEST_H

#define RED "\x1b[1;31m"
#define GREEN "\x1b[1;32m"
#define RESET   "\033[m"

#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "bonus_set.hpp"
#include <list>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>

#include <string>
#include <iostream>
#include <iomanip> 
#include <unistd.h>
#include <memory>
#include <limits>
#include <exception>

bool hasBigA(const std::string &s);
bool startsWithTheSameLetter(const std::string &n, const std::string &f);
bool caseInsensitiveFirstCharCompare(const std::string &f, const std::string &s);
bool luckyNumber(const std::string &n, const std::string &f);

void test_list();
void test_vector();
void test_map();
void test_stack();
void test_queue();
void test_set();

#endif