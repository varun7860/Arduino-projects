# Quadruped Robot
<img src="https://github.com/varun7860/Arduino-projects/blob/master/Quadruped%20Robot/Images/Quadruped.jpg" width="577" height="555"/>

## Description 
- This is a cool quadruped which can walk, exercise and dance. how cool is that!? This Robot uses a special type of algorithm for its walking which I will explain in detail below. But before that lets talk about difference between statically and dynamically stable gaits.

## Statically and Dynamically Stable Gaits
- When the robot walks, it has to keep its balance. There are two general strategies for doing that, and according to them, we divide the gaits into statically stable and dynamically stable.
- For statically stable gaits it doesn’t matter how fast they are performed, or whether the robot is stopped in a middle of a step – it is stable at any moment, at all times. Animals and people use those gaits when they want to go slowly, or when they want to be able to stop at any time. An example of such a gait is the “creep” gait, used by cats stalking their prey.
- Dynamically stable gaits are much harder, as they have to be performed at a particular speed and cannot be interrupted at an arbitrary point. They are sometimes called “controlled falling”, as they exploit the fact that it takes some time for the robot to fall when it’s unstable, and that time can be used to move the legs in such a way as to prevent the fall. Most animal gaits are dynamically stable, as they tend to be faster and more energy-efficient. An example of a simple dynamically stable gait is the “trot” gait.

## Hardware Requirements
1. Chassis(Body)
2. 8 SG-90 Servo Motors
3. Arduino Pro mini
4. Battery(Lipo or lithium-ion is suggested)
5. General Purpose PCB
6. HC-05 Bluetooth Module.

## Software Requirements
1. Arduino IDE
2. Bluetooth app to control the Robot using voice or text commands.(Blynk is one of the best option for this)

## Passive Vs Active Stability:

- when a Quadruped is standing on 4 legs it is passively stable because it doesn't need an control or adjustment to stay upright.
when it is walking it has options : it can maintain passive stability while walking by keeping three legs on the ground and reaching out with the fourth(Creep Gait Algorithm).
- It can also use active stability to move faster (Trot Gait Algorithm).

## Types of Gaits
<img src="https://github.com/varun7860/Arduino-projects/blob/master/Quadruped%20Robot/Images/COG.jpg" width="620" height="360"/>

1. Creep Gait : This gait is the easiest walking gait to use. The robot keeps 3 feet on the ground and keeps its center of gravity (COG) inside the triangle formed by those 3 feet. If COG goes outside the triangle for too long it will fall over.In case of quadrupeds such as animals, they use movements of the head and tail to move the COG back and forth to keep it within Stability Triangle.

2. Trot Gait: Its sometimes called amble gait. Two diagonal legs swings forward while the other two support the body and move backward(as if the body is moving forward. Its one of the quickest gaits because two of its legs are lifted at one time. The stability of the body is related to the frequency of the legs lifted and placed. Quicker the placement the less shaky you will find it is. Make sure the feet have a large contact which will help it stay better while the other two legs are lifted.

3. Crawl Gait: This is similar to the first gait but in this one COG shifts while walking to maintain a better stability. To do that we need to know which leg is going to be lifted and placed forward and the other three legs will form a supporting tripod.To stay stable the robot has to be inside the COG Triangle.

## Creep Gait Algorithm
<img src="https://github.com/varun7860/Arduino-projects/blob/master/Quadruped%20Robot/Images/Gait.jpg" width="620" height="190"/>

1. (From left side)This is the starting position, with two legs extended out on one side, and the other two legs pulled inward.

2. The top-right leg lifts up and reaches out, far ahead of the robot.

3. All the legs shift backward, moving the body forward.

4. The back-left leg lifts and steps forward alongside the body. This position is the mirror image of the starting position.

5. The top-left leg lifts and reaches out, far ahead of the robot.

6. Again, all the legs shift backward, moving the body forward.

7. The back-right leg lifts and steps back into the body, bringing us back to the starting position.

- **Notice that at all times, the triangle formed by the legs on the ground contains the CoG. This is the essence of the creep gait. When we look at this pattern, we can see it is essentially two sets of mirrored movements. Step, step and shift, followed by another step, step and shift on the other side. Here is the code snippet for it:)**

- **Note: My code may or may not work you. why? Because COG depends upon the weight and type of the body of the robot!. Yours chasis may be different. Tweak the Arduino code and Inverse Kinematics (IK) accordingly.**

- **Note :I have taken this algorithm step by step and some of information from Make magzine's official website https://makezine.com/2016/11/22/robot-quadruped-arduino-program/ check this link to find out more !**

- **Note : There are variations for Quadruped Robots. I have used 8 Motor Quadruped. So inverse Kinematics of 2 DOF is required here not 3.**

     - > 8 Motor Quadruped (There is no Tibia : Requires 2DOF Inverse Kinematics)
     - > 12 Motor Quadruped (It consist of Tibia:Requires 3DOF Inverse Kinematics)
     
## Code Explanation

## Demonstration Video

[![alt text][1]][2]

[1]: https://github.com/varun7860/Arduino-projects/blob/master/Quadruped%20Robot/Images/Output%20Video.jpg
[2]: https://youtu.be/-mtmB8SGPz0
