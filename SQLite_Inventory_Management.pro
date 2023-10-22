# add an icon to the application here
#win32: {
#    RC_FILE += resources/icone.rc
#}


QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    sources/database/init/dbetat.cpp \
    sources/database/init/dblocation.cpp \
    sources/database/init/triggerdelete.cpp \
    sources/database/init/triggerlenddown.cpp \
    sources/database/init/triggerreturnup.cpp \
    sources/database/show/admin.cpp \
    sources/database/show/category.cpp \
    sources/database/show/notavailable.cpp \
    sources/database/show/panne.cpp \
    sources/database/show/provider.cpp \
    sources/database/show/seuil.cpp \
    sources/database/show/trash.cpp \
    sources/database/show/user.cpp \
    sources/window/insertadmin.cpp \
    sources/window/pdfsave.cpp \
    sources/window/returnproduct.cpp \
    sources/window/insertlocation.cpp \
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
    headers/database/init/triggerdelete.h \
    headers/database/init/triggerlend.h \
    headers/database/init/triggersave.h \
    headers/window/inscategory.h \
    headers/window/insertprovider.h \
    headers/window/mainapp.h \
    headers/window/login.h \
    headers/window/insproduct.h \
    headers/window/lendproduct.h \
    headers/window/insertadmin.h \
    headers/window/insertuser.h \
    headers/database/show/product.h \
    headers/database/show/history.h \
    headers/database/show/table.h \
    headers/database/show/available.h \
    headers/window/returnproduct.h \
    headers/database/show/admin.h \
    headers/database/show/category.h \
    headers/database/show/provider.h \
    headers/database/show/user.h \
    headers/window/pdfsave.h \
    headers/database/init/dbetat.h \
    headers/database/init/dblocation.h \
    headers/window/insertlocation.h \
    headers/database/show/notavailable.h \
    headers/database/show/seuil.h \
    headers/database/show/panne.h \
    headers/database/init/triggerlenddown.h \
    headers/database/init/triggerreturnup.h \
    headers/database/show/trash.h



FORMS += \
    forms/inscategory.ui \
    forms/mainapp.ui \
    forms/login.ui \
    forms/insproduct.ui \
    forms/insertuser.ui \
    forms/insertprovider.ui \
    forms/lendproduct.ui \
    forms/returnproduct.ui \
    forms/insertadmin.ui \
    forms/insertlocation.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc
