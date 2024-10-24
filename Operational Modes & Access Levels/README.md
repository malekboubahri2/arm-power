# Operational Modes and Access Levels

This project demonstrates how to manipulate operational modes and access levels of a Cortex-M microcontroller (MCU). It provides practical examples of switching between different operational modes and privileged mode.

## Setup Instructions

### Prerequisites

- **Development Environment:** Ensure you have STM32CubeIDE or a similar ARM development environment installed.
- **STM32 Development Board:** This project was tested on the STM32U585-IOT02A board but can be adapted for other STM32 microcontrollers.
- **Debugger:** Use an ST-Link or equivalent to flash and debug the project.

### Step 1: Create an Empty STM32CubeIDE Project

1. **Open STM32CubeIDE** and create a new project.
2. **Select Your Target MCU/Board:** Choose the appropriate Cortex-M MCU or board.
3. **Configure the Project:** Select the "Empty project" option.
4. **Generate the Project Code:** STM32CubeIDE will generate the necessary project files.

### Step 2: Copy the Source Code

1. **Copy the Provided Source Files:** Navigate to the project folder in this repository and copy the source file (`main.c`) into your STM32CubeIDE project.

### Step 3: Build and Run

1. **Build the Project:** Compile the project within STM32CubeIDE.
2. **Connect to the Target:** Use a debugger such as ST-Link to connect to your STM32 board.
3. **Start Debugging:** Begin debugging to observe operational mode transitions and access level changes.

### Notes

- **Debugging Mode Transitions:** Use a debugger to track the changes in operational modes and access levels in real-time.
- **Customization:** You can adapt the project to different MCUs or modify the mode-switching logic based on your project needs.

This project serves as a practical guide for manipulating modes and access levels in Cortex-M-based projects. Feel free to experiment with the implementation and adjust it to meet your specific requirements!