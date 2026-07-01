#include "Process.h"


int Process::processCount = 0;

Process::Process() : pid(0), name("Default"), priority(0), memoryRequired(0), burstTime(0) {
    processCount++;
}


Process::Process(int id, string n, int p, int mem, int bt)
    : pid(id), name(n), priority(p), memoryRequired(mem), burstTime(bt) {
    processCount++;
}


Process::Process(const Process& other) {
    pid = other.pid;
    name = other.name;
    priority = other.priority;
    memoryRequired = other.memoryRequired;
    burstTime = other.burstTime;
    processCount++;
}


Process::~Process() {
    processCount--;
}


int Process::getPID() const { return pid; }
string Process::getName() const { return name; }
int Process::getPriority() const { return priority; }
int Process::getMemoryRequired() const { return memoryRequired; }
int Process::getBurstTime() const { return burstTime; }


void Process::setPID(int id) { pid = id; }
void Process::setName(string n) { name = n; }
void Process::setPriority(int p) { priority = p; }
void Process::setMemoryRequired(int mem) { memoryRequired = mem; }
void Process::setBurstTime(int bt) { burstTime = bt; }


bool Process::operator==(const Process& other) const {
    return (pid == other.pid && name == other.name);
}

Process Process::operator+(const Process& other) const {
   
    int newPID = pid + other.pid;
    string newName = name + "_" + other.name;
    int newPriority = (priority + other.priority) / 2;
    int newMemory = memoryRequired + other.memoryRequired;
    int newBurst = burstTime + other.burstTime;

    return Process(newPID, newName, newPriority, newMemory, newBurst);
}


void displayProcessDetails(const Process& p) {
    cout << "Friend Function Access: PID=" << p.pid << ", Name=" << p.name << endl;
}


void Process::display() const {
    cout << "PID: " << pid
        << ", Name: " << name
        << ", Priority: " << priority
        << ", Memory: " << memoryRequired << "KB"
        << ", Burst Time: " << burstTime << "ms" << endl;
}


int Process::getTotalProcessCount() {
    return processCount;
}