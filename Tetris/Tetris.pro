TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    tetris_graph.c \
    kernel.c

include(deployment.pri)
qtcAddDeployment()

INCLUDEPATH += -I 'C:/Program Files/Common Files/MinGW/freeglut/include'

LIBS += -L'C:/Program Files/Common Files/MinGW/freeglut/lib'
LIBS += -lfreeglut \
    -lopengl32 \
    -lGLU32

HEADERS += GL/glut.h \
    tetris_graph.h \
    tetriminos_maps.h \
    kernel_types.h \
    kernel.h
