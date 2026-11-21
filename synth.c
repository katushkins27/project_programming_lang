#include "synth.h"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void generate_wave(int16_t *buffer, int num_samples, double frequency, WaveType type, float volume) {
    for (int i = 0; i < num_samples; i++) {
        double t = (double)i / 44100.0;
        double value = 0.0;

        switch (type) {
            case WAVE_SINE:
                value = sin(2.0 * M_PI * frequency * t);
                break;
                
            case WAVE_SQUARE:
                // Квадратная волна
                // если синус > 0, то 1, иначе -1
                value = sin(2.0 * M_PI * frequency * t) >= 0 ? 1.0 : -1.0;
                break;
                
            case WAVE_SAW: {
                // Пилообразная волна
                double period = 1.0 / frequency;
                double t_mod = fmod(t, period);
                value = 2.0 * (t_mod / period) - 1.0;
                break;
            }
        }

        buffer[i] = (int16_t)(value * volume * 10000.0);
    }
}