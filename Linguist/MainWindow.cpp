
#include "MainWindow.h"



MainWindow::MainWindow(QWidget* parent)
: QMainWindow(parent)
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), tr(""),QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	QDirIterator it(dir, QStringList() << "*.cpp" << "*.h", QDir::NoFilter, QDirIterator::Subdirectories);

	while (it.hasNext())
	{
		processStringTable(it.next());
 	}
}

MainWindow::~MainWindow()
{
}


<message>
	<filename>{{ filename }}</filename>
	<line>{{ line }}</line>
	<string>{{ original }}</string>
	<translated>{{ translated }}</translated>
<message>

void MainWindow::processStringTable(const QString& filename)
{
	QFile file(filename);
	QStringList list; // QList<LocaleInfo *> list

	// cout << i18n("banana") << endl;
	// captures the string banana
	QRegExp regex("i18n\\(\"([A-Za-z0-9% \\\\-]+)\"\\)");

	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QString data = QTextStream(&file).readAll(); // readLine
		file.close();

		int pos = 0;
		while ((pos = regex.indexIn(data, pos)) != -1)
		{
			pos += regex.matchedLength();
			list << regex.cap(1);
		}
	}

	// return list;
}
