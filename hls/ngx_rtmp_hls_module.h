
/*
 * Copyright (C) Vidmind
 */


#ifndef _NGX_RTMP_HLS_H_INCLUDED_
#define _NGX_RTMP_HLS_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>
#include "ngx_rtmp.h"

typedef struct {
    u_char                              frag_path[NGX_MAX_PATH + 1];
    uint64_t                            id;
    uint64_t                            key_id;
    double                              duration;
    unsigned                            active;
    unsigned                            discont;
    u_char                              stream[NGX_RTMP_MAX_NAME+1];
    u_char                              variant[NGX_RTMP_MAX_NAME+1];
    u_char                              variant_args[1024];
    uint64_t                            frag_ts;
    uint64_t                            system_ts;
} ngx_rtmp_hls_frag_done_t;


typedef ngx_int_t (*ngx_rtmp_hls_frag_done_pt)(ngx_rtmp_session_t *s,
        ngx_rtmp_hls_frag_done_t *v);


extern ngx_rtmp_hls_frag_done_pt          ngx_rtmp_hls_frag_done;


extern ngx_module_t                     ngx_rtmp_hls_module;


#endif /* _NGX_RTMP_HLS_H_INCLUDED_ */
