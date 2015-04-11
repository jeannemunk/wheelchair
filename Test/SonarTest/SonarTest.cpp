#include "/root/libs/BlackLib/v2_0/BlackLib.h"
#include <iostream>
#include <unistd.h>
#include <sys/time.h>

int main()
{
    BlackLib::BlackGPIO Listen(BlackLib::GPIO_45, BlackLib::input);

    while(1)
    {
        if(Listen.isHigh())
        {
            std::cout << "STOP!" << std::endl;
        }
        else
        {
            std::cout << "Go!" << std::endl;
        }
        sleep(1);
    }
    return 0;
}
