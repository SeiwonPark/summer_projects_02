# summer_projects_02
Multiple Functions with Arduino and Raspberry Pi

**ABSTRACT**

This project was created as a part of the 2020 IoT SMART DESIGN CAMP(2020.08.10 ~ 2020.08.13). In this project, I implemented Multiple Functions(Serial Communication, Sensing and Actuating) between Arduino and Raspberry Pi using Python, C/C++ to automate the circuit and to communicate. And in this process, I tried to control sensors and actuators only by Raspberry Pi. But what I've realized was that Raspberry Pi can't directly control Arduino's actuator but only can receive Serial values. So I regarded Raspberry Pi as an Actuator, and Arduino as a Sensor. The method that was implemented in this project was giving certain values that I set(like 999, 119 or 112) and take those values at a certain condition so that I can divide cases from which sensors gave Raspbery Pi those values.

## Table of Contents   
* [1. Author](#1-author)   
* [2. Version and Connect](#2-version-and-connect)   
* [3. How to use](#3-how-to-use)   
> * [3.1 Run using <code>main.ipynb</code> in Jupyter Notebook by PL-App Launcher](#31-run-using-mainipynb-in-jupyter-notebook-by-pl-app-launcher)   
>> * [3.1.1 Arduino serial communication test](#311-arduino-serial-communication-test)   
* [4. How it works](#4-how-it-works)   
> * [4.1 Limitation](#41-limitation)   
> * [4.2 Execution and Functions](#42-execution-and-functions)   
>> * [4.2.1 Overall Execution](#421-overall-execution)   
>> * [4.2.2 Function <code>toASCII(serialRead)</code>](#422-function-<code>toascii(serialread)</code>)   
>> * [4.2.3 Function <code>buttonSound(num)</code>, <code>noteSound(soundList)</code>](#423-function-<code>buttonsound(num)</code>-<code>notesound(soundlist)</code>)   
>> * [4.2.4 Function <code>rotateServo(num)</code>](#424-function-<code>rotateservo(num)</code>)   

## 1. Author   
* Name: 박세원(Seiwon Park)   

## 2. Version and Connect   
* Version: Arduino 1.8.13, Raspberry Pi PL-App 1.0
* Connect:   
            <code>%%bash</code>   
            <code>ls /sys/bus/usb-serial/devices/ | sed "s/^/\\/dev\\//g"</code>                 
    
## 3. How to use   
### 3.1 Run using <code>main.ipynb</code> in Jupyter Notebook by PL-App Launcher
_Note_: You should make sure that Raspberry Pi is connected correctly and use the same Wi-Fi with your computer   
Or you can manually run each cell in <code>steps.ipynb</code>

#### 3.1.1 Arduino serial communication test   
You can run <code>SerialCommunication.ino</code> and test how Arduino communicates with Serial Monitor   
The format of result of <code>SerialCommunication.ino</code> is as follows:   
```c   
            (analogInputPin) : (analogInputPinValue)   
            (analogInputPin) : (analogInputPinValue)   
            (analogInputPin) : (analogInputPinValue)   
            ...   
```

## 4. How it works   
### 4.1 Limitation   
As time complexity is too high, when <code>main.ipynb</code> is implemented, it sometimes got _Time Out Error_   
Though suspecting Raspberry Pi's performance, but I couldn't find out accurate reason why it fails when running   

### 4.2 Execution and Functions   
#### 4.2.1 Overall Execution   
Overall execution code is as follows:   
```python
        while True:
               try:
                    while True:   
                        try:
                            tou = ser1.readline()       #    Touch Sensor
                            pas = ser2.readline()       #    Password Button
                            vib = ser3.readline()       #    Vibration Sensor

                            if toASCII(tou[0]) and toASCII(vib[0]):       #  57 is the value that I set in Arduino 
                                                                          #  which means 'normal state'
                                print(999)                                #  999 is 'normal state' value that I set in Raspberry Pi

                            if toASCII(pas[0]):
                                print(999)
                            else:
                                print(int(pas[0]) - 48)

                            if touch:
                                if not toASCII(tou[0]) or not toASCII(vib[0]):  #  49 is the value that I set in Arduino
                                                                                #  which means 'problem occured'
                                                                                #  NOTE: regardless of the value, buzzer actuates automatically
                                    print("        Problem Occurred !!!")
                                    noteSound(beep)
                                    break
                            if not toASCII(tou[1]) and toASCII(tou[2]):
                                print("        Fire Occurred !!!")
                                noteSound(beep)
                                break

                            if pas[0] != 0:

                                num = int(pas[0]) - 48

                                if int(pas[0]) == 42:                           #  when received '*', terminate input
                                    buttonSound(num)

                                    if password == test:                        #  password succeeded
                                        touch = False                           # inactivate Touch Sensor
                                        print("        The Safe Is Opened")
                                        noteSound(dingdong)
                                        rotateServo(7.5)                        #  servo rotates by 90 degree
                                    else:                                       #  password failed
                                        print("        Wrong !!!")
                                        noteSound(error)
                                        break

                                elif 0 <= num and num <= 9:
                                    num = int(pas[0]) - 48
                                    buttonSound(num)
                                    print("Num {} has been pressed".format(num))
                                    test.append(num)

                                elif int(pas[0]) == 35:                         #  when received '#', delete last input
                                    buttonSound(num)
                                    del test[-1]

                        except KeyboardInterrupt:
                            break
               except KeyboardInterrupt:
                    break
```   
Arduino gives Serial value to the connected Raspberry Pi, and Raspberry Pi takes that value with <code>serial.Serial('Connected USB Route', 9600).readline()</code>. As return type is string(<code>.readline()</code>), I tried to find out the first letter Arduino is giving to Raspberry Pi(Like 9, 1). But, as it is string type, the first letter would be  a byte type. So I needed to convert it into int type just for convenience. In this moment, the byte type converts into int type and this value follows ASCII. Finally I could divide cases 'Touched', 'Fire detected', 'Password entered', 'Vibration detected'.   
   
 

#### 4.2.2 Function <code>toASCII(serialRead)</code>   
This function confirms 'normal state' of Arduino by receiving certain value that I set before   

#### 4.2.3 Function <code>buttonSound(num)</code>, <code>noteSound(soundList)</code>   
These functions make sounds using note list(which is <code>scale</code> in <code>main.ipynb</code>   
And buzzer makes sounds by changing frequency   

#### 4.2.4 Function <code>rotateServo(num)</code>    
This function makes servo rotate by certain degree by chaning duty cycle   




        
