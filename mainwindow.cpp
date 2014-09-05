#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->playerInventory->setModel(theGame.thePlayer.inven.model);

	theGame.theAreas.addArea("Spawn", "Spawn", "Not much here. Just a decent landing place", "North Room", "", "", "");
	theGame.theAreas.addArea("North Room", "North Room", "This is the northern room", "", "", "Spawn", "");
	theGame.thePlayer.Location = "Spawn";
	theGame.thePlayer.dispLocation = theGame.theAreas.find("Spawn")->dispName;

	theGame.theItems.addItem("Test Item", "Test item description");
	theGame.theItems.addItem("Knife", "A dull, rusty knife. It seems to have a blue glow");
	theGame.theAreas.find("North Room")->inven.addItem("Knife");
	theGame.thePlayer.inven.addItem("Test Item");

	updateLocation();

	ui->statusBar->showMessage("Ready player one", 2000);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::updateLocation()
{
	ui->areaInventory->setModel(theGame.curAreaInvenModel());
	ui->currentArea->setText(theGame.thePlayer.dispLocation);
	ui->roomOutput->setText(theGame.curDescription());
}

void MainWindow::on_worldInput_returnPressed()
{
	QString Text = ui->worldInput->text();
	ui->worldInput->setText("");
	if(Text == "inventory"){
		ui->stackedWidget->setCurrentIndex(MainWindow::INVENTORY);
		ui->invenInput->setFocus();
	} else if(Text == "save"){
		QString file = QFileDialog::getSaveFileName(this,"Save Game", "", "Save files (*.sav)");
		ui->statusBar->showMessage( theGame.Save(file), 5000);
	} else if(Text == "load"){
		QString file = QFileDialog::getOpenFileName(this,"Save Game", "", "Save files (*.sav)");
		QString msg = theGame.Load(file);
//		ui->playerInventory->setModel(theGame.playerInvenModel());
		ui->playerInventory->setModel(theGame.thePlayer.inven.model);
		updateLocation();
		ui->statusBar->showMessage( msg, 5000);
	} else if (Text == "quit"){
		close();
	} else {
		ui->statusBar->showMessage( theGame.parseWorldInput(Text), 5000 );
		if(theGame.thePlayer.hasMoved()){
			updateLocation();
		}
	}
}

void MainWindow::on_invenInput_returnPressed()
{
	QString Text = ui->invenInput->text();
	ui->invenInput->setText("");
	if(Text == "cancel"){
		ui->stackedWidget->setCurrentIndex(MainWindow::WORLD);
		ui->worldInput->setFocus();
	} else {
		ui->statusBar->showMessage( theGame.parseInvenInput(Text), 5000 );
	}
}

void MainWindow::on_playerInventory_clicked(const QModelIndex &index)
{
	QString selectedItem = index.data().toString();
	ui->itemDescription->setText( theGame.theItems.find(selectedItem)->Description );

}


void MainWindow::on_playerInventory_doubleClicked(const QModelIndex &index)
{
	ui->statusBar->showMessage(theGame.drop(index.data().toString()), 5000);
}

void MainWindow::on_areaInventory_doubleClicked(const QModelIndex &index)
{
	ui->statusBar->showMessage(theGame.take(index.data().toString()), 5000);
}

void MainWindow::on_btnNorth_clicked()
{
	ui->statusBar->showMessage( theGame.parseWorldInput("north"), 5000 );
	if(theGame.thePlayer.hasMoved()) updateLocation();
}

void MainWindow::on_btnWest_clicked()
{
	ui->statusBar->showMessage( theGame.parseWorldInput("west"), 5000 );
	if(theGame.thePlayer.hasMoved()) updateLocation();
}

void MainWindow::on_btnSouth_clicked()
{
	ui->statusBar->showMessage( theGame.parseWorldInput("south"), 5000 );
	if(theGame.thePlayer.hasMoved()) updateLocation();
}

void MainWindow::on_btnEast_clicked()
{
	ui->statusBar->showMessage( theGame.parseWorldInput("east"), 5000 );
	if(theGame.thePlayer.hasMoved()) updateLocation();
}
