#include "MemoryBlock.h"

int MemoryBlock::totalAllocatedMemory = 0;

MemoryBlock::MemoryBlock(int id, int s) : blockID(id), size(s) {
    allocated = false;
    processName = "";
}


int MemoryBlock::getBlockID() const { return blockID; }
int MemoryBlock::getSize() const { return size; }
bool MemoryBlock::isAllocated() const { return allocated; }
string MemoryBlock::getProcessName() const { return processName; }

// Setters
void MemoryBlock::allocate(string pName) {
    allocated = true;
    processName = pName;
    totalAllocatedMemory += size;
}

void MemoryBlock::deallocate() {
    totalAllocatedMemory -= size;
    allocated = false;
    processName = "";
}


void MemoryBlock::display() const {
    cout << "Block ID: " << blockID
        << ", Size: " << size << "KB"
        << ", Allocated: " << (allocated ? "Yes" : "No");
    if (allocated) {
        cout << ", Process: " << processName;
    }
    cout << endl;
}


int MemoryBlock::getTotalAllocated() {
    return totalAllocatedMemory;
}