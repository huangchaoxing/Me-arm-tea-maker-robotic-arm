# Me-arm-tea-maker-robotic-arm
**Bachelor project**  
vision control in opencv and arduino C++

## **Overview**:
This is a project of a vision based me-arm that can make tea with a tea bag.  
The opencv will calculate the position of the centre of the cup and send the coordinate 
to the arduino controller, the controller will then make the arm moving in a certain movement

Here is an video that shows how it work:https://www.youtube.com/watch?v=s4jkMhVCvxM
                                        https://www.bilibili.com/video/av16741350/ (for those who can't go to youtube)

## **How to use the code**:  
1.What you need:   
- a Mearm robot: https://shop.mime.co.uk/collections/frontpage/products/mearm-pocket-sized-robot-arm
                 opencv 2.4.9 (C++ version). The opencv 3.0+ might be ok but it is not guatanteed.  
- arduino 328  
- usb web cam  
- personal computer
                 
                 
2.The robotic part: The  file arduino-code.ino is what you need to burn to the arduino controller. It is mainly an inverse_kinematic
   implementation of the mearm. A rough kinematic model of the mearm is demonstrated in the file model.m(to see the simulation model you    will need a matlab with the robotic toolbox of peter corke http://petercorke.com/wordpress/toolboxes/robotics-toolbox)
   
3.The vision part:  
- Make sure to clone the head file bot_control.h and tserial.h to your pc and include them in the opencv.cpp, these two                      ensure the serial communication of opencv and arduino(a detailed tutorial of serial communication of opencv and                            arduino can be seen here:https://www.youtube.com/watch?v=UiDXnww0LQ4 )  
- Camera calibration. You will need to calibrate the fixed camera to obtain the matrix that can caculate the actual                           position of the cup
            
       
