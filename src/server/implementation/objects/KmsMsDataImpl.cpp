/**
Licensing and distribution

ArModule is licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.

ALVAR 2.0.0 - A Library for Virtual and Augmented Reality Copyright 2007-2012 VTT Technical Research Centre of Finland Licensed under the GNU Lesser General Public License

Irrlicht Engine, the zlib and libpng. The Irrlicht Engine is based in part on the work of the Independent JPEG Group The module utilizes IJG code when the Irrlicht engine is compiled with support for JPEG images.
*/

/** @author Markus Ylikerälä */

/* Autogenerated with kurento-module-creator */

#include <gst/gst.h>
#include "MediaPipeline.hpp"
#include "MediaPipelineImpl.hpp"
#include <KmsMsDataImplFactory.hpp>
#include "KmsMsDataImpl.hpp"
#include <jsonrpc/JsonSerializer.hpp>
#include <KurentoException.hpp>

#define GST_CAT_DEFAULT kurento_kms_ms_data_impl
GST_DEBUG_CATEGORY_STATIC (GST_CAT_DEFAULT);
#define GST_DEFAULT_NAME "KurentoKmsMsDataImpl"

#define FACTORY_NAME "kmsmsdata"

namespace kurento
{
namespace module
{
namespace msdata
{

KmsMsDataImpl::KmsMsDataImpl (const boost::property_tree::ptree &config, std::shared_ptr<MediaPipeline> mediaPipeline)  : MediaElementImpl (config,
                    std::dynamic_pointer_cast<MediaPipelineImpl> (mediaPipeline),
                    FACTORY_NAME) 
{
}

MediaObjectImpl *
KmsMsDataImplFactory::createObject (const boost::property_tree::ptree &config, std::shared_ptr<MediaPipeline> mediaPipeline) const
{
  return new KmsMsDataImpl (config, mediaPipeline);
}

KmsMsDataImpl::StaticConstructor KmsMsDataImpl::staticConstructor;

KmsMsDataImpl::StaticConstructor::StaticConstructor()
{
  GST_DEBUG_CATEGORY_INIT (GST_CAT_DEFAULT, GST_DEFAULT_NAME, 0,
                           GST_DEFAULT_NAME);
}

} /* msdata */
} /* module */
} /* kurento */
