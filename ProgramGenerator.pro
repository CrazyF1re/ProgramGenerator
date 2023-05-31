QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp

HEADERS += \
      \
    class_unit.h \
    cpp_class_unit.h \
    cpp_factory.h \
    cpp_method_unit.h \
    cpp_print_operator_unit.h \
    factory.h \
    java_class_unit.h \
    java_factory.h \
    java_method_unit.h \
    java_print_operator_unit.h \
    method_unit.h \
    print_operator_unit.h \
    programfactory.h \
    sharp_class_unit.h \
    sharp_factory.h \
    sharp_method_unit.h \
    sharp_print_operator_unit.h \
    unit.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
