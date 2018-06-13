#pragma once
#include <assert.h>

namespace BC {
namespace Base {
class App;
extern App *curr_app;

App *get_curr_app();
void set_curr_app(App *app);
}
}

/*
}
}
*/
