// Generated by gencpp from file message_tests/ChangerateRequest.msg
// DO NOT EDIT!


#ifndef MESSAGE_TESTS_MESSAGE_CHANGERATEREQUEST_H
#define MESSAGE_TESTS_MESSAGE_CHANGERATEREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace message_tests
{
template <class ContainerAllocator>
struct ChangerateRequest_
{
  typedef ChangerateRequest_<ContainerAllocator> Type;

  ChangerateRequest_()
    : newrate(0.0)  {
    }
  ChangerateRequest_(const ContainerAllocator& _alloc)
    : newrate(0.0)  {
  (void)_alloc;
    }



   typedef double _newrate_type;
  _newrate_type newrate;





  typedef boost::shared_ptr< ::message_tests::ChangerateRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::message_tests::ChangerateRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ChangerateRequest_

typedef ::message_tests::ChangerateRequest_<std::allocator<void> > ChangerateRequest;

typedef boost::shared_ptr< ::message_tests::ChangerateRequest > ChangerateRequestPtr;
typedef boost::shared_ptr< ::message_tests::ChangerateRequest const> ChangerateRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::message_tests::ChangerateRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::message_tests::ChangerateRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::message_tests::ChangerateRequest_<ContainerAllocator1> & lhs, const ::message_tests::ChangerateRequest_<ContainerAllocator2> & rhs)
{
  return lhs.newrate == rhs.newrate;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::message_tests::ChangerateRequest_<ContainerAllocator1> & lhs, const ::message_tests::ChangerateRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace message_tests

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::message_tests::ChangerateRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::message_tests::ChangerateRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::message_tests::ChangerateRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::message_tests::ChangerateRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::message_tests::ChangerateRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::message_tests::ChangerateRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::message_tests::ChangerateRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "16f24c25ebb8fdfdbd54328d251e49b8";
  }

  static const char* value(const ::message_tests::ChangerateRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x16f24c25ebb8fdfdULL;
  static const uint64_t static_value2 = 0xbd54328d251e49b8ULL;
};

template<class ContainerAllocator>
struct DataType< ::message_tests::ChangerateRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "message_tests/ChangerateRequest";
  }

  static const char* value(const ::message_tests::ChangerateRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::message_tests::ChangerateRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 newrate\n"
;
  }

  static const char* value(const ::message_tests::ChangerateRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::message_tests::ChangerateRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.newrate);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ChangerateRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::message_tests::ChangerateRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::message_tests::ChangerateRequest_<ContainerAllocator>& v)
  {
    s << indent << "newrate: ";
    Printer<double>::stream(s, indent + "  ", v.newrate);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MESSAGE_TESTS_MESSAGE_CHANGERATEREQUEST_H