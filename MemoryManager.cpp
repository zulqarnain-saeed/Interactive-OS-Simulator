#include "MemoryManager.h"


MemoryManager::MemoryManager() : capacity(10), blockCount(0), totalMemory(1000) {
    memoryBlocks = new MemoryBlock * [capacity];
    initializeBlocks();
}


MemoryManager::MemoryManager(int totalMem, int blockCapacity)
    : capacity(blockCapacity), blockCount(0), totalMemory(totalMem) {
    memoryBlocks = new MemoryBlock * [capacity];
    initializeBlocks();
}


MemoryManager::MemoryManager(const MemoryManager& other) {
    capacity = other.capacity;
    blockCount = other.blockCount;
    totalMemory = other.totalMemory;

    memoryBlocks = new MemoryBlock * [capacity];
    for (int i = 0; i < blockCount; i++) {
        memoryBlocks[i] = new MemoryBlock(*other.memoryBlocks[i]);
    }
}


MemoryManager::~MemoryManager() {
    for (int i = 0; i < blockCount; i++) {
        delete memoryBlocks[i];
    }
    delete[] memoryBlocks;
}


void MemoryManager::initializeBlocks() {
    int blockSize = totalMemory / capacity;
    for (int i = 0; i < capacity; i++) {
        memoryBlocks[i] = new MemoryBlock(i + 1, blockSize);
        blockCount++;
    }
}


bool MemoryManager::allocateFirstFit(int size, string processName) {
    for (int i = 0; i < blockCount; i++) {
        if (!memoryBlocks[i]->isAllocated() && memoryBlocks[i]->getSize() >= size) {
            memoryBlocks[i]->allocate(processName);
            return true;
        }
    }
    return false;
}


bool MemoryManager::allocateBestFit(int size, string processName) {
    int bestFitIndex = -1;
    int minDifference = totalMemory + 1;

    for (int i = 0; i < blockCount; i++) {
        if (!memoryBlocks[i]->isAllocated()) {
            int blockSize = memoryBlocks[i]->getSize();
            if (blockSize >= size) {
                int difference = blockSize - size;
                if (difference < minDifference) {
                    minDifference = difference;
                    bestFitIndex = i;
                }
            }
        }
    }

    if (bestFitIndex != -1) {
        memoryBlocks[bestFitIndex]->allocate(processName);
        return true;
    }
    return false;
}


void MemoryManager::deallocate(string processName) {
    for (int i = 0; i < blockCount; i++) {
        if (memoryBlocks[i]->isAllocated() &&
            memoryBlocks[i]->getProcessName() == processName) {
            memoryBlocks[i]->deallocate();
        }
    }
}


void MemoryManager::displayMemoryMap() const {
    cout << "\n=== Memory Map ===" << endl;
    cout << "Total Memory: " << totalMemory << "KB" << endl;
    cout << "Allocated Memory: " << MemoryBlock::getTotalAllocated() << "KB" << endl;
    cout << "Free Memory: " << (totalMemory - MemoryBlock::getTotalAllocated()) << "KB" << endl;

    for (int i = 0; i < blockCount; i++) {
        memoryBlocks[i]->display();
    }
}

void MemoryManager::createMemoryLeak() {
    cout << "\n=== Creating Memory Leak (for demonstration) ===" << endl;
    MemoryBlock* leakedBlock = new MemoryBlock(999, 100);  
    leakedBlock->allocate("LEAK_PROCESS");
    cout << "Memory allocated but pointer will be lost (Memory Leak Created)" << endl;
  
}


MemoryBlock* MemoryManager::createDanglingPointer() {
    MemoryBlock* tempBlock = new MemoryBlock(888, 50);
    tempBlock->allocate("TEMP_PROCESS");

    delete tempBlock;  

    cout << "Dangling pointer created (points to freed memory)" << endl;
    return tempBlock;  
}


int MemoryManager::getTotalMemory() const { return totalMemory; }
int MemoryManager::getFreeMemory() const {
    return totalMemory - MemoryBlock::getTotalAllocated();
}