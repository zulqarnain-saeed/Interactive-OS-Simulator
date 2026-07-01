#include "FileSystem.h"


File::File() : fileName("untitled"), fileSize(0), content("") {}

File::File(string name, int size) : fileName(name), fileSize(size), content("") {}

string File::getFileName() const { return fileName; }
int File::getFileSize() const { return fileSize; }
string File::getContent() const { return content; }

void File::setContent(string cont) {
    content = cont;
    fileSize = cont.length();
}


File File::operator+(const File& other) const {
    string newName = fileName + "_merged_" + other.fileName;
    int newSize = fileSize + other.fileSize;
    string newContent = content + other.content;

    File merged(newName, newSize);
    merged.setContent(newContent);
    return merged;
}

bool File::operator>(const File& other) const {
    return fileSize > other.fileSize;
}

bool File::operator==(const File& other) const {
    return fileName == other.fileName;
}


ostream& operator<<(ostream& os, const File& f) {
    os << "File: " << f.fileName << " (" << f.fileSize << " bytes)";
    return os;
}

istream& operator>>(istream& is, File& f) {
    cout << "Enter file name: ";
    is >> f.fileName;
    cout << "Enter file size: ";
    is >> f.fileSize;
    return is;
}

void File::display() const {
    cout << *this << endl;
    if (!content.empty()) {
        cout << "Content: " << content.substr(0, 50);
        if (content.length() > 50) cout << "...";
        cout << endl;
    }
}



Directory::Directory(string name) : dirName(name), fileCount(0) {
    for (int i = 0; i < 10; i++) {
        files[i] = nullptr;
    }
}

Directory::~Directory() {
    for (int i = 0; i < fileCount; i++) {
        delete files[i];  
    }
}

bool Directory::addFile(File* f) {
    if (fileCount < 10) {
        files[fileCount] = f;
        fileCount++;
        return true;
    }
    return false;
}

void Directory::listFiles() const {
    cout << "\n=== Directory: " << dirName << " ===" << endl;
    cout << "Total Files: " << fileCount << endl;

    for (int i = 0; i < fileCount; i++) {
        if (files[i] != nullptr) {
            cout << i + 1 << ". ";
            files[i]->display();
        }
    }
}

File* Directory::searchFile(string name) const {
    for (int i = 0; i < fileCount; i++) {
        if (files[i] != nullptr && files[i]->getFileName() == name) {
            return files[i];
        }
    }
    return nullptr;
}