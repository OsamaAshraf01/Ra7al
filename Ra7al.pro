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
    src/DataFrame/DataFrame.cpp \
    src/DataFrame/Case.cpp \
    src/DataFrame/CSVManager.cpp \
    src/DataFrame/Series.cpp \
    src/Activity.cpp\
    src/Admin.cpp \
    src/Airline.cpp \
    src/Airport.cpp \
    src/Budget.cpp \
    src/Card.cpp\
    src/Country.cpp\
    src/Currency.cpp\
    src/Date.cpp \
    src/Duration.cpp \
    src/Flight.cpp\
    src/Hotel.cpp \
    src/Itinerary.cpp\
    src/Location.cpp \
    src/PaymentMethod.cpp \
    src/Person.cpp \
    src/Time.cpp \
    src/Transportation.cpp\
    src/User.cpp

HEADERS += \
    mainwindow.h \
    config.h \
    build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/registered_users.csv \
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
    headers/Airport.h \
    headers/Itinerary.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
