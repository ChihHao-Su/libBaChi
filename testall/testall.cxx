#include "testall.h"
using namespace TESTALL;

BC::Base::App *TESTALL::curr_app = nullptr;

BC::Base::App *TESTALL::get_curr_app(){
    if(curr_app == nullptr){
        assert(!(curr_app == nullptr));
    }

    return curr_app;
}
void TESTALL::set_curr_app(BC::Base::App *app){
    curr_app = app;
}
