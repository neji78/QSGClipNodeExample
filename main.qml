import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import component.shape 1.0
//import view.drawer 1.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle{
        anchors.fill: parent
        color:"yellow"
        RoundedRectangle{
            width: 200
            height: 100
            anchors.centerIn: parent
            color: "green"
            blRadius: 50
            opacity: 1.0
            Rectangle{
                width: 500
                height: 500
                color: "red"
            }
        }
    }
}
