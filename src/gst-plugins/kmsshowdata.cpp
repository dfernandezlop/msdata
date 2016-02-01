#include "kmsshowdata.h"

#include <glib/gstdio.h>



#include <opencv/cv.h>
#include <opencv/highgui.h>

#include <opencv2/opencv.hpp>
#include <memory>

#include <opencv2/opencv.hpp>

#include <string>

#include <glib.h>


#include <gst/gst.h>
#include <gst/video/video.h>
#include <gst/video/gstvideofilter.h>
#include <glib/gstdio.h>
#include <ftw.h>
#include <string.h>
#include <errno.h>


cv::Mat auxImage;


GST_DEBUG_CATEGORY_STATIC (kms_show_data_debug_category);
#define GST_CAT_DEFAULT kms_show_data_debug_category
#define PLUGIN_NAME "kmsshowdata"

#define KMS_SHOW_DATA_GET_PRIVATE(obj) (                    \
    G_TYPE_INSTANCE_GET_PRIVATE (                           \
        (obj),                                              \
        KMS_TYPE_SHOW_DATA,                                 \
        KmsShowDataPrivate                                  \
    )                                                       \
)





/* class initialization */

G_DEFINE_TYPE_WITH_CODE (KmsShowData, kms_show_data,
                         KMS_TYPE_ELEMENT,
                         GST_DEBUG_CATEGORY_INIT (kms_show_data_debug_category,
                             PLUGIN_NAME, 0,
                             "debug category for kms_show_data element") );

struct _KmsShowDataPrivate
{
  GstElement *text_overlay;
};


static void
kms_show_data_connect_video (KmsShowData * self, GstElement * agnosticbin)
{
  GstPad *text_overlay_sink = gst_element_get_static_pad (self->priv->text_overlay, "video_sink");
  GstElement *videoconvert = gst_element_factory_make ("videoconvert", NULL);

  gst_bin_add (GST_BIN (self), videoconvert);

  kms_element_connect_sink_target (KMS_ELEMENT (self), text_overlay_sink, KMS_ELEMENT_PAD_TYPE_VIDEO);
  gst_element_link (self->priv->text_overlay, videoconvert);
  gst_element_link (videoconvert, agnosticbin);

  g_object_unref (text_overlay_sink);
}

static void
kms_show_data_connect_audio (KmsShowData * self, GstElement * agnosticbin)
{
  GstPad *target = gst_element_get_static_pad (agnosticbin, "sink");

  kms_element_connect_sink_target (KMS_ELEMENT (self), target, KMS_ELEMENT_PAD_TYPE_AUDIO);
  g_object_unref (target);
}

void new_data (GstElement* object, GstBuffer* buffer, KmsShowData* self)
{
  GstMapInfo info;
  gchar *msg;

  if (!gst_buffer_map (buffer, &info, GST_MAP_READ)) {
    GST_WARNING_OBJECT (self, "Can not read buffer");
    return;
  }

  msg = g_strndup ((const gchar *) info.data, info.size);
  gst_buffer_unmap (buffer, &info);

  if (msg != NULL) {
    g_object_set (self->priv->text_overlay, "text", msg, NULL);
    g_free (msg);


    //    g_object_set (self->priv->text_overlay, "text", (guchar*)auxImage.data, NULL);

    //self->priv->text_overlay = (gchar)auxImage.data;

    
    GstBuffer *buffer;
    GstMapInfo map;

    int size = auxImage.channels() * auxImage.cols * auxImage.rows;
    buffer = gst_buffer_new_allocate (NULL, size, NULL);
    //gst_buffer_map (buffer, &map, GST_MAP_WRITE);
    memcpy((guchar*)map.data, (guchar*)auxImage.data,  gst_buffer_get_size( buffer ) );
    //    GST_BUFFER_DURATION( buffer ) = gst_util_uint64_scale( size, GST_SECOND, 1 );
  
    /*









    */
  }
}


static void
kms_show_data_connect_data (KmsShowData * self, GstElement * tee)
{
  GstElement *identity =  gst_element_factory_make ("identity", NULL);
  GstPad *identity_sink = gst_element_get_static_pad (identity, "sink");;

  gst_bin_add (GST_BIN (self), identity);

  kms_element_connect_sink_target (KMS_ELEMENT (self), identity_sink, KMS_ELEMENT_PAD_TYPE_DATA);
  gst_element_link (identity, tee);

  g_signal_connect (identity, "handoff", G_CALLBACK (new_data), self);

  g_object_unref (identity_sink);
}

static void
kms_show_data_init (KmsShowData *self)
{
  self->priv = KMS_SHOW_DATA_GET_PRIVATE (self);

  self->priv->text_overlay = gst_element_factory_make ("textoverlay", NULL);
  g_object_set (self->priv->text_overlay, "font-desc", "Sans 26", NULL);
  gst_bin_add (GST_BIN (self), self->priv->text_overlay);

  kms_show_data_connect_video (self, kms_element_get_video_agnosticbin (KMS_ELEMENT (self)));
  kms_show_data_connect_audio (self, kms_element_get_audio_agnosticbin (KMS_ELEMENT (self)));
  kms_show_data_connect_data (self, kms_element_get_data_tee (KMS_ELEMENT (self)));


  gst_element_sync_state_with_parent (self->priv->text_overlay);
}


#if 0
static GstFlowReturn
kms_show_data_transform_frame_ip (GstVideoFilter * filter,
    GstVideoFrame * frame)
{
  std::cout << "\njestas: " << std::endl;

  return GST_FLOW_OK;
}
#endif

static void
kms_show_data_class_init (KmsShowDataClass *klass)
{
  GST_DEBUG_CATEGORY_INIT (GST_CAT_DEFAULT, PLUGIN_NAME, 0, PLUGIN_NAME);

  gst_element_class_set_static_metadata (GST_ELEMENT_CLASS (klass),
      "KmsShowData", "Generic",
      "Receives text from the client and prints it in the image",
      "David Fernández López <d.fernandezlop@gmail.com>");

  g_type_class_add_private (klass, sizeof (KmsShowDataPrivate));


  /*
  std::string overlay = std::string("/opt/heartrate1.bmp");
    auxImage = cvLoadImage (overlay.c_str(), CV_LOAD_IMAGE_UNCHANGED);	
    std::cout << "\nTHE IMAGE: " << overlay << " " <<
      auxImage.depth() << " " << auxImage.channels() << " " << auxImage.cols << " " << auxImage.rows << std::endl;
  */


    /*
  GstVideoFilterClass *video_filter_class = GST_VIDEO_FILTER_CLASS (klass);
  video_filter_class->transform_frame_ip =
      GST_DEBUG_FUNCPTR (kms_show_data_transform_frame_ip);
    */
}

gboolean
kms_show_data_plugin_init (GstPlugin *plugin)
{
  return gst_element_register (plugin, PLUGIN_NAME, GST_RANK_NONE,
                               KMS_TYPE_SHOW_DATA);
}