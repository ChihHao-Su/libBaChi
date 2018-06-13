#pragma once
#include <string>
#include <vector>
#include <cBase/cBase.h>
#include <cBase/cApp.h>
#include <cBase/cObj.h>
#include <cBase/Baash_define.h>
using namespace std;

namespace BC {
namespace Var {

class BaseVar : public BC::Base::BasicObj {
public:
	BaseVar();
	virtual string getClassName() const;
	void onMessage(const string msg, const vector<BasicObj *> par) override;

	virtual string toString() const = 0;
	virtual void add(const BaseVar &v) = 0;
	virtual void ass(const BaseVar &v) = 0;
	virtual bool isEqal(const BaseVar &v) const = 0;
	virtual ~BaseVar();


private:
	string nick;


};

}
}
