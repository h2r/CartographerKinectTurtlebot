# Google Cartographer with xbox 360 Kinetic Augmented Reality Tag Tracking with Turtle Bot Tutorial:


Dependencies Required for Installation for Ubuntu 14.04 and newer distributions:

-------------------------------------
Kinect Installation and Setup on ROS:

    sudo apt-get install libfreenect-dev

    sudo apt-get install ros-<ROS-VERSION>-freenect-launch

Example:

    sudo apt-get install libfreenect-dev

    sudo apt-get install ros-indigo-freenect-launch
    
Ensure Installation was successful by running the following command:

    roslaunch freenect_launch freenect.launch
    
    
Additional documentation can be found at the following link:



-------------------------------------
AR tag tracking library Installation:

    sudo apt-get install ros-<ROS-VERSION>-ar-track-alvar
   
Example:
    
    sudo apt-get install ros-indigo-ar-track-alvar
    

Additional documentation can be found at the following link:

    http://wiki.ros.org/ar_track_alvar


