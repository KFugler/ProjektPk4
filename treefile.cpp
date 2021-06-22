#include "treefile.h"

treeFile::treeFile(QString value) : File(value) {}
treeFile::~treeFile(){}

void treeFile::readTreeFile(Tree &tree, QString currentUser)
{
    File input("C:/Pk4Qt2/ProjektPk4/MyFile.csv");
    readFile = input.read();
    userName = currentUser;
    Directory *dir;
    bool isLogged = false;
    for (int i = 0; i < readFile.size(); i++) {
      if (readFile[i].size() == 1) {
          isLogged = readFile[i][0] == currentUser;
      }
      if (isLogged && readFile[i].size() > 1) {
          if (readFile[i].size() == 2) {
              dir = new Directory(readFile[i][0], readFile[i][1]);
              tree.addDirectory(dir);
          } else {
             QVector<QString> vector;
             for (int k=3;k<readFile[i].size();k++) {
              vector.append(readFile[k]);
             }
              Url* newUrl = new Url(readFile[i][0], readFile[i][1], vector);
              dir->addUrl(newUrl);

              newUrl = nullptr;
              delete newUrl;
          }
      }
    }
    dir = nullptr;
    delete dir;
}

void treeFile::writeFile(Tree &newTree) {
    QString path = "C:/Pk4Qt2/ProjektPk4/MyFile.csv";
    File output (path);
    QFile ClearFile (path);
    ClearFile.open(QIODevice::WriteOnly | QIODevice::Truncate);
    ClearFile.close();

    for(int i=0; i < readFile.size() ; i++) {
        int ret = 0;
        if (readFile[i].size() == 1 && readFile[i][0] == userName) {
            int x = i+1;
            while (x< readFile.size() && readFile[x].size() != 1){
                x++;
            }
            ret = x;
            output.write(userName);
            for (int j=0; j< newTree.getDirectories().size(); j++) {
                output.endrow();
                output.write(newTree.getDirectories()[j]->getName());
                output.write(newTree.getDirectories()[j]->getDescription());
                for (int k=0; k<newTree.getDirectories()[j]->getUrls().size(); k++){
                    output.endrow();
                    output.write(newTree.getDirectories()[j]->getUrls()[k]->getUrl());
                    output.write(newTree.getDirectories()[j]->getUrls()[k]->getDescription());
                    output.write("ikona.jpg");
                    output.write("0");
                }
            }
            i = ret;
            if (ret == readFile.size())
               return;
            output.endrow();
        }
        for(int l=0; l < readFile[i].size(); l++) {
            output.write(readFile[i][l]);
        }
        output.endrow();
    }
}
