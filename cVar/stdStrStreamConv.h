#pragma once
#include <sstream>
#include <string>
using namespace std;

template <class Type>
Type stdStrToType(const string& str) {
	stringstream iss(str);
	Type num;
	iss >> num;
	return num;
}

template <class Type>
string typeToStdStr(const Type& i) {
	return to_string(i);
}
