//---------------------------------------------------------------------------//
//!
//! \file   led.hpp
//! \author Alex Robinson
//! \brief  Task 1: flashing led C++ code declarations
//!
//---------------------------------------------------------------------------//

#ifndef LED_HPP
#define LED_HPP

// Wiring Pi Includes
#include <wiringPi.h>

// Qt Includes
#include <QtCore/QObject>

//! The GPIO pin class
class GPIOPin : public QObject
{
  Q_OBJECT
  Q_PROPERTY(qint32 pinId READ getPinId WRITE setPinId)
  Q_PROPERTY(bool isVoltageHigh READ isPinVoltageHigh)
  
public:

  //! Constructor
  GPIOPin( QObject* parent = 0 )
    : QObject( parent ),
      d_pin_id( 0 ),
      d_pin_voltage_high( false )
  {
    this->activatePin();
    this->setPinVoltageToHigh();
  }

  //! Destructor
  virtual ~GPIOPin()
  { /* ... */ }

  //! Set the pin that will be managed
  void setPinId( const int pin_id )
  {
    d_pin_id = pin_id;
    d_pin_voltage_high = false;

    this->activatePin();
    this->setPinVoltageToHigh();
  }

  //! Get the pin that is being managed
  qint32 getPinId() const
  {
    return d_pin_id;
  }

  //! Check if the pin voltage is high
  bool isPinVoltageHigh() const
  {
    return d_pin_voltage_high;
  }

signals:

  //! The pin voltage has been set to high
  void pinVoltageHigh( const int pin_id );

  //! The pin voltage has been set to low
  void pinVoltageLow( const int pin_id );

public slots:

  //! Set the pin voltage to high
  void setPinVoltageToHigh()
  {
    if( !d_pin_voltage_high )
    {
      digitalWrite(d_pin_id, HIGH);
      emit pinVoltageHigh( d_pin_id );

      d_pin_voltage_high = true;
    }
  }

  //! Set the pin voltage to low
  void setPinVoltageToLow()
  {
    if( d_pin_voltage_high )
    {
      digitalWrite(d_pin_id, LOW);
      emit pinVoltageLow( d_pin_id );

      d_pin_voltage_high = false;
    }
  }

private:

  // Activate the pin
  void activatePin()
  {
    pinMode(d_pin_id, OUTPUT);
  }

  // The pin id
  qint32 d_pin_id;

  // The pin voltage
  bool d_pin_voltage_high;
};

#endif // end LED_HPP

//---------------------------------------------------------------------------//
// end led.cpp
//---------------------------------------------------------------------------//
