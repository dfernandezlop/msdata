/* Autogenerated with kurento-module-creator */

#ifndef __KMS_MS_DATA_IMPL_FACTORY_HPP__
#define __KMS_MS_DATA_IMPL_FACTORY_HPP__

#include "KmsMsDataImpl.hpp"
#include "MediaElementImplFactory.hpp"
#include <Factory.hpp>
#include <MediaObjectImpl.hpp>
#include <boost/property_tree/ptree.hpp>

namespace kurento
{
namespace module
{
namespace msdata
{

class KmsMsDataImplFactory : public virtual MediaElementImplFactory
{
public:
  KmsMsDataImplFactory () {};

  virtual std::string getName () const {
    return "KmsMsData";
  };

private:

  virtual MediaObjectImpl *createObjectPointer (const boost::property_tree::ptree &conf, const Json::Value &params) const;

  MediaObjectImpl *createObject (const boost::property_tree::ptree &conf, std::shared_ptr<MediaPipeline> mediaPipeline) const;
};

} /* msdata */
} /* module */
} /* kurento */

#endif /*  __KMS_MS_DATA_IMPL_FACTORY_HPP__ */