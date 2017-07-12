1. run `moc led.hpp > moc_led.cpp`
2. run `g++ moc_led.cpp led.cpp -o led -I/usr/include/qt4 -lwiringPi -lQtGui -lQtCore -lQtScript -lQtDeclarative`
