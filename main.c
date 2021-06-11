#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable : 4996) // Отключает ошибку 4996


struct Wavheader { // имя структуры - Wavheader
    char                chunkId[4];                 // Информация о формате файла (RIFF), Содержит символы “RIFF” в ASCII кодировке;
    unsigned long       ChunkSize;                  // Размер без  chunkId[4];
    char                format[4];                  // Формат потоковых данных (WAVE);
    char                subchunk1Id[4];             // Описание параметров WAV-файла (fmt-chunk);
    unsigned long       subchunk1Size;              // Размер подструктуры  subchunk1  (16 байт);
    unsigned short      wFomatTag;                  // Аудио формат (PCM = 1);
    unsigned short      nChannels;                  // Количество каналов (Моно = 1, Стерео = 2);
    unsigned long       SamplesPerSec;              // Частота дискретизации в Гц;
    unsigned long       ByteRate;                   // Кол-во передаваемых байт в секунду воспроизведения;
    unsigned short      blockAlign;                 // Размер сэмпла в байтах 16 бит = 2 байта моно, 32 бита = 4 байта стерео (включая все каналы);
    unsigned short      BitsPerSample;              // Количество бит в сэмпле. Так называемая “глубина” или точность звучания. 8 бит, 16 бит и т.д. /// битов на отсчет
    char                Subchunk2ID[4];             // Символы "Data", начало чанка данных;
    unsigned long       Subchunk2Size;              // Размер области данных в байтах;
} Wavheader;


long double main() {
    FILE* file;
    char array[1000000];


    //Открытие и проверка открытия файла
    printf("Open the file: ");
    file = fopen("C:/Users/123/Downloads/infa.wav", "rb");  
    if (file == NULL) printf("False\n");
    else printf("Tru\n");

    // считываем данные
    int i;
    for (i = 0; i < 285724; i++) { // размер считываемых данных (в байтах) для данного аудиофайла
        fscanf(file, "%c", &array[i]);
        printf("%c", array[i]);
        printf("\n");
    } 

    // создаем файл со звуком (при обычной громкости)
    FILE* fp;
    if ((fp = fopen("test.wav", "wb")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    fwrite(array, sizeof(float), 71431, fp); // размер всего файла  285724 байт (71431*4)
    int l;
    char x;
    for (l = 256; l < 285724; l++) {
        x = array[226];
    }
    x = array[226];
    printf("%c", x);

    // создаем файл со звуком (при повышенной в 2 раза громкости)
    FILE* fp;
    if ((fp = fopen("test1.wav", "wb")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    fwrite(array1, sizeof(float), 71431, fp); // размер всего файла  285724 байт (71431*4)

    return 0;
}
