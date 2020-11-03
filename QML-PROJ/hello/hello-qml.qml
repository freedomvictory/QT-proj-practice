import QtQuick 2.0

Rectangle{
    id: page
    Text {
        id: text_hi
        text: qsTr("Hello World")
        elide: Text.ElideRight
    }
    y:30
    anchors.horizontalCenter: page.horizontalCenter
    Font.pointSize: 24;Font.bold: true

    width: 320;height:480
    color:"lightgray"
}
