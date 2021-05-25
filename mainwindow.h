#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTableWidgetItem>

#include "tree.h"
#include "treefile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
void selectionChanged (const QItemSelection & selected, const QItemSelection & deselected);
void fillDirectories();
void fillUrls(QVector<Url> urls);
void addItem(QString name, QString desc, QString id, QString type);
private slots:
    void on_deleteButton_clicked();
    void selectionChanged();
    void itemChanged(QTableWidgetItem *item);

    void on_addDirectoryButton_clicked();

    void on_openDirectoryButton_clicked();

    void on_showDirectoriesButton_clicked();

    void on_addUrlButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Tree tree;
    int lastOpenedDirectoryId = -1;
};
#endif // MAINWINDOW_H
