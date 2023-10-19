# add an icon to the application here
#win32: {
#    RC_FILE += resources/icone.rc
#}


QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    sources/database/init/dbhistory.cpp \
    sources/database/init/dbcategory.cpp \
    sources/database/init/dbadmin.cpp \
    sources/database/init/dbinit.cpp \
    sources/database/init/dbproduct.cpp \
    sources/database/init/dbprovider.cpp \
    sources/database/init/dbuser.cpp \
    sources/database/init/triggerdown.cpp \
    sources/database/init/triggerlend.cpp \
    sources/database/init/triggerreturn.cpp \
    sources/database/init/triggerup.cpp \
    sources/database/init/triggersave.cpp \
    sources/database/show/available.cpp \
    sources/database/show/history.cpp \
    sources/database/show/product.cpp \
    sources/window/inscategory.cpp \
    sources/window/insertuser.cpp \
    sources/window/insproduct.cpp \
    sources/window/insertprovider.cpp \
    sources/window/lendproduct.cpp \
    sources/window/login.cpp \
    sources/window/main.cpp \
    sources/window/mainapp.cpp

HEADERS += \
    headers/database/init/dbadmin.h \
    headers/database/init/dbcategory.h \
    headers/database/init/dbhistory.h \
    headers/database/init/dbinit.h \
    headers/database/init/dbproduct.h \
    headers/database/init/dbprovider.h \
    headers/database/init/dbuser.h \
    headers/database/init/triggerup.h \
    headers/database/init/triggerdown.h \
    headers/database/init/triggerreturn.h \
    headers/database/init/triggerlend.h \
    headers/database/init/triggersave.h \
    headers/window/inscategory.h \
    headers/window/insertprovider.h \
    headers/window/mainapp.h \
    headers/window/login.h \
    headers/window/insproduct.h \
    headers/window/lendproduct.h \
    headers/window/insertuser.h \
    headers/database/show/product.h \
    headers/database/show/history.h \
    headers/database/show/table.h \
    headers/database/show/available.h



FORMS += \
    forms/inscategory.ui \
    forms/mainapp.ui \
    forms/login.ui \
    forms/insproduct.ui \
    forms/insertuser.ui \
    forms/insertprovider.ui \
    forms/lendproduct.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc
