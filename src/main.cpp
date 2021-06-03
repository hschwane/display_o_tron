#include <mpUtils/mpUtils.h>
#include "Dot.h"

int main()
{
    // setup logging
    mpu::Log myLog( mpu::LogLvl::ALL, mpu::ConsoleSink());
    myLog.printHeader("display_o_tron", DOT_VERSION, DOT_VERSION_SHA, DOT_BUILD_TYPE);

    // setup application
    Dot dot;

    // run the dot app
    while(true) {
        dot.run();
    }
    return 0;
}
