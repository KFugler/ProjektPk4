#include <iostream>
#include <string>
#include "Directory.h"
#include "Tree.h"
#include "Url.h"
#include "File.h"
#include "Tag.h"
#include "TreeFile.h"
#include "User.h"
#include "UserList.h"
#include "UserFile.h"


void removeUrl(Tree& newTree);
void removeDirectory(Tree& newTree);
void updateUrl(Tree& newTree);
void printTree(Tree& newTree);
void addTreeScheme(Tree& newTree);
Directory getFromTree(string name, Tree& newTree);

int main()
{
    Tree newTree;
    TreeFile csv("MyFile.csv");

    csv.readTreeFile(newTree);

    printTree(newTree);

    updateUrl(newTree);

    addTreeScheme(newTree);

   // csv.writeFile(newTree);


    //testy user
    UserList newUserList;
    UserFile userscsv("users.csv");
    userscsv.readUserFile(newUserList);

    //newUserList.registerUser("user3", "password3");
    newUserList.loginUser("user1", "password1");

    userscsv.writeUserFile(newUserList);

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

void addTreeScheme(Tree& newTree)
{
    std::cout << endl;

    Directory test = getFromTree("Ulubione", newTree);  //dodanie do directory "Ulubione" podfolder?w by tworzy? struktur? drzewa 
    test.addDirectory("SPORT", "Strony sportowe");
    test.addDirectory("WIADOMOSCI", "Strony informacyjne");

    newTree.updateDirectory(test);
    auto temp = getFromTree("Ulubione", newTree).getDirectories();
    for (int i = 0; i < temp.size(); i++)
    {
        std::cout << temp[i].getName() << "  " << temp[i].getDescription() << std::endl;
    }

    Directory temp2 = getFromTree("SPORT", newTree);    //dodanie URLI do podfoldedru o nazwie SPORT
    temp2.addUrl("www.sport.pl", "strona z wynikami meczow", "default icon", { "tag1","tag2" });
    temp2.addUrl("www.meczyki.pl", "strona ze streamami", "default icon", { "tag3","tag4" });
    newTree.updateDirectory(temp2);

    std::cout << endl;
}

Directory getFromTree(string name, Tree& newTree) // ustawianie przeszukiwania drzewa od pierwszego elementu
{
    Directory dir = newTree.getDirectories()[0];
    return newTree.getFromWholeTree(name, dir);
}
