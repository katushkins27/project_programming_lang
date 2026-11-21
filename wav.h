#ifndef WAV_H
#define WAV_H

#include <stdint.h>
#include <stdio.h>

#define SAMPLE_RATE 44100

typedef struct {
    char riff[4];
    uint32_t fileSize;
    char wave[4];
    char fmt[4];
    uint32_t fmtSize;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char data[4];
    uint32_t dataSize;
} WAVHeader;

// Функция для сохранения массива семплов в WAV-файл
void save_wav(const char *filename, int16_t *samples, int total_samples);

#endif