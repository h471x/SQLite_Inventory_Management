# add an icon to the application here
#win32: {
#    RC_FILE += resources/icone.rc
#}


QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    sources/database/init/dbcategory.cpp \
    sources/database/init/dbadmin.cpp \
    sources/database/init/dbinit.cpp \
    sources/database/init/dbproduct.cpp \
    sources/database/init/dbprovider.cpp \
    sources/database/init/dbuser.cpp \
    sources/database/init/triggerdown.cpp \
    sources/database/init/triggerup.cpp \
    sources/database/show/product.cpp \
    sources/window/inscategory.cpp \
    sources/window/login.cpp \
    sources/window/main.cpp \
    sources/window/mainapp.cpp

HEADERS += \
    headers/database/init/dbadmin.h \
    headers/database/init/dbcategory.h \
    headers/database/init/dbinit.h \
    headers/database/init/dbproduct.h \
    headers/database/show/product.h \
    headers/database/init/dbprovider.h \
    headers/database/init/dbuser.h \
    headers/database/init/triggerup.h \
    headers/database/init/triggerdown.h \
    headers/window/inscategory.h \
    headers/window/mainapp.h \
    headers/window/login.h

FORMS += \
    forms/inscategory.ui \
    forms/mainapp.ui \
    forms/login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc
