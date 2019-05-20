// Generated by gencpp from file robostilt_common/robostilt_state_message.msg
// DO NOT EDIT!


#ifndef ROBOSTILT_COMMON_MESSAGE_ROBOSTILT_STATE_MESSAGE_H
#define ROBOSTILT_COMMON_MESSAGE_ROBOSTILT_STATE_MESSAGE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace robostilt_common
{
template <class ContainerAllocator>
struct robostilt_state_message_
{
  typedef robostilt_state_message_<ContainerAllocator> Type;

  robostilt_state_message_()
    : header()
    , name()
    , is_supporting()  {
    }
  robostilt_state_message_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , name(_alloc)
    , is_supporting(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _name_type;
  _name_type name;

   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _is_supporting_type;
  _is_supporting_type is_supporting;





  typedef boost::shared_ptr< ::robostilt_common::robostilt_state_message_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robostilt_common::robostilt_state_message_<ContainerAllocator> const> ConstPtr;

}; // struct robostilt_state_message_

typedef ::robostilt_common::robostilt_state_message_<std::allocator<void> > robostilt_state_message;

typedef boost::shared_ptr< ::robostilt_common::robostilt_state_message > robostilt_state_messagePtr;
typedef boost::shared_ptr< ::robostilt_common::robostilt_state_message const> robostilt_state_messageConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robostilt_common::robostilt_state_message_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robostilt_common::robostilt_state_message_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace robostilt_common

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'robostilt_common': ['/home/fernandomierhicks/robostilt/src/robostilt_common/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::robostilt_common::robostilt_state_message_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robostilt_common::robostilt_state_message_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robostilt_common::robostilt_state_message_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robostilt_common::robostilt_state_message_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robostilt_common::robostilt_state_message_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robostilt_common::robostilt_state_message_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robostilt_common::robostilt_state_message_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7b6f28c055f5a9e7c3caa539d494bf54";
  }

  static const char* value(const ::robostilt_common::robostilt_state_message_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7b6f28c055f5a9e7ULL;
  static const uint64_t static_value2 = 0xc3caa539d494bf54ULL;
};

template<class ContainerAllocator>
struct DataType< ::robostilt_common::robostilt_state_message_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robostilt_common/robostilt_state_message";
  }

  static const char* value(const ::robostilt_common::robostilt_state_message_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robostilt_common::robostilt_state_message_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# This is a message that holds data abou the general state of the robo\n\
#\n\
# name holds the name of each leg\n\
# is_supporting=true when that leg is currenlty supporting weight of the robot. Otherwise its false\n\
#\n\
# Each leg is uniquely identified by its name\n\
# The header specifies the time at which the leg states were recorded. All the leg states\n\
# in one message have to be recorded at the same time.\n\
#\n\
# This message consists of a multiple arrays, one for each part of the leg state. \n\
#\n\
# All arrays in this message should have the same size, or be empty.\n\
# This is the only way to uniquely associate the joint name with the correct\n\
# states.\n\
\n\
Header header\n\
\n\
string[] name\n\
bool[] is_supporting\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::robostilt_common::robostilt_state_message_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robostilt_common::robostilt_state_message_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.name);
      stream.next(m.is_supporting);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct robostilt_state_message_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robostilt_common::robostilt_state_message_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robostilt_common::robostilt_state_message_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "name[]" << std::endl;
    for (size_t i = 0; i < v.name.size(); ++i)
    {
      s << indent << "  name[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name[i]);
    }
    s << indent << "is_supporting[]" << std::endl;
    for (size_t i = 0; i < v.is_supporting.size(); ++i)
    {
      s << indent << "  is_supporting[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.is_supporting[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOSTILT_COMMON_MESSAGE_ROBOSTILT_STATE_MESSAGE_H