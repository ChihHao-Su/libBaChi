#include "cVec.h"
using namespace BC::Base;

VectorLike::VectorLike() {
	cout<<OUTPUTS(spawn, INFOTYPE_INFO)<<"VectorLike Initing...."<<endl;

	cout<<OUTPUTS(spawn, INFOTYPE_INFO)<<"VectorLike Init finished."<<endl<<endl;
}
string VectorLike::getClassName() const {
	return "VectorLike";
}
void VectorLike::onMessage(const string msg, const vector<BasicObj *> par) {
	cout<<OUTPUTS(onMessage, INFOTYPE_WARN)<<"Vec that basetype received a "<<msg<<" message!"<<endl<<endl;
}
VectorLike::~VectorLike() {
	cout<<OUTPUTS(die, INFOTYPE_INFO)<<"VectorLike Dying...."<<endl;

	cout<<OUTPUTS(die, INFOTYPE_INFO)<<"VectorLike Died."<<endl<<endl;
}

__BasicVector::__BasicVector() {
	cout<<OUTPUTS(spawn, INFOTYPE_INFO)<<"__BasicVector Initing...."<<endl;
    this->size = 0;

	cout<<"\t"<<OUTPUTT("size")<<OUTPUTT(this->size)<<endl;
	cout<<OUTPUTS(spawn, INFOTYPE_INFO)<<"__BasicVector Init finished."<<endl<<endl;
}
void __BasicVector::setSize(const int size) {
	cout<<OUTPUTS(setSize,INFOTYPE_INFO)<<"Setting size...."<<endl;
	if(size<=0) {
		cout<<OUTPUTS(setSize,INFOTYPE_FALT)<<"Usr try to set size to 0!"<<endl<<endl;
		assert(!(size<=0));
		return;
	}
	if(size<this->size) {
		cout<<OUTPUTS(setSize,INFOTYPE_FALT)<<"Usr try to set size that little that curr_size!"<<endl<<endl;
		assert(!(size<this->size));
		return;
	}

	this->size = size;

	cout<<"\t"<<OUTPUTT("size")<<OUTPUTT(this->size)<<endl;
	cout<<OUTPUTS(setSize, INFOTYPE_INFO)<<"setSize finished."<<endl<<endl;
}
int __BasicVector::getSize() const {
	cout<<OUTPUTS(getSize,INFOTYPE_INFO)<<"Getting size...."<<endl;
	int _RET = this->size;

	cout<<"\t"<<OUTPUTT("RET")<<OUTPUTT(_RET)<<endl;
	cout<<OUTPUTS(getSize,INFOTYPE_INFO)<<"Finished."<<endl<<endl;
	return _RET;
}
int __BasicVector::getObjNum() const {
	cout<<OUTPUTS(getObjNum,INFOTYPE_INFO)<<"Getting objNum...."<<endl;
	int _RET = this->data.size();

	cout<<"\t"<<OUTPUTT("RET")<<OUTPUTT(_RET)<<endl;
	cout<<OUTPUTS(getObjNum,INFOTYPE_INFO)<<"Finished."<<endl<<endl;
	return _RET;
}
void __BasicVector::pushBack(BasicObj &o){
	cout<<OUTPUTS(pushBack,INFOTYPE_INFO)<<"Adding obj...."<<endl;
	if(&o == nullptr) {
		cout<<OUTPUTS(pushBack, INFOTYPE_FALT)<<"Pushing nullptr obj ref!"<<endl<<endl;

		assert(!(&o == nullptr));
	}
	if(this->data.size()+1 > this->size) {
		cout<<OUTPUTS(pushBack, INFOTYPE_WARN)<<"__Vec is full!"<<endl<<endl;
		throw 452;
		return;
	}
	this->data.push_back(&o);

	cout<<"\tsize\t\t"<<this->size<<endl;
	cout<<"\tobj num\t\t"<<this->data.size()<<endl;
	DBG___VECTOR_SHOW_ALL_OBJ(this->data);
	cout<<OUTPUTS(pushBack,INFOTYPE_INFO)<<"Finished."<<endl<<endl;
}
BasicObj& __BasicVector::bGet(const int num) const {
	cout<<OUTPUTS(bGet,INFOTYPE_INFO)<<"Getting obj..."<<endl;
	if(num>this->data.size() || num<0) {
		cout<<OUTPUTS(get,INFOTYPE_FALT)<<"num little that 0 or big than objnum!"<<endl<<endl;
		assert(!(num>this->size || num<0));
	}
	BasicObj &_RET = *(this->data[num]);

	cout<<"\t"<<OUTPUTT("RET")<<OUTPUTT(&_RET)<<endl;
	cout<<OUTPUTS(bGet,INFOTYPE_INFO)<<"Getting finished."<<endl<<endl;
	return _RET;
}
void __BasicVector::del(const int num) {
	cout<<OUTPUTS(del,INFOTYPE_INFO)<<"Deling obj...."<<endl;
	if(num>this->data.size() || num<0) {
		cout<<OUTPUTS(del,INFOTYPE_FALT)<<"num little that 0 or big than objnum!"<<endl<<endl;
		assert(!(num>this->data.size() || num<0));
	}
	vector<BasicObj *>::iterator iter = this->data.begin()+num;
	this->data.erase(iter);

	cout<<"\t"<<OUTPUTT("size")<<OUTPUTT(this->size)<<endl;
	cout<<"\t"<<OUTPUTT("obj num")<<OUTPUTT(data.size())<<endl;
	DBG___VECTOR_SHOW_ALL_OBJ(this->data);
	cout<<OUTPUTS(del,INFOTYPE_INFO)<<"Del finished."<<endl<<endl;
}
string __BasicVector::getClassName() const {
	return "__BasicVector";
}

__BasicVector::~__BasicVector() {
	cout<<OUTPUTS(die, INFOTYPE_INFO)<<"__BasicVector Dying...."<<endl;

	cout<<OUTPUTS(die, INFOTYPE_INFO)<<"__BasicVector died."<<endl<<endl;
}

__Vector::__Vector() {
	cout<<OUTPUTS(spawn, INFOTYPE_INFO)<<"__Vector Initing...."<<endl;
	this->size = 0;

	cout<<"\t"<<OUTPUTT("size")<<OUTPUTT(this->size)<<endl;
	cout<<OUTPUTS(spawn, INFOTYPE_INFO)<<"__Vector init finished."<<endl<<endl;
}
void __Vector::pushBack(Obj &o) {
	cout<<OUTPUTS(pushBack,INFOTYPE_INFO)<<"Adding obj...."<<endl;
	if(&o == nullptr) {
		cout<<OUTPUTS(pushBack, INFOTYPE_FALT)<<"Pushing nullptr obj ref!"<<endl<<endl;

		assert(!(&o == nullptr));
	}
	if(this->data.size()+1 > this->size) {
		cout<<OUTPUTS(pushBack, INFOTYPE_WARN)<<"__Vec is full!"<<endl<<endl;
		throw 452;
		return;
	}
	o.retain();
	this->data.push_back(&o);

	cout<<"\tsize\t\t"<<this->size<<endl;
	cout<<"\tobj num\t\t"<<this->data.size()<<endl;
	DBG___VECTOR_SHOW_ALL_OBJ(this->data);
	cout<<OUTPUTS(pushBack,INFOTYPE_INFO)<<"Finished."<<endl<<endl;
}
Obj&  __Vector::get(const int num) const {
	cout<<OUTPUTS(get,INFOTYPE_INFO)<<"Getting obj..."<<endl;
	if(num>this->data.size() || num<0) {
		cout<<OUTPUTS(get,INFOTYPE_FALT)<<"num little that 0 or big than objnum!"<<endl<<endl;
		assert(!(num>this->size || num<0));
	}
	Obj &_RET = *((Obj *)this->data[num]);


	cout<<"\t"<<OUTPUTT("RET")<<OUTPUTT(&_RET)<<endl;
	cout<<OUTPUTS(get,INFOTYPE_INFO)<<"Getting finished."<<endl<<endl;
	return _RET;
}
BasicObj& __Vector::bGet(const int num) const {
	cout<<OUTPUTS(bGet,INFOTYPE_INFO)<<"Getting obj..."<<endl;
	if(num>this->data.size() || num<0) {
		cout<<OUTPUTS(get,INFOTYPE_FALT)<<"num little that 0 or big than objnum!"<<endl<<endl;
		assert(!(num>this->size || num<0));
	}
	BasicObj &_RET = *(this->data[num]);

	cout<<"\t"<<OUTPUTT("RET")<<OUTPUTT(&_RET)<<endl;
	cout<<OUTPUTS(bGet,INFOTYPE_INFO)<<"Getting finished."<<endl<<endl;
	return _RET;
}
void __Vector::del(const int num) {
	cout<<OUTPUTS(del,INFOTYPE_INFO)<<"Deling obj...."<<endl;
	if(num>this->data.size() || num<0) {
		cout<<OUTPUTS(del,INFOTYPE_FALT)<<"num little that 0 or big than objnum!"<<endl<<endl;
		assert(!(num>this->data.size() || num<0));
	}
	((Obj *)this->data[num])->release();
	vector<BasicObj *>::iterator iter = this->data.begin()+num;
	this->data.erase(iter);

	cout<<"\t"<<OUTPUTT("size")<<OUTPUTT(this->size)<<endl;
	cout<<"\t"<<OUTPUTT("obj num")<<OUTPUTT(data.size())<<endl;
	DBG___VECTOR_SHOW_ALL_OBJ(this->data);
	cout<<OUTPUTS(del,INFOTYPE_INFO)<<"Del finished."<<endl<<endl;
}
void __Vector::delById(const int Id) {
	cout<<OUTPUTS(delById,INFOTYPE_INFO)<<"DelByIding obj...."<<endl;
	int i = 0;
	for(const BasicObj *bp : this->data) {
		Obj *p = (Obj *)bp;
		if(p->getId() == Id) {
			cout<<"\tFound "<<Id<<"!"<<endl;
			p->release();
			this->del(i);
		}
		i++;
	}

	cout<<"\t"<<OUTPUTT("size")<<OUTPUTT(this->size)<<endl;
	cout<<"\t"<<OUTPUTT("obj num")<<OUTPUTT(data.size())<<endl;
	DBG___VECTOR_SHOW_ALL_OBJ(this->data);
	cout<<OUTPUTS(delById,INFOTYPE_INFO)<<"DelById finished."<<endl;
}
bool __Vector::isContain(const int objId) const {
	cout<<OUTPUTS(isContain,INFOTYPE_INFO)<<"Find obj...."<<endl;
	bool _RET = false;
	for(int i=0; i<=this->data.size()-1; i++) {
		if(((Obj *)this->data[i])->getId() == objId) {
			_RET = true;
		}
	}

	cout<<'\t'<<OUTPUTT("_RET")<<OUTPUTT(_RET)<<endl;
	cout<<OUTPUTS(isContain,INFOTYPE_INFO)<<"Find FInished.."<<endl<<endl;
	return _RET;
}
string __Vector::getClassName() const {
	return "__Vector";
}
__Vector::~__Vector() {
	cout<<OUTPUTS(die, INFOTYPE_INFO)<<"__Vector Dying...."<<endl;
	int tON = this->getObjNum()-1;
	for(int i=0; i<=tON; i++) {
		this->del(0);
	}

	DBG___VECTOR_SHOW_ALL_OBJ(this->data);
	cout<<OUTPUTS(die, INFOTYPE_INFO)<<"__Vector Died."<<endl<<endl;
}
