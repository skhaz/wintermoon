
TEMPLATE = app
TARGET = Liguist 
DESTDIR = bin

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

