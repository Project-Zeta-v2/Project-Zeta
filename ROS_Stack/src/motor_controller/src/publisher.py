#!/usr/bin/env python3
# license removed for brevity
import rospy
from std_msgs.msg import Float64

motors = [['FL_1_position_controller', 'FL_2_position_controller', 'FL_3_position_controller'], ['FR_1_position_controller', 'FR_2_position_controller', 'FR_3_position_controller'], ['BL_1_position_controller', 'BL_2_position_controller', 'BL_3_position_controller'], ['BR_1_position_controller', 'BR_2_position_controller', 'BR_3_position_controller']]
publishers = [[None, None, None],[None, None, None],[None, None, None]]

def publisher():
    for i in motors:
        for j in i:
            pub = rospy.Publisher('/zeta_urdf/' + j + '/command', Float64, queue_size=10)
            try:
                publishers[motors.index(i)][i.index(j)] = pub
            except IndexError:
                pass
    print(publishers)
    rospy.init_node('motor_controller_pub', anonymous=True)
    rate = rospy.Rate(200) # 10hz
    angle = 0
    while not rospy.is_shutdown():
        rospy.loginfo(f"Publishing...{angle}")
        publishers[0][0].publish(angle)
        angle += 0.001
        if(angle >= 1):
            angle = 0 
        rate.sleep()

if __name__ == '__main__':
    try:
        publisher()
    except rospy.ROSInterruptException:
        pass
