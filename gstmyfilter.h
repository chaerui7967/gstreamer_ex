/* 
 * GStreamer
 * Copyright (C) 2006 Stefan Kost <ensonic@users.sf.net>
 * Copyright (C) 2020 Niels De Graef <niels.degraef@gmail.com>
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
 
#ifndef __GST_MY_FILTER_H__
#define __GST_MY_FILTER_H__

#include <gst/gst.h>

G_BEGIN_DECLS

/* Standard macros for defining types for this element.  */
#define GST_TYPE_MY_FILTER \
  (gst_my_filter_get_type())
#define GST_MY_FILTER(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), GST_TYPE_MY_FILTER, GstMyFilter))
#define GST_MY_FILTER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_MY_FILTER,GstMyFilterClass))
#define GST_IS_MY_FILTER(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_MY_FILTER))
#define GST_IS_MY_FILTER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_MY_FILTER))

typedef struct _GstMyFilter      GstMyFilter;
typedef struct _GstMyFilterClass GstMyFilterClass;

struct _GstMyFilter {
    GstElement element;

    GstPad *sinkpad, *srcpad;

    gboolean silent;
};

/* Standard definition defining a class for this element. */
struct _GstMyFilterClass {
    GstElementClass parent_class;
};

/* Standard function returning type information. */
GType gst_my_filter_get_type (void);

G_END_DECLS

#endif /* __GST_MYFILTER_H__ */