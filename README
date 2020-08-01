## gr-adaptive_resampler

A gnuradio module trying to act as a bridge in a flowgraph operating with two externally clocked modules, e.g. an audio source and a SDR sink (or vice-versa).

### Challenge
When a flowgraph contains an audio source, the samples come into the flowgraph at a sample rate approximately the one you set (e.g. 48 kHz) but that timing is defined externally (by your soundcard, maybe resampled by your audio server, but not synchronized to your flowgraph). Now imagine your flowgraph containing some blocks for processing until finally the samples reach a SDR sink.

This SDR sink also operates by a clock that matches approximately the sample rate you set (e.g. 2 MHz), but this is now defined by the rate the SDR itself takes samples out of its buffer (defined by the clock generator on your SDR).

Although both sample rates are approximately in sync (with a factor that you defined in your flowgraph, e.g. \* 2 MHz / 48 kHz), they are actually not.
Additionally, both sample rates may have a small drift mainly induced by temperature changes in the two devices involved.

Either, the soundcard clock is a bit faster than the SDR clock: Then, you will have sound samples filling up your buffers in all the different flow graph blocks. Eventually, all buffers are full and some samples are dropped (Buffer overflow). Additionally, you will operate at the upper limit of possible latency given the configured buffer sizes.

Or, the SDR clock is a bit faster than the soundcard clock: Initially, gnuradio will fill the buffers about to half of their size before the first packet actally reaches your SDR. From that moment on, all buffers will be continually drained a bit more until there is no more data to be transmitted: the SDR will transmit zero samples (or repeats the last buffer block? I don't know) instead. Anyway, your transmitted signal will be far from what you want it to be in that moment.

This block needs to find a measurement to compare the clocks against each other and resample the signal in a way to have the sample rates match up perfectly.

### Further references
Most ideas here were influenced by this paper from Fons Adriaensen: https://kokkinizita.linuxaudio.org/papers/adapt-resamp.pdf

### Implementation ideas
In gnuradio, a flowgraph has its inputs and outputs and additionally gets information on how many input samples are available and how many output samples it should produce.
The input buffer is exactly the output buffer of the previous stage.
Although not stated, we can use `noutput_items` as a measurement of the available output buffer space (The first call of our method will give us an indicator of the output buffer size; following calls should at some point have lower numbers here).
As said before, the number of available input samples is directly given as a parameter to the `work` method.

Thinking about how an audio source actually works is that the source block will get chunks of audio data (chunk size is normally called `period` here and is in the range of 5..100 ms corresponding to 200..4800 samples per period at 48 kHz). Looking at the input buffer at discrete intervals (e.g. when our block is called), it will have grown by a factor depending on the period size and the number of periods happened since the last call.

On the output side, this is similar: Considering all blocks following the adaptive resampler will just do some signal processing without (or little) requirements on chunk sizes, the output buffer of this resampling block should reflect what's going on in the input buffer of the SDR (e.g. the block "blocking" transmission) - if it's mostly empty, there should be no data queuing up in the last output buffer. if it's filling up, that's also the case later in the flowgraph.

Now the adaptive resampler needs to fine tune its resampling rate trying to keep the input buffer quite empty (to keep latency down and not cause buffer overflows) while making sure, the output buffer always has some data in it (to not cause buffer underflows). 

So that's theory so far from reading gnuradio documentation and trying to make sense of it. Next step, what this repo should do, is implementing and trying out.
