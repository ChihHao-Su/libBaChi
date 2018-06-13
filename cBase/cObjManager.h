#pragma once
#include <string>
#include <iostream>
#include <map>
#include "cBase.h"
#include "Baash_define.h"
using namespace std;

namespace BC {
namespace Base {

class App;
class Obj;
class ObjManager {
public:
	ObjManager();
	friend class Obj;
	const Obj& getObj(int ID);
	string getClassName() const;
	~ObjManager();


private:
	string nick;
	int regObj(Obj& obj);	//returns ID, User cannot call
	void delObj(int ID);	//User cannot call

	map<int, Obj *> objPool;
	int next_ID;


};

}
}
