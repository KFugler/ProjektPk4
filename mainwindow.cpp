#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tree.addDirectory("Praca", "Katalog z pracy");
    tree.addDirectory("Ulubione", "Katalog z ulubionymi");
    tree.addDirectory("Dom", "Katalog z domu");
    tree.addDirectory("Szkola", "Katalog ze szkoly");
    QVector<QString> vector;
    vector.append("tagTest");

    Directory workDir = tree.getDirectoryObjectByIndex(0);
    workDir.addUrl("www.onet.pl", "fajna strona", "icon", vector);
    workDir.addUrl("www.wp.pl", "nie fajna strona", "icon", vector);

    // pomyslec jak to zmienic aby za kazdym razem nie aktualizowac
    tree.updateDirectory(workDir);

    fillDirectories();

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->tableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(selectionChanged()));
    connect(ui->tableWidget, SIGNAL(itemChanged(QTableWidgetItem *)), this, SLOT(itemChanged(QTableWidgetItem *)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillDirectories() {
    int dirSize = tree.getDirectories().size();

    ui->tableWidget->setRowCount(0);

    ui->addUrlButton->setVisible(false);
    ui->addDirectoryButton->setVisible(true);
    ui->openDirectoryButton->setVisible(true);
    ui->showDirectoriesButton->setVisible(false);

    if (dirSize > 0) {
        for (int i = 0; i < dirSize; ++i) {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(tree.getDirectories()[i].getName()));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(tree.getDirectories()[i].getDescription()));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem(QString::number(tree.getDirectories()[i].getId())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, new QTableWidgetItem("folder"));
        }
    }
}

void MainWindow::fillUrls(QVector<Url> urls) {
    int urlsSize = urls.size();

    ui->tableWidget->setRowCount(0);

    ui->addUrlButton->setVisible(true);
    ui->addDirectoryButton->setVisible(false);
    ui->openDirectoryButton->setVisible(false);
    ui->showDirectoriesButton->setVisible(true);

    if (urlsSize > 0) {
        for (int i = 0; i < urlsSize; ++i) {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(urls[i].getUrl()));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(urls[i].getDescription()));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem(QString::number(urls[i].getId())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, new QTableWidgetItem("URL"));
        }
    }
}

void MainWindow::on_deleteButton_clicked()
{
    QModelIndexList selection = ui->tableWidget->selectionModel()->selectedRows();
    QVector<int> rowToDelete;
    for(int i=0; i < selection.count(); ++i)
    {
        QModelIndex index = selection.at(i);
        rowToDelete.push_back(index.row());
        QString id = ui->tableWidget->model()->data(ui->tableWidget->model()->index(index.row(),2)).toString();
        QString type = ui->tableWidget->model()->data(ui->tableWidget->model()->index(index.row(),3)).toString();
        if (type == "folder") {
            tree.removeDirectoryById(id.toInt());
        } else {
            Directory dir = tree.getDirectoryObjectById(lastOpenedDirectoryId);
            if (dir.getUrls().size() > 0) {
                dir.removeUrlById(id.toInt());
                tree.updateDirectory(dir);
            }
        }
    }
    sort(rowToDelete.rbegin(), rowToDelete.rend());
    foreach(int row, rowToDelete) {
        ui->tableWidget->removeRow(row);
    }
}

void MainWindow::selectionChanged()
{
    QModelIndexList selection = ui->tableWidget->selectionModel()->selectedRows();
    ui->deleteButton->setEnabled(selection.count() > 0);
    ui->openDirectoryButton->setEnabled(selection.count() == 1);
}

void MainWindow::on_addDirectoryButton_clicked()
{
    tree.addDirectory("Nowy", "Opis katalogu");
    Directory dir = tree.getDirectoryObjectByIndex(tree.getDirectories().count() - 1);
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 0, new QTableWidgetItem(dir.getName()));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 1, new QTableWidgetItem(dir.getDescription()));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 2, new QTableWidgetItem(QString::number(dir.getId())));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 3, new QTableWidgetItem("folder"));
}

void MainWindow::itemChanged(QTableWidgetItem *item)
{
//    qDebug() << item->row();
//    qDebug() << item->text();
//    qDebug() << item->column();
}

void MainWindow::on_openDirectoryButton_clicked()
{
    QModelIndexList selection = ui->tableWidget->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);
    QString id = ui->tableWidget->model()->data(ui->tableWidget->model()->index(index.row(),2)).toString();
    QVector<Url> urls = tree.getDirectoryObjectById(id.toInt()).getUrls();
    lastOpenedDirectoryId = id.toInt();
    fillUrls(urls);
}

void MainWindow::on_showDirectoriesButton_clicked()
{
    fillDirectories();
}

void MainWindow::on_addUrlButton_clicked()
{
    QVector<QString> tags;
    Directory dir = tree.getDirectoryObjectById(lastOpenedDirectoryId);
    dir.addUrl("www.example.com", "website description", "icon", tags);
    tree.updateDirectory(dir);
    Url addedUlr = dir.getUrlObjectByIndex(dir.getUrls().count() - 1);
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 0, new QTableWidgetItem(addedUlr.getUrl()));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 1, new QTableWidgetItem(addedUlr.getDescription()));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 2, new QTableWidgetItem(QString::number(addedUlr.getId())));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 3, new QTableWidgetItem("URL"));
}
