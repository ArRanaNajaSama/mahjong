import QtQuick 2.0

Item {
    id: root

    GamesForm {
        id: gamesForm
        anchors {
            top: parent.top
            left: parent.left
        }
        width: 4 * parent.width / 5
        height: parent.height / 2

        onSelectedRowChanged: {
            usersForm.gameSelected = gamesForm.selectedRow
            handsForm.gameSelected = gamesForm.selectedRow
        }
    }

    UsersForm {
        id: usersForm
        anchors {
            top: parent.top
            left: gamesForm.right
        }
        width: parent.width / 5
        height: parent.height / 2
    }

    HandsForm {
        id: handsForm
        anchors {
            top: gamesForm.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            topMargin: 15
        }
    }
}