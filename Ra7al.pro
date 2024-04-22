QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    public/classes/List.cpp \
    public/classes/Any.cpp \
    src/Date.cpp \
    src/Duration.cpp \
    src/User.cpp \
    src/Person.cpp \
    src/DataFrame/DataFrame.cpp \
    src/Admin.cpp \
    src/Location.cpp \
    src/Time.cpp \
    src/PaymentMethod.cpp \
    src/DataFrame/Case.cpp \
    src/Airline.cpp \
    src/Hotel.cpp \
    src/Budget.cpp

HEADERS += \
    mainwindow.h \
    config.h \
    headers/Date.h \
    headers/User.h \
    headers/Person.h \
    headers/DataFrame/DataFrame.h \
    headers/Admin.h \
    public/functions.h \
    public/classes/List.h \
    public/classes/Any.h \
    headers/Location.h \
    headers/Time.h \
    headers/PaymentMethod.h \
    headers/DataFrame/Case.h \
    headers/Hotel.h \
    headers/Airline.h \
    headers/Budget.h \
    headers/DataFrame/Series.h \
    headers/Currency.h \
    headers/Country.h \
    headers/DataFrame/CSVManager.h \
    headers/Card.h \
    headers/Transportation.h \
    headers/Activity.h \
    headers/Flight.h \
    headers/Duration.h \
    headers/Airport.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
