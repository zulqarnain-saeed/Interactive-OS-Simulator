#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Process.h"
#include "MemoryManager.h"
#include "FCFSScheduler.h"
#include "PriorityScheduler.h"
#include "FileSystem.h"
#include "SystemClock.h"
#include "DeviceManager.h"

using namespace std;

class InteractiveOSSimulator {
private:
    vector<Process*> processTable;
    MemoryManager* memoryManager;
    DeviceManager* deviceManager;
    SystemClock* systemClock;

public:
    InteractiveOSSimulator() {
        memoryManager = new MemoryManager(2048, 64);
        deviceManager = new DeviceManager();
        systemClock = SystemClock::getInstance();
        initializeDefaultDevices();
    }

    ~InteractiveOSSimulator() {
        for (auto process : processTable) {
            delete process;
        }
        delete memoryManager;
        delete deviceManager;
    }

private:
    void initializeDefaultDevices() {
        deviceManager->addDevice(new Device("Printer"));
        deviceManager->addDevice(new Device("Scanner"));
        deviceManager->addDevice(new Device("Modem"));
    }

    void displayMainMenu() {
        cout << "\n===========================================" << endl;
        cout << "      INTERACTIVE OS SIMULATOR" << endl;
        cout << "===========================================" << endl;
        cout << "1. Create New Process" << endl;
        cout << "2. View All Processes" << endl;
        cout << "3. Allocate Memory to Process" << endl;
        cout << "4. Run CPU Scheduling" << endl;
        cout << "5. Manage Devices" << endl;
        cout << "6. View Memory Status" << endl;
        cout << "7. View Device Status" << endl;
        cout << "8. Advanced Operations" << endl;
        cout << "9. Exit Simulator" << endl;
        cout << "===========================================" << endl;
        cout << "System Time: " << systemClock->getTime() << endl;
        cout << "Total Processes: " << processTable.size() << endl;
        cout << "===========================================" << endl;
        cout << "Enter your choice: ";
    }

    void createNewProcess() {
        cout << "\n=== CREATE NEW PROCESS ===" << endl;

        int pid, priority, cpuTime;
        string name;
        size_t memory;

        cout << "Enter Process ID: ";
        cin >> pid;
        cin.ignore();

        for (auto process : processTable) {
            if (process->getPID() == pid) {
                cout << "Error: Process ID " << pid << " already exists!" << endl;
                return;
            }
        }

        cout << "Enter Process Name: ";
        getline(cin, name);

        cout << "Enter Priority (1-10, 1=highest): ";
        cin >> priority;

        cout << "Enter Required Memory (KB): ";
        cin >> memory;

        cout << "Enter CPU Time Required (units): ";
        cin >> cpuTime;

        Process* newProcess = new Process(pid, name, priority, memory, cpuTime);
        processTable.push_back(newProcess);

        cout << "\n✓ Process created successfully!" << endl;
        cout << "Process Details:" << endl;
        newProcess->display();

        systemClock->tick(1);
    }

    void viewAllProcesses() {
        cout << "\n=== PROCESS TABLE (PCB) ===" << endl;
        cout << "Total Processes: " << processTable.size() << endl;
        cout << "----------------------------" << endl;

        if (processTable.empty()) {
            cout << "No processes running." << endl;
            return;
        }

        for (size_t i = 0; i < processTable.size(); i++) {
            cout << "[" << i << "] ";
            processTable[i]->display();
            cout << endl;
        }
    }

    void allocateMemoryToProcess() {
        cout << "\n=== MEMORY ALLOCATION ===" << endl;

        if (processTable.empty()) {
            cout << "No processes available. Create a process first." << endl;
            return;
        }

        viewAllProcesses();
        cout << "\nSelect process index to allocate memory: ";
        int index;
        cin >> index;

        if (index < 0 || index >= processTable.size()) {
            cout << "Invalid index!" << endl;
            return;
        }

        Process* selectedProcess = processTable[index];
        size_t requiredMemory = selectedProcess->getMemoryRequired();

        cout << "\nAllocating " << requiredMemory << "KB for process: "
            << selectedProcess->getName() << endl;

        bool allocated = memoryManager->allocateFirstFit(
            requiredMemory,
            selectedProcess->getName()
        );

        if (allocated) {
            cout << "✓ Memory allocated successfully!" << endl;
            cout << "Process state: Ready (Memory Allocated)" << endl;
        }
        else {
            cout << "✗ Memory allocation failed! Not enough contiguous memory." << endl;
        }

        systemClock->tick(1);
    }

    void runCPUScheduling() {
        cout << "\n=== CPU SCHEDULING ===" << endl;

        if (processTable.empty()) {
            cout << "No processes to schedule." << endl;
            return;
        }

        cout << "Select scheduling algorithm:" << endl;
        cout << "1. First-Come, First-Served (FCFS)" << endl;
        cout << "2. Priority Scheduling" << endl;
        cout << "3. View scheduling queues" << endl;
        cout << "Choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            FCFSScheduler fcfs(processTable.size());
            cout << "\n--- FCFS Scheduling ---" << endl;

            for (auto process : processTable) {
                fcfs.addProcess(process);
            }

            cout << "Scheduling Queue:" << endl;
            fcfs.displayQueue();
            cout << "\nExecuting..." << endl;
            fcfs.schedule();
            break;
        }
        case 2: {
            PriorityScheduler ps(processTable.size());
            cout << "\n--- Priority Scheduling ---" << endl;

            for (auto process : processTable) {
                ps.addProcess(process);
            }

            cout << "Scheduling Queue (sorted by priority):" << endl;
            ps.displayQueue();
            cout << "\nExecuting..." << endl;
            ps.schedule();
            break;
        }
        case 3: {
            cout << "\n--- Process States ---" << endl;
            for (auto process : processTable) {
                cout << process->getName() << " (PID: " << process->getPID()
                    << ") - Priority: " << process->getPriority()
                    << ", CPU Time: " << process->getBurstTime() << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
        }

        systemClock->tick(2);
    }

    void manageDevices() {
        cout << "\n=== DEVICE MANAGEMENT ===" << endl;

        if (processTable.empty()) {
            cout << "No processes available. Create a process first." << endl;
            return;
        }

        cout << "1. Allocate device to process" << endl;
        cout << "2. Release device" << endl;
        cout << "3. View device status" << endl;
        cout << "Choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            viewAllProcesses();
            cout << "\nSelect process index: ";
            int procIndex;
            cin >> procIndex;

            if (procIndex < 0 || procIndex >= processTable.size()) {
                cout << "Invalid process index!" << endl;
                return;
            }

            cout << "\nAvailable Devices:" << endl;
            cout << "1. Printer" << endl;
            cout << "2. Scanner" << endl;
            cout << "3. Modem" << endl;

            cout << "Select device (enter name): ";
            string deviceName;
            cin >> deviceName;

            deviceManager->allocateDevice(deviceName, processTable[procIndex]);
            break;
        }
        case 2: {
            cout << "\nEnter device name to release: ";
            string deviceName;
            cin >> deviceName;
            deviceManager->releaseDevice(deviceName);
            break;
        }
        case 3:
            deviceManager->displayAllDevices();
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

        systemClock->tick(1);
    }

    void viewMemoryStatus() {
        cout << "\n=== MEMORY STATUS ===" << endl;
        cout << "Memory Manager Information:" << endl;
        memoryManager->displayMemoryMap();

        cout << "\nSystem Statistics:" << endl;
        cout << "Total allocated memory: "
            << MemoryBlock::getTotalAllocated() << "KB" << endl;
        cout << "Total processes in memory: " << processTable.size() << endl;
    }

    void viewDeviceStatus() {
        cout << "\n=== DEVICE STATUS ===" << endl;
        deviceManager->displayAllDevices();
    }

    void advancedOperations() {
        cout << "\n=== ADVANCED OPERATIONS ===" << endl;
        cout << "1. Create multiple processes (batch)" << endl;
        cout << "2. Run complete simulation cycle" << endl;
        cout << "3. Clear all processes" << endl;
        cout << "4. View system statistics" << endl;
        cout << "Choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            createBatchProcesses();
            break;
        case 2:
            runSimulationCycle();
            break;
        case 3:
            clearAllProcesses();
            break;
        case 4:
            displaySystemStatistics();
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    void createBatchProcesses() {
        cout << "\n=== BATCH PROCESS CREATION ===" << endl;
        cout << "Creating 3 sample processes..." << endl;

        processTable.push_back(new Process(1001, "System_Service", 1, 256, 50));
        processTable.push_back(new Process(1002, "User_Application", 3, 512, 30));
        processTable.push_back(new Process(1003, "Background_Task", 5, 128, 20));

        cout << "✓ 3 processes created successfully!" << endl;
        systemClock->tick(3);
    }

    void runSimulationCycle() {
        cout << "\n=== SIMULATION CYCLE ===" << endl;
        cout << "Running complete OS cycle..." << endl;

        cout << "\n1. Current Process Table:" << endl;
        viewAllProcesses();

        cout << "\n2. Memory Allocation Phase:" << endl;
        for (auto process : processTable) {
            cout << "Allocating memory for " << process->getName() << "... ";
            if (memoryManager->allocateFirstFit(process->getMemoryRequired(), process->getName())) {
                cout << "✓ Success" << endl;
            }
            else {
                cout << "✗ Failed" << endl;
            }
        }

        cout << "\n3. Memory Status:" << endl;
        viewMemoryStatus();

        cout << "\n4. Running Priority Scheduling:" << endl;
        PriorityScheduler ps(processTable.size());
        for (auto process : processTable) {
            ps.addProcess(process);
        }
        ps.schedule();

        cout << "\n✓ Simulation cycle completed!" << endl;
        systemClock->tick(5);
    }

    void clearAllProcesses() {
        cout << "\nAre you sure you want to clear all processes? (y/n): ";
        char confirm;
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            for (auto process : processTable) {
                delete process;
            }
            processTable.clear();
            cout << "✓ All processes cleared!" << endl;
        }
    }

    void displaySystemStatistics() {
        cout << "\n=== SYSTEM STATISTICS ===" << endl;
        cout << "System Time: " << systemClock->getTime() << " units" << endl;
        cout << "Total Processes Created: " << Process::getTotalProcessCount() << endl;
        cout << "Currently Running Processes: " << processTable.size() << endl;
        cout << "Total Memory Allocated: "
            << MemoryBlock::getTotalAllocated() << "KB" << endl;
        cout << "Memory Manager Status:" << endl;
        memoryManager->displayMemoryMap();
    }

public:
    void run() {
        cout << "Initializing Interactive OS Simulator..." << endl;
        cout << "System components loaded successfully." << endl;
        cout << "Default devices: Printer, Scanner, Modem" << endl;

        int choice;
        do {
            displayMainMenu();
            cin >> choice;

            switch (choice) {
            case 1:
                createNewProcess();
                break;
            case 2:
                viewAllProcesses();
                break;
            case 3:
                allocateMemoryToProcess();
                break;
            case 4:
                runCPUScheduling();
                break;
            case 5:
                manageDevices();
                break;
            case 6:
                viewMemoryStatus();
                break;
            case 7:
                viewDeviceStatus();
                break;
            case 8:
                advancedOperations();
                break;
            case 9:
                cout << "\nShutting down OS Simulator..." << endl;
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }

        } while (choice != 9);
    }
};

int main() {
    InteractiveOSSimulator osSimulator;
    osSimulator.run();

    return 0;
}