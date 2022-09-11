import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15
import Qt.labs.folderlistmodel 2.3

Image {
    property string folderpath
    property string currentImagePath
    property string placeHolderImageSource
    
    id: imageViewer
    height:mainImage.height +lstView.height
    width:mainImage.width
    
    
    
    ColumnLayout{
        anchors.fill: parent
        
        Image{
            id:mainImage
            sourceSize.width: 512
            sourceSize.height: 512
            Layout.margins:  10
            opacity: 1
            source :currentImagePath
            

        }
        
        ListView {
            id: lstView
            width: 512
            height: 105
            orientation: ListView.Horizontal
            spacing:10
            Layout.leftMargin:  10
            clip:true
            ScrollBar.horizontal:  ScrollBar {
                active: true
            }
            
            function loadImage(imagePath)
            {
                if (imagePath)
                    imageViewer.currentImagePath = "file:/"+imagePath;

            }
            
            FolderListModel {
                id: folderModel
                nameFilters: ["*.png","*.jpg"]
                folder:imageViewer.folderpath
            }
            
            Component {
                id: fileDelegate
                Column {
                    opacity: ListView.isCurrentItem ? 1 : 0.5
                    Image {
                        width: 90
                        height: 90
                        fillMode: Image.PreserveAspectFit
                        smooth: true
                        source: fileURL
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {lstView.currentIndex = index;
                                
                            }
                        }
                    }
                    Component.onCompleted: {
                        if (index == 0){
                            console.log("Load first image")
                            if (imageViewer.folderpath)
                                imageViewer.currentImagePath = "file:/"+folderModel.get(lstView.currentIndex,"filePath");
                        }
                        
                    }
                }
                
            }
            onCurrentIndexChanged: {
                console.log("currentIndex", currentIndex)
                console.log(folderModel.get(lstView.currentIndex,"filePath"))
                if (imageViewer.folderpath)
                    loadImage(folderModel.get(lstView.currentIndex,"filePath"))
                
            }
            model: folderModel
            delegate: fileDelegate
        }
        
    }
}
