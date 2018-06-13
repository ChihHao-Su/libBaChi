#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include "cObj/Obj.h"
#include "cObj/Baash_define.h"
using namespace std;

#define DBG___VECTOR_SHOW_ALL_OBJ(__v) \
	int mi_vec_sao = 0; \
	cout<<"\tObj in vec info>>>>"<<endl; \
	cout<<"\t|(Posi)\t\t|Addr"<<endl; \
	for(Obj* o : __v){ \
		cout<<"\t"<<mi_vec_sao<<"\t\t"<<o<<"\t\t"<<endl; \
		mi_vec_sao += 1; \
	} \
	cout<<"\t<<<<<<<<<<<<<<<<<<<"<<endl; \


namespace BC
{

class __Vector
{
protected:
	__Vector()
	{
		cout<<OUTPUTS(spawn, INFOTYPE_INFO)<<"__Vector Initing...."<<endl;
		this->size = 0;

		cout<<"\t"<<OUTPUTT("size")<<OUTPUTT(this->size)<<endl;
		cout<<OUTPUTS(spawn, INFOTYPE_INFO)<<"__Vector init finished."<<endl<<endl;
	}
	void setSize(int size){
		cout<<OUTPUTS(setSize,INFOTYPE_INFO)<<"Setting size...."<<endl;
		if(size<=0){
			cout<<OUTPUTS(setSize,INFOTYPE_FALT)<<"Usr try to set size to 0!"<<endl<<endl;
			assert(!(size<=0));
			return;
		}
		if(size<this->size){
			cout<<OUTPUTS(setSize,INFOTYPE_FALT)<<"Usr try to set size that little that curr_size!"<<endl<<endl;
			assert(!(size<this->size));
			return;
		}

		this->size = size;

		cout<<"\t"<<OUTPUTT("size")<<OUTPUTT(this->size)<<endl;
		cout<<OUTPUTS(setSize, INFOTYPE_INFO)<<"setSize finished."<<endl<<endl;
	}
	int getSize(){
		cout<<OUTPUTS(getSize,INFOTYPE_INFO)<<"Getting size...."<<endl;
		int _RET = this->size;

		cout<<"\t"<<OUTPUTT("RET")<<OUTPUTT(_RET)<<endl;
		cout<<OUTPUTS(getSize,INFOTYPE_INFO)<<"Finished."<<endl<<endl;
		return _RET;
	}
	void pushBack(Obj &o){
		cout<<OUTPUTS(pushBack,INFOTYPE_INFO)<<"Adding obj...."<<endl<<endl;
		if(&o == nullptr){
			cout<<OUTPUTS(pushBack, INFOTYPE_FALT)<<"Pushing nullptr obj ref!"<<endl<<endl;

			assert(!(&o == nullptr));
		}
		if(this->data.size()+1 > this->size){
			cout<<OUTPUTS(pushBack, INFOTYPE_WARN)<<"__Vec is full!"<<endl<<endl;
			throw 452;
			return;
		}

		this->data.push_back(&o);
		o.retain();
		this->size = this->data.size();

		cout<<"\tsize\t\t"<<this->size<<endl;
		cout<<"\tobj num\t\t"<<this->data.size()<<endl;
		DBG___VECTOR_SHOW_ALL_OBJ(this->data);
		cout<<OUTPUTS(pushBack,INFOTYPE_INFO)<<"Finished."<<endl<<endl;

	}

	Obj& get(const int num){
		cout<<OUTPUTS(get,INFOTYPE_INFO)<<"Getting obj..."<<endl;
		if(num>this->size || num<0){
			cout<<OUTPUTS(get,INFOTYPE_FALT)<<"num little that 0 or big than size!"<<endl<<endl;
			assert(!(num>this->size || num<0));
		}
		Obj &_RET = *(this->data[num]);

		cout<<"\t"<<OUTPUTT("RET")<<OUTPUTT(&_RET)<<endl;
		cout<<OUTPUTS(get,INFOTYPE_INFO)<<"Getting finished."<<endl<<endl;
		return _RET;
	}

	void del(const int num){
		cout<<OUTPUTS(del,INFOTYPE_INFO)<<"Deling obj...."<<endl<<endl;
		if(num>this->size || num<0){
			cout<<OUTPUTS(del,INFOTYPE_FALT)<<"num little that 0 or big than size!"<<endl<<endl;
			assert(!(num>this->size || num<0));
		}
		vector<Obj *>::iterator iter = this->data.begin()+num;
		this->data.erase(iter);

		cout<<OUTPUTS(del,INFOTYPE_INFO)<<"Del finished."<<endl<<endl;
	}

	void delById(const int Id){
		cout<<OUTPUTS(delById,INFOTYPE_INFO)<<"DelByIding obj...."<<endl;
		for(vector<Obj *>::iterator it=this->data.begin(); it!=this->data.end();){
			if((*it)->getId() == Id){
				data.erase(it);
				cout<<"\tFound "<<Id<<"!"<<endl;
			}else{
				it++;
			}
		}

		cout<<"\t"<<OUTPUTT("size")<<OUTPUTT(this->size)<<endl;
		cout<<"\t"<<OUTPUTT("obj num")<<OUTPUTT(data.size())<<endl;
		DBG___VECTOR_SHOW_ALL_OBJ(this->data);
		cout<<OUTPUTS(delById,INFOTYPE_INFO)<<"DelById finished."<<endl;
	}

	bool isContain(const int objId){
		cout<<OUTPUTS(isContain,INFOTYPE_INFO)<<"Find obj...."<<endl;
		bool _RET = false;
		for(int i=0; i<=this->data.size()-1; i++){
			if(this->data[i]->getId() == objId){
				_RET = true;
			}
		}

		cout<<'\t'<<OUTPUTT("_RET")<<OUTPUTT(_RET)<<endl;
		cout<<OUTPUTS(isContain,INFOTYPE_INFO)<<"Find FInished.."<<endl<<endl;
		return _RET;
	}

	string getClassName() const{
		return "__Vector";
	}
	~__Vector()
	{

	}
private:
	string nick;
	int size;
	vector<Obj *> data;
};

template <typename T>		//no msg output
class Vector : public __Vector
{
public:
	Vector(int size){
		__Vector::setSize(size);
	}

	T& operator [](const int num){
		if(data[num] == nullptr){
			assert(!(data[num] == nullptr));
		}
		return (T&)__Vector::get(num);
	}

	void pushBack(Obj &o){
		__Vector::pushBack(o);
	}

	void remove(const int num){
		__Vector::del(num);
	}

	void removeById(const int Id){
		__Vector::delById(Id);
	}

	int getSize(){
		return __Vector::getSize();
	}

	bool isContain(const int objId){
		return __Vector::isContain(objId);
	}

	~Vector(){

	}

};
}
