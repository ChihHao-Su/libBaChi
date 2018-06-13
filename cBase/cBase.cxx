#include "cBase.h"
using namespace BC::Base;

App *BC::Base::curr_app = nullptr;

App *BC::Base::get_curr_app() {
	if(curr_app == nullptr) {
		assert(!(curr_app == nullptr));
	}

	return curr_app;
}
void BC::Base::set_curr_app(App *app) {
	curr_app = app;
}
