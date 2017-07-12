1. run `sudo apt-get install libqt4-dev libqt4-gui libqt4-core qt4-dev-tools`
2. run `moc led.hpp > moc_led.cpp`
3. run `g++ moc_led.cpp led.cpp -o led -I/usr/include/qt4 -lwiringPi -lQtGui -lQtCore -lQtScript -lQtDeclarative`
4. run `./led`
