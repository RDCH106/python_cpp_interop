#include "MapHolder_py.h"
#include <iostream>


// Original Idea --> http://ppiotrow.blogspot.com/2013/01/boostpythondict-to-stdmap-conversion.html


MapHolder::MapHolder(){

};

MapHolder::MapHolder(boost::python::dict &py_dict)
{
  update_map(py_dict);
}

void MapHolder::update_map(boost::python::dict &py_dict)
{
  boost::python::list keys = py_dict.keys();
  for (int i = 0; i < len(keys); ++i) {
    boost::python::extract<std::string> extracted_key(keys[i]);
    if (!extracted_key.check()) {
      std::cout << "Key invalid, map might be incomplete" << std::endl;
      continue;
    }
    std::string key = extracted_key;
    boost::python::extract<std::string> extracted_val(py_dict[key]);
    if (!extracted_val.check()) {
      std::cout << "Value invalid, map might be incomplete" << std::endl;
      continue;
    }
    std::string value = extracted_val;
    map_[key] = value;
  }
}

void MapHolder::clear()
{
  map_.clear();
}

boost::python::dict MapHolder::get_dict()
{
  boost::python::dict py_dict;
  for (StringMap::const_iterator it = map_.begin(); it != map_.end(); ++it) py_dict[it->first] = it->second;
  return py_dict;
}

StringMap MapHolder::get_map()
{
  return map_;
}

size_t MapHolder::size() {
  return map_.size();
}
