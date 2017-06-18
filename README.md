# SumoRobot
An Arduino based robot that simulates sumo combats with other robots inside an arena


![SumoRobot](https://lh5.googleusercontent.com/-9ArerPmuiZTNpkfwb-7r8yfkJnOwcU2_vzPAdTJZ93ZC2YbVKxDlMCwaEY4ql_I5lhXm2WythjeYNM=w1920-h935-rw)

The robots uses two sensors:
* Ultrasonic Sensor HC-SR04
* IR Proximity Sensor TCRT5000

With the help of the Ultrasonic Sensor the robot can detect presence of other Robots/Objects, and Then push them toward the outside of the arena.

When arriving at the arena limit (black lines) the robots can detect the edge using the IR Proximity Sensor and goes backward

The robots signals it's current state through different color signals emitted from an RGB LED :

* BLUE  Detecting presence other Robots/Objects
* RED : Edge of the arena reached
* GREEN : searching for other Robots/Objects
