# Rocket League Car Controller

This repository contains two versions of a project for controlling a Rocket League car, either through a mobile application or using a PS4 controller.

## Mobile Version

The mobile version allows you to control the car using a mobile app.

### Getting Started

To control the car using your mobile phone, you will need the APK file for the program used on the phone:

- [Bluetooth RC Controller](https://bluetooth-rc-controller.en.aptoide.com/app)

Feel free to fork this project and work on developing your own mobile application with Flutter or add more functionalities like flashlights to the car. There are plenty of ideas for further development.

## PS4 Control Version

The PS4 control version allows you to control the car using a PS4 controller.

### Getting Started

To use a PS4 controller, you need to install the following library:

- [PS4-esp32 Library](https://github.com/aed3/PS4-esp32)

### Important Notes

1. **SixaxisPairTool**: You probably know this if you have watched videos about this project. You need to install this program to pair your PS4 controller with the ESP32 board:

   - [SixaxisPairTool](https://sixaxispairtool.en.lo4d.com/windows)

2. **MAC Address**: The MAC address you see in SixaxisPairTool is the MAC address of the device the controller is synchronized with. When your controller is turned on, it searches for the device with this MAC address.

   - Get the MAC address of the ESP32 board using the sketch in the repo.
   - Change the MAC address in SixaxisPairTool and in the `PS4.begin("xx:xx:xx:xx:xx")` line in the code.

3. **Alternative MAC Address Setup**: Alternatively, you can get the MAC address the controller is programmed to connect to and set that in the `PS4.begin("xx:xx:xx:xx:xx")` line in the code.
