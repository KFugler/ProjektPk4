#include <iostream>
#include <string>
#include <vector>
#include "Directory.h"
#include "Tree.h"
#include "Url.h"

void fillTree(Tree& newTree);
void removeUrl(Tree& newTree);
void removeDirectory(Tree& newTree);
void updateUrl(Tree& newTree);
void printTree(Tree& newTree);

int main()
{
    Tree newTree;

    fillTree(newTree);

    printTree(newTree);

    removeUrl(newTree);

    printTree(newTree);

    updateUrl(newTree);

    printTree(newTree);

    removeDirectory(newTree);

    printTree(newTree);

    return 0;
}

void fillTree(Tree& newTree) {
    newTree.addDirectory("Ulubione", "Ulubione strony");

    auto directory = newTree.getDirectoryObjectByName("Ulubione");

    directory.addUrl("www.onet.pl", "strona z informacjami", "ikona.jpg");
    directory.addUrl("www.wp.pl", "strona z informacjami wpppp", "ikona.jpg");
    directory.addUrl("www.google.pl", "strona z informacjami google", "ikona.jpg");

    newTree.updateDirectory(directory);
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
    auto directory = newTree.getDirectoryObjectByName("Ulubione");
    auto url = directory.getUrlObjectByName("www.google.pl");

    url.setUrl("www.google.commmm");
    url.setIcon("gooogleee icon");

    directory.updateUrl(url);
    newTree.updateDirectory(directory);
}

void printTree(Tree& newTree) {
    int size = newTree.getItems().size();
    if (size > 0) {
        cout << "******Print tree items********" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "directory name: " << newTree.getItems()[i].getName() << endl;
            for (int c = 0; c < newTree.getItems()[i].getItems().size(); ++c) {
                cout << "-------------------------------------" << endl;
                cout << "url: " << newTree.getItems()[i].getItems()[c].getUrl() << endl;
                cout << "description: " << newTree.getItems()[i].getItems()[c].getDescription() << endl;
                cout << "icon: " << newTree.getItems()[i].getItems()[c].getIcon() << endl;
                cout << "id: " << newTree.getItems()[i].getItems()[c].getId() << endl;
            }
        }
    }
    else {
        cout << "No items to write" << endl;
    }
}
