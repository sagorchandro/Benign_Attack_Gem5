**Attack vs Benign C Code Dataset: Side-Channel Attack Detection using
gem5 and Machine Learning**

**Overview**

This dataset contains a collection of C programs categorized into two
classes: Attack and Benign.\
The goal of this dataset is to support research in computer architecture
security, microarchitectural attack detection, and machine learning
based program behavior analysis. The dataset was designed to help
researchers and students analyze differences between normal program
behavior and security-oriented attack patterns at the source code level
and during runtime execution.

It can be used for:

- Microarchitectural security research

- Machine learning--based attack detection

- Computer architecture education

- gem5 simulation experiments

- Program behavior classification

- Side-channel and speculative execution studies

**Example Code**

![](https://github.com/sagorchandro/Benign_Attack_Gem5/blob/main/AttackBenign.jpg 

Security vulnerability analysis of a RISC-V fault-timing side-channel
attack: annotated code regions mapped to their corresponding
microarchitectural and software-level weaknesses

**Dataset Structure**

The dataset is organized into two main categories.

Generated_programs/

│

├── benign/

│ └── Benign Codes/

│ ├── benign_001.c

│ ├── benign_002.c

│ ├── \...

│ └── Benign Stats/

│ ├── benign_001_stats.txt

│ ├── benign_002_stats.txt

│ ├──.....

│ └── Benign Binaries/

│ ├── benign_001_binary.out

│ ├── benign_002_binary.out

│ ├──

│└── attack/

│ └── Attack Codes/

│ ├── attack_001.c

│ ├── attack_002.c

│ ├── \...

│ └── Attack Stats/

│ ├── attack_001_stats.txt

│ ├── attack_002_stats.txt

│ ├── \...

│ └── Attack Binaries/

│ ├── attack_001_binary.out

│ ├── attack_002_binary.out

│ ├──........

**Dataset Categories**

**1. Benign Programs**

The benign programs contain standard C implementations of typical
programming tasks.\
These programs represent normal software behavior.

Examples include:

- Mathematical computations

- Array and matrix operations

- Loop and conditional logic

- Memory access patterns

- Sorting algorithms

- Input/output operations

- Basic data structure manipulations

Purpose:

- Provide baseline program behavior

- Train models to recognize normal execution patterns

- Compare runtime characteristics with attack programs

**2. Attack Programs**

The attack programs simulate security-related behaviors that may appear
in malicious or exploitative code patterns. These programs are designed
to reproduce behaviors useful for studying microarchitectural
vulnerabilities and attack patterns.

Examples may include:

- Cache-based memory access patterns

- Timing-dependent memory operations

- Speculative execution related patterns

- Side-channel inspired memory accesses

- Controlled memory manipulation sequences

Purpose:

- Study security vulnerabilities in computer architecture

- Train ML models to detect malicious program behavior

- Generate execution traces for hardware security analysis

**Intended Use**

This dataset can be used in several research areas.

**1. Computer Architecture Security**

Researchers can analyze program execution in simulators such as:

- gem5

- QEMU

**2. Machine Learning for Security**

The dataset can be used to train models such as:

- Random Forest

- Support Vector Machines

- Neural Networks

- Transformers for code analysis

- Graph Neural Networks on program graphs

Tasks may include:

- Attack vs benign classification

- Program behavior prediction

- Vulnerability detection

**3. Program Analysis**

Possible analysis techniques include:

- Static code analysis

- Runtime trace analysis

**Install Dependencies**

To compile and run the programs in this dataset, install the following
tools:

A.  **GCC Compiler (for native execution)**

Ubuntu / Debian:

sudo apt update\
sudo apt install build-essential

Verify installation:

gcc \--version

B.  **RISC-V Cross Compiler (for gem5 experiments)**

sudo apt install gcc-riscv64-linux-gnu

Verify:

riscv64-linux-gnu-gcc \--version

C.  **Python (optional for dataset processing)**

sudo apt install python3 python3-pip

D.  **gem5 Simulator (for architectural experiments)**

Clone gem5:

git clone https://github.com/gem5/gem5.git\
cd gem5

Build for RISC-V:

scons build/RISCV/gem5.opt -j\$(nproc)

Verify:

./build/RISCV/gem5.opt \--help

E.  **Example Usage**

**Compile a program**

gcc benign_001.c -o benign_001 ./benign_001

**Compile for RISC-V**

riscv64-unknown-linux-gnu-gcc attack_001.c -o attack_001.out

**Run in gem5**

./build/RISCV/gem5.opt configs/deprecated/example/se.py -c
attack_001.out

This allows researchers to analyze:

- execution traces

- cache behavior

- memory access patterns

- microarchitectural side effects

**Possible Research Applications**

- Microarchitectural attack detection

- Hardware security evaluation

- Malware behavior classification

- Program behavior modeling

- AI-based vulnerability detection

- Runtime anomaly detection

**Ethical Considerations**

The attack programs included in this dataset are intended only for
research and educational purposes.

They should be used in:

- controlled environments

- research laboratories

- secure simulation platforms

The dataset must not be used for malicious activities.
