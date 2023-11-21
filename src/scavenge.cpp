#include <Arduino.h>
// For each character in alphabet, figure out the corresponding _ _ _ + _ _ _ _ _  number
//  : ___ on my titties
//  : assume as fact
// Shift that by my age
// Divide character position number by the value
// Multiply value by 10
// Truncate value to one decimal
// Optional:  that you did it correctly

static const int composites[26] = { 4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,26,27,28,30,32,33,34,35,36,38,39 };
char alphabet[26];

int shifted[26];
float divided[26];
float multiplied[26];
float truncated[26];
char letter[26];
int age = 9;

void setup() {
    Serial.begin(115200);
    delay(1000);
    for (int i=0; i<26; i++) alphabet[i] = (char)(0x41 + i);
}
void loop() {
    printf("\n\nPsn Lt Cmp Shf  Div     Mult   Trunc Lt\n");
    for (int i=0; i<26; i++) {        
        shifted[i] = composites[(i + age) % 26];
        divided[i] = (float)(i + 1) / (float)shifted[i];
        multiplied[i] = 10.0 * divided[i];
        truncated[i] = (float)((int)(10.0 * (multiplied[i] + 0.001)) / 10.0);
        printf("%2d  %s  %2d  %2d  %6.4f  %6.3f  %4.1f  %s\n", i+1, String(alphabet[i]), composites[i], shifted[i], divided[i], multiplied[i], truncated[i], String(alphabet[i])); 
    }
    while(true);
}