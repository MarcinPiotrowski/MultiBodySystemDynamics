# 2200

INCLUDEPATH += C:/Users/Maniek/Documents/MBSD/EigenLib/Eigen \
    C:\Users\Maniek\Documents\MBSD\Graphics\Lib\GLTools\include_ \
    C:\Users\Maniek\Documents\MBSD\Graphics\Lib\GLTools\include_\GL \
    C:\Users\Maniek\Documents\MBSD\Graphics\Lib \
    C:\Users\Maniek\Documents\MBSD\Complex\
    C:\Users\Maniek\Documents\MBSD\include\Armadillo



SOURCES += $$PWD/Lib/GLTools/src/GLTools.cpp \
    $$PWD/Lib/GLTools/src/GLBatch.cpp \
    $$PWD/Lib/GLTools/src/glew.c \
    $$PWD/Lib/GLTools/src/math3d.cpp \
    $$PWD/Lib/GLTools/src/GLTriangleBatch.cpp \
    $$PWD/Lib/glmath.cpp \
    $$PWD/GCamera.cpp \
    $$PWD/GFunctions.cpp \
    $$PWD/GLoadedObject.cpp \
    $$PWD/GMouse.cpp \
    $$PWD/GObject.cpp \
    $$PWD/GPrimitiveObject.cpp \
    $$PWD/GRender.cpp \
    $$PWD/GShaderProgram.cpp


HEADERS += $$PWD/GCamera.h \
    $$PWD/GFunctions.h \
    $$PWD/GHeaders.h \
    $$PWD/GLoadedObject.h \
    $$PWD/GMouse.h \
    $$PWD/GObject.h \
    $$PWD/GPrimitiveObject.h \
    $$PWD/GRender.h \
    $$PWD/GShaderProgram.h \
    $$PWD/Lib/FreeImage.h

DISTFILES += \
    $$PWD/gvertexshader.vert \
    $$PWD/gfragmentshader.frag \
    $$PWD/Lib/FreeImage.lib

RESOURCES += \
    $$PWD/gresource.qrc

win32: LIBS += -LC:/Users/Maniek/Documents/MBSD/Graphics/Lib -lFreeImage

INCLUDEPATH += C:/Users/Maniek/Documents/MBSD/Graphics/Lib
DEPENDPATH += C:/Users/Maniek/Documents/MBSD/Graphics/Lib

win32:!win32-g++: PRE_TARGETDEPS += C:/Users/Maniek/Documents/MBSD/Graphics/Lib/FreeImage.lib
else:win32-g++: PRE_TARGETDEPS += C:/Users/Maniek/Documents/MBSD/Graphics/Lib/libFreeImage.a

