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

-------------------------------------
AR tag tracking library Installation:

    sudo apt-get install ros-<ROS-VERSION>-ar-track-alvar
   
Example:
    
    sudo apt-get install ros-indigo-ar-track-alvar
    

Further documentation can be found at the link below:

    http://wiki.ros.org/ar_track_alvar


