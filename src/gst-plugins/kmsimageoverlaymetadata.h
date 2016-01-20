/*
 * (C) Copyright 2013 Kurento (http://kurento.org/)
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 */

#ifndef _KMS_IMAGE_OVERLAY_METADATA_H_
#define _KMS_IMAGE_OVERLAY_METADATA_H_

#include <gst/video/gstvideofilter.h>

G_BEGIN_DECLS

#define KMS_TYPE_IMAGE_OVERLAY_METADATA   (kms_image_overlay_metadata_get_type())
#define KMS_IMAGE_OVERLAY_METADATA(obj)   (G_TYPE_CHECK_INSTANCE_CAST((obj),KMS_TYPE_IMAGE_OVERLAY_METADATA,KmsImageOverlayMetadata))
#define KMS_IMAGE_OVERLAY_METADATA_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST((klass),KMS_TYPE_IMAGE_OVERLAY_METADATA,KmsImageOverlayMetadataClass))
#define KMS_IS_IMAGE_OVERLAY_METADATA(obj)   (G_TYPE_CHECK_INSTANCE_TYPE((obj),KMS_TYPE_IMAGE_OVERLAY_METADATA))
#define KMS_IS_IMAGE_OVERLAY_METADATA_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass),KMS_TYPE_IMAGE_OVERLAY_METADATA))

typedef struct _KmsImageOverlayMetadata KmsImageOverlayMetadata;
typedef struct _KmsImageOverlayMetadataClass KmsImageOverlayMetadataClass;
typedef struct _KmsImageOverlayMetadataPrivate KmsImageOverlayMetadataPrivate;

struct _KmsImageOverlayMetadata
{
  GstVideoFilter base;
  KmsImageOverlayMetadataPrivate *priv;
};

struct _KmsImageOverlayMetadataClass
{
  GstVideoFilterClass base_facedetector_class;
};

GType kms_image_overlay_metadata_get_type (void);

gboolean kms_image_overlay_metadata_plugin_init (GstPlugin * plugin);

G_END_DECLS

#endif  /* _KMS_IMAGE_OVERLAY_METADATA_H_ */
