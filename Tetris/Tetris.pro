TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += warn_on


SOURCES += main.c
#SOURCES += main_2.c
SOURCES += tetris_graph.c
SOURCES += kernel.c
SOURCES += score_system.c

QMAKE_CFLAGS_WARN_ON += -Wall -Wextra
QMAKE_CXXFLAGS_WARN_ON += -Wall -Wextra

win32: {
INCLUDEPATH += -I 'C:/Program Files/Common Files/MinGW/freeglut/include'
LIBS += -L'C:/Program Files/Common Files/MinGW/freeglut/lib'
LIBS += -lfreeglut
LIBS += -lopengl32
LIBS += -lGLU32
}

unix: {
LIBS += -L/usr/lib64
#LIBS += -lncurses
LIBS += -lGLU
LIBS += -lGL
LIBS += -lglut
}


HEADERS += GL/glut.h
HEADERS += tetris_graph.h \
    score_system.h \
    ss_types.h
HEADERS += tetriminos_maps.h
HEADERS += kernel_types.h
HEADERS += kernel.h
HEADERS += Tfont.h
