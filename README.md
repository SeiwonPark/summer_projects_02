# summer_projects_02
Multiple Functions with Arduino and Raspberry Pi

**ABSTRACT**

This project was created as a part of the 2020 IoT SMART DESIGN CAMP(2020.08.10 ~ 2020.08.13). In this project, I implemented Multiple Functions(Serial Communication, Sensing and Actuating) between Arduino and Raspberry Pi using Python, C/C++ to automate the circuit and to communicate. And in this process, I tried to control sensors and actuator with only Raspberry Pi. But what I've realized was that Raspberry Pi can't directly control Arduino's actuator but only can receive Serial values. So I regarded Raspberry Pi as an Actuator, and Arduino as a Sensor. The method that was implemented in this project was giving certain values that I set(like 999, 119 or 112) and take those values at a certain condition so that I can divide cases from which sensors gave Raspbery Pi that values.



## 1. Author   
* Name: 박세원(Seiwon Park)
* Student ID: 20153178

## 2. Version and Connect   
* Version: Arduino 1.8.13, Raspberry Pi PL-App 1.0
* Connect:   
            <code>%%bash</code>   
            <code>ls /sys/bus/usb-serial/devices/ | sed "s/^/\/dev\//g"</code>                 
    
## 3. How to use   
### 3.1 Run using <code>main.ipynb</code> in Jupyter Notebook by PL-App Launcher
_Note_: You should make sure that Raspberry Pi uses the same Wi-Fi with your computer   
You can manually run each cell in <code>main.ipynb</code>   

## 4. How it works   
### 4.1 Algorithm   
```
        while True:   
            try:
                    tou = ser1.readline()       #    Touch Sensor
                    pas = ser2.readline()       #    Password
                    vib = ser3.readline()       #    Vibration Sensor
                    
                    touch = True                #    if Touch Sensor is on, initialized with True

                    if int(tou[0]) == 57 and int(vib[0]) == 57:  #  57 is the value that I set in Arduino 
                                                                 #  which means 'normal'
                        print(999)              #    999 is 'normal' value that I set in Raspberry Pi

                    if pas[0] == 0:          
                        print(999)
                    else:
                        print(int(pas[0]) - 48)

                    # When each sensors sensed
                    if touch:
                        if int(tou[0]) == 49 or int(vib[0]) == 49:   # buzzer actuates automatically
                            print("        Problem Occurred !!!")
                            for i in range(8):
                                buzzer.ChangeFrequency(scale[beep[i]])
                                time.sleep(0.3)
                            break
                    if int(tou[1]) == 49 and int(tou[2]) == 57:
                        print("        Fire Occurred !!!")
                        break

                    # Enter password        
                    if pas[0] != 0:

                        num = int(pas[0]) - 48

                        if int(pas[0]) == 42:                  #    when received '*', terminate input
                            buzzer.ChangeFrequency(scale[10])
                            if password == test:               #    password succeeded
                                touch = False
                                print("        The Safe Is Opened")
                                for i in range(4):
                                    buzzer.ChangeFrequency(scale[dingdong[i]])
                                    time.sleep(0.5)
                                servo.ChangeDutyCycle(7.5)     #    servo rotates by 90 degree

                            else:                              #    password failed
                                print("        Wrong !!!")
                                for i in range(3):
                                    buzzer.ChangeFrequency(scale[error[i]])
                                    time.sleep(0.5)
                                break
                        elif 0 <= num and num <= 9:
                            num = int(pas[0]) - 48
                            buzzer.ChangeFrequency(scale[num])
                            print("Num {} has been pressed".format(num))
                            test.append(num)
                        elif int(pas[0]) == 35:                #   when received '#', delete last input
                            buzzer.ChangeFrequency(scale[11])
                            del test[-1]

            except KeyboardInterrupt:
                        break
```





        
