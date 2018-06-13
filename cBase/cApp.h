#pragma once
#include "cObjManager.h"
#include "cObj.h"

namespace BC {
namespace Base {

class App {
private:
	ObjManager OM;
	BasicObj nanObj;
	string name;


public:
	App(string name);
	~App();

	void setName(string name);
	string getName() const;

	ObjManager& getOMInstance();
	BasicObj& getNOInstance();


};

}
}
