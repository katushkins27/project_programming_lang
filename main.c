#include <stdio.h>
#include <stdlib.h>
#include "wav.h"
#include "synth.h"

int main() {
    int duration_sec = 2;
    int total_samples = SAMPLE_RATE * duration_sec;

    int16_t *buffer = (int16_t *)malloc(total_samples * sizeof(int16_t));
    if (!buffer) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    printf("Генерируем ноту (Квадратная волна, 440 Гц)...\n");
    generate_wave(buffer, total_samples, 440.0, WAVE_SQUARE, 0.5f);

    save_wav("retro_game.wav", buffer, total_samples);

    free(buffer);

    printf("Готово! Файл 'retro_game.wav' сохранен.\n");
    return 0;
}