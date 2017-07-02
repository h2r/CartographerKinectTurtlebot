# Google Cartographer and LIDAR with xbox 360 Kinetic Augmented Reality Tag Tracking with TurtleBot2 Tutorial:

This tutorial was created at Brown University's h2r Human to Robots Laboratory in the summer of 2017.

<Put Description of the Purpose of the tutorial>

# Dependencies Required for Installation for Ubuntu 14.04 and newer distributions:

------------------------------------
Turtlebot2 information link:


    http://www.turtlebot.com/turtlebot2/


-------------------------------------
Kinect installation and setup on ROS:

    sudo apt-get install libfreenect-dev

    sudo apt-get install ros-<ROS-VERSION>-freenect-launch

Example:

    sudo apt-get install libfreenect-dev

    sudo apt-get install ros-indigo-freenect-launch
    
Ensure installation was successful by running the following command:

    roslaunch freenect_launch freenect.launch
    
    
Additional documentation can be found at the following link:

    http://wiki.ros.org/freenect_launch

-------------------------------------
AR tag tracking library Installation:

    sudo apt-get install ros-<ROS-VERSION>-ar-track-alvar
   
Example:
    
    sudo apt-get install ros-indigo-ar-track-alvar
    

Additional documentation can be found at the following link:

    http://wiki.ros.org/ar_track_alvar
    
-------------------------------------
Teleoperation of turtlebot installation:

Following directions at following link: 
    
    http://wiki.ros.org/Robots/TurtleBot
    
-------------------------------------
AR tag TF Listening and Broadcasting Installation:

    <TO DO - Still working on minor software stuff>
        
-------------------------------------
ros rviz Information:

Additional documentation can be found at the following link:

    http://wiki.ros.org/rviz/UserGuide

    http://docs.ros.org/indigo/api/rviz/html/user_guide/index.html   
    
-------------------------------------
ros rqt_graph Information:
    
Additional documentation can be found at the following link:

    http://wiki.ros.org/rqt_graph
    
    
-------------------------------------
Screen Session Installation:

    sudo apt-get install screen
    
Additional documentation can found at the following link:

    https://www.gnu.org/software/screen/manual/screen.html
  
Feel free to use the command below on your linux machine to gain a better understanding of how to use screen:

    man screen

# Directions getting up and running once all dependencies are satisfied:
