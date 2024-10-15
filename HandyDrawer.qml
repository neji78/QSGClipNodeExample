import QtQuick 2.15
import QtQuick.Controls 2.15
import view.drawer 1.0
Item{
    id:root
    required property Component contentItem
    readonly property real cursorPosition: (root.direction === Drawer.Horizental) ? cursor.x : cursor.y
    onCursorPositionChanged: {
        if(cursorPosition == root.height - 1){
            root.fullOpened = true
        }else{
            root.fullOpened = false
        }
    }

    property bool fullOpened: false

    property int direction: DrawerType.Vertical
    property real primaryLength: 0
    property bool animated: false
    signal fullOpened()
    rotation: 180
    function open(){
        popup.open()
    }

    WheelHandler{
        property: "y"
        onWheel: {
            if(root.direction === DrawerType.Vertical){
                var newYPostion = cursor.y + event.angleDelta.y/120 * 60;
                if(newYPostion >= 0 && newYPostion <= root.height){
                    if(newYPostion < root.primaryLength){
                        root.close()
                    }else{
                        cursor.y = newYPostion
                    }


                }
            }
        }
    }
    Item{
        x:0
        y:0
        height: (root.direction === DrawerType.Vertical) ? cursor.y : parent.height
        width: (root.direction === DrawerType.Vertical) ? parent.width : cursor.x
        Item{
            anchors.fill: parent
            rotation: 180
            Popup{
                id:popup
                topPadding: 0
                bottomPadding: 0
                leftPadding: 0
                rightPadding: 0
                MouseArea {
                    id: dragArea
                    anchors.fill: parent
                    drag.target: cursor
                    drag.axis:(root.direction === DrawerType.Horizental) ? Drag.XAxis : Drag.YAxis
                    drag.minimumX: 20
                    drag.maximumX: root.width - cursor.width
                    drag.minimumY: 20
                    drag.maximumY: root.height - cursor.height
                    onReleased: {
                        if(cursor.y < root.primaryLength - 50){
                            root.close()
                        }
                    }

                }

                width:parent.width
                height: parent.height
                dim:true
                closePolicy: Popup.CloseOnPressOutsideParent | Popup.CloseOnEscape
                contentItem: Loader{
                    id:popupLoader
                    sourceComponent: root.contentItem

                }
                exit:Transition {
                    ParallelAnimation{
                        NumberAnimation { target: cursor;property: "y"; to: 0.0 }
                        NumberAnimation { target: popup;property: "opacity"; from: 1.0; to: 0.0 }
                    }
                }
                enter:Transition {
                    ParallelAnimation{
                        NumberAnimation { target: cursor;property: "y"; to: root.primaryLength }
                        NumberAnimation { target: popup;property: "opacity"; from: 0.0; to: 1.0 }
                    }
                }
                background: Item{}
            }
        }
    }

    Item {
        id:cursor
        x:0
        y:0
        width: (root.direction === DrawerType.Horizental) ? 1 : parent.width;
        height: (root.direction === DrawerType.Vertical) ? 1 : parent.height
        Drag.active: dragArea.drag.active
        Drag.hotSpot.x: 0
        Drag.hotSpot.y: 0

        Behavior on x{
            NumberAnimation{
                duration: 200
            }
            enabled: !dragArea.drag.active && (root.direction === DrawerType.Horizental) && !root.animated
        }
        Behavior on y{
            NumberAnimation{
                duration: 200
            }
            enabled: !dragArea.drag.active && (root.direction === DrawerType.Vertical) && !root.animated
        }
//        NumberAnimation{
//            id:lifter
//            target: cursor
//            property: "y"
//            duration: 200
//            running: false
//        }
    }
}
