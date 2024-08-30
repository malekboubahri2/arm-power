# ITM Implementation in printf

This project demonstrates how to implement Instrumentation Trace Macrocell (ITM) in the `printf` function using STM32CubeIDE. ITM allows for real-time data tracing without disrupting the operation of the microcontroller, making it an invaluable tool for debugging and performance analysis.

## Setup Instructions

### Prerequisites

- **STM32CubeIDE:** Ensure you have the latest version installed.
- **STM32 Development Board:** This project was tested on an STM32F4 series board, but it can be adapted for other STM32 microcontrollers.

### Step 1: Create an Empty STM32CubeIDE Project

1. **Open STM32CubeIDE** and create a new STM32 project.
2. **Select Your Target MCU/Board:** Choose the appropriate STM32 microcontroller or board.
3. **Configure the Project:** Choose empty project Option.
4. **Generate the Project Code:** STM32CubeIDE will generate the necessary project files.

### Step 2: Copy the Source Code

1. **Copy the Provided Source Files:** Navigate to the project folder in this repository and copy the source files (`main.c`) into your STM32CubeIDE project.

### Step 3: Build and Run

1. **Build the Project:** Compile the project in STM32CubeIDE.
2. **Connect to the Target:** Use an ST-Link or similar debugger to connect to your STM32 board.
3. **Start Debugging:** Begin debugging to see ITM output in the SWV ITM Data Console.

### Notes

- **SWV ITM Data Console:** Make sure to enable the Serial Wire Viewer (SWV) in your debugger settings to view the ITM output.
- **Customization:** You can customize the ITM implementation based on your project needs, such as changing the ITM stimulus port.

This project is a starting point for using ITM in your embedded systems projects. Feel free to experiment and expand on this implementation to suit your specific requirements!
