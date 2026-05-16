# WaveForge — C++ Music Synthesizer

> Generating real audio from pure mathematics. No libraries. No shortcuts. Just C++.

[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)]()
[![Standard](https://img.shields.io/badge/Standard-C%2B%2B11-blue)]()
[![Output](https://img.shields.io/badge/Output-.wav%20Audio-green)]()
[![Libraries](https://img.shields.io/badge/Libraries-None-red)]()

---

## What It Does

WaveForge is a software synthesizer that generates `.wav` audio files entirely from scratch using mathematical wave functions. You give it notes, it gives you music.

No external audio libraries used. Every sample is computed manually, every WAV header byte is written by hand. Pure C++ from silence to sound.

---

## Demo

Preset mode generates a synthesized rendition of **Beethoven's Moonlight Sonata** (Op. 27 No. 2, First Movement) with three simultaneous tracks — piano melody, bass line, and drums — all exported to a single `Song.wav` file.

---

## How It Works

```
Math formula → Raw samples → ADSR envelope → Track timeline → Mixer → WAV file
```

1. Each instrument renders notes sample by sample at **44,100 samples/second**
2. **Waveform** generates the shape — sine, square, or sawtooth formula
3. **Envelope** shapes the volume over the note's lifetime — attack, decay, sustain, release
4. **Track** places each rendered note at the correct position on the song timeline
5. **Mixer** sums all tracks together and normalizes to prevent clipping
6. **WAVExporter** writes the 44-byte binary header and raw PCM data to disk

---

## Features

- Three waveform types — **Sine**, **Square**, **Sawtooth**
- Full **ADSR envelope** control per instrument
- Three instrument types — **Piano**, **Bass**, **Drum**
- Multi-track mixing with automatic **normalization**
- Binary **WAV file export** — 44.1kHz, 16-bit PCM, mono
- **Preset mode** — Moonlight Sonata ready to play
- **Custom mode** — define your own ADSR values and compose your own notes interactively

---

## Project Structure

```
WaveForge/
├── soundGenerator.h       — Waveforms, Note, Envelope, Instrument declarations
├── soundGenerator.cpp     — All sound generation implementations
├── organizeExport.h       — Track, Mixer, Sequencer, WAVExporter declarations
├── organizeExport.cpp     — All organization and export implementations
├── main.cpp               — Song composition and program entry point
└── Song.wav               — Generated audio output
```

---

## OOP Concepts Implemented

| Concept | Where It Appears |
|---|---|
| **Abstraction** | `waveForm` and `instrument` abstract base classes with pure virtual functions |
| **Inheritance** | `sinWave`, `squareWave`, `sawtoothWave` inherit from `waveForm` — `piano`, `bass`, `drum` inherit from `instrument` |
| **Polymorphism** | `instrument->render()` called on base pointer — behaves differently per subclass at runtime |
| **Encapsulation** | Private data in `note` and `envelope` — accessed only through public getters |
| **Composition** | `instrument` HAS-A `waveForm*` and HAS-A `envelope*` |
| **Operator Overloading** | `operator<` in `note` for sorting notes by start time |
| **File I/O** | Manual binary WAV writing in `wavExporter` — 44-byte header + raw PCM samples |

---

## How To Compile & Run

### Requirements
- Any C++ compiler supporting C++11 or later
- `g++` recommended

### Compile
```bash
g++ main.cpp organizeExport.cpp soundGenerator.cpp -o synth
```

### Run
```bash
./synth
```

### Choose a mode
```
User which of presets would you like:
1. Custom presets
2. User defined presets
Input the choice either 1 or 2:
```

- **Option 1** — Loads Moonlight Sonata preset with tuned ADSR values. Exports immediately.
- **Option 2** — You define ADSR values for piano, bass, and drum. Then add your own notes interactively.

Output file `Song.wav` appears in the same directory. Open it in any media player — VLC, Windows Media Player, QuickTime, Audacity.

---

## Technical Details

### WAV File Format
The exporter manually writes a **44-byte RIFF header** followed by raw 16-bit PCM audio data:

```
RIFF header    — 4 bytes
File size      — 4 bytes
WAVE marker    — 4 bytes
fmt chunk      — 4 bytes
Format data    — 16 bytes
data marker    — 4 bytes
Data size      — 4 bytes
─────────────────────────
Total          — 44 bytes
```

Each audio sample is converted from `double [-1.0, 1.0]` to `int16_t [-32768, 32767]` before writing.

### Sample Rate
44,100 Hz — CD quality. Based on the Nyquist theorem which requires sampling at least twice the highest human-audible frequency (20,000 Hz).

### Waveform Formulas

| Waveform | Formula |
|---|---|
| Sine | `amplitude × sin(2π × freq × t)` |
| Square | `amplitude × sign(sin(2π × freq × t))` |
| Sawtooth | `amplitude × (2 × fmod(freq × t, 1.0) - 1.0)` |

### ADSR Envelope
```
Attack  — volume climbs from 0.0 to 1.0 over attackTime seconds
Decay   — volume falls from 1.0 to sustainLevel over decayTime seconds  
Sustain — volume holds at sustainLevel until release begins
Release — volume falls from sustainLevel to 0.0 over releaseTime seconds
```

---

## Built With

| Tool | Purpose |
|---|---|
| `<cmath>` | `sin()`, `fmod()`, `M_PI` for waveform mathematics |
| `<fstream>` | Binary WAV file writing |
| `<vector>` | Audio sample buffers |
| `<map>` | Note name to frequency lookup table |
| `<cstdlib>` | `rand()` for drum noise generation |
| `<ctime>` | `srand(time(0))` for random seed |

**No external audio libraries. Standard library only.**

---

## Author

**Ismail Bassam Chaudhry**  
Registration No. 2025320 — Section H, FSCE

---

## Course Information

**Course** — CS112 Object Oriented Programming  
**University** — Ghulam Ishaq Khan Institute of Engineering Sciences and Technology (GIKI)  
**Year** — 2026

---


