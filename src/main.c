#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ALPHABET_SIZE 26

const char* FREQ_BASE = "etaoinshrdlcumwfgypbvkjxqz";

//int comp(const void *x_void, const void *y_void){
//
//  int x = *(int *)x_void;
//  int y = *(int *)y_void;
//  return y-x; 
//
//}

void two_array_sort(double *d_arr, char *c_arr, int n) { for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (d_arr[j] < d_arr[j + 1]) {
                // Swap in double arr
                double temp_double = d_arr[j];
                d_arr[j] = d_arr[j + 1];
                d_arr[j + 1] = temp_double;

                // Swap in char arr
                char temp_char = c_arr[j];
                c_arr[j] = c_arr[j + 1];
                c_arr[j + 1] = temp_char;
            }
        }
    }
}


void analisis(const char* input){

  int len = strlen(input);
  char result[len];
  double freq_message[ALPHABET_SIZE] = {0};
  char freq_alphabet[ALPHABET_SIZE]="abcdefghijklmnopqrstuvwxyz";

  int total_letters = 0;

  for (const char *ptr = input; *ptr != '\0'; ++ptr){

        if (isalpha(*ptr)) {
            char lowercase_char = tolower(*ptr);
            freq_message[lowercase_char - 'a'] += 1;
            total_letters++;
        }
  }

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        freq_message[i] = (freq_message[i] / total_letters) * 100;
    }
  

    two_array_sort(freq_message, freq_alphabet, (int)ALPHABET_SIZE);

     printf("Letter Frequencies:\n");
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        printf("%c: %.2f%%\n", freq_alphabet[i], freq_message[i]);
    }


      strcpy(result, input);

      for(int j = 0;j<len; j++) {
        
        if(isalpha(result[j])){

          for(int c = 0; c < ALPHABET_SIZE; c++)
            if(freq_alphabet[c] == tolower(result[j])) {
              result[j] = FREQ_BASE[c];
              break;
            }

        }

      }



  printf("Possible plaintext found:\n %s\n",result);

}



int main(int argc, char *argv[]) {
    const char* s = argv[1];
 
   analisis(s);
 
    return 0;
}
