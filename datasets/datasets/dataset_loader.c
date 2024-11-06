#include <stdio.h>
#include <stdlib.h>

int* load_dataset(const char* filename, int* size) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return NULL;
    }

    int* data = NULL;
    int number, count = 0;
    while (fscanf(file, "%d", &number) != EOF) {
        data = realloc(data, (count + 1) * sizeof(int));
        data[count++] = number;
    }

    fclose(file);
    *size = count;
    return data;
}
