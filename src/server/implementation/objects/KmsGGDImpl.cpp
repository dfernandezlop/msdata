/* Autogenerated with kurento-module-creator */

#include <gst/gst.h>
#include "MediaPipeline.hpp"
#include <KmsGGDImplFactory.hpp>
#include "KmsGGDImpl.hpp"
#include <jsonrpc/JsonSerializer.hpp>
#include <KurentoException.hpp>

#define GST_CAT_DEFAULT kurento_kms_ggd_impl
GST_DEBUG_CATEGORY_STATIC (GST_CAT_DEFAULT);
#define GST_DEFAULT_NAME "KurentoKmsGGDImpl"

namespace kurento
{
namespace module
{
namespace msdatamodule
{

KmsGGDImpl::KmsGGDImpl (const boost::property_tree::ptree &config, std::shared_ptr<MediaPipeline> mediaPipeline)  : FilterImpl (
																config, std::dynamic_pointer_cast<MediaObjectImpl> ( mediaPipeline))								
{
  g_object_set (element, "filter-factory", "graphcmetadata", NULL);

  g_object_get (G_OBJECT (element), "filter", &graphc, NULL);

  if (graphc == NULL) {
    throw KurentoException (MEDIA_OBJECT_NOT_AVAILABLE,
                            "Media Object GGD not available");
  }

  g_object_unref (graphc);
}

MediaObjectImpl *
KmsGGDImplFactory::createObject (const boost::property_tree::ptree &config, std::shared_ptr<MediaPipeline> mediaPipeline) const
{
  return new KmsGGDImpl (config, mediaPipeline);
}

KmsGGDImpl::StaticConstructor KmsGGDImpl::staticConstructor;

KmsGGDImpl::StaticConstructor::StaticConstructor()
{
  GST_DEBUG_CATEGORY_INIT (GST_CAT_DEFAULT, GST_DEFAULT_NAME, 0,
                           GST_DEFAULT_NAME);
}

} /* msdatamodule */
} /* module */
} /* kurento */
