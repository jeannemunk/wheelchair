g++ -O2 `pkg-config --cflags opencv` `pkg-config --libs opencv` main.cpp ../CamTest/camera.cpp ../ControlTest/control.cpp ../MotorTest/motor.cpp -L/root/libs/BlackLib/v2_0/ -lBlackLib -std=c++0x
