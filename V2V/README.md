
# V2V Sub-system

The V2V (Vehicle-to-Vehicle) sub-system enables the communication between the master and slave cars, both equipped with STM32F103 BLUEPILL microcontrollers. This sub-system enhances safety and coordination on the road by utilizing ultrasonic sensors to detect obstacles and control motor actions based on predefined modes.

## Overview

The V2V sub-system is designed to facilitate real-time communication between vehicles, allowing them to exchange safety information and coordinate their movements effectively. By integrating ultrasonic sensors and motor control mechanisms, the sub-system enables autonomous decision-making and adaptive behavior in both master and slave cars.

## Features

- **Master-Slave Communication:** Establishes communication between the master and slave cars via USART.
- **Ultrasonic Sensors:** Utilizes front and backward ultrasonic sensors on the master car to detect obstacles and measure distances.
- **Motor Control:** Controls motor actions in both master and slave cars based on predefined modes.
- **Autonomous Operation:** Enables autonomous decision-making in response to environmental conditions and sensor readings.

## Installation and Setup

To use the V2V sub-system, follow these steps:

1. **Hardware Setup:**
   - Connect the components as shown in the provided Proteus schematic or use the attached Proteus schematic directly.
   - Create a bridge between the virtual ports (e.g., COM1 and COM2) using the Virtual Serial Port Tools application.
   - Ensure that the communication configuration (baud rate, bit number, parity bits, etc.) for COM1 and COM2 in Proteus matches the configuration of the virtual ports.

2. **Mode Control:**
   - Familiarize yourself with the four-mode conditions illustrated in the provided Proteus schematic.
   - Understand how the ultrasonic sensor readings influence motor actions and determine the operational state of the master and slave cars.

3. **Testing:**
   - Use the Proteus simulation environment to test the functionality of the V2V sub-system.
   - Observe how changes in ultrasonic sensor readings affect motor actions and mode transitions.
   - Verify that the master and slave cars communicate effectively and respond appropriately to environmental stimuli.

## Proteus Schematic

A Proteus schematic is provided to facilitate testing and validation of the V2V sub-system. The schematic depicts the connections between the master and slave cars, as well as the configuration of virtual ports for communication.
![image](https://github.com/mohnagah/V2X_STM32_BLUEPILL/assets/157398651/a30c2b06-d3eb-4c95-b96e-fad2c2154287)
![image](https://github.com/mohnagah/V2X_STM32_BLUEPILL/assets/157398651/f380c53a-5a97-4ed4-8cfe-ce3f97d800e0)

## Video
(V2V Video)[https://drive.google.com/file/d/14AlpnU1DaGrllxCIZEGOUKeVba8zaNHt/view?usp=sharing]

## License

This sub-system is part of the V2X Project and is licensed under the [GPL-3.0 License](../LICENSE).

