//---------------------------------------------------------------------------//
//!
//! \file   led.cpp
//! \author Alex Robinson
//! \brief  Task 1: flashing led C++ code
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <iostream>

// Wiring Pi Includes
#include <wiringPi.h>

// Qt Includes
#include <QtGui/QApplication>
#include <QtGui/QGraphicsView>
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QtDeclarative>

// Task includes
#include "led.hpp"

int main( int argc, char** argv )
{
  if(wiringPiSetup() == -1)
  {
    std::cout << "wiringPi setup failed!" << std::endl;
    return 1;
  }

  // Create the app instance
  QApplication app( argc, argv );

  // Register the GPIOPin class with qml
  qmlRegisterType<GPIOPin>( "Sunfounder.SuperKit", 1, 0, "Pin" );

  // Load the gui
  QDeclarativeView view;
  view.setSource( QUrl::fromLocalFile("led.qml") );
  view.show();

  return app.exec();
}

