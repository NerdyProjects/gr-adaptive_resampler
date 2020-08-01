/* -*- c++ -*- */

#define ADAPTIVE_RESAMPLER_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "adaptive_resampler_swig_doc.i"

%{
#include "adaptive_resampler/adaptive_resampler_ff.h"
%}

%include "adaptive_resampler/adaptive_resampler_ff.h"
GR_SWIG_BLOCK_MAGIC2(adaptive_resampler, adaptive_resampler_ff);
