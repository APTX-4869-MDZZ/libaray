#include "Ebook.h"
#include <vector>
#include <fstream>
#include <iostream>

vector<Ebook> Ebook::ebookList = Ebook::readEbook("ebook.txt");

vector<Ebook> Ebook::readEbook(string fileName) {
    vector<Ebook> ebookList;
    fstream f(fileName, ios::in);
    if (f.bad()) {
        cout << "�����ļ��򿪳���";
        exit(0);
    }
    while (!f.eof()) {
        string book;
        string name;
        f >> book >> name;
        Ebook ebook = Ebook(book, name);
        ebookList.push_back(ebook);
    }
    f.close();
    return ebookList;
}

void Ebook::writeEbook(string fileName) {
    fstream f(fileName, ios::out);
    if (f.bad()) {
        cout << "����Ա�ļ��򿪳���";
        exit(0);
    }
    int i = 0;
    vector<Ebook>::iterator it;
    for (it = ebookList.begin(); it != ebookList.end(); it++) {
        f << it->getBook() << ' ' << it->getName();
        i++;
        if (i != ebookList.size()) {
            f << endl;
        }
    }
    f.close();
};
