/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
EqAudioProcessorEditor::EqAudioProcessorEditor (EqAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 400);
    
    lsfFreqSlider.addListener(this);
    lsfFreqSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    lsfFreqSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 30, 20);
    lsfFreqSlider.setTextValueSuffix("Hz");
    lsfFreqSlider.setRange(20,20000);
    addAndMakeVisible(lsfFreqSlider);
    
    lsfQSlider.addListener(this);
    lsfQSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    lsfQSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 30, 20);
    lsfQSlider.setRange(0,1);
    addAndMakeVisible(lsfQSlider);
    
    lsfGainSlider.addListener(this);
    lsfGainSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    lsfGainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 30, 20);
    lsfGainSlider.setRange(0,4);
    addAndMakeVisible(lsfGainSlider);
    
    peakLowFreqSlider.addListener(this);
    peakLowFreqSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    peakLowFreqSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 30, 20);
    peakLowFreqSlider.setTextValueSuffix("Hz");
    peakLowFreqSlider.setRange(20,20000);
    addAndMakeVisible(peakLowFreqSlider);
    
    peakLowQSlider.addListener(this);
    peakLowQSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    peakLowQSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 30, 20);
    peakLowQSlider.setRange(0,1);
    addAndMakeVisible(peakLowQSlider);
    
    peakLowGainSlider.addListener(this);
    peakLowGainSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    peakLowGainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 30, 20);
    peakLowGainSlider.setRange(0,4);
    addAndMakeVisible(peakLowGainSlider);
    
    peakHighFreqSlider.addListener(this);
    peakHighFreqSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    peakHighFreqSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 30, 20);
    peakHighFreqSlider.setTextValueSuffix("Hz");
    peakHighFreqSlider.setRange(20,20000);
    addAndMakeVisible(peakHighFreqSlider);
    
    peakHighQSlider.addListener(this);
    peakHighQSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    peakHighQSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 30, 20);
    peakHighQSlider.setRange(0,1);
    addAndMakeVisible(peakHighQSlider);
    
    peakHighGainSlider.addListener(this);
    peakHighGainSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    peakHighGainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 30, 20);
    peakHighGainSlider.setRange(0,4);
    addAndMakeVisible(peakHighGainSlider);
    
    hsfFreqSlider.addListener(this);
    hsfFreqSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    hsfFreqSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 30, 20);
    hsfFreqSlider.setTextValueSuffix("Hz");
    hsfFreqSlider.setRange(20,20000);
    addAndMakeVisible(hsfFreqSlider);
    
    hsfQSlider.addListener(this);
    hsfQSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    hsfQSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 30, 20);
    hsfQSlider.setRange(0,1);
    addAndMakeVisible(hsfQSlider);
    
    hsfGainSlider.addListener(this);
    hsfGainSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    hsfGainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 30, 20);
    hsfGainSlider.setRange(0,4);
    addAndMakeVisible(hsfGainSlider);
    
    
}

EqAudioProcessorEditor::~EqAudioProcessorEditor()
{
}

//==============================================================================
void EqAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    
}

void EqAudioProcessorEditor::resized()
{
    Rectangle<int> area(getLocalBounds());
    Rectangle<int> dialArea(getWidth()/3, getHeight()/4);
    
    
    
    hsfFreqSlider.setBounds(0, 0, dialArea.getWidth(), dialArea.getHeight());
    hsfQSlider.setBounds(getWidth()/3, 0, dialArea.getWidth(), dialArea.getHeight());
    hsfGainSlider.setBounds(2*(getWidth()/3), 0, getWidth()/3, getHeight()/4);
    
    peakLowFreqSlider.setBounds(0, getHeight()/4, dialArea.getWidth(), dialArea.getHeight());
    peakLowQSlider.setBounds(getWidth()/3, getHeight()/4, dialArea.getWidth(), dialArea.getHeight());
    peakLowGainSlider.setBounds(2*(getWidth()/3), getHeight()/4, dialArea.getWidth(), dialArea.getHeight());
    
    peakHighFreqSlider.setBounds(0, getHeight()/2, dialArea.getWidth(), dialArea.getHeight());
    peakHighQSlider.setBounds(getWidth()/3, getHeight()/2, dialArea.getWidth(), dialArea.getHeight());
    peakHighGainSlider.setBounds(2*(getWidth()/3), getHeight()/2, dialArea.getWidth(), dialArea.getHeight());
    
    lsfFreqSlider.setBounds(0, 3*(getHeight()/4), dialArea.getWidth(), dialArea.getHeight());
    lsfQSlider.setBounds(getWidth()/3, 3*(getHeight()/4), dialArea.getWidth(), dialArea.getHeight());
    lsfGainSlider.setBounds(2*(getWidth()/3), 3*(getHeight()/4), dialArea.getWidth(), dialArea.getHeight());
     
     
    
    
    
}

void EqAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    if (slider == &hsfFreqSlider) {
        processor.highShelfFrequency = hsfFreqSlider.getValue();
        processor.hsfc = IIRCoefficients::makeHighShelf(processor.fs, processor.highShelfFrequency, processor.highShelfQ, processor.highShelfGain);
        processor.highShelfFilterL.setCoefficients(processor.hsfc);
        processor.highShelfFilterR.setCoefficients(processor.hsfc);
    }
    if (slider == &lsfFreqSlider) {
        processor.lowShelfFrequency = lsfFreqSlider.getValue();
        processor.lsfc = IIRCoefficients::makeLowShelf(processor.fs, processor.lowShelfFrequency, processor.lowShelfQ, processor.lowShelfGain);
        processor.lowShelfFilterL.setCoefficients(processor.lsfc);
        processor.lowShelfFilterR.setCoefficients(processor.lsfc);
    }
    if (slider == &peakHighFreqSlider) {
        processor.peakHighFrequency = peakHighFreqSlider.getValue();
        processor.phfc = IIRCoefficients::makePeakFilter(processor.fs, processor.peakHighFrequency, processor.peakHighQ, processor.peakHighGain);
        processor.peakHighFilterL.setCoefficients(processor.phfc);
        processor.peakHighFilterR.setCoefficients(processor.phfc);
    }
    if (slider == &peakLowFreqSlider) {
        processor.peakLowFrequency = peakLowFreqSlider.getValue();
        processor.plfc = IIRCoefficients::makePeakFilter(processor.fs, processor.peakLowFrequency, processor.peakLowQ, processor.peakLowGain);
        processor.peakLowFilterL.setCoefficients(processor.plfc);
        processor.peakLowFilterR.setCoefficients(processor.plfc);
    }
    
    
    
    if (slider == &hsfQSlider) {
        processor.highShelfQ = hsfQSlider.getValue();
        processor.hsfc = IIRCoefficients::makeHighShelf(processor.fs,processor.highShelfFrequency, processor.highShelfQ, processor.highShelfGain);
        processor.highShelfFilterL.setCoefficients(processor.hsfc);
        processor.highShelfFilterR.setCoefficients(processor.hsfc);
    }
    if (slider == &lsfQSlider) {
        processor.lowShelfQ = lsfQSlider.getValue();
        processor.lsfc = IIRCoefficients::makeLowShelf(processor.fs, processor.lowShelfFrequency, processor.lowShelfQ, processor.lowShelfGain);
        processor.lowShelfFilterL.setCoefficients(processor.lsfc);
        processor.lowShelfFilterR.setCoefficients(processor.lsfc);
    }
    if (slider == &peakHighQSlider) {
        processor.peakHighQ = peakHighQSlider.getValue();
        processor.phfc = IIRCoefficients::makePeakFilter(processor.fs, processor.peakHighFrequency, processor.peakHighQ, processor.peakHighGain);
        processor.peakHighFilterL.setCoefficients(processor.phfc);
        processor.peakHighFilterR.setCoefficients(processor.phfc);
    }
    if (slider == &peakLowQSlider) {
        processor.peakLowQ = peakLowQSlider.getValue();
        processor.plfc = IIRCoefficients::makePeakFilter(processor.fs, processor.peakLowFrequency, processor.peakLowQ, processor.peakLowGain);
        processor.peakLowFilterL.setCoefficients(processor.plfc);
        processor.peakLowFilterR.setCoefficients(processor.plfc);
    }
    
    
    if (slider == &hsfGainSlider) {
        processor.highShelfGain = hsfGainSlider.getValue();
        processor.hsfc = IIRCoefficients::makeHighShelf(processor.fs,processor.highShelfFrequency, processor.highShelfQ, processor.highShelfGain);
        processor.highShelfFilterL.setCoefficients(processor.hsfc);
        processor.highShelfFilterR.setCoefficients(processor.hsfc);
    }
    if (slider == &lsfGainSlider) {
        processor.lowShelfGain = lsfGainSlider.getValue();
        processor.lsfc = IIRCoefficients::makeLowShelf(processor.fs, processor.lowShelfFrequency, processor.lowShelfQ, processor.lowShelfGain);
        processor.lowShelfFilterL.setCoefficients(processor.lsfc);
        processor.lowShelfFilterR.setCoefficients(processor.lsfc);
    }
    if (slider == &peakHighGainSlider) {
        processor.peakHighGain = peakHighGainSlider.getValue();
        processor.phfc = IIRCoefficients::makePeakFilter(processor.fs, processor.peakHighFrequency, processor.peakHighQ, processor.peakHighGain);
        processor.peakHighFilterL.setCoefficients(processor.phfc);
        processor.peakHighFilterR.setCoefficients(processor.phfc);
    }
    if (slider == &peakLowGainSlider) {
        processor.peakLowGain = peakLowGainSlider.getValue();
        processor.plfc = IIRCoefficients::makePeakFilter(processor.fs, processor.peakLowFrequency, processor.peakLowQ, processor.peakLowGain);
        processor.peakLowFilterL.setCoefficients(processor.plfc);
        processor.peakLowFilterR.setCoefficients(processor.plfc);
    }

}

