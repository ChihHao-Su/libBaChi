#include "cString.h"
using namespace BC::Var;

String::String() {
	this->init();
}
String::String(const char *cp) {
	this->init();
	this->ass(string(cp));
}
String::String(const String &v) {
	this->init();
	this->ass(v);
}
String::String(const BaseVar &s) {
	this->init();
	this->ass(s);
}
void String::init() {
	//Do nothing.

}
string String::getClassName() const {
	return "String";
}
string String::toString() const {
	return this->data;
}
const string &String::getData() const {
	return this->data;
}
void String::add(const BaseVar &s) {
	this->data += s.toString();
}
void String::add(const String &v) {
	this->data += v.getData();
}
void String::ass(const BaseVar &s) {
	this->data = s.toString();
}
void String::ass(const String &v) {
	this->data = v.getData();
}
void String::ass(const string &s) {
	this->data = s;
}
void String::ass(const char *cp) {
	this->data = cp;
}
bool String::isEqal(const BaseVar &s) const {
	return this->isEqal(s.toString().c_str());
}
bool String::isEqal(const String &v) const {
	return (v.getData() == this->data);
}
void String::trim() {
	if (!this->data.empty()) {
		this->data.erase(0,this->data.find_first_not_of(" "));
		this->data.erase(this->data.find_last_not_of(" ") + 1);

	}
}
int String::replaceAll(const String &vOld, const String &vNew) {
	int _RET = 0;
	while(true) {
		int pos=0;
		if((pos=this->data.find(vOld.getData(),0))!=string::npos) {
			this->data.replace(pos,vOld.getData().length(),vNew.getData());
			_RET++;
		} else
			break;
	}

	return _RET;
}
String String::launchc(const String &v, const BasicVector<String> &vv) {
	this->ass(v);
	for(int i=0; i<=vv.getSize()-1; i++) {
		this->replaceAll((string("%")+to_string(i)).c_str(), vv[i]);
	}

	return this;
}
String::~String() {

}
