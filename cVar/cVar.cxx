#include "cVar.h"
using namespace BC::Var;

BaseVar::BaseVar() {
	cout<<OUTPUTS(spawn, INFOTYPE_INFO)<<"BaseVar Initing...."<<endl;

	cout<<OUTPUTS(spawn, INFOTYPE_INFO)<<"BaseVar Init finished."<<endl<<endl;
}
string BaseVar::getClassName() const {
	return "BaseVar";
}
void BaseVar::onMessage(const string msg, const vector<BasicObj *> par) {
	cout<<OUTPUTS(onMessage, INFOTYPE_WARN)<<"Var that basetype received a "<<msg<<" message!"<<endl<<endl;
}
BaseVar::~BaseVar() {
	cout<<OUTPUTS(die, INFOTYPE_INFO)<<"BaseVar Dying...."<<endl;

	cout<<OUTPUTS(die, INFOTYPE_INFO)<<"BaseVar Dying."<<endl<<endl;
}

