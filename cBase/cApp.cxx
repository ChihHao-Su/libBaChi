#include "cApp.h"
using namespace BC::Base;

BC::Base::App::App(string name) {
	this->setName(name);
}
ObjManager& BC::Base::App::getOMInstance() {
	return this->OM;

}
BasicObj& BC::Base::App::getNOInstance() {
	return this->nanObj;
}
void BC::Base::App::setName(string name) {
	this->name = name;
}
string BC::Base::App::getName() const {
	return this->name;
}
BC::Base::App::~App() {

}
