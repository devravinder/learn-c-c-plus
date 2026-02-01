#include <stdio.h>
#include <stdlib.h>

/* ============================================
   WRITE TO FILE (text)
   ============================================ */

void writeFile() {

    FILE *fp = fopen("data.txt", "w");   // write mode

    if(fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    fprintf(fp, "Name: Ravinder\n");
    fprintf(fp, "Age: 12\n");
    fprintf(fp, "GPA: 4.9\n");

    fclose(fp);

    printf("File written successfully!\n");
}

/* ============================================
   READ FROM FILE (text)
   ============================================ */

void readFile() {

    FILE *fp = fopen("data.txt", "r");

    if(fp == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    char ch;

    printf("\nReading file:\n");

    while((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
}

/* ============================================
   APPEND TO FILE
   ============================================ */

void appendFile() {

    FILE *fp = fopen("data.txt", "a");

    if(fp == NULL) {
        printf("Error opening file for appending!\n");
        return;
    }

    fprintf(fp, "Section: A\n");

    fclose(fp);

    printf("\nData appended successfully!\n");
}

/* ============================================
   READ LINR BY LINE
   ============================================ */

void readLineByLine() {

    FILE *fp = fopen("data.txt", "r");

    if(fp == NULL) {
        printf("File open failed!\n");
        return;
    }

    char buffer[100];   // holds one line at a time

    printf("\n\nReading file line by line:\n\n");

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);   // already contains newline
    }

    fclose(fp);
}

/* ============================================
   WRITE BINARY FILE
   ============================================ */

void writeBinary() {

    FILE *fp = fopen("numbers.bin", "wb");

    if(fp == NULL) {
        printf("Error opening binary file!\n");
        return;
    }

    int nums[] = {10, 20, 30, 40};

    fwrite(nums, sizeof(int), 4, fp); // data, per element size, no of elements, file writer

    fclose(fp);

    printf("\nBinary file written!\n");
}

/* ============================================
   READ BINARY FILE
   ============================================ */

void readBinary() {

    FILE *fp = fopen("numbers.bin", "rb");

    if(fp == NULL) {
        printf("Error opening binary file!\n");
        return;
    }

    int nums[4];

    fread(nums, sizeof(int), 4, fp);// data to hold, per element size, no of elements, file reader

    fclose(fp);

    printf("\nReading binary file:\n");

    for(int i = 0; i < 4; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");
}




/* ============================================
   MAIN
   ============================================ */

int main() {

    writeFile();      // create & write
    readFile();       // read text
    appendFile();     // append more data
    readFile();       // read again
    readLineByLine(); // read line by line

    writeBinary();    // binary write
    readBinary();     // binary read

    return 0;
}
