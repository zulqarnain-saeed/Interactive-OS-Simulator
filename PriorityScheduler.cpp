#include "PriorityScheduler.h"


PriorityScheduler::PriorityScheduler(int capacity) : Scheduler(capacity) {}


void PriorityScheduler::addProcess(Process* p) {
    if (processCount < queueCapacity) {
        processQueue[processCount] = p;
        processCount++;
        cout << "Process " << p->getPID() << " added to Priority queue" << endl;
    }
    else {
        cout << "Queue is full!" << endl;
    }
}


void PriorityScheduler::sortByPriority() {
    for (int i = 0; i < processCount - 1; i++) {
        for (int j = 0; j < processCount - i - 1; j++) {
            if (processQueue[j]->getPriority() < processQueue[j + 1]->getPriority()) {

                Process* temp = processQueue[j];
                processQueue[j] = processQueue[j + 1];
                processQueue[j + 1] = temp;
            }
        }
    }
}


void PriorityScheduler::schedule() {
    cout << "\n=== Priority Scheduling ===" << endl;
    if (processCount == 0) {
        cout << "No processes to schedule." << endl;
        return;
    }

    
    sortByPriority();

    int totalTime = 0;
    for (int i = 0; i < processCount; i++) {
        if (processQueue[i] != nullptr) {
            cout << "Executing Process " << processQueue[i]->getPID()
                << " (Priority: " << processQueue[i]->getPriority() << ")" << endl;
            cout << "Burst Time: " << processQueue[i]->getBurstTime() << "ms" << endl;
            totalTime += processQueue[i]->getBurstTime();
            cout << "Cumulative Time: " << totalTime << "ms" << endl;
            cout << "-------------------" << endl;
        }
    }
    cout << "Total Execution Time: " << totalTime << "ms" << endl;
}