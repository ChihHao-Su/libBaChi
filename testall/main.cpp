#include <stdio.h>
#include <gtest/gtest.h>
#include <cBase/cObj.h>
#include <cBase/cVec.h>
#include <cVar/cString.h>
#include <cVar/cInt.h>
using namespace BC;
using namespace BC::Base;


TEST(this, currapp_addr) {
	printf("%i\n", Base::curr_app);
	Base::set_curr_app(new Base::App("MAIN"));
	printf("%i\n", Base::get_curr_app());
}
TEST(cObj, spqwn) {
	Base::Obj a;
	a.setNick("AaAaAaAa");
}
TEST(cObj, autorelease) {
	auto b = new Base::Obj();
	b->setNick("B");
	b->setAutoRelease();
	b->retain();
	b->release();
}
TEST(cObj, sendMessage) {
	Base::Obj c;
	c.setNick("C");
	Base::Obj::sendMessage(c, "WTF~", {});
}
TEST(cVec, spawn) {
	auto A = new Base::Obj();
	A->setNick("A");
	A->setAutoRelease();

	auto B = new Base::Obj();
	B->setNick("B");
	B->setAutoRelease();

	auto C = new Base::Obj();
	C->setNick("C");
	C->setAutoRelease();

	Base::Vector<Base::Obj> a{A, B, C};
}
TEST(cString, spqwn) {
	using namespace BC::Var;
	String b("god saves the queen.");
	printf("%s\n", b.getData().c_str());
}
TEST(cString, add_ass) {
	using namespace BC::Var;
	String b("This is a ");
	b.add("example");
    b.replaceAll(" ", "_");
	printf("%s\n", b.getData().c_str());
}
TEST(cString, launch) {
	using namespace BC::Var;
	String c;
	c.launchc("SELECT %0 FROM %1 WHERE %2 ;", {"name", "employee", "age>99"});

	printf("%s\n", c.getData().c_str());
}

