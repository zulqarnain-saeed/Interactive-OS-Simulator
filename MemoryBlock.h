#pragma once
#include <iostream>
#include <string>

using namespace std;

class MemoryBlock {
private:
    const int blockID;  
    int size;
    bool allocated;
    string processName;

public:
   
    MemoryBlock(int id, int s);

    
    int getBlockID() const;
    int getSize() const;
    bool isAllocated() const;
    string getProcessName() const;

    
    void allocate(string pName);
    void deallocate();

   
    void display() const;

    
    static int totalAllocatedMemory;
    static int getTotalAllocated();
};