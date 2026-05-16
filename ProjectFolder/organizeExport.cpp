#include "organizeExport.h"
using namespace std;

#pragma pack(1)
struct WAVHeader {
    char riff[4] = {'R','I','F','F'};
    uint32_t fileSize;
    char wave[4] = {'W','A','V','E'};
    char fmt[4]  = {'f','m','t',' '};
    uint32_t fmtSize      = 16;
    uint16_t audioFormat  = 1;
    uint16_t numChannels  = 1;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign   = 2;
    uint16_t bitsPerSample = 16;
    char data[4] = {'d','a','t','a'};
    uint32_t dataSize;
};

//track class
track::track(instrument* in,double vol){
    volume = vol;
    inst = in;
}
track::~track(){
    delete inst;
}
void track::addNote(string name,double duration,double sTime){
    notes.push_back(note(name,duration,sTime));
}
vector<double> track::render(double sampleRate,double tDuration){
    vector<double> track;
    vector<double> samples;
    int index = 0;
    for(int i = 0;i<(sampleRate * tDuration);i++){
        track.push_back(0.0);
    }
    for(int j = 0;j<notes.size();j++){
        samples = inst->render(notes.at(j),sampleRate);
        int startIndex = notes.at(j).getStartTime() * sampleRate;
        for(int k = 0; k < samples.size(); k++){
            track.at(startIndex + k) += samples.at(k) * volume;
        }
    }
    return track;
}
double track::getTotalDuration(){
    double maxDur;
    double endTime = 0.0;
    for(int i = 0;i<notes.size();i++){
        maxDur = notes.at(i).getDur() + notes.at(i).getStartTime();
        if(maxDur > endTime){
            endTime = maxDur;
        }
    }
    return endTime;
}
//mixer class
vector<double> mixer::mix(vector<vector<double>> mixTracks){
    int len = mixTracks.at(0).size();
    vector<double> outPutArr(len,0.0);
    for(int i = 0;i < mixTracks.size();i++){
        for(int j = 0; j < len;j++){
            outPutArr[j] += mixTracks.at(i).at(j);
        }
    }
    normalize(outPutArr);
    return outPutArr;
}
void mixer::normalize(vector<double>& samples){
    double peak = 0.0;
    for(int i = 0;i < samples.size();i++){
        if(abs(samples.at(i)) > peak){
            peak = abs(samples.at(i));
        }
    }
    if(peak == 0){
        return;
    }
    for(int j = 0;j < samples.size();j++){
        samples.at(j) /= peak;
    }

}
//Sequencer class
sequencer::sequencer(double bpm, double sRate){
    Bpm = bpm;
    SampleRate = sRate;
}
double sequencer::bpmConversion(double beats){
    return beats*(60/Bpm);
}
void sequencer::addTrack(track* tr){
    tracks.push_back(tr);
}
vector<double> sequencer::mixDown(){
    vector <vector<double>> arrayMix;
    double totalDur = 0;
    for (int i = 0; i < tracks.size(); i++) {
        double d = tracks.at(i)->getTotalDuration();
        if (d > totalDur)
            totalDur = d;
    }
    for (int i =0;i<tracks.size();i++){
        arrayMix.push_back(tracks.at(i)->render(SampleRate,totalDur));
    }
    return Mixer.mix(arrayMix);
}
void sequencer::exportWav(string fileName){
    vector<double> mixArr = mixDown();
    wavExporter exporter;
    exporter.exportToFile(mixArr,fileName,SampleRate);
}
//wavExporter
void wavExporter::exportToFile(const vector<double>& samples,string fileName, double sampleRate){
    ofstream file(fileName,ios::binary);

    WAVHeader header;
    header.dataSize = samples.size() * 2;
    header.fileSize = header.dataSize + 36;
    header.sampleRate = sampleRate;
    header.byteRate = sampleRate * 2;

    file.write((char*)&header,sizeof(header));

    for(int i = 0; i < samples.size(); i++){
        int16_t pcm = samples.at(i) * 32767;
        file.write((char*)&pcm, sizeof(pcm));
    }
    file.close();
}
