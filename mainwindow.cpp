#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*                                                                                              // pisanie do pliku
File output("C:\\Users\\Adam\\Desktop\\PROJEKT PK4 AKT\\ProjektPk4\\users.csv");                  // trzeba wpisać ścieżkę swojego pliku csv na sztywno
output.endrow();
output.write("newUser");
output.write("sample");
*/
                                                                          // wczytanie danych do programu z pliku
    treeFile input(":/resources/Files/MyFile.csv");                             // przykładowy plik umieszczony w resources żeby każdemu się załadował
    input.readTreeFile(tree);
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
            QString name = tree.getDirectories()[i].getName();
            QString description = tree.getDirectories()[i].getDescription();
            QString id = QString::number(tree.getDirectories()[i].getId());
            addItem(name, description, id, "folder");
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
            QString name = urls[i].getUrl();
            QString description = urls[i].getDescription();
            QString id = QString::number(urls[i].getId());
            addItem(name, description, id, "URL");
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

    QString name = dir.getName();
    QString description = dir.getDescription();
    QString id = QString::number(dir.getId());
    addItem(name, description, id, "folder");
}

void MainWindow::itemChanged(QTableWidgetItem *item)
{
//    QString id = ui->tableWidget->model()->data(ui->tableWidget->model()->index(item->row(),2)).toString();
//    QString type = ui->tableWidget->model()->data(ui->tableWidget->model()->index(item->row(),3)).toString();
//    if (!id.isEmpty() && !type.isEmpty()) {
//        qDebug() << item->text();
//        qDebug() << item->row();
//        qDebug() << item->column();
//        Directory dir = tree.getDirectoryObjectById(id.toInt());
//        if (type == "folder") {
//            if (item->column() == 0) {
//                dir.setName(item->text());
//            } else if (item->column() == 1) {
//                dir.setDescription(item->text());
//            }
//            tree.updateDirectory(dir);
    //    } else {
    //        Directory dir = tree.getDirectoryObjectById(lastOpenedDirectoryId);
    //        if (dir.getUrls().size() > 0) {
    //            dir.removeUrlById(id.toInt());
    //            tree.updateDirectory(dir);
    //        }
//        }
//    }
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

    QString name = addedUlr.getUrl();
    QString description = addedUlr.getDescription();
    QString id = QString::number(addedUlr.getId());
    addItem(name, description, id, "URL");
}

void MainWindow::on_lineEdit_textChanged(const QString &text)
{
    for( int i = 0; i < ui->tableWidget->rowCount(); ++i )
    {
        bool match = false;
        for( int j = 0; j < ui->tableWidget->columnCount(); ++j )
        {
            QTableWidgetItem *item = ui->tableWidget->item( i, j );
            if( item->text().contains(text) )
            {
                match = true;
                break;
            }
        }
        ui->tableWidget->setRowHidden( i, !match );
    }
}

void MainWindow::addItem(QString name, QString desc, QString id, QString type)
{
    // It's a hack to set not editable column but not good practise
    QTableWidgetItem *itemId = new QTableWidgetItem(id);
    QTableWidgetItem *itemType = new QTableWidgetItem(type);
    itemId->setFlags(itemId->flags() ^ Qt::ItemIsEditable);
    itemType->setFlags(itemType->flags() ^ Qt::ItemIsEditable);

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 0, new QTableWidgetItem(name));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 1, new QTableWidgetItem(desc));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 2, itemId);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 3, itemType);
}
