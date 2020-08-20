# summer_projects_02
Multiple Functions with Arduino and Raspberry Pi

**ABSTRACT**

This project was created as a part of the 2020 IoT SMART DESIGN CAMP(2020.08.10 ~ 2020.08.13). In this project, I implemented Multiple Functions(Serial Communication, Sensing and Actuating) between Arduino and Raspberry Pi using Python, C/C++ to automate the circuit and to communicate. And in this process, I tried to control sensors and actuator with only Raspberry Pi. But what I've realized was that Raspberry Pi can't directly control Arduino's actuator but only can receive Serial values. So I regarded Raspberry Pi as an Actuator, and Arduino as a Sensor. The method that was implemented in this project was giving certain values that I set(like 999, 119 or 112) and take those values at a certain condition so that I can divide cases from which sensors gave me that values.



**1. Author**
* Name: 박세원(Seiwon Park)
* Student ID: 20153178

**2. Version and Connect**
* Version: Arduino 1.8.13, Raspberry Pi PL-App 1.0
* Connect
    %%bash
    ls /sys/bus/usb-serial/devices/ | sed "s/^/\/dev\//g"
            

**3. How to use**
3.1 Run using Jupyter Notebook
