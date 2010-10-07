
TEMPLATE = app
TARGET = Editor
DESTDIR = bin

CONFIG += console
CONFIG += warn_on

OBJECTS_DIR = tmp/obj
MOC_DIR = tmp/moc
RCC_DIR = tmp/rcc
UI_DIR = tmp/ui

SOURCES += \
	Main.cpp \
	Application.cpp \
	MainWindow.cpp

HEADERS += \
	Application.h \
	MainWindow.h

TRANSLATIONS = pt_BR.ts 

RESOURCES += \
	Media.qrc


