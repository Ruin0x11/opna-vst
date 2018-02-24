/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
OpnaAudioProcessorEditor::OpnaAudioProcessorEditor (OpnaAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 600);

	// these define the parameters of our slider object
	midiVolume.setSliderStyle(Slider::LinearBarVertical);
	midiVolume.setRange(0.0, 127.0, 1.0);
	midiVolume.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
	midiVolume.setPopupDisplayEnabled(true, false, this);
	midiVolume.setTextValueSuffix(" Volume");
	midiVolume.setValue(1.0);

	// this function adds the slider to the editor
	addAndMakeVisible(&midiVolume);
	
	midiVolume.addListener(this);
}

OpnaAudioProcessorEditor::~OpnaAudioProcessorEditor()
{
}

//==============================================================================
void OpnaAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
	g.drawFittedText("Midi Volume", 0, 0, getWidth(), 30, Justification::centred, 1);
}

void OpnaAudioProcessorEditor::resized()
{
	// sets the position and size of the slider with arguments (x, y, width, height)
	midiVolume.setBounds(40, 30, 20, getHeight() - 60);
}

void OpnaAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
	processor.noteOnVel = midiVolume.getValue();
}