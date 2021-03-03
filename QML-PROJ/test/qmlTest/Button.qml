import QtQuick 2.0

Rectangle {
    id: rect
    signal buttonClicked(int xPos, int yPos)
    width: 100;height:100
    MouseArea{
        anchors.fill: parent
        onClicked: rect.buttonClicked(mouseX, mouseY)
    }

}
