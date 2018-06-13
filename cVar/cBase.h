#pragma once
#include <cBase/cApp.h>

namespace BC{
namespace Var{
    extern Base::App *curr_app;

    Base::App *get_curr_app();
    void set_curr_app(Base::App *app);
}
}
