# V2X Mega Project
The V2X Mega Project is a comprehensive vehicular communication system consisting of three main sub-systems: V2V, V2I, and V2N (Firmware Over-The-Air updates). These sub-systems enable communication between vehicles (V2V), vehicles and infrastructure (V2I), and facilitate firmware updates for the master vehicle (V2N).

# Table of Contents
* [Overview](#Overview)
* [Sub-Systems](#Sub-Systems)
* [Hardware Platform](#Hardware)
* [Installation and Setup](#Installation)

## Overview
The V2X project aims to enhance road safety and traffic efficiency through real-time communication and intelligent decision-making capabilities. By integrating cutting-edge technology and utilizing the STM32F103 BLUE PILL microcontroller platform, the project enables seamless interaction between vehicles and their environment.
![image](https://github.com/mohnagah/V2X_STM32_BLUEPILL/assets/157398651/f30fb74e-14cc-421d-8a61-ff6fae2f02bb)


## Sub-Systems
### V2V (Vehicle-to-Vehicle Communication)
The V2V sub-system enables communication between the master and slave vehicles, enhancing safety and coordination on the road. It utilizes ultrasonic sensors mounted on both vehicles to transmit safety messages and trigger appropriate motor actions based on received data.

Features:
- Bi-directional Communication: Exchange of safety modes between master and slave vehicles.
- Ultrasonic Sensors: Frontward and backward ultrasonic sensors for obstacle detection.
- Motor Control: Executes motor actions in response to received safety modes.

### V2I (Vehicle-to-Infrastructure Communication)
The V2I sub-system establishes communication between the master vehicle and the Roadside Control Unit (RCU), representing the traffic light system. Continuous updates on traffic light status are received by the master vehicle, enabling adaptive driving strategies and efficient traffic flow.

Features:
- RCU Integration: Connectivity with the Traffic Light System (RCU) for real-time traffic light status updates.
- Continuous Monitoring: Receive and interpret traffic light signals to optimize driving decisions.
- Traffic Flow Optimization: Enhance traffic efficiency by adapting driving behavior based on traffic conditions.

### V2N (Firmware Over-The-Air Updates)
The V2N sub-system facilitates Firmware Over-The-Air (FOTA) updates for the master vehicle, ensuring it remains up-to-date with the latest software releases. This sub-system enables seamless integration of new features and improvements without physical intervention, enhancing the functionality and performance of the vehicle.

Features:
- Firmware Updates: Over-the-air updates for the master vehicle's firmware.
- Remote Management: Manage software versions and configurations remotely.
- STM32F103 BLUE PILL Compatibility: Designed for the STM32F103 BLUE PILL microcontroller platform.
  
## Hardware Platform
All sub-systems, including the master and slave vehicles, as well as the traffic light system, are programmed on the STM32F103 BLUE PILL microcontroller platform. This platform provides a robust and flexible foundation for developing intelligent vehicular communication systems.

## Installation and Setup
Detailed installation and setup instructions for each sub-system can be found in their respective README files:
* [V2V Sub-system](https://github.com/mohnagah/V2X_STM32_BLUEPILL/blob/main/V2V/README.md)
* [V2I Sub-system](https://github.com/mohnagah/V2X_STM32_BLUEPILL/blob/main/V2I/README.md)
* [V2N (FOTA) Sub-system](https://github.com/mohnagah/V2X_STM32_BLUEPILL/blob/main/V2N(FOTA)/README.md)

## License
This project is licensed under the GPL-3.0 License.
