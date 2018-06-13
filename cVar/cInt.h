#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cBase/cVec.h>
#include "cVar.h"
#include "stdStrStreamConv.h"
using namespace std;

namespace BC {
namespace Var {

class Num final : public BaseVar {
public:
	Num();
	Num(const int &i);
	Num(const double &d);
	Num(const Num &v);
	Num(const BaseVar &s);
	void init();

	string getClassName() const override;
	string toString() const override;
	const double &getData() const;

	void add(const BaseVar &s) override;
	void add(const Num &s);
	void ass(const BaseVar &s) override;
	void ass(const Num &s);
	void ass(const int i);
	void ass(const double d);
	bool isEqal(const BaseVar &s) const override;
	bool isEqal(const Num &v) const;

	Num operator -() const;
	Num operator +(const Num &v) const;
	Num operator -(const Num &v) const;

	~Num();


private:
	double data;
};

}
}
