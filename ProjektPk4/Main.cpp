#include <iostream>
#include <string>
#include "Directory.h"
#include "Tree.h"
#include "Url.h"
#include "File.h"
#include "Tag.h"
#include "TreeFile.h"


void removeUrl(Tree& newTree);
void removeDirectory(Tree& newTree);
void updateUrl(Tree& newTree);
void printTree(Tree& newTree);

int main()
{
    Tree newTree;
    TreeFile csv("MyFile.csv");

    csv.readTreeFile(newTree);

    printTree(newTree);

    updateUrl(newTree);

    //csv.writeFile(newTree);

    return 0;
}

void removeUrl(Tree& newTree) {
    cout << "!!! Remove www.wp.pl url !!!" << endl;
    auto directory = newTree.getDirectoryObjectByName("Ulubione");

    directory.removeUrl("www.wp.pl");

    newTree.updateDirectory(directory);
}

void removeDirectory(Tree& newTree) {
    cout << "!!! remove Ulubione directory !!!" << endl;
    newTree.removeDirectory("Ulubione");
}

void updateUrl(Tree& newTree) {
    cout << "test" << newTree.getDirectories()[0].getName() << endl;
    auto directory = newTree.getDirectoryObjectByName("Ulubione");
    auto url = directory.getUrlObjectByName("www.google.pl");

    url.setUrl("www.google.commmm");
    url.setIcon("gooogleee icon");
    url.addTag("tagi dla googleeeeeeeee");

    directory.updateUrl(url);
    newTree.updateDirectory(directory);
}

void printTree(Tree& newTree) {
    int size = newTree.getDirectories().size();
    if (size > 0) {
        cout << "******Print tree items********" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "directory name: " << newTree.getDirectories()[i].getName() << endl;
            for (int c = 0; c < newTree.getDirectories()[i].getUrls().size(); ++c) {
                cout << "-------------------------------------" << endl;
                cout << "url: " << newTree.getDirectories()[i].getUrls()[c].getUrl() << endl;
                cout << "description: " << newTree.getDirectories()[i].getUrls()[c].getDescription() << endl;
                cout << "icon: " << newTree.getDirectories()[i].getUrls()[c].getIcon() << endl;
                cout << "id: " << newTree.getDirectories()[i].getUrls()[c].getId() << endl;
                int tagsSize = newTree.getDirectories()[i].getUrls()[c].getTags().getItems().size();
                for (int t = 0; t < tagsSize; ++t) {
                    cout << "tag: " << newTree.getDirectories()[i].getUrls()[c].getTags().getItems()[t] << endl;
                }
            }
        }
    }
    else {
        cout << "No items to write" << endl;
    }
}
