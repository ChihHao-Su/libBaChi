#include "cObjManager.h"
using namespace BC::Base;
#define DBG_OBJMANAGER_SHOW_ALL_OBJ(__v) \
	cout<<"\tObj in vec info>>>>"<<endl; \
	cout<<"\t|ID\t\t|(Addr)"<<endl; \
	map<int, Obj *>::iterator iter; \
	for(iter = __v.begin(); iter!=__v.end(); iter++){ \
		cout<<"\t"<<iter->first<<"\t\t"<<iter->second<<endl; \
	} \
	cout<<"\t<<<<<<<<<<<<<<<<<<<"<<endl;


ObjManager::ObjManager() {
	cout<<OUTPUTS(spawn, INFOTYPE_INFO)<<"Initing...."<<endl;
	this->next_ID = 0;

	cout<<"\t"<<OUTPUTT("next_ID")<<this->next_ID<<endl;
	cout<<OUTPUTS(spawn, INFOTYPE_INFO)<<"Initing finished."<<endl<<endl;
}
string ObjManager::getClassName() const {
	return "ObjManager";
}
int ObjManager::regObj(Obj& obj) {
	int _RET = 0;
	cout<<OUTPUTS(regObj, INFOTYPE_INFO)<<"Reging...."<<endl;
	if(this->objPool.count(this->next_ID) != 0) {
		cout<<OUTPUTS(regObj, INFOTYPE_FALT)<<"next_ID compl with id of obj in manager!"<<endl;
		assert(!(this->objPool.count(this->next_ID) != 0));
		return 0;
	}
	this->objPool.insert(pair<int, Obj *>(this->next_ID, &obj));
	_RET = this->next_ID;
	this->next_ID += 1;

	cout<<"\t"<<OUTPUTT("next_ID")<<this->next_ID<<endl;
	DBG_OBJMANAGER_SHOW_ALL_OBJ(this->objPool);
	cout<<OUTPUTS(regObj, INFOTYPE_INFO)<<"Reg finished."<<endl<<endl;
	return _RET;
}
void ObjManager::delObj(int ID) {
	cout<<OUTPUTS(delObj, INFOTYPE_INFO)<<"Deling...."<<endl;
	if(this->objPool.count(ID) == 0) {
		cout<<OUTPUTS(delObj, INFOTYPE_WARN)<<"Have no obj that ID "<<ID<<endl<<endl;
		throw 1;
		return;
	}
	this->objPool.erase(ID);

	cout<<"\t"<<OUTPUTT("next_ID")<<this->next_ID<<endl;
	DBG_OBJMANAGER_SHOW_ALL_OBJ(this->objPool);
	cout<<OUTPUTS(delObj, INFOTYPE_INFO)<<"Del finished."<<endl<<endl;
}
ObjManager::~ObjManager() {
	cout<<OUTPUTS(die, INFOTYPE_INFO)<<"Dying...."<<endl;


	cout<<OUTPUTS(spawn, INFOTYPE_INFO)<<"Die finished...."<<endl<<endl;
}
