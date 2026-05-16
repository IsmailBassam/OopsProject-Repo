#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <thread>
using namespace std;



class waveForm{
    protected:
        double amplitude;
        double frequency;
    public:
        void setAmp(double amp);
        void setFreq(double freq);
        virtual double sample(double t) = 0;
        virtual void name() = 0;

};

class sinWave:public waveForm{
    public:
        double sample(double t) override;
        void name() override;
        sinWave(double amp,double freq);

};
class squareWave:public waveForm{
    public:
        double sample(double t) override;
        void name() override;
        squareWave(double amp,double freq);
};
class sawtoothWave:public waveForm{
    public:
        double sample(double t) override;
        void name() override;
        sawtoothWave(double amp,double freq);
};

class note{
    private:
        string pitch;
        double noteTime;
        double dur;
        double pitchFreq;

    public:
        note(string p,double d,double start):pitch(p),noteTime(start),dur(d){}
        double noteToFrequency();
        double getDur(); 
        double getStartTime();  
};

class envelope{
    private:
        double attack;
        double decay;
        double sustain;
        double release;
        double progress;
    public:
        envelope(double a,double d,double s,double r):attack(a),decay(d),sustain(s),release(r){}
        double apply(double t,double duration);

};
class instrument{
    protected:
        waveForm* waveform;
        envelope* Envelope;
    public:
        virtual vector<double> render(note &Note,double sampleRate) = 0;
        virtual ~instrument();
};
class piano:public instrument{
    public:
        piano(double amp, double freq,double att,double dec,double sus,double rel);
        vector<double> render(note &Note,double saampleRate) override;
};
class bass:public instrument{
    public:
        bass(double amp,double freq, double att, double dec, double sus,double rel);
        vector<double> render(note &Note, double sampleRate) override;
};
class drum:public instrument{
    public:
        drum(double att, double dec, double sus, double rel);
        vector<double> render(note &Note,double sampleRate) override;
};
