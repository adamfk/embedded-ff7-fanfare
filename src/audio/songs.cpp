#include "songs.hpp"
#include <stddef.h>

#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

// These frequencies will need to be scaled up to be audible with a piezo speaker,
// but we are simulating on a PC and I find the lower frequencies less irritating :)
// Tones: https://github.com/bhagman/Tone
#define Ab1 52
#define Bb1 58
#define C_2 65

// minimum duration for a note to be audible with wokwi
#define MINIMUM_DURATION_MS 50

// quarter note duration
#define WHOLE    520
#define HALF     (WHOLE / 2)
#define QUARTER  (HALF / 2)
#define EIGHTH   (QUARTER / 2)

// https://www.hooktheory.com/theorytab/view/nobuo-uematsu/final-fantasy-vii---victory-fanfare
// RAM: AVR based boards should consider storing in PROGMEM to save RAM
const Note Ff7FanFare::notes[] = {
    { .tone_hz = C_2, .duration_ms = QUARTER },
    { .tone_hz = C_2, .duration_ms = QUARTER },
    { .tone_hz = C_2, .duration_ms = QUARTER },
    { .tone_hz = C_2, .duration_ms = QUARTER * 3 },
    { .tone_hz = Ab1, .duration_ms = QUARTER * 3 },
    { .tone_hz = Bb1, .duration_ms = QUARTER * 3 },
    { .tone_hz = C_2, .duration_ms = HALF },
    { .tone_hz = Bb1, .duration_ms = QUARTER },
    { .tone_hz = C_2, .duration_ms = WHOLE * 2 }
};

// RAM: AVR based boards should consider storing in PROGMEM to save RAM
const Song Ff7FanFare::song
{
    .notes = &notes[0],
    .notes_length = COUNT_OF(notes),
    .note_interior_end_gap_ms = MINIMUM_DURATION_MS // so we can hear the end of each note
};
