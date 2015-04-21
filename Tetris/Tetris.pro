TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    tetris_graph.c

include(deployment.pri)
qtcAddDeployment()


LIBS += -L'C:/Program Files/Common Files/MinGW/freeglut/lib'
LIBS += -lfreeglut \
    -lopengl32 \
    -lGLU32


INCLUDEPATH += -I 'C:/Program Files/Common Files/MinGW/freeglut/include'

HEADERS += GL/glut.h \
    tetris_graph.h
