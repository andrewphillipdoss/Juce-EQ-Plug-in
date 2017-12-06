/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "FilterGraph.h"


//==============================================================================
/**
*/
class EqAudioProcessorEditor  : public AudioProcessorEditor,
                                public Slider::Listener
{
public:
    EqAudioProcessorEditor (EqAudioProcessor&);
    ~EqAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged(Slider *slider) override;

    
private:
    
    Slider lsfFreqSlider;
    Slider lsfQSlider;
    Slider lsfGainSlider;
    
    Slider hsfFreqSlider;
    Slider hsfQSlider;
    Slider hsfGainSlider;
    
    Slider peakLowFreqSlider;
    Slider peakLowQSlider;
    Slider peakLowGainSlider;
    
    Slider peakHighFreqSlider;
    Slider peakHighQSlider;
    Slider peakHighGainSlider;
    
    FilterGraph filterGraph;
    

    EqAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EqAudioProcessorEditor)
};
