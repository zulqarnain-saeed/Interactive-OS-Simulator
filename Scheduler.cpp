#include "Scheduler.h"

int Scheduler::schedulerCreatedCount = 0;


Scheduler::Scheduler(int capacity) : queueCapacity(capacity), processCount(0) {
    processQueue = new Process * [queueCapacity];
    for (int i = 0; i < queueCapacity; i++) {
        processQueue[i] = nullptr;
    }
    schedulerCreatedCount++;
}


Scheduler::~Scheduler() {
    for (int i = 0; i < processCount; i++) {
        
        processQueue[i] = nullptr;
    }
    delete[] processQueue;
}


void Scheduler::displayQueue() const {
    cout << "\n=== Process Queue ===" << endl;
    cout << "Total Processes: " << processCount << endl;

    for (int i = 0; i < processCount; i++) {
        if (processQueue[i] != nullptr) {
            cout << "Queue Position " << i << ": ";
            processQueue[i]->display();
        }
    }
}

int Scheduler::getProcessCount() const {
    return processCount;
}