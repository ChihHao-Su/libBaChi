#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cBase/cVec.h>
#include "cVar.h"
using namespace std;
using namespace BC::Base;

namespace BC {
namespace Var {

class String final : public BaseVar {
public:
	String();
	String(const char *cp);            ///< ʹ����������string���ڻ�
	String(const String &v);            ///< ʹ����������ڻ�
	String(const BaseVar &s);           ///< ʹ����string���ڻ�
	void init();

	string getClassName() const override;
	string toString() const override;
	const string &getData() const;

	void add(const BaseVar &s) override;
	void add(const String &v);
	void ass(const BaseVar &s) override;
	void ass(const String &v);
	void ass(const string &s);
	void ass(const char *cp);
	bool isEqal(const BaseVar &s) const override;
	bool isEqal(const String &v) const;

	void trim();
	int replaceAll(const String &vOld, const String &vNew);
	String &launchc(const String &v, const BasicVector<String> &vv);

	~String();


private:
	string data;


};


}
}
