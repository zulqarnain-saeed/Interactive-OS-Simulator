#pragma once
#include <iostream>
#include <string>
#include "MemoryBlock.h"

using namespace std;

class MemoryManager {
private:
    MemoryBlock** memoryBlocks;  
    int capacity;
    int blockCount;
    int totalMemory;

    void initializeBlocks();

public:
   
    MemoryManager();  
    MemoryManager(int totalMem, int blockCapacity); 
    MemoryManager(const MemoryManager& other); 

    ~MemoryManager();

    
    bool allocateFirstFit(int size, string processName);
    bool allocateBestFit(int size, string processName);

    
    void deallocate(string processName);

    
    void displayMemoryMap() const;

    
    void createMemoryLeak();

    
    MemoryBlock* createDanglingPointer();

    
    int getTotalMemory() const;
    int getFreeMemory() const;
};