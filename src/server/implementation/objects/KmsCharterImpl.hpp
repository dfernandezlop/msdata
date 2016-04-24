/* Autogenerated with kurento-module-creator */

#ifndef __KMS_CHARTER_IMPL_HPP__
#define __KMS_CHARTER_IMPL_HPP__

#include "FilterImpl.hpp"
#include "KmsCharter.hpp"
#include <EventHandler.hpp>
#include <boost/property_tree/ptree.hpp>

namespace kurento
{
namespace module
{
namespace msdatamodule
{
class KmsCharterImpl;
} /* msdatamodule */
} /* module */
} /* kurento */

namespace kurento
{
void Serialize (std::shared_ptr<kurento::module::msdatamodule::KmsCharterImpl> &object, JsonSerializer &serializer);
} /* kurento */

namespace kurento
{
class MediaPipelineImpl;
} /* kurento */

namespace kurento
{
namespace module
{
namespace msdatamodule
{

class KmsCharterImpl : public FilterImpl, public virtual KmsCharter
{

public:

  KmsCharterImpl (const boost::property_tree::ptree &config, std::shared_ptr<MediaPipeline> mediaPipeline);

  virtual ~KmsCharterImpl () {};

  /* Next methods are automatically implemented by code generator */
  virtual bool connect (const std::string &eventType, std::shared_ptr<EventHandler> handler);
  virtual void invoke (std::shared_ptr<MediaObjectImpl> obj,
                       const std::string &methodName, const Json::Value &params,
                       Json::Value &response);

  virtual void Serialize (JsonSerializer &serializer);

private:

  class StaticConstructor
  {
  public:
    StaticConstructor();
  };

  static StaticConstructor staticConstructor;

};

} /* msdatamodule */
} /* module */
} /* kurento */

#endif /*  __KMS_CHARTER_IMPL_HPP__ */
