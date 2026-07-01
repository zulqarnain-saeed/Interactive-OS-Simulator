# 🖥️ Interactive OS Simulator

An interactive, object-oriented simulation of core Operating System (OS) subsystems written in C++. This project provides a conceptual framework and a hands-on look at how an operating system handles processes, schedules execution cycles, allocates RAM dynamically, manages physical hardware devices, and handles file structures in real-time.

---

## 🛠️ System Architecture

The project is structured into modular, object-oriented components that interact dynamically through a central simulation loop:

              +-----------------------+
              |      SystemClock      |  (Drives simulation ticks)
              +-----------+-----------+
                          |
                          v
              +-----------------------+
              |     System Loop       |  (Core engine / main11.cpp)
              +---/-------|---------\-+
                 /        |          \
                v         v           v
   +---------------+ +---------------+ +---------------+
   | MemoryManager | |   Scheduler   | | DeviceManager |
   | (RAM Blocks)  | |(FCFS/Priority)| |  (Hardware)  |
   +---------------+ +---------------+ +---------------+
          |                                   |
          v                                   v
   +---------------+                   +---------------+
   |  FileSystem   |                   | I/O Request   |
   | (Disk Storage)|                   |    Queues     |
   +---------------+                   +---------------+

### 1. Process & CPU Scheduling
*   **`Process`**: Encapsulates the attributes of an OS process, including Process ID (PID), execution state (Ready, Running, Waiting, Terminated), priority level, dynamic memory requirements, and total CPU cycles needed.
*   **`Scheduler`**: An abstract base class defining the execution interface for processing task queues.
*   **`FCFSScheduler`**: Implements **First-Come, First-Served** non-preemptive scheduling. Processes are queued and executed sequentially based exactly on arrival sequence.
*   **`PriorityScheduler`**: Implements **Priority-Based** scheduling, sorting the execution pool so that higher priority workloads are handled first.

### 2. Memory Architecture
*   **`MemoryBlock`**: Represents a physical block or segment of RAM. Tracks allocation offsets, block size, availability flags, and holding process ownership details.
*   **`MemoryManager`**: The global memory controller responsible for mapping processes to dynamic partitions, validating allocation requests, avoiding out-of-memory states, and handling defragmentation/deallocation upon process exit.

### 3. File System & Device Infrastructure
*   **`FileSystem`**: Simulates hard drive data structures, managing file node generation, directory entries, content sizing, and basic reading/writing abstractions.
*   **`DeviceManager`**: Simulates motherboard I/O controller hardware. Manages attached peripherals (e.g., storage disks, input streams, external devices), processes resource locking, and handles blocking I/O queues.

### 4. Synchronization Core
*   **`SystemClock`**: Generates uniform timeline "ticks" that synchronize operations across all subsystems. Every discrete clock step updates execution progress, modifies resource allocation matrices, increments waiting cycles, and moves process lifetime states.

---

## 🚀 Getting Started

### Prerequisites
*   A modern C++ compiler supporting **C++11** or higher (e.g., `GCC/g++`, `Clang`, or MSVC).
*   `make` utility (Optional, for build automation).

### Compiling via CLI
Navigate to the root directory of the project and compile using your preferred toolchain:

```bash
# Using g++ to compile all modules together
g++ -std=c++11 *.cpp -o OSSimulator
Execution
Run the compiled binary executable:

Bash
./OSSimulator
🎮 How to Interact with the Simulator
Upon starting, main11.cpp initiates a text-based, interactive Command-Line Interface (CLI). You can fully drive the simulated kernel using standard terminal controls:

Configure Scheduler: Toggle your primary operating scheduling metric between FCFS and Priority modes before launching queues.

Spawn Processes: Programmatically inject dynamic processes with tailored parameters (e.g., custom sizes, specific cycle durations, or priority indices).

Trace Subsystems: Print active memory grid maps via the MemoryManager layout or review hardware block state flags inside the DeviceManager.

Execute Cycles: Advance the global time frame by manual integer step iterations or toggle continuous execution mode to witness real-time kernel dispatch changes.

📂 Repository File Index
.
├── DeviceManager.cpp      # Physical device queue & lock logic
├── DeviceManager.h        # Device structural schemas
├── FCFSScheduler.cpp      # First-Come First-Served scheduling path
├── FCFSScheduler.h        # FCFS structure definition
├── FileSystem.cpp         # Disk block node simulation
├── FileSystem.h           # Directory layout structures
├── MemoryBlock.cpp        # RAM allocation block entities
├── MemoryBlock.h          # Memory segment data mappings
├── MemoryManager.cpp      # Global RAM segment partitioning/freeing
├── MemoryManager.h        # Memory allocation interface definitions
├── PriorityScheduler.cpp  # Priority-based cycle dispatching
├── PriorityScheduler.h    # Priority queue class architecture
├── Process.cpp            # Process lifecycles and state machines
├── Process.h              # State constants and process control blocks
├── Scheduler.cpp          # Universal scheduling pipeline patterns
├── Scheduler.h            # Base abstract scheduling contract
├── SystemClock.cpp        # Global tick generator implementation
├── SystemClock.h          # Time state structures
└── main11.cpp             # User shell console UI and primary state machine
📜 License
This project is for educational and simulation purposes. Feel free to fork, expand, or repurpose the components for academic study!
