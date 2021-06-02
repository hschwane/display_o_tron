#include <iostream>
#include "NextionHMI.h"

int main()
{
    NextionHMI nextion("/dev/ttyUSB0",mpu::io::BaudRate::BAUD_9600);
    nextion.setValue("blubber",25);
    return 0;
}
