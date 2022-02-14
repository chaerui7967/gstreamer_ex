#include <gst/gst.h>

int main (int arg, char *argv[]) {
    GstElement *pipeline, *audio_source, *tee, *audio_queue, *audio_convert, *audio_resample, *audio_sink;
    GstElement *video_queue, *visual, *video_convert, *video_sink;
    GstBus *bus;
    GstMessage *msg;
    GstPad *tee_audio_pad, *tee_video_pad;
    GstPad *queue_audio_pad, *queue_video_pad;

    gst_init(&arg, &argv);

    audio_source = gst_element_factory_make("audiotestsrc", "audio_source");

}