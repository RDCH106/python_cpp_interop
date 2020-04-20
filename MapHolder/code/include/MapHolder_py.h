#include <map>
#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>
#include <string>

#ifndef MAPHOLDER_HPP
#  define MAPHOLDER_HPP
typedef std::map<std::string, std::string> StringMap;
class MapHolder
{
public:
  /*Constructors*/
  MapHolder();
  MapHolder(boost::python::dict &py_dict);

  /*Modifiers*/
  void update_map(boost::python::dict &py_dict);
  void clear();

  boost::python::dict get_dict();
  StringMap get_map();
  size_t size();

protected:
  StringMap map_;
};
#endif
