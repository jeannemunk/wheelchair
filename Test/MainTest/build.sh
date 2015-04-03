g++ -O2 `pkg-config --cflags opencv` `pkg-config --libs opencv`  main.cpp ../CamTest/camera.cpp ../ControlTest/control.cpp -std=c++0x
