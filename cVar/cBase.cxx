#include "cBase.h"
using namespace BC::Base;

App *BC::Var::curr_app = nullptr;

App *BC::Var::get_curr_app(){
    if(BC::Var::curr_app == nullptr){
        assert(!(BC::Var::curr_app == nullptr));
    }

    return curr_app;
}
void BC::Var::set_curr_app(App *app){
    BC::Var::curr_app = app;
    BC::Base::set_curr_app(app);
}


