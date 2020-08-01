/* -*- c++ -*- */
/*
 * Copyright 2020 gr-adaptive_resampler author.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_ADAPTIVE_RESAMPLER_ADAPTIVE_RESAMPLER_FF_H
#define INCLUDED_ADAPTIVE_RESAMPLER_ADAPTIVE_RESAMPLER_FF_H

#include <adaptive_resampler/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace adaptive_resampler {

    /*!
     * \brief <+description of block+>
     * \ingroup adaptive_resampler
     *
     */
    class ADAPTIVE_RESAMPLER_API adaptive_resampler_ff : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<adaptive_resampler_ff> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of adaptive_resampler::adaptive_resampler_ff.
       *
       * To avoid accidental use of raw pointers, adaptive_resampler::adaptive_resampler_ff's
       * constructor is in a private implementation
       * class. adaptive_resampler::adaptive_resampler_ff::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace adaptive_resampler
} // namespace gr

#endif /* INCLUDED_ADAPTIVE_RESAMPLER_ADAPTIVE_RESAMPLER_FF_H */

