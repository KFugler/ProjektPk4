#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QWidget *loginWindow, QString currentUser)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->tree = new Tree();
    this->file = new treeFile(":/resources/Files/MyFile.csv");

    file->readTreeFile(*tree, currentUser);
    fillDirectories();

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->tableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(selectionChanged()));
    connect(ui->tableWidget, SIGNAL(itemChanged(QTableWidgetItem *)), this, SLOT(itemChanged(QTableWidgetItem *)));
    connect(ui->logoutButton, SIGNAL(clicked()), this, SLOT(hide()));
    connect(ui->logoutButton, SIGNAL(clicked()), loginWindow, SLOT(show()));
}

MainWindow::~MainWindow()
{
    tree = nullptr;
    file = nullptr;
    delete file;
    delete tree;
    delete ui;
}

void MainWindow::fillDirectories() {
    int dirSize = tree->getDirectories().size();

    ui->tableWidget->model()->removeRows(0, ui->tableWidget->model()->rowCount());
    ui->addUrlButton->setVisible(false);
    ui->addDirectoryButton->setVisible(true);
    ui->openDirectoryButton->setVisible(true);
    ui->showDirectoriesButton->setVisible(false);

    if (dirSize > 0) {
        for (int i = 0; i < dirSize; ++i) {
            QString name = tree->getDirectories()[i]->getName();
            QString description = tree->getDirectories()[i]->getDescription();
            addDirectory(tree->getDirectories()[i]);
        }
    }
}

void MainWindow::fillUrls(QVector<Url*> urls) {
    int urlsSize = urls.size();

    ui->tableWidget->model()->removeRows(0, ui->tableWidget->model()->rowCount());

    ui->addUrlButton->setVisible(true);
    ui->addDirectoryButton->setVisible(false);
    ui->openDirectoryButton->setVisible(false);
    ui->showDirectoriesButton->setVisible(true);

    if (urlsSize > 0) {
        for (int i = 0; i < urlsSize; ++i) {
            QString name = urls[i]->getUrl();
            QString description = urls[i]->getDescription();
            addUrl(urls[i]);
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
        QTableWidgetItem* item = ui->tableWidget->item(index.row(), 2);
        WidgetItem* convertItem = dynamic_cast<WidgetItem*>(item);

        if (convertItem != NULL) {
            rowToDelete.push_back(index.row());
            if (convertItem->getType() == "folder") {
                Directory* dir = convertItem->getDirectoryPtr();
                tree->removeDirectory(dir);

                dir = nullptr;
                delete dir;
            } else if (convertItem->getType() == "URL"){
                Url* url = convertItem->getUrlPtr();
                lastOpenedDirectoryPtr->removeUrl(url);

                url = nullptr;
                delete url;
            }
        }

        convertItem = nullptr;
        item = nullptr;
        delete convertItem;
        delete item;
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
    Directory* dir = new Directory("Nowy", "Opis katalogu");
    tree->addDirectory(dir);
    addDirectory(dir);

    dir = nullptr;
    delete dir;
}

void MainWindow::on_addUrlButton_clicked()
{
    QVector<QString> tags;
    Url* newUrl = new Url("www.example.com", "website description", tags);
    lastOpenedDirectoryPtr->addUrl(newUrl);
    addUrl(newUrl);

    newUrl = nullptr;
    delete newUrl;
}

void MainWindow::itemChanged(QTableWidgetItem *item)
{
    QModelIndexList selection = ui->tableWidget->selectionModel()->selectedRows();

    if (selection.count() > 0) {
        QTableWidgetItem *itemWithPointer = ui->tableWidget->item(item->row(), 2);

        WidgetItem * convertItem;
        convertItem = dynamic_cast<WidgetItem*>(itemWithPointer);

        if (convertItem != nullptr) {
            if (convertItem->getType() == "folder") {
                Directory* dirPtr = convertItem->getDirectoryPtr();

                if (item->column() == 0) {
                    dirPtr->setName(item->text());
                } else if (item->column() == 1) {
                    dirPtr->setDescription(item->text());
                }
                dirPtr = nullptr;
                delete dirPtr;
            } else if (convertItem->getType() == "URL"){
                Url* url = convertItem->getUrlPtr();
                if (item->column() == 0) {
                    url->setUrl(item->text());
                } else if (item->column() == 1) {
                    url->setDescription(item->text());
                }
                url = nullptr;
                delete url;
            }
        }

        itemWithPointer = nullptr;
        convertItem = nullptr;

        delete itemWithPointer;
        delete convertItem;
    }
}

void MainWindow::on_openDirectoryButton_clicked()
{
    QModelIndexList selection = ui->tableWidget->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);
    QTableWidgetItem *item = ui->tableWidget->item(index.row(), 2);

    WidgetItem * convertItem;
    convertItem = dynamic_cast<WidgetItem*>(item);

    if (convertItem != NULL) {
        Directory* dirPtr = convertItem->getDirectoryPtr();

        lastOpenedDirectoryPtr = dirPtr;
        fillUrls(dirPtr->getUrls());

        dirPtr = nullptr;
        delete dirPtr;
    }

    item = nullptr;
    convertItem = nullptr;

    delete item;
    delete convertItem;
}

void MainWindow::on_showDirectoriesButton_clicked()
{
    fillDirectories();
}

void MainWindow::on_lineEdit_textChanged(const QString &text)
{
    for(int i = 0; i < ui->tableWidget->rowCount(); ++i)
    {
        bool match = false;
        for (int j = 0; j < ui->tableWidget->columnCount(); ++j)
        {
            QTableWidgetItem *item = ui->tableWidget->item(i, j);
            if (item->text().contains(text))
            {
                match = true;
                break;
            }
            item = nullptr;
            delete item;
        }
        ui->tableWidget->setRowHidden(i, !match);
    }
}

void MainWindow::addDirectory(Directory* dir)
{
    ui->tableWidget->setSortingEnabled(false);
    WidgetItem *itemType = new WidgetItem();

    itemType->setFlags(itemType->flags() ^ Qt::ItemIsEditable);
    itemType->setDirectoryPtr(dir);
    itemType->setIcon(QIcon(":/icons/Files/directoryIcon.png"));
    itemType->setType("folder");

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 0, new WidgetItem(dir->getName()));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 1, new WidgetItem(dir->getDescription()));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 2, itemType);
    ui->tableWidget->setSortingEnabled(true);
    itemType = nullptr;
    delete itemType;
}

void MainWindow::addUrl(Url* url)
{
    ui->tableWidget->setSortingEnabled(false);
    WidgetItem *itemType = new WidgetItem();

    itemType->setFlags(itemType->flags() ^ Qt::ItemIsEditable);
    itemType->setUrlPtr(url);
    itemType->setType("URL");
    itemType->setIcon(QIcon(":/icons/Files/urlIcon.png"));

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 0, new WidgetItem(url->getUrl()));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 1, new WidgetItem(url->getDescription()));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 2, itemType);

    ui->tableWidget->setSortingEnabled(true);
    itemType = nullptr;
    delete itemType;
}

void MainWindow::on_saveButton_clicked()
{
    file->writeFile(*tree);
    QMessageBox::information(this, "Sukces!", "Pomyślnie zapisano dane");
}
