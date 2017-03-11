#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <sys/stat.h>

void get_comand(void);
std::vector <std::string> parsing (std::string inputLine);
bool exists (std::string);
