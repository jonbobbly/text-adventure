#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

		enum Screen {WORLD = 0, INVENTORY};

	private slots:
		void on_worldInput_returnPressed();
		void on_invenInput_returnPressed();
		void on_playerInventory_clicked(const QModelIndex &index);
		void on_playerInventory_doubleClicked(const QModelIndex &index);
		void updateLocation();

		void on_areaInventory_doubleClicked(const QModelIndex &index);

	private:
		Ui::MainWindow *ui;
		Game theGame;
};

#endif // MAINWINDOW_H
