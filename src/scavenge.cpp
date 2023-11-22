#include <Arduino.h>
// For each character in alphabet, figure out the corresponding _ _ _ + _ _ _ _ _  number
//  : ___ on my titties
//  : assume as fact
// Shift that by my age
// Divide character position number by the value
// Multiply value by 10
// Truncate value to one decimal
// Optional:  that you did it correctly

int age = 9;
int cumposit[26] = { 4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,26,27,28,30,32,33,34,35,36,38,39 };
String alpha[26];
int shifted[26];
float divd[26];
float mult[26];
float truncd[26];

void setup() {
    Serial.begin(115200);
    delay(1000);
    for (int i=0; i<26; i++) alpha[i] = String((char)('A' + i));
}
void loop() {
    printf("\n\nPsn Lt Cmp Shf  Div     Mult   Trunc Lt\n");
    for (int i=0; i<26; i++) {        
        shifted[i] = cumposit[(i + age) % 26];
        divd[i] = (float)(i + 1) / (float)shifted[i];
        mult[i] = 10.0 * divd[i];
        truncd[i] = (float)((int)(10.0 * (mult[i] + 0.001)) / 10.0);
        printf("%2d  %s  %2d  %2d  %6.4f  %6.3f  %4.1f  %s\n", i+1, alpha[i],
            cumposit[i], shifted[i], divd[i], mult[i], truncd[i], alpha[i]); 
    }
    while(true);
}