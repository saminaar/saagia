QT += quick
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        database_handler.cpp \
        datareader.cpp \
        main.cpp \
        saagia_controller.cpp \
        saagia_model.cpp \
        saagia_view.cpp

RESOURCES += qml.qrc \
    image_resources.qrc
PACKAGECONFIG_append = "gif"

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = 

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH = \../../../

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../chart_example.gif \
    ../../../single-line-chart.png \
    Chart_base_beta.qml \
    Energy_type_button.qml \
    Text_input_bar.qml \
    energy_type_button.qml

HEADERS += \
    database_handler.h \
    datareader.h \
    saagia_controller.h \
    saagia_model.h \
    saagia_view.h
    data_reader_test.hh
