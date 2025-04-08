# Team8InsulinPumpSimulator
Names: Shakil Muhammad (101259661), Pavle Vujicic (101159343), Jacob Rada (101265520), Shivam Khanna (101268691)

t:slim X2 Insulin Pump Simulator: This repository contains a C++ Qt framework project that simulates the t:slim X2 Insulin Pump, aiming to replicate key functionalities and provide a virtual interface for diabetes management training. 

## IMPORTANT NOTE
- This requires Qt Charts to compile, which is not included in the course VM.
- Please ensure Qt Charts is installed when building.
- Linux distros (like the course VM) can install Qt Charts with: 
   - sudo apt-get install libqt5charts5-dev

Files-
Final Project 3004.pdf - has all use cases, diagrams and traceability matrix 
Diagrams folder - Diagram images

Headers:
	mainwindow.h
	user.h
	device.h
	profilemanager.h
	historymanager.h
	
CPP:
	mainwindow.cpp
	main.cpp
	user.cpp
	device.cpp
	profilemanager.cpp
	historymanager.cpp
	
QT Forms:
	mainwindow.ui
	
Instructions:  
1. Unzip the file
2. Open .pro file in QT Creator
3. Clean the project
4. Build the project
5. Run the project
6. To run the simulation, press the START button after selecting a profile.

YouTube Video Link: https://www.youtube.com/watch?v=NRCWGWKIg7Q

Work distribution:
Shakil 
-  user class
-  part of device class
-  Use case 1,2,3
-  Use case diagram
-  UML class diagram
-  UML success scenarios

Shivam
-  profilemanager class
-  part of device class
-  Use case 4,5,6 and 10,11,12,13
-  UML state diagram
-  UML safety scenarios
   
Jacob
- historymanager class
- part of device class
- Use case 7,8,9

Pavle
- setup github repo and board
- mainwindow functionality
- 	charting
- 	status imaging
- tracability matrix

