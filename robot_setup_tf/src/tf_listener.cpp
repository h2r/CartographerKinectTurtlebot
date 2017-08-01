/*********************************************************************
*
* Simple AR Tag Tracker
*
*********************************************************************/

#include <ros/ros.h>
#include <geometry_msgs/PointStamped.h>
#include <tf/transform_listener.h>
#include <ar_track_alvar_msgs/AlvarMarkers.h>
#include <costmap_2d/costmap_2d_ros.h>
#include <base_local_planner/trajectory_planner_ros.h>
#include <eigen3/Eigen/Eigen>

bool arTagInProximity = false;

void subscribeTagData (const ar_track_alvar_msgs::AlvarMarkers &msg);

bool searchForARTag(ros::Publisher& pub);
     
void subscribeTagData (const ar_track_alvar_msgs::AlvarMarkers& msg) {
    if(!msg.markers.empty()) {
        tf::Quaternion q(msg.markers[0].pose.pose.orientation.x,
                msg.markers[0].pose.pose.orientation.y,
                msg.markers[0].pose.pose.orientation.z,
                msg.markers[0].pose.pose.orientation.w);
        // TO DO - WHEN A NEW TAG IS FOUND IN THE WORLD, NEED TO CREATE A NODE TO SIGNAL
        // THE LOCATION OF THE TAG IN THE GLOBAL FRAME.
    }   
}

bool searchForARTag( ros::Publisher& pub ) {
    if (!arTagInProximity) {
        ROS_INFO("Has not found AR_TAG");
    } else {
        ROS_INFO("Has found AR_TAG");
        // TO DO - WHEN A TAG IS FOUND, NEED TO LOG LOCATION ON THE MAP.
    }
    return arTagInProximity;
}

int main(int argc, char** argv){
    ros::init(argc, argv, "robot_tf_listener");
    ros::Publisher nodePublisher;
    ros::NodeHandle node;
    ros::Subscriber arTagData = node.subscribe("ar_pose_marker",1,&subscribeTagData);
    ros::Rate loop_rate(1);
    int count =  0;
    while (ros::ok()) {
        // If there is an AR_Tag in the proximity of the robot.
        searchForARTag( nodePublisher );
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    return 0;
}
