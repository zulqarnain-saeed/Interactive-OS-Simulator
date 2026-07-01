#include "FCFSScheduler.h"


FCFSScheduler::FCFSScheduler(int capacity) : Scheduler(capacity) {}


void FCFSScheduler::addProcess(Process* p) {
    if (processCount < queueCapacity) {
        processQueue[processCount] = p;
        processCount++;
        cout << "Process " << p->getPID() << " added to FCFS queue" << endl;
    }
    else {
        cout << "Queue is full! Cannot add process." << endl;
    }
}


void FCFSScheduler::schedule() {
    cout << "\n=== FCFS Scheduling ===" << endl;
    if (processCount == 0) {
        cout << "No processes to schedule." << endl;
        return;
    }

    int totalTime = 0;
    for (int i = 0; i < processCount; i++) {
        if (processQueue[i] != nullptr) {
            cout << "Executing Process " << processQueue[i]->getPID()
                << " (" << processQueue[i]->getName() << ")" << endl;
            cout << "Burst Time: " << processQueue[i]->getBurstTime() << "ms" << endl;
            totalTime += processQueue[i]->getBurstTime();
            cout << "Cumulative Time: " << totalTime << "ms" << endl;
            cout << "-------------------" << endl;
        }
    }
    cout << "Total Execution Time: " << totalTime << "ms" << endl;
}


void FCFSScheduler::displayQueue() const {
    cout << "\n=== FCFS Process Queue ===" << endl;
    cout << "Scheduling Algorithm: First-Come First-Served" << endl;
    Scheduler::displayQueue();  
}