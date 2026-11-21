#ifndef SYNTH_H
#define SYNTH_H

#include <stdint.h>

typedef enum {
    WAVE_SINE,     // Чистый синус
    WAVE_SQUARE,   // Меандр/квадрат
    WAVE_SAW       // Пила
} WaveType;

void generate_wave(int16_t *buffer, int num_samples, double frequency, WaveType type, float volume);

#endif