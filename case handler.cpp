#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum case_type {
  NORMAL,
  UPPER,
  LOWER,
  SENTENCE,
};

void handle_case(char *file_name, int case_type);

int main(int argc, char *argv[]) {
 
  if (argc != 3) {
    printf("Usage: %s C:\\Users\\ASUS\\Desktop\\Module 1\\Day 7\\text.txt\n", argv[0]);
    return 1;
  }

  char *option = argv[1];
  if (strcmp(option, "-u") == 0) {
  
    handle_case(argv[2], UPPER);
  } else if (strcmp(option, "-l") == 0) {
    
    handle_case(argv[2], LOWER);
  } else if (strcmp(option, "-s") == 0) {
    
    handle_case(argv[2], SENTENCE);
  } else {
    
    handle_case(argv[2], NORMAL);
  }

  return 0;
}

void handle_case(char *file_name, int case_type) {
  
  FILE *source = fopen(file_name, "r");
  if (source == NULL) {
    printf("Could not open source file: %s\n", file_name);
    return;
  }

  FILE *target = fopen("target.txt", "w");
  if (target == NULL) {
    printf("Could not open target file: target.txt\n");
    return;
  }

  int ch;
  while ((ch = fgetc(source)) != EOF) {
  	
    switch (case_type) {
      case UPPER:
        ch = toupper(ch);
        break;
      case LOWER:
        ch = tolower(ch);
        break;
      case SENTENCE:
        if (ch == ' ' || ch == '\n') {
          ch = toupper(ch);
        }
        break;
      case NORMAL:
        break;
    }

    fputc(ch, target);
  }

  fclose(source);
  fclose(target);
}
