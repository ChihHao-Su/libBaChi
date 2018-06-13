#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include "cObj.h"
#include "Baash_define.h"
using namespace std;

#define DBG___VECTOR_SHOW_ALL_OBJ(__v) \
	int mi_vec_sao = 0; \
	cout<<"\tObj in vec info>>>>"<<endl; \
	cout<<"\t|(Posi)\t\t|Addr"<<endl; \
	for(const BasicObj* o : __v){ \
		cout<<"\t"<<mi_vec_sao<<"\t\t"<<o<<"\t\t"<<endl; \
		mi_vec_sao += 1; \
	} \
	cout<<"\t<<<<<<<<<<<<<<<<<<<"<<endl; \


namespace BC {
namespace Base {

interface VectorLike : public BasicObj {
public:
	virtual void setSize(const int size) = 0;
	virtual int getSize() const = 0;
	virtual int getObjNum() const = 0;
	virtual BasicObj& bGet(const int num) const = 0;
	virtual void del(const int num) = 0;
	virtual string getClassName() const;
	void onMessage(const string msg, const vector<BasicObj *> par) override;
	virtual ~VectorLike();


protected:
    VectorLike();
	string nick;
	int size;


};
class __BasicVector : protected VectorLike {
public:
	void setSize(const int size) override;
	int getSize() const override;
	int getObjNum() const override;
	virtual BasicObj& bGet(const int num) const override;
	void pushBack(BasicObj &o);
	virtual void del(const int num) override;
	virtual ~__BasicVector();


public:
	virtual string getClassName() const override;


protected:
    __BasicVector();
	vector<BasicObj *> data;
	int size;


};
template <typename T>		//no msg output
class BasicVector : public __BasicVector {
public:
	BasicVector(int size) {
		__BasicVector::setSize(size);
	}
	BasicVector(const std::initializer_list<T>& li) {
		__BasicVector::setSize(li.size());
		for(const T &p : li) {          //YES. COPY. IT IS NOT AN ERROR.
			this->pushBack(*new T(p));
		}
	}
	BasicVector(const std::initializer_list<T *>& li) {
		__BasicVector::setSize(li.size());
		for(T *p : li) {
			this->pushBack(p);
		}
	}
	/*BasicVector(const std::initializer_list<T *>& li) {
		__BasicVector::setSize(li.size());
		for(Obj *p : li) {
			this->pushBack(*p);
		}
	}*/

	T& operator [](const int num) const{
		if(data[num] == nullptr) {
			assert(!(data[num] == nullptr));
		}
		return (T&)__BasicVector::bGet(num);
	}

	~BasicVector() {

	}

};
class __Vector : protected __BasicVector {
protected:
	__Vector();
	void pushBack(Obj &o);
	Obj& get(const int num) const;
	BasicObj& bGet(const int num) const override;
	void del(const int num) override;
	void delById(const int Id);
	bool isContain(const int objId) const;
	virtual ~__Vector();


public:
	string getClassName() const override;


};

template <typename T>		//no msg output
class Vector : public __Vector {
public:
	Vector(int size) {
		__Vector::setSize(size);
	}
	Vector(const std::initializer_list<Obj *>& li) {
		__Vector::setSize(li.size());
		for(Obj *p : li) {
			this->pushBack(*p);
		}
	}
	Vector(const vector<Obj *>& ve) {
		__Vector::setSize(ve.size());
		for(Obj *p : ve) {
			this->pushBack(*p);
		}
	}

	T& operator [](const int num) {
		if(data[num] == nullptr) {
			assert(!(data[num] == nullptr));
		}
		return (T&)__Vector::get(num);
	}

	void pushBack(Obj &o) {
		__Vector::pushBack(o);
	}

	void remove(const int num) {
		__Vector::del(num);
	}

	void removeById(const int Id) {
		__Vector::delById(Id);
	}

	int getSize() {
		return __Vector::getSize();
	}

	void setSize(const int size) {
		__Vector::setSize(size);
	}

	bool isContain(const int objId) {
		return __Vector::isContain(objId);
	}

	~Vector() {

	}

};

}
}

