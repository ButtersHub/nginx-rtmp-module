# NGINX-based Media Streaming Server
## nginx-rtmp-module

This is a fork of https://github.com/arut/nginx-rtmp-module with the following
changes:

1. HLS cleanup interval

   Directive hls_cleanup_interval when hls is enabled sets the time that
   fragments are kept on disk. the interval is in msec
2. HLS fragment done notification

  Directive on_hls_fargment_done sends an async HTTP notification when a
  fragment is closed and written to disk.

  The notification has the following parameters in addition to the parameters
  sent by on_connect notification:
  * path: fragment path
  * stream: the stream off which the fragment is part
  * variant: if it's a variant stream the variant prefix
  * variant_args: variant arguments from the configuration
  * id: fragment id
  * key_id: fragment key id
  * duration: fragment duration
  * active: is the stream active
  * discontinuity: is discontinuity set for this fragment
  * ts: stream timestamp
  * systs: system timestamp when the fragment was opened

Sample configuration:

```
rtmp {

    server {

        listen 1935;

        application hls {

            # enable live streaming
            live on;

            hls on;
            hls_path /data/hls;
            hls_variant -low  BANDWIDTH=900000;
            hls_variant -high BANDWIDTH=1500000;
            hls_cleanup_interval 3600000;

            on_publish http://server.com/notify/publish;
            on_hls_fargment_done http://server2.com/notify/hls-frag;
        }
    }
}
```
