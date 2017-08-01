/********************************************************************
*
* Augmented Reality Tag Listener and Broadcaster
*
*********************************************************************/

#include <ros/ros.h>
#include <geometry_msgs/PointStamped.h>
#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>
#include <ar_track_alvar_msgs/AlvarMarkers.h>
#include <costmap_2d/costmap_2d_ros.h>
#include <base_local_planner/trajectory_planner_ros.h>
#include <eigen3/Eigen/Eigen>
#include <list>

typedef struct {
    int id;
    tf::Quaternion q; 
    tf::Vector3 v;
} arTagEntry;

arTagEntry generateNewTagEntry( int id, 
                                tf::Quaternion &tagQ, 
                                tf::Vector3    &tagV, 
                                tf::Quaternion &botQ , 
                                tf::Vector3    &botV ) {
    arTagEntry     arTag;
    tf::Quaternion qTemp; 
    tf::Vector3    vTemp;
    // Use the coordinates from the bot and the tag to create post data points.

    qTemp.setX( tagQ.x() - botQ.x() );
    qTemp.setY( tagQ.y() - botQ.y() ); 
    qTemp.setZ( tagQ.z() - botQ.z() );
    qTemp.setW( tagQ.w() - botQ.w() );

    vTemp.setX( tagV.x() - botV.x() );
    vTemp.setY( tagV.y() - botV.y() );
    vTemp.setZ( tagV.z() - tagV.z() );

    // Set the return values
    arTag.id = id; 
    arTag.q = qTemp;
    arTag.v = vTemp;
    return arTag;
}

std::list<arTagEntry> arTagList; // List to hold all the AR Tag Entrys

void getBotMapCoordiantes ( geometry_msgs::PoseStamped & pBot ) { 
    tf::TransformListener listener;
    geometry_msgs::PoseStamped pBase, pMap;
    pBase.header.frame_id = "base_link";
    pBase.pose.position.x = 0.0;
    pBase.pose.position.y = 0.0;
    pBase.pose.orientation = tf::createQuaternionMsgFromYaw(0.0);
    ros::Time current_transform = ros::Time::now();
    listener.getLatestCommonTime(pBase.header.frame_id, "map", current_transform, NULL);
    pBase.header.stamp = current_transform;
    listener.transformPose("map", pBase, pMap);
    // pMap now contains the pose of the robot transformed into map 
    // coordinates according to the TF data available at time "current_transform"
    pBot = pMap;
}

void subscribeTagData (const ar_track_alvar_msgs::AlvarMarkers& msg) {
    if( !msg.markers.empty() ) {
	if ( !arTagList.empty() ) {
 	    for ( std::list<arTagEntry>::iterator it = arTagList.begin(); 
                  it != arTagList.end(); 
                  ++it ) {
		if (msg.markers[0].id == it->id) {
		    return;
      		}
            }
	}

        tf::Quaternion qTag( msg.markers[0].pose.pose.orientation.x, 
                             msg.markers[0].pose.pose.orientation.y, 
                             msg.markers[0].pose.pose.orientation.z, 
                             msg.markers[0].pose.pose.orientation.w);

        tf::Vector3 vTag ( msg.markers[0].pose.pose.position.x, 
                           msg.markers[0].pose.pose.position.y,
                           msg.markers[0].pose.pose.position.z);

        geometry_msgs::PoseStamped pBase;
        getBotMapCoordiantes( pBase );

        tf::Quaternion qBot( pBase.pose.orientation.x, 
                             pBase.pose.orientation.y, 
                             pBase.pose.orientation.z, 
                             pBase.pose.orientation.w );
        
        tf::Vector3 vBot( pBase.pose.position.x, 
                          pBase.pose.position.y, 
                          pBase.pose.position.z );

        arTagList.push_back( generateNewTagEntry( msg.markers[0].id , qTag, vTag, qBot, vBot ) );
    }
}

void broadcastArTagTF ( tf::TransformBroadcaster & broadcaster ) {
    if( !arTagList.empty()) {
         for ( std::list<arTagEntry>::iterator it = arTagList.begin();
               it != arTagList.end();
               ++it ) {

              broadcaster.sendTransform(
                    tf::StampedTransform(
                        tf::Transform(tf::Quaternion( it->q.x(), it->q.y(), it->q.z(), it->q.w() ), 
                                      tf::Vector3( it->v.x(), it->v.y() ,it->v.z() )),
                                      ros::Time::now(),
                                      "base_link", 
                                      "base_laser"));

     	}
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "tf_L_B_node");
    ros::NodeHandle node;
    ros::Subscriber arTagData = node.subscribe("ar_pose_marker",1,&subscribeTagData);
    ros::Rate loopRate(1);
    tf::TransformBroadcaster broadcaster;
    while(ros::ok()) {
        broadcastArTagTF( broadcaster );
        ros::spinOnce();
        loopRate.sleep();
    }
}
