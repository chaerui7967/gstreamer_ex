/*
 * GStreamer
 * Copyright (C) 2006 Stefan Kost <ensonic@users.sf.net>
 * Copyright (C) 2022  <<user@hostname.org>>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/**
 * SECTION:element-myfilter
 *
 * FIXME:Describe myfilter here.
 *
 * <refsect2>
 * <title>Example launch line</title>
 * |[
 * gst-launch -v -m fakesrc ! myfilter ! fakesink silent=TRUE
 * ]|
 * </refsect2>
 */

#ifdef HAVE_CONFIG_H
#endif

#include "config.h"
#include <gst/gst.h>
//#include <gst/base/base.h>
//#include <gst/controller/controller.h>
#include "gstmyfilter.h"

GST_DEBUG_CATEGORY_STATIC (gst_my_filter_debug);
#define GST_CAT_DEFAULT gst_my_filter_debug

/* Filter signals and args */
enum
{
  /* FILL ME */
  LAST_SIGNAL
};

enum
{
  PROP_0,
  PROP_SILENT,
};

/* the capabilities of the inputs and outputs.
 *
 * FIXME:describe the real formats here.
 */
static GstStaticPadTemplate sink_template = GST_STATIC_PAD_TEMPLATE (
        "sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS ("ANY")
    );

static GstStaticPadTemplate src_template = GST_STATIC_PAD_TEMPLATE (
        "src",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS ("ANY")
    );

#define gst_my_filter_parent_class parent_class
G_DEFINE_TYPE(GstMyFilter, gst_my_filter, GST_TYPE_ELEMENT);

static void gst_my_filter_set_property (GObject * object, guint prop_id, const GValue * value, GParamSpec * pspec);
static void gst_my_filter_get_property (GObject * object, guint prop_id, GValue * value, GParamSpec * pspec);

static gboolean gst_my_filter_sink_event (GstPad * pad, GstObject * parent, GstEvent * event);
static GstFlowReturn gst_my_filter_chain (GstPad * pad, GstObject * parent, GstBuffer * buf);


static void
gst_my_filter_class_init (GstMyFilterClass * klass)
{
    GObjectClass *gobject_class;
    GstElementClass *gstelement_class;

    gobject_class = (GObjectClass *) klass;
    gstelement_class = (GstElementClass *) klass;

    gobject_class->set_property = gst_my_filter_set_property;
    gobject_class->get_property = gst_my_filter_get_property;

    g_object_class_install_property (gobject_class, PROP_SILENT,
                                     g_param_spec_boolean ("silent", "Silent", "Produce verbose output ?",
                                                           FALSE, G_PARAM_READWRITE));

    gst_element_class_set_details_simple(gstelement_class,
                                         "MyFilter",
                                         "FIXME:Generic",
                                         "FIXME:Generic Template Element",
                                         "Ozan Karaali <<user@hostname.org>>");

    gst_element_class_add_pad_template (gstelement_class,
                                        gst_static_pad_template_get (&src_template));
    gst_element_class_add_pad_template (gstelement_class,
                                        gst_static_pad_template_get (&sink_template));
}

static void
gst_my_filter_init (GstMyFilter * filter)
{
    filter->sinkpad = gst_pad_new_from_static_template (&sink_template, "sink");
    gst_pad_set_event_function (filter->sinkpad,
                                GST_DEBUG_FUNCPTR(gst_my_filter_sink_event));
    gst_pad_set_chain_function (filter->sinkpad,
                                GST_DEBUG_FUNCPTR(gst_my_filter_chain));
    GST_PAD_SET_PROXY_CAPS (filter->sinkpad);
    gst_element_add_pad (GST_ELEMENT (filter), filter->sinkpad);

    filter->srcpad = gst_pad_new_from_static_template (&src_template, "src");
    GST_PAD_SET_PROXY_CAPS (filter->srcpad);
    gst_element_add_pad (GST_ELEMENT (filter), filter->srcpad);

    filter->silent = FALSE;
}

static void
gst_my_filter_set_property (GObject * object, guint prop_id,
                            const GValue * value, GParamSpec * pspec)
{
    GstMyFilter *filter = GST_MY_FILTER (object);

    switch (prop_id) {
        case PROP_SILENT:
            filter->silent = g_value_get_boolean (value);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
            break;
    }
}

static void
gst_my_filter_get_property (GObject * object, guint prop_id,
                            GValue * value, GParamSpec * pspec)
{
    GstMyFilter *filter = GST_MY_FILTER (object);

    switch (prop_id) {
        case PROP_SILENT:
            g_value_set_boolean (value, filter->silent);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
            break;
    }
}

/* GstElement vmethod implementations */

/* this function handles sink events */
static gboolean
gst_my_filter_sink_event (GstPad * pad, GstObject * parent, GstEvent * event)
{
    GstMyFilter *filter = GST_MY_FILTER (parent);
    gboolean ret;

    GST_LOG_OBJECT (filter, "Received %s event: %" GST_PTR_FORMAT,
                    GST_EVENT_TYPE_NAME (event), event);

    switch (GST_EVENT_TYPE (event)) {
        case GST_EVENT_CAPS:
        {
            GstCaps * caps;

            gst_event_parse_caps (event, &caps);
            /* do something with the caps */

            /* and forward */
            ret = gst_pad_event_default (pad, parent, event);
            break;
        }
        default:
            ret = gst_pad_event_default (pad, parent, event);
            break;
    }
    return ret;
}

/* chain function
 * this function does the actual processing
 */
static GstFlowReturn
gst_my_filter_chain (GstPad * pad, GstObject * parent, GstBuffer * buf)
{
    GstMyFilter *filter;

    filter = GST_MY_FILTER (parent);

    if (! filter->silent){
        g_print ("Have data of size %" G_GSIZE_FORMAT" bytes!\n",
                 gst_buffer_get_size (buf));
//        g_print ("Loaded!");
        // Now we can use iostream C++:
//        std::cout<< "Test" <<std::endl;
    }

    /* just push out the incoming buffer without touching it */
    return gst_pad_push (filter->srcpad, buf);
}


/* entry point to initialize the plug-in
 * initialize the plug-in itself
 * register the element factories and other features
 */
static gboolean
myfilter_init (GstPlugin * myfilter)
{
    /* debug category for fltering log messages
     *
     * exchange the string 'Template myfilter' with your description
     */
    GST_DEBUG_CATEGORY_INIT (gst_my_filter_debug, "myfilter",
                             0, "Template myfilter");

    return gst_element_register (myfilter, "myfilter", GST_RANK_NONE,
                                 GST_TYPE_MY_FILTER);
}

/* PACKAGE: this is usually set by autotools depending on some _INIT macro
 * in configure.ac and then written into and defined in config.h, but we can
 * just set it ourselves here in case someone doesn't use autotools to
 * compile this code. GST_PLUGIN_DEFINE needs PACKAGE to be defined.
 */

#ifndef PACKAGE
#define PACKAGE "myfilter"
#endif

/* gstreamer looks for this structure to register myfilters
 *
 * exchange the string 'Template myfilter' with your myfilter description
 */
GST_PLUGIN_DEFINE (
        GST_VERSION_MAJOR,
        GST_VERSION_MINOR,
        myfilter,
        "Template myfilter",
        myfilter_init,
        VERSION,
        "LGPL",
        "GStreamer",
        "http://gstreamer.net/"
)





//
//
//static GstFlowReturn gst_my_filter_chain (GstPad    *pad,
//                                          GstObject *parent,
//                                          GstBuffer *buf);
//
//#define gst_myfilter_parent_class parent_class
//
//G_DEFINE_TYPE (GstMyFilter, gst_my_filter, GST_TYPE_ELEMENT);
//GST_ELEMENT_REGISTER_DEFINE (my_filter, "my-filter", GST_RANK_NONE, GST_TYPE_MY_FILTER);
//
//
//static void gst_my_filter_set_property (GObject * object,
//    guint prop_id, const GValue * value, GParamSpec * pspec);
//static void gst_my_filter_get_property (GObject * object,
//    guint prop_id, GValue * value, GParamSpec * pspec);
//
//static GstFlowReturn gst_my_filter_transform_ip (GstBaseTransform *
//    base, GstBuffer * outbuf);
//
///* GObject vmethod implementations */
//
///* initialize the myfilter's class */
//static void
//gst_my_filter_class_init (GstMyFilterClass * klass)
//{
//  GstElementClass *element_class = GST_ELEMENT_CLASS(klass);
//
//  GObjectClass *gobject_class;
//  GstElementClass *gstelement_class;
//
//  gobject_class = (GObjectClass *) klass;
//  gstelement_class = (GstElementClass *) klass;
//
//  gobject_class->set_property = gst_my_filter_set_property;
//  gobject_class->get_property = gst_my_filter_get_property;
//
//  g_object_class_install_property (gobject_class, PROP_SILENT,
//      g_param_spec_boolean ("silent", "Silent", "Produce verbose output ?",
//          FALSE, G_PARAM_READWRITE | GST_PARAM_CONTROLLABLE));
//
//  gst_element_class_set_details_simple (gstelement_class,
//      "my_filter",
//      "Generic/Filter",
//      "FIXME:Generic Template Filter", " <<user@hostname.org>>");
//
//  gst_element_class_add_pad_template (gstelement_class,
//      gst_static_pad_template_get (&src_template));
//  gst_element_class_add_pad_template (gstelement_class,
//      gst_static_pad_template_get (&sink_template));
////  gst_element_class_add_pad_template(element_class,
////                                     gst_static_pad_template_get(&src_template));
////  gst_element_class_add_pad_template(element_class,
////                                     gst_static_pad_template_get(&sink_template));
//
//  GST_BASE_TRANSFORM_CLASS (klass)->transform_ip =
//      GST_DEBUG_FUNCPTR (gst_my_filter_transform_ip);
//
//  /* debug category for fltering log messages
//   *
//   * FIXME:exchange the string 'Template myfilter' with your description
//   */
//  GST_DEBUG_CATEGORY_INIT (gst_my_filter_debug, "my_filter", 0,
//      "Template my_filter");
//
//  gst_element_class_set_metadata(gstelement_class,
//                                 "An example plugin",
//                                 "Example/FirstExample",
//                                 "Shows the basic structure of a plugin",
//                                 "your name <your.name@your.isp>");
//}
//
///* initialize the new element
// * initialize instance structure
// */
//static void
//gst_my_filter_init (GstMyFilter * filter)
//{
//  filter->silent = FALSE;
//  gst_pad_set_chain_function (filter->sinkpad,
//                            gst_my_filter_chain);
//}
//
//static void
//gst_my_filter_set_property (GObject * object, guint prop_id,
//    const GValue * value, GParamSpec * pspec)
//{
//  GstMyFilter *filter = GST_MY_FILTER (object);
//
//  switch (prop_id) {
//    case PROP_SILENT:
//      filter->silent = g_value_get_boolean (value);
//      break;
//    default:
//      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
//      break;
//  }
//}
//
//static void
//gst_my_filter_get_property (GObject * object, guint prop_id,
//    GValue * value, GParamSpec * pspec)
//{
//  GstMyFilter *filter = GST_MY_FILTER (object);
//
//  switch (prop_id) {
//    case PROP_SILENT:
//      g_value_set_boolean (value, filter->silent);
//      break;
//    default:
//      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
//      break;
//  }
//}
//
///* GstBaseTransform vmethod implementations */
//
///* this function does the actual processing
// */
//static GstFlowReturn
//gst_my_filter_transform_ip (GstBaseTransform * base, GstBuffer * outbuf)
//{
//  GstMyFilter *filter = GST_MY_FILTER (base);
//
//  if (GST_CLOCK_TIME_IS_VALID (GST_BUFFER_TIMESTAMP (outbuf)))
//    gst_object_sync_values (GST_OBJECT (filter), GST_BUFFER_TIMESTAMP (outbuf));
//
//  if (filter->silent == FALSE)
//    g_print ("I'm plugged, therefore I'm in.\n");
//
//  /* FIXME: do something interesting here.  This simply copies the source
//   * to the destination. */
//
//  return GST_FLOW_OK;
//}
//
//static GstFlowReturn
//gst_my_filter_chain (GstPad    *pad,
//                     GstObject *parent,
//                     GstBuffer *buf)
//{
//    GstMyFilter *filter = GST_MY_FILTER (parent);
//
//    if (!filter->silent)
//        g_print ("Have data of size %" G_GSIZE_FORMAT" bytes!\n",
//                 gst_buffer_get_size (buf));
//
//    return gst_pad_push (filter->srcpad, buf);
//}
//
//
///* entry point to initialize the plug-in
// * initialize the plug-in itself
// * register the element factories and other features
// */
//static gboolean
//plugin_init (GstPlugin * plugin)
//{
//  return GST_ELEMENT_REGISTER (my_filter, plugin);
//}
//
///* gstreamer looks for this structure to register myfilters
// *
// * FIXME:exchange the string 'Template myfilter' with you myfilter description
// */
//
//
//GST_PLUGIN_DEFINE (
//    GST_VERSION_MAJOR,
//    GST_VERSION_MINOR,
//    my_filter,
//    "My filter plugin",
//    plugin_init,
//    "3.10",
//    "LGPL",
//    "gstreamer",
//    "http://gstreamer.net/")
