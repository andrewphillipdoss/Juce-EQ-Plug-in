/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
*/
class EqAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    EqAudioProcessor();
    ~EqAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect () const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    IIRFilter lowShelfFilterL;
    IIRFilter lowShelfFilterR;
    IIRFilter highShelfFilterL;
    IIRFilter highShelfFilterR;
    IIRFilter peakLowFilterL;
    IIRFilter peakLowFilterR;
    IIRFilter peakHighFilterL;
    IIRFilter peakHighFilterR;
    
    IIRCoefficients lsfc;
    IIRCoefficients hsfc;
    IIRCoefficients phfc;
    IIRCoefficients plfc;
    
    float lowShelfFrequency;
    float lowShelfQ;
    float lowShelfGain;
    
    float peakLowFrequency;
    float peakLowQ;
    float peakLowGain;
    
    float peakHighFrequency;
    float peakHighQ;
    float peakHighGain;
    
    float highShelfFrequency;
    float highShelfQ;
    float highShelfGain;
    
    float fs;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EqAudioProcessor)
};
