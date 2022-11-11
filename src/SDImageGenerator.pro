QT += quick
QT += quickcontrols2
QT += widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        diffusionenvironment.cpp \
        diffusionenvironmentstatus.cpp \
        diffusionenvvalidator.cpp \
        diffusionoptions.cpp \
        diffusionprocess.cpp \
        installer/devicedetector.cpp \
        installer/installerprocess.cpp \
        installer/pythonenvvalidator.cpp \
        main.cpp \
        myprocess.cpp \
        settings.cpp \
        texttoimagebackend.cpp \
        utils.cpp

RESOURCES += qml.qrc \
    sdimagegenerator.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    WinVersion.h \
    defines.h \
    diffusionenvironment.h \
    diffusionenvironmentstatus.h \
    diffusionenvvalidator.h \
    diffusionoptions.h \
    diffusionprocess.h \
    installer/devicedetector.h \
    installer/installerprocess.h \
    installer/pythonenvvalidator.h \
    myprocess.h \
    settings.h \
    texttoimagebackend.h \
    utils.h

RC_FILE = sdImagefenerator.rc
