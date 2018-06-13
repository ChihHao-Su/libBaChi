#pragma once
#include <string>
#include <vector>
#include "Baash_define.h"
#include "cBase.h"
//#include "cApp.h"
using namespace std;

namespace BC {
namespace Base {

class App;
class BasicObj {
public:
	BasicObj();
	virtual string getClassName() const;
	virtual void onMessage(const string msg, const vector<BasicObj *> par);
	static void sendMessage(BasicObj &o,const string msg, const vector<BasicObj *> par);
	virtual ~BasicObj();


};

class Obj : public BasicObj {
public:
	Obj();
	virtual string getClassName() const override;
	virtual void onMessage(const string msg, const vector<BasicObj *> par) override;
	void retain();
	void release();

	void setAutoRelease();
	void unsetAutoRelease();
	void setNick(const string &s);
	const string &getNick() const;
	const int getId() const;

	virtual ~Obj();


private:
	string nick;
	bool isAutoRelease;
	int refNum;
	int ID;


deleted:
    Obj(const Obj &) = delete;

};



}
}
