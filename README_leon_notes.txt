All files listed in the section "File descriptions" are in the folder ~/Desktop/leon_turtlebot_notes.

Note that whenever I refer to a file in my notes about cartographer, it's a file in the folder ~/Desktop/leon_turtlebot_notes/google_cartographer_files and if it's using Gmapping, it's in the folder labeled so.

File descriptions:
##################

burlap_rosbridge: control turtlebot programmatically using BURLAP Rosbridge.

cartographer_kinect_mapping: how to make a map using Google Cartographer and the Kinect camera.

cartographer_lidar_mapping: how to make a map using Google Cartographer and the LIDAR.

changelog: documents changes made to the computer, such as changing values of environment variables, moving files and folders around, etc.

generate_rosbag.txt: how to make a rosbag with the scan data.

localization_navigation: localization (either autonomous or manual) and navigation (automatic) using Rviz.

odom_notes: assorted notes when examining the /odom topic (using for localization and stuff programatically)

offline_mapping: how to use the rosbag to go to localization and navigation.

ros_gmapping: making a map with gmapping.

General notes:
##################
SSH: make sure that all the machines are on the same network! It sounds obvious but I've spent time messing around with IP addresses when the laptop was on Brown-Guest instead of RLAB.

RENAMING/MOVING FILES: in the yaml file generated, there's a line that says "image:" followed by the name of the file and/or path to the file. Make sure that you edit this if you decide to rename the file and/or move it. Otherwise, you'll get something like "[map_server-15] process has died [pid some process ID here, exit code 255]"

Known issues:
##################
- Teleop can stop sometimes when running Cartographer live (online, as in on-the-fly, without a rosbag). Appears to be caused when Cartographer is taking up a ton of computer power-- in this case, first confirm that the network is fine (try opening up a fresh terminal and SSH-ing into the Turtlebot, and if this works then the network is probably fine). If the network is fine, just let the Turtlebot sit for a little bit and let Cartographer to "catch up." After a while, the Turtlebot should respond to teleop commands again.
- RLAB network dropping-- might have some dead spots in the wifi. The network seems to drop randomly on both the Turtlebot computer as well as the laptop-- in this case maybe wait for a bit and try reconnecting.


Other files in ~/Desktop/leon_turtlebot_notes (not particularly crucial now that we can make maps with decent loop closure):
##################
cit_first_floor_run_1.png: made using cartographer, mapping CIT 121, hallway, CIT 115, lobby. 
hallway test 1.png, hallway test 2.png: old tests when loop closure was really bad to the point that we had trouble making a decent map of the CIT first floor.