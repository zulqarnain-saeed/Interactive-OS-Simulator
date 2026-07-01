#pragma once
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class File {
private:
    string fileName;
    int fileSize;
    string content;

public:
    File();
    File(string name, int size);

    string getFileName() const;
    int getFileSize() const;
    string getContent() const;

    
    void setContent(string cont);

    
    File operator+(const File& other) const;  
    bool operator>(const File& other) const;  
    bool operator==(const File& other) const; 

    
    friend ostream& operator<<(ostream& os, const File& f);
    friend istream& operator>>(istream& is, File& f);

    void display() const;
};

class Directory {
private:
    string dirName;
    File* files[10];  //Composition
    int fileCount;

public:
    Directory(string name);
    ~Directory();  


    bool addFile(File* f);

    void listFiles() const;

   
    File* searchFile(string name) const;
};