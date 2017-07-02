# Google Cartographer and LIDAR with xbox 360 Kinetic Augmented Reality Tag Tracking with TurtleBot2 Tutorial:

This tutorial was created at Brown University's h2r Human to Robots Laboratory in the summer of 2017.

<Put Description of the Purpose of the tutorial>

# Dependencies Required for Installation on Ubuntu 14.04 and newer distributions:

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
-------------------------------------
Running the rosnodes from your remote machine (Turtlebot2):

1. ssh into the remote machine from your local machine.

Additional information for ssh can be found at the following link:

    https://www.freebsd.org/cgi/man.cgi?query=ssh&sektion=1
    
You can also find additional by using the following command:

    man ssh
    
Example:

    ssh -X h2r@xxx.xx.xx.xxx # IP Address

2. Once connect the remote machine (Turtlebot2), type in the following command:

        rospack find ar_track_alvar

Change to the directory which has been outputed to the terminal. 

*If the rospack is not found, you have not properly installed the ar_track_alvar library.

Copy the freenect_launch_pr2_indiv.launch to the launch directory of the ar_track_alvar ros package.

2. Navigate to the directory which contains the .screenrc file. If the screenrc file is not currently on the remote machine, copy the file .screenrc file to the directory of your choice.

3. Run the following command to run the screen session script.

        screen -c <SCREEN-SCRIPS>
        
 Example:
 
        screen -c cartographer_single_echo.screenrc
 
The screen session will source the appropriate bash files and load the command line with the necessary ros commands.
    
4. Navigate between the newly created screen sessions with the following command:

        `-<SCREEN-SESSION-NUMBER>
        
Example: 

Navigating to the third screen session would look something like this:
    
        `-3
        
-------------------------------------
Running rviz from your local machine:

* Warning: Instruction will not work if the local and remote machines are not on the same network and if you have not properly set up the environment on you remote machine (Turtlebot2).

1. Copy the rviz configuration to your local machines desktop

2. Open a terminal and type the following command:

        rosrun rviz rviz
    
 3. Once rviz loads successfully, press ctrl-o and select the rviz configuration file from your desktop.
 
    If the configuration file is properly loaded, you should see the following on the rviz screen:
    
    *  Global Options 
    *  Global Status
    *  Grid
    *  PointCloud2
    *  LaserScan
    *  Map
    *  RobotModel

-------------------------------------
Running rqt_graph from your local machine:

* Warning: Instruction will not work if the local and remote machines are not on the same network and if you have not properly set up the environment on you remote machine (Turtlebot2).

1. Open a terminal and type in the following command:

        rosrun rqt_graph rqt_graph
