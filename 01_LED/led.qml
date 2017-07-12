import QtQuick 1.1
import Sunfounder.SuperKit 1.0

Rectangle {
    id: led_window
    width: 400
    height: 400

    Pin {
        id: pin
        pinId: 0
    }

    Rectangle {
        id: led_button
        width: 200
        height: 200
        color: "gray"
	anchors.horizontalCenter: led_window.horizontalCenter
	anchors.verticalCenter: led_window.verticalCenter

        Text{
            id: led_button_text
            anchors.horizontalCenter: led_button.horizontalCenter
            anchors.verticalCenter: led_button.verticalCenter

            text: "off"
            font.pointSize: 24
            color: "darkgray"
        }

        MouseArea {
            id: led_button_mouse_area
            anchors.fill: led_button
            
            onClicked: {
                if( pin.isVoltageHigh ) {
                    pin.setPinVoltageToLow();

                    led_button_text.text = "ON"
                    led_button_text.color = "red"
                }
                else {
                    pin.setPinVoltageToHigh();

                    led_button_text.text = "off"
                    led_button_text.color = "darkgray"
                }
            }
        }
    }
}
