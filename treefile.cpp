#include "treefile.h"

treeFile::treeFile(QString value) : File(value) {}
treeFile::~treeFile(){}

void treeFile::readTreeFile(Tree &tree, QString currentUser)
{
    File input("C:/Pk4Qt3/ProjektPk4/MyFile.csv");
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
              Url* newUrl = new Url(readFile[i][0], readFile[i][1], readFile[i][2]);
              dir->addUrl(newUrl);

              newUrl = nullptr;
              delete newUrl;
            }
        }
    }
}

void treeFile::writeFile(Tree &newTree) {
    QString path = "C:/Pk4Qt3/ProjektPk4/MyFile.csv";
    File output (path);
    QFile ClearFile (path);
    ClearFile.open(QIODevice::WriteOnly | QIODevice::Truncate);
    ClearFile.close();
    bool userFound = false;
    for(int i=0; i < readFile.size() ; i++) {
        int ret = 0;
        if (readFile[i].size()==1 && readFile[i][0] == userName){
            int x = i+1;
            while (x < readFile.size() && readFile[x].size() != 1) {
                x++;
            }
            userFound = true;
            ret = x;
            writeTreeToFile(newTree, output);
            i = ret;
            if (ret == readFile.size())
               return;
            output.endrow();
        }
        for(int l=0; l < readFile[i].size(); l++){
            output.write(readFile[i][l]);
        }
        output.endrow();
    }
    if (userFound == false){
        writeTreeToFile(newTree, output);
        return;
    }
}

void treeFile::writeTreeToFile(Tree& newTree, File output)
{
    output.write(userName);
    for (int j=0; j< newTree.getDirectories().size(); j++){
        output.endrow();
        output.write(newTree.getDirectories()[j]->getName());
        output.write(newTree.getDirectories()[j]->getDescription());

        for (int k=0; k<newTree.getDirectories()[j]->getUrls().size(); k++){
            output.endrow();
            output.write(newTree.getDirectories()[j]->getUrls()[k]->getUrl());
            output.write(newTree.getDirectories()[j]->getUrls()[k]->getDescription());
            output.write(newTree.getDirectories()[j]->getUrls()[k]->getTags());
        }
    }
}
