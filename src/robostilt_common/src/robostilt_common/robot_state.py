#! /usr/bin/env python
import rospy
import actuators_state 

from  common import print_ros
from  common import wait_for_user

import parameters as p
from constants import constants as C






class robot_state:
    actuators=None
    supportingFrame=C.FRAME.NONE    


    def __init__(self):        
        print_ros("Robot_state setup started")
        self.actuators=actuators_state.actuators_state()  
        p.read_from_parameter_server()           
        print_ros("Robot_state setup completed")

    def lower_legs_on_frame(self,frame,limited_effort):

        print_ros("Lowering legs on frame " + frame.name +" to position " +str(p.dimension.nominal_walking_height)+ " with effort_limit= " + str(limited_effort)+ " ...")

        indexes=frame.actuatorIndexes
        for i in indexes:
            if(limited_effort==True):  
                self.actuators.actuator[i].motor.set_effort_limits(p.effort.lowering_leg_min,p.effort.lowering_leg_max)   
            else:
                self.actuators.actuator[i].motor.set_effort_limits_to_max()
            self.actuators.actuator[i].motor.set_position(p.dimension.nominal_walking_height,p.speed.lowering_legs)
        self.actuators.wait_for_all_actuators_to_finish()
        #We are now supported by this frame
        self.supportingFrame=frame
        for i in indexes:
            self.actuators.actuator[i].is_supporting=True       

        print_ros("Lowering legs on frame " + frame.name +" to position " +str(p.dimension.nominal_walking_height)+ " with effort_limit= " + str(limited_effort) +" COMPLETED")
            

    def raise_legs_on_frame(self, frame):
        print_ros("Raising legs on frame " + frame.name + " to position 0.0 with effort_limit=max...")
        indexes=frame.actuatorIndexes
        for i in indexes:
            self.actuators.actuator[i].motor.set_effort_limits_to_max()            
            self.actuators.actuator[i].motor.set_position(0.0,p.speed.raising_legs)
            self.actuators.actuator[i].is_supporting=False
        self.actuators.wait_for_all_actuators_to_finish()
        print_ros("Raising legs on frame " + frame.name + " to position 0 with effort_limit=max COMPLETED")

    def move_prismatic(self,position):
            print_ros("Moving third frame Prismatic to " + str(position) + "...")
            i=C.ACTUATOR.third_frame_prismatic.index            
            self.actuators.actuator[i].motor.set_effort_limits_to_max() 
            self.actuators.actuator[i].motor.set_position(position,p.speed.prismatic)
            self.actuators.wait_for_all_actuators_to_finish()
            print_ros("Moving third frame Prismatic to " + str(position) + " COMPLETED")

    def step_forward(self):
        #Move Forward        
        wait_for_user()
        self.move_prismatic(-0.2)
        
        #Lower legs on ODD        
        wait_for_user()
        self.lower_legs_on_frame(C.FRAME.ODD,True)

        #Raise legs on even        
        wait_for_user()        
        self.raise_legs_on_frame(C.FRAME.EVEN)
        
        #Move Forward
        wait_for_user()       
        self.move_prismatic(-0.5)     
        
        #Lower legs on EVEN
        wait_for_user()        
        self.lower_legs_on_frame(C.FRAME.EVEN, True)        

        #Raise legs on ODD       
        wait_for_user()        
        self.raise_legs_on_frame(C.FRAME.ODD)


    def init_position(self):
            print_ros("Initializing position. Lower legs on even, raise legs on odd, prismatic to -0.5...")
            wait_for_user()  
            self.lower_legs_on_frame(C.FRAME.EVEN,False)
            self.raise_legs_on_frame(C.FRAME.ODD)
            self.move_prismatic(-0.5)
            self.actuators.wait_for_all_actuators_to_finish()
            print_ros("Initial position COMPLETED")



