#include "soundGenerator.h"
using namespace std;

map<string,double> freqMap = {
    {"C2", 65.41},
    {"D2", 73.42},
    {"E2", 82.41},
    {"F2", 87.31},
    {"G2", 98.00},
    {"A2", 110.00},
    {"B2", 123.47},

    {"C#3", 138.59},
    {"F#3", 185.00},
    {"C#4", 277.18},
    {"F#4", 369.99},
    {"G#4", 415.30},
    {"A#4", 466.16},
    {"C#5", 554.37},
    {"F#5", 739.99},
    {"C#2", 69.30},
    {"F#2", 92.50},
    {"C#2", 69.30},
    {"D#2", 77.78},
    {"F#2", 92.50},
    {"G#2", 103.83},
    {"G#3", 207.65},
    {"D#4", 311.13},
    {"G#4", 415.30},
    {"C#4", 277.18},
    {"F#3", 185.00},

    {"C3", 130.81},
    {"D3", 146.83},
    {"E3", 164.81},
    {"F3", 174.61},
    {"G3", 196.00},
    {"A3", 220.00},
    {"B3", 246.94},

    {"C4", 261.63},
    {"D4", 293.66},
    {"E4", 329.63},
    {"F4", 349.23},
    {"G4", 392.00},
    {"A4", 440.00},
    {"B4", 493.88},

    {"C5", 523.25},
    {"D5", 587.33},
    {"E5", 659.25},
    {"F5", 698.46},
    {"G5", 783.99},
    {"A5", 880.00},
    {"B5", 987.77},

    {"KICK", 60.0}
};

//waveForm class
void waveForm::setAmp(double amp){
    amplitude = amp;
}
void waveForm::setFreq(double freq){
    frequency = freq;
}
//sinWave class
double sinWave::sample(double t){
    return sin(2*M_PI*frequency*t)*amplitude;
}
void sinWave::name(){
    cout << "SinWave" << endl;
}
sinWave::sinWave(double amp,double freq){
    setAmp(amp);
    setFreq(freq);
}
//squareWave class
double squareWave::sample(double t){
    if(sin(2*M_PI*frequency*t) >= 0){
        return amplitude;
    }
    else{
        return -amplitude;
    }
}
void squareWave::name(){
    cout << "square Wave" << endl;
}
squareWave::squareWave(double amp,double freq){
    setAmp(amp);
    setFreq(freq);
}
//sawtoothWave class
double sawtoothWave::sample(double t){
    return amplitude * (2.0 * fmod(frequency * t, 1.0) - 1.0);
}
void sawtoothWave::name(){
    cout << "Sawtooth wave" << endl;
}
sawtoothWave::sawtoothWave(double amp,double freq){
    setAmp(amp);
    setFreq(freq);
}

//Note class
double note::noteToFrequency(){
    pitchFreq = freqMap[pitch];
    return pitchFreq;
}
double note::getDur(){
    return dur;
}
double note::getStartTime(){
    return noteTime;
}
//envelope class
double envelope::apply(double t,double duration){
    if(t <= attack){
        //Attack zone
        progress = t/attack;
        return progress;
    }
    else if(t <= attack + decay){
        //decay zone
        progress = (t-attack)/decay;
        return 1 - (progress * (1 - sustain));
    }
    else if(t <= duration - release){
        //sustain zone
        return sustain;
    }
    else{
        //Release zone
        progress = (t-(duration - release))/release;
        return sustain * (1-progress);
    }
}
//Instrument class and the sub classes
instrument::~instrument(){
    delete waveform;
    delete Envelope;
}
//piano class
piano::piano(double amp, double freq,double att,double dec,double sus,double rel){
    waveform = new sinWave(amp,freq);
    Envelope = new envelope(att,dec,sus,rel);
}
vector<double> piano::render(note &n,double sampleRate){
    vector<double> SampleList;
    double t;
    waveform->setFreq(n.noteToFrequency());
    for(int j = 0;j<(n.getDur()) * sampleRate;j++){
        SampleList.push_back(0.0);
    }
    for(int i = 0;i<(n.getDur()) * sampleRate;i++){
        t = i/sampleRate;
        SampleList.at(i) = Envelope->apply(t,n.getDur())*waveform->sample(t);
    }
    return SampleList;
}
//bass class
bass::bass(double amp,double freq,double att,double dec,double sus,double rel){
    waveform = new sinWave(amp,freq);
    Envelope = new envelope(att,dec,sus,rel);

}
vector<double> bass::render(note &n,double sampleRate){
    vector<double> SampleList;
    double t;
    waveform->setFreq(n.noteToFrequency());
    for(int j = 0;j<(n.getDur()) * sampleRate;j++){
        SampleList.push_back(0.0);
    }
    for(int i = 0;i<(n.getDur()) * sampleRate;i++){
        t = i/sampleRate;
        SampleList.at(i) = Envelope->apply(t,n.getDur())*waveform->sample(t);
    }
    return SampleList;
}
//Drum class
drum::drum(double att, double dec, double sus, double rel){
    waveform = nullptr;
    Envelope = new envelope(att,dec,sus,rel);
}
vector<double> drum::render(note &n,double sampleRate){
    vector<double> SampleList;
    double t;
    for(int j = 0;j<(n.getDur()) * sampleRate;j++){
        SampleList.push_back(0.0);
    }
    for(int i = 0;i<(n.getDur()) * sampleRate;i++){
        double noise = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        t = i/sampleRate;
        SampleList.at(i) = Envelope->apply(t,n.getDur())*noise;
    }
    return SampleList;
}



