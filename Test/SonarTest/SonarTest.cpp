#include "/root/libs/BlackLib/v2_0/BlackLib.hpp"
#include <iostream>
#include <unistd.h>
#include <sys/time.h>

int main()
{
    BlackLib::BlackGPIO Echo(BlackLib::GPIO_43, BlackLib::input, BlackLib::WorkingMode);       // Echo for Sonar
    BlackLib::BlackGPIO Enable(BlackLib::GPIO_44, BlackLib::output, BlackLib::WorkingMode);    // Enable for Sonar
    BlackLib::BlackGPIO Sel0(BlackLib::GPIO_46, BlackLib::output, BlackLib::WorkingMode);      // Sel0 for MUX/DEMUX
    BlackLib::BlackGPIO Sel1(BlackLib::GPIO_47, BlackLib::output, BlackLib::WorkingMode);      // Sel1 for MUX/DEMUX
    BlackLib::BlackGPIO Sel2(BlackLib::GPIO_48, BlackLib::output, BlackLib::WorkingMode);      // Sel2 for MUX/DEMUX

    struct timeval start, end;

    long timeInterval_usec, distance;

    int i = 0;

    while(1)
    {

        // Set the selection to 0
        Sel0.setValue(i & 0x1);
        Sel1.setValue((i & 0x2)>>1);
        Sel2.setValue((i & 0x4)>>2);

        // Trigger the enable high
        if (Enable.setValue(BlackLib::high))
        {
            std::cout << "Error setting enable high" << std::endl;
            return 0;
        }
        usleep(10);
        // Set the enable low
        if (Enable.setValue(BlackLib::low))
        {
            std::cout << "Error setting enable low" << std::endl;
            return 0;
        }

        gettimeofday(&start, NULL);     // Start the timer

        while(!Echo.isHigh());          // Check to see if Echo is high

        gettimeofday(&end, NULL);       // end the timer

        timeInterval_usec = end.tv_usec - start.tv_usec;
        
        distance = timeInterval_usec/58;

        std::cout << "Distance at " << i << ": " << distance;
    }

    return 0;
}
