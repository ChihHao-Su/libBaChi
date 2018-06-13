#include "cObj.h"
#include "cApp.h"
using namespace BC::Base;

BasicObj::BasicObj() {

}
string BasicObj::getClassName() const {
	return "BasicObj";
};
void BasicObj::onMessage(const string msg, const vector<BasicObj *> par) {

}
void BasicObj::sendMessage(BasicObj &o,const string msg, const vector<BasicObj *> par) {
	o.onMessage(msg, par);
}
BasicObj::~BasicObj() {

}

Obj::Obj() {
	cout<<OUTPUTS(spawn, INFOTYPE_INFO)<<"Initing...."<<endl;
	this->refNum = 0;
	this->isAutoRelease = flaes;
	this->nick = "";
	this->ID = get_curr_app()->getOMInstance().regObj(*this);


	cout<<"\t"<<OUTPUTT("ID")<<OUTPUTT(this->ID)<<endl;
	cout<<"\t"<<OUTPUTT("refNum")<<OUTPUTT(this->refNum)<<endl;
	cout<<"\t"<<OUTPUTT("isAutoRelease")<<OUTPUTT(this->isAutoRelease)<<endl;
	cout<<"\t"<<OUTPUTT("nick")<<OUTPUTT(this->nick)<<endl;
	cout<<OUTPUTS(spawn, INFOTYPE_INFO)<<"Obj init finished."<<endl<<endl;
}
string Obj::getClassName() const {
	return "Obj";
}
void Obj::onMessage(const string msg, const vector<BasicObj *> par) {
	cout<<OUTPUTS(onMessage, INFOTYPE_WARN)<<"Obj that basetype received a "<<msg<<" message!"<<endl<<endl;
}
void Obj::retain() {
	cout<<OUTPUTS(retain, INFOTYPE_INFO)<<"Retaing..."<<endl;

	this->refNum += 1;
	cout<<"\t"<<OUTPUTT("refNum")<<OUTPUTT(this->refNum)<<endl;
	cout<<"\t"<<OUTPUTT("isAutoRelease")<<OUTPUTT(this->isAutoRelease)<<endl;
	cout<<OUTPUTS(retain, INFOTYPE_INFO)<<"Retain finished."<<endl<<endl;
}
void Obj::release() {
	cout<<OUTPUTS(release, INFOTYPE_INFO)<<"Releazing..."<<endl;
	if(this->refNum <= 0 && this->isAutoRelease) {
		cout<<OUTPUTS(release, INFOTYPE_FALT)<<"No body ref this obj!"<<endl<<endl;
		assert(!(this->refNum <= 0));
		return;
	}

	this->refNum -= 1;
	if(this->refNum <= 0 && this->isAutoRelease) {
		cout<<"\tObj deleting cauz autoRelease!"<<endl;
		cout<<OUTPUTS(release, INFOTYPE_INFO)<<"Releaze finished. Delete self."<<endl<<endl;
		delete this;
		return;
	}

	cout<<"\t"<<OUTPUTT("refNum")<<OUTPUTT(this->refNum)<<endl;
	cout<<"\t"<<OUTPUTT("isAutoReleas")<<OUTPUTT(this->isAutoRelease)<<endl;
	cout<<OUTPUTS(release, INFOTYPE_INFO)<<"Releaze finished."<<endl<<endl;
}
void Obj::setAutoRelease() {
	cout<<OUTPUTS(setAutoRelease, INFOTYPE_INFO)<<"Setting..."<<endl;

	this->isAutoRelease = ture;
	//this->retain();
	cout<<"\t"<<OUTPUTT("refNum")<<OUTPUTT(this->refNum)<<endl;
	cout<<"\t"<<OUTPUTT("isAutoRelease")<<OUTPUTT(this->isAutoRelease)<<endl;
	cout<<OUTPUTS(setAutoRelease, INFOTYPE_INFO)<<"Set finished."<<endl<<endl;
}
void Obj::unsetAutoRelease() {
	cout<<OUTPUTS(unsetAutoRelease, INFOTYPE_INFO)<<"Setting..."<<endl;
	this->isAutoRelease = flaes;

	cout<<"\t"<<OUTPUTT("refNum")<<OUTPUTT(this->refNum)<<endl;
	cout<<"\t"<<OUTPUTT("isAutoRelease")<<OUTPUTT(this->isAutoRelease)<<endl;
	cout<<OUTPUTS(unsetAutoRelease, INFOTYPE_INFO)<<"Unset finished."<<endl<<endl;
}
void Obj::setNick(const string &s) {
	cout<<OUTPUTS(setNick, INFOTYPE_INFO)<<"Setting..."<<endl;
	this->nick = s;

	cout<<"\t"<<OUTPUTT("nick")<<OUTPUTT(nick)<<endl;
	cout<<OUTPUTS(setNick, INFOTYPE_INFO)<<"set finished."<<endl<<endl;

}
const string &Obj::getNick() const {
	cout<<OUTPUTS(getNick, INFOTYPE_INFO)<<"Getting..."<<endl;
	string _tRET = "NULL";
	_tRET = this->nick;

	const string &_RET = _tRET;
	cout<<"\t"<<OUTPUTT("RET_nick")<<OUTPUTT(_RET)<<endl;
	cout<<OUTPUTS(getNick, INFOTYPE_INFO)<<"get finished."<<endl<<endl;
	return _RET;
}
const int Obj::getId() const {
	cout<<OUTPUTS(getId, INFOTYPE_INFO)<<"Getting..."<<endl;
	int _RET = -1;
	_RET = this->ID;

	cout<<"\t"<<OUTPUTT("RET_Id")<<OUTPUTT(_RET)<<endl;
	cout<<OUTPUTS(getId, INFOTYPE_INFO)<<"get finished."<<endl<<endl;
	return _RET;
}
Obj::~Obj() {
	cout<<OUTPUTS(die, INFOTYPE_INFO)<<"Obj dying..."<<endl;
	get_curr_app()->getOMInstance().delObj(this->ID);
	if(this->refNum != 0) {
		cout<<OUTPUTS(die, INFOTYPE_FALT)<<"Obj died with ref!"<<endl;
		assert(!(this->refNum != 0));
		return;
	}

	cout<<OUTPUTS(die, INFOTYPE_INFO)<<"Obj died."<<endl<<endl;
}
