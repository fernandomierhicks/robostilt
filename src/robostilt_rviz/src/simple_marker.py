#! /usr/bin/env python
import rospy

from interactive_markers.interactive_marker_server import *
from visualization_msgs.msg import *



class myInteractivemarker:

    def __init__(self):
        rospy.init_node("simple_marker")
        self.server = InteractiveMarkerServer("simple_marker") 
        # create an interactive marker for our server
        int_marker = InteractiveMarker()
        int_marker.header.frame_id = "leg_2" 
        int_marker.name = "leg_2_marker"
        int_marker.description = "leg_2"
        # create a control which will move the box
        # this control does not contain any markers,
        # which will cause RViz to insert two arrows
        control = InteractiveMarkerControl()
        control.name = "move_x"
        control.orientation.w = 1
        control.orientation.x = 0
        control.orientation.y = 1
        control.orientation.z = 0
        control.interaction_mode = InteractiveMarkerControl.MOVE_AXIS
        # add the control to the interactive marker
        int_marker.controls.append(control)
        # add the interactive marker to our collection &
        # tell the server to call processFeedback() when feedback arrives for it
        self.server.insert(int_marker, self.processFeedback)
        # 'commit' changes and send to all clients
        self.server.applyChanges()
         

    def processFeedback(self, feedback):

        p = feedback.pose.position
        print feedback.marker_name + " is now at " + str(p.x) + ", " + str(p.y) + ", " + str(p.z)    

         # Make it return to its original position.
        if feedback.pose.position.z != 0:
             feedback.pose.position.z = 0.5    #leg lenght /2.0
        # Apply changes to the marker.
        self.server.setPose(feedback.marker_name, feedback.pose)
        self.server.applyChanges()   
        # create an interactive marker server on the topic namespace simple_marker


if __name__=="__main__":    
    myinteractivemarker=myInteractivemarker()  
    rospy.spin()