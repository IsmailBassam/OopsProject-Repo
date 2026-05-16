#include "organizeExport.h"
using namespace std;

int main(){
    srand(time(0));
    int choice = 1;
    double pFreq,pAmp,pAtt,pDec,pSus,pRel;
    double bFreq,bAmp,bAtt,bDec,bSus,bRel;
    double dAtt,dDec,dSus,dRel;
    string notes;
    char userC = 'y';
    double duration,time;

    sequencer seq(143,44100);
    cout << "User which of presets would you like: " << endl;
    cout << "1.Custom presets" << endl;
    cout << "2.User defined presets" << endl;
    cout << "Input the choice either 1 or 2" << endl;
    cin >> choice;

    switch(choice){
        case 1:
            pFreq = 293.66;
            pAmp = 0.6;
            pAtt = 0.02;
            pDec = 0.15;
            pSus = 0.6;
            pRel = 0.4;

            bFreq = 73.42;
            bAmp = 0.7;
            bAtt = 0.04;
            bDec = 0.2;
            bSus = 0.75;
            bRel = 0.5;

            dAtt = 0.002;
            dDec = 0.08;
            dSus = 0.0;
            dRel = 0.08;

            break;
        case 2:
            cout << "Enter the piano freq: ";
            cin >> pFreq;
            cout << "Enter the piano amp: ";
            cin >> pAmp;
            cout << "Enter the attack: ";
            cin >> pAtt;
            cout << "Enter the decay: ";
            cin >> pDec;
            cout << "Enter the sustain: ";
            cin >> pSus;
            cout << "Enter the release: ";
            cin >> pRel;

            cout << "Enter the bass freq: ";
            cin >> bFreq;
            cout << "Enter the bass amp: ";
            cin >> bAmp;
            cout << "Enter the attack: ";
            cin >> bAtt;
            cout << "Enter the decay: ";
            cin >> bDec;
            cout << "Enter the sustain: ";
            cin >> bSus;
            cout << "Enter the release: ";
            cin >> bRel;

            cout << "Enter the attack: ";
            cin >> dAtt;
            cout << "Enter the decay: ";
            cin >> dDec;
            cout << "Enter the sustain: ";
            cin >> dSus;
            cout << "Enter the release: ";
            cin >> dRel;

            break;
        }

    track pi(new piano(pAmp,pFreq,pAtt,pDec,pSus,pRel));
    track bassline(new bass(bAmp,bFreq,bAtt,bDec,bSus,bRel));
    track Drums(new drum(dAtt,dDec,dSus,dRel));

    if(choice == 1){
        pi.addNote("E4",  0.419, 0.000);
        pi.addNote("G#4", 0.419, 0.419);
        pi.addNote("B4",  0.419, 0.839);
        pi.addNote("E4",  0.419, 1.258);
        pi.addNote("G#4", 0.419, 1.678);
        pi.addNote("B4",  0.419, 2.097);
        pi.addNote("E4",  0.419, 2.516);
        pi.addNote("G#4", 0.419, 2.936);
        pi.addNote("B4",  0.419, 3.355);
        pi.addNote("E4",  0.419, 3.774);
        pi.addNote("G#4", 0.419, 4.194);
        pi.addNote("B4",  0.419, 4.613);

        pi.addNote("D#4", 0.419, 5.032);
        pi.addNote("G#4", 0.419, 5.452);
        pi.addNote("B4",  0.419, 5.871);
        pi.addNote("D#4", 0.419, 6.290);
        pi.addNote("G#4", 0.419, 6.710);
        pi.addNote("B4",  0.419, 7.129);
        pi.addNote("D#4", 0.419, 7.548);
        pi.addNote("G#4", 0.419, 7.968);
        pi.addNote("B4",  0.419, 8.387);
        pi.addNote("D#4", 0.419, 8.806);
        pi.addNote("G#4", 0.419, 9.226);
        pi.addNote("B4",  0.419, 9.645);

        pi.addNote("C#4", 0.419, 10.064);
        pi.addNote("G#4", 0.419, 10.484);
        pi.addNote("B4",  0.419, 10.903);
        pi.addNote("C#4", 0.419, 11.322);
        pi.addNote("G#4", 0.419, 11.742);
        pi.addNote("B4",  0.419, 12.161);
        pi.addNote("C#4", 0.419, 12.580);
        pi.addNote("G#4", 0.419, 13.000);
        pi.addNote("B4",  0.419, 13.419);
        pi.addNote("C#4", 0.419, 13.839);
        pi.addNote("G#4", 0.419, 14.258);
        pi.addNote("B4",  0.419, 14.677);

        pi.addNote("A3",  0.419, 15.097);
        pi.addNote("E4",  0.419, 15.516);
        pi.addNote("A4",  0.419, 15.935);
        pi.addNote("A3",  0.419, 16.355);
        pi.addNote("E4",  0.419, 16.774);
        pi.addNote("A4",  0.419, 17.194);
        pi.addNote("A3",  0.419, 17.613);
        pi.addNote("E4",  0.419, 18.032);
        pi.addNote("A4",  0.419, 18.452);
        pi.addNote("A3",  0.419, 18.871);
        pi.addNote("E4",  0.419, 19.290);
        pi.addNote("A4",  0.419, 19.710);

        pi.addNote("G#3", 0.419, 20.129);
        pi.addNote("E4",  0.419, 20.548);
        pi.addNote("B4",  0.419, 20.968);
        pi.addNote("G#3", 0.419, 21.387);
        pi.addNote("E4",  0.419, 21.806);
        pi.addNote("B4",  0.419, 22.226);
        pi.addNote("G#3", 0.419, 22.645);
        pi.addNote("E4",  0.419, 23.064);
        pi.addNote("B4",  0.419, 23.484);
        pi.addNote("G#3", 0.419, 23.903);
        pi.addNote("E4",  0.419, 24.322);
        pi.addNote("B4",  0.419, 24.742);

        pi.addNote("F#3", 0.419, 25.161);
        pi.addNote("D#4", 0.419, 25.580);
        pi.addNote("A4",  0.419, 26.000);
        pi.addNote("F#3", 0.419, 26.419);
        pi.addNote("D#4", 0.419, 26.839);
        pi.addNote("A4",  0.419, 27.258);
        pi.addNote("F#3", 0.419, 27.677);
        pi.addNote("D#4", 0.419, 28.097);
        pi.addNote("A4",  0.419, 28.516);
        pi.addNote("F#3", 0.419, 28.935);
        pi.addNote("D#4", 0.419, 29.355);
        pi.addNote("A4",  0.419, 29.774);

        pi.addNote("G#3", 0.419, 30.194);
        pi.addNote("D#4", 0.419, 30.613);
        pi.addNote("G#4", 0.419, 31.032);
        pi.addNote("G#3", 0.419, 31.452);
        pi.addNote("D#4", 0.419, 31.871);
        pi.addNote("G#4", 0.419, 32.290);
        pi.addNote("G#3", 0.419, 32.710);
        pi.addNote("D#4", 0.419, 33.129);
        pi.addNote("G#4", 0.419, 33.548);
        pi.addNote("G#3", 0.419, 33.968);
        pi.addNote("D#4", 0.419, 34.387);
        pi.addNote("G#4", 0.419, 34.806);

        // Bass line
        bassline.addNote("C#2", 1.258, 0.000);
        bassline.addNote("E2",  1.258, 1.258);
        bassline.addNote("G#2", 1.258, 2.516);
        bassline.addNote("B2",  1.258, 3.774);

        bassline.addNote("B2",  1.258, 5.032);
        bassline.addNote("D#2", 1.258, 6.290);
        bassline.addNote("G#2", 1.258, 7.548);
        bassline.addNote("B2",  1.258, 8.806);

        bassline.addNote("A2",  1.258, 10.064);
        bassline.addNote("C#2", 1.258, 11.322);
        bassline.addNote("E2",  1.258, 12.580);
        bassline.addNote("G#2", 1.258, 13.839);

        bassline.addNote("A2",  1.258, 15.097);
        bassline.addNote("C#2", 1.258, 16.355);
        bassline.addNote("E2",  1.258, 17.613);
        bassline.addNote("A2",  1.258, 18.871);

        bassline.addNote("E2",  1.258, 20.129);
        bassline.addNote("G#2", 1.258, 21.387);
        bassline.addNote("B2",  1.258, 22.645);
        bassline.addNote("E2",  1.258, 23.903);

        bassline.addNote("F#2", 1.258, 25.161);
        bassline.addNote("A2",  1.258, 26.419);
        bassline.addNote("D#2", 1.258, 27.677);
        bassline.addNote("F#2", 1.258, 28.935);

        bassline.addNote("E2",  1.258, 30.194);
        bassline.addNote("G#2", 1.258, 31.452);
        bassline.addNote("B2",  1.258, 32.710);
        bassline.addNote("E2",  1.258, 33.968);
    }
    else{
        cout << "Do you wish to add the piano(y or n): ";
        cin >> userC;
        while(userC == 'y' || userC == 'Y'){
            cout << "Give the note start time and its duration for piano track";
            cin >> notes;
            cin >> duration;
            cin >> time;
            pi.addNote(notes,duration,time);

            cout << "Do you wish to add more notes(y or n): ";
            cin >> userC;
        }
        cout << "Do you wish to add bass(y or n): ";
        cin >> userC;
        while(userC == 'y' || userC == 'Y'){
            cout << "Give the note start time and its duration for bass track";
            cin >> notes;
            cin >> duration;
            cin >> time;
            bassline.addNote(notes,duration,time);

            cout << "Do you wish to add more notes(y or n): ";
            cin >> userC;
        }
        cout << "Do you wish to add drums(y or n): ";
        cin >> userC;
        while(userC == 'y' || userC == 'Y'){
            cout << "Give the start time and its duration for drum track";
            cin >> duration;
            cin >> time;
            Drums.addNote("KICK",duration,time);

            cout << "Do you wish to add more notes(y or n): ";
            cin >> userC;
        }

    }
    seq.addTrack(&pi);
    seq.addTrack(&bassline);
    seq.addTrack(&Drums);

    seq.exportWav("Song.wav");
    cout << "song.wav exported successfully" << endl;

}