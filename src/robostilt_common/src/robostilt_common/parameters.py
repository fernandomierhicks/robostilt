# Parameters are retrieved from the ROS parameter server and exposed as an object. This enabled autocomplete while coding and avoid harcoding names on other files.
#! /usr/bin/env python
import rospy
from  common import print_ros




class speed:
    lowering_legs= None     
    raising_legs= None
    prismatic= None

    print_ros("went in")

    @classmethod
    def read(self):
        speeds=rospy.get_param("robostilt/speeds")
        self.lowering_legs=speeds["lowering_legs"]
        self.raising_legs=speeds["raising_legs"]
        self.prismatic=speeds["raising_legs"]
        print_ros("Parameters: speeds updated")


class dimension:
    nominal_walking_height= None  

    @classmethod   
    def read(self):
        dimensions=rospy.get_param("robostilt/dimensions")
        self.nominal_walking_height=dimensions["nominal_walking_height"]
        print_ros("Parameters: dimensions updated")


class effort:
    leg_max= None  
    lowering_leg_min=None
    lowering_leg_max=None

    @classmethod   
    def read(self):
        efforts=rospy.get_param("robostilt/efforts")
        self.leg_max=efforts["leg_max"]
        self.lowering_leg_min=efforts["lowering_leg_min"]
        self.lowering_leg_max=efforts["lowering_leg_max"]



        print_ros("Parameters: efforts updated")


def read_from_parameter_server():
    speed.read()
    dimension.read()
    effort.read()