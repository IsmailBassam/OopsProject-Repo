#include "soundGenerator.h"
using namespace std;

class track{
    protected:
        instrument* inst;
        vector<note> notes;
        double volume;
    public:
        track(instrument* in,double vol = 1.0);
        ~track();
        void addNote(string name,double duration,double sTime);
        vector<double> render(double sampleRate,double tDuration);
        double getTotalDuration();
};
class mixer{
    public:
        vector<double> mix(vector<vector<double>> mixTracks);
        void normalize(vector<double>& samples);
};
class sequencer{
    protected:
        vector<track*> tracks;
        double Bpm;
        double SampleRate;
        mixer Mixer;
    public:
        sequencer(double bpm,double sRate);
        double bpmConversion(double beats);
        void addTrack(track* tr);
        vector<double> mixDown();
        void exportWav(string fileName);
};
class wavExporter{
    public:
        void exportToFile(const vector<double>& samples, string filename, double sampleRate);
};