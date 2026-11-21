#include "wav.h"
#include <stdlib.h>

void save_wav(const char *filename, int16_t *samples, int total_samples) {
    int data_size = total_samples * sizeof(int16_t);
    
    WAVHeader header = {
        .riff = {'R', 'I', 'F', 'F'},
        .fileSize = 36 + data_size,
        .wave = {'W', 'A', 'V', 'E'},
        .fmt = {'f', 'm', 't', ' '},
        .fmtSize = 16,
        .audioFormat = 1,
        .numChannels = 1,
        .sampleRate = SAMPLE_RATE,
        .bitsPerSample = 16,
        .byteRate = SAMPLE_RATE * 1 * (16 / 8),
        .blockAlign = 1 * (16 / 8),
        .data = {'d', 'a', 't', 'а'},
    };
    header.data[0] = 'd'; header.data[1] = 'a'; header.data[2] = 't'; header.data[3] = 'a';
    header.dataSize = data_size;

    FILE *f = fopen(filename, "wb");
    if (!f) {
        printf("Ошибка: не удалось создать файл %s\n", filename);
        return;
    }

    fwrite(&header, sizeof(WAVHeader), 1, f);
    fwrite(samples, sizeof(int16_t), total_samples, f);
    fclose(f);
}