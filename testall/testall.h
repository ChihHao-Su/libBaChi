#include <assert.h>
#include <cBase/cApp.h>

namespace TESTALL{


extern BC::Base::App *curr_app;

BC::Base::App *get_curr_app();
void set_curr_app(BC::Base::App *app);

}
