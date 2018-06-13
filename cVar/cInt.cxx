#include "cInt.h"
using namespace BC::Var;

Num::Num() {
	this->init();
}
Num::Num(const int &i) {
	this->init();
}
Num::Num(const double &d) {
	this->init();
}
Num::Num(const Num &v) {
	this->init();
}
Num::Num(const BaseVar &s) {
	this->init();
}
void Num::init() {
	this->data = 0;
}
string Num::getClassName() const {
	return "Num";
}
string Num::toString() const {
	return typeToStdStr<double>(this->data);
}
const double& Num::getData() const {
	return this->data;
}
void Num::add(const BaseVar &s) {
	this->data += stdStrToType<double>(s.toString());
}
void Num::add(const Num &s) {
	this->data += s.getData();
}
void Num::ass(const BaseVar &s) {
	this->data = stdStrToType<double>(s.toString());
}
void Num::ass(const Num &s) {
	this->data = s.getData();
}
void Num::ass(const int i) {
	this->data = i;
}
void Num::ass(const double d) {
	this->data = d;
}
bool Num::isEqal(const BaseVar &s) const {
	return this->data == stdStrToType<double>(s.toString());
}
bool Num::isEqal(const Num &v) const {
	return this->data == v.getData();
}
Num Num::operator -() const {
	Num _RET(-(this->data));

	return _RET;
}
Num Num::operator +(const Num &v) const {
	Num _RET(*this);
	_RET.add(v);

	return _RET;
}
Num Num::operator -(const Num &v) const {
	Num _RET(*this);
	_RET.add(-v);

	return _RET;
}
Num::~Num() {

}
