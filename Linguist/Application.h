
#ifndef _Application_h
#define _Application_h

#include <QApplication>



class Application : public QApplication
{
	public:
		Application(int& argc, char** argv);
		~Application();

	private:
		Q_OBJECT
};

#endif


