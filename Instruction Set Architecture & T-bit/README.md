# Instruction Set Architecture & T-bit

## Project Description
This project demonstrates the importance of the T-bit in function execution within an embedded system. We start by invoking a function through a function pointer, which works correctly. However, when attempting to call the same function directly using its address, a HardFault occurs. The project explores the root cause by analyzing the disassembly and understanding the automatic setting of the T-bit during runtime, explaining its critical role in proper function execution.

## Setup Instructions

### Prerequisites

- **Development Environment:** Ensure you have STM32CubeIDE or a similar ARM development environment installed.
- **STM32 Development Board:** The project can be adapted to various ARM Cortex-M-based boards.
- **Debugger:** Use an ST-Link or equivalent to flash and debug the project.

### Step 1: Create an Empty STM32CubeIDE Project

1. **Open STM32CubeIDE** and create a new project.
2. **Select Your Target MCU/Board:** Choose an appropriate ARM Cortex-M MCU or board.
3. **Configure the Project:** Select the "Empty project" option.
4. **Generate the Project Code:** STM32CubeIDE will generate the necessary project files.

### Step 2: Copy the Source Code

1. **Copy the Provided Source Files:** Navigate to the project folder in this repository and copy the source file (`main.c`) into your STM32CubeIDE project.

### Step 3: Build and Run

1. **Build the Project:** Compile the project in STM32CubeIDE.
2. **Connect to the Target:** Use a debugger such as ST-Link to connect to your STM32 board.
3. **Start Debugging:** Begin debugging and observe how function pointers work correctly, but direct function calls result in a HardFault.

### Notes

- **Understanding the T-bit:** The T-bit is part of the ARM processor's Program Status Register (PSR) and controls whether the CPU is in Thumb mode. A mismatch in the T-bit state during function calls can lead to a HardFault.
- **Disassembly View:** Use the disassembly view in your IDE to track how the T-bit is automatically set or cleared during runtime.

This project provides a hands-on exploration of the T-bit's role in ARM's Instruction Set Architecture (ISA). It demonstrates the importance of understanding this bit for proper function execution and debugging in embedded systems.
