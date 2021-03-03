import QtQuick 2.0

Item {
   id: item
   width: 200;height: 200
   function myMethod(){
       console.log("Button was clicked!")
   }

   Button {
       id:button
       anchors.fill: parent
       Component.onCompleted: buttonClicked.connect(item.myMethod)
   }
}
