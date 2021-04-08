QT += quick
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        data_calculations.cpp \
        data_reader.cpp \
        database_handler.cpp \
        datastructures.cpp \
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
    Calendar_model.qml \
    Chart_base_beta.qml \
    Chart_base_test.qml \
    Checkbox_column.qml \
    Currently_showing_box.qml \
    Date_input.qml \
    Energy_type_button.qml \
    Energy_type_button_row.qml \
    Fetch_data_button.qml \
    Load_data_button.qml \
    New_data_load_popup.qml \
    Save_data_button.qml \
    Text_input_bar.qml \
    Time_input.qml \
    Title_text.qml \
    Window_bar_menu.qml \
    energy_type_button.qml \
    Output_area.qml

HEADERS += \
    data_calculations.h \
    data_reader.h \
    database_handler.h \
    datastructures.hh \
    saagia_controller.h \
    saagia_model.h \
    saagia_view.h
    data_reader_test.hh
