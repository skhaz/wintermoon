
#ifndef _MainWindow_h
#define _MainWindow_h

#include <QMainWindow>

#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QDirIterator>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QTextStream>
#include <QRegExp>



class MainWindow : public QMainWindow
{
	public:
		MainWindow(QWidget* parent = 0);

		~MainWindow();

	protected slots:
		void processStringTable(const QString& filename);

	private:
		Q_OBJECT
};

#endif
