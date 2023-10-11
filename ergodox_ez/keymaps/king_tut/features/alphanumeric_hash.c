#include "alphanumeric_hash.h"

#ifndef ALPHANUMERIC_HASHING_TIMEOUT
#    define ALPHANUMERIC_HASHING_TIMEOUT 500
#endif

#define NUM_ALPHANUMERIC_CHARS 41
const char mapping[] = "E@GR$90!1#UL7PBVC5^MFZHYTS368DNKIQ4XOWAJ2";

#define ALPHANUMERIC_OUTPUT_LEN 16

// Flags and variables for alphanumeric hash generation
bool alphanumeric_hashing = false;
uint16_t alphanumeric_hashing_time = 0;
uint8_t alphanumeric_hash_index = 0;
uint32_t alphanumeric_hash_digits = 0;

// Function to map a digit to a character based on the mapping array
char map_digit_to_char(int digit) {
    char character;

    if (digit >= 0 && digit < NUM_ALPHANUMERIC_CHARS) {
        character = mapping[digit];
    } else {
        // Handle out of range digits
        character = '?'; // You can choose any character for out of range digits
    }

    uprintf("Mapped digit %d to character: %c\n", digit, character);

    return character;
}

// Function to convert a number to a sequence of alphanumeric characters
void number_to_sequence(int number, char *sequence, int sequenceLength) {
    int numDigits = 1;  // Initialize the number of digits
    int temp = NUM_ALPHANUMERIC_CHARS;

    // Calculate the number of digits required for the base
    while (temp > 0) {
        temp /= 10;
        numDigits++;
    }

    for (int i = sequenceLength - 2; i >= 0; i--) {
        // Extract a segment of 'numDigits' digits from the number
        int segment = number % (int)pow(NUM_ALPHANUMERIC_CHARS, numDigits);

        // Take modulo against NUM_ALPHANUMERIC_CHARS to determine the character
        int digit = segment % NUM_ALPHANUMERIC_CHARS;
        
        sequence[i] = map_digit_to_char(digit);
        number /= (int)pow(NUM_ALPHANUMERIC_CHARS, numDigits);
    }
}

// Function to start the alphanumeric hash generation process
void alphanumeric_hash_start(void) {
    if (alphanumeric_hashing) {
        return;
    }
    alphanumeric_hashing = true;
    alphanumeric_hashing_time = timer_read();
    alphanumeric_hash_index = 0;
    alphanumeric_hash_digits = 0;
}

// Function to finish the alphanumeric hash generation and send the result as keycodes
void alphanumeric_hash_end(void) {
    alphanumeric_hashing = false;
    char alphanumeric[ALPHANUMERIC_OUTPUT_LEN + 1];

    number_to_sequence(alphanumeric_hash_digits, alphanumeric, ALPHANUMERIC_OUTPUT_LEN + 1);

    // Use the keymap_ascii library to send the alphanumeric string as keycodes
    send_string_as_keycodes(alphanumeric);
}

// Function to check if alphanumeric hash generation is active
bool alphanumeric_hash_active(void) {
    return alphanumeric_hashing;
}

// Function to check if alphanumeric hash generation has timed out
bool alphanumeric_hash_timed_out(void) {
#if defined(ALPHANUMERIC_HASH_NO_TIMEOUT)
    return alphanumeric_hash_index > 0 && timer_elapsed(alphanumeric_hashing_time) > ALPHANUMERIC_HASHING_TIMEOUT;
#else
    return timer_elapsed(alphanumeric_hashing_time) > ALPHANUMERIC_HASHING_TIMEOUT;
#endif
}

// Function to handle the alphanumeric hash generation process
void alphanumeric_hash_task(void) {
    if (alphanumeric_hash_active() && alphanumeric_hash_timed_out()) {
        alphanumeric_hash_end();
    }
}

// Function to reset the timer for alphanumeric hash generation
void alphanumeric_hash_reset_timer(void) {
    alphanumeric_hashing_time = timer_read();
}

// Function to perform alphanumeric hash generation
uint32_t alphanumeric_hashing_function(uint16_t keycode, uint8_t hash_index, uint32_t hash) {
    // Modify the hash function to include a different prime number
    keycode = keycode * 5;
    hash ^= ((keycode << 5) | (keycode >> 13)) ^ (hash_index + 1);  // Adjust the prime number and hash index
    hash *= 2654435761U;  // You can experiment with different prime numbers
    uprintf("hash: %u\n", hash);
    return hash;
}

// Function to add a keycode to the alphanumeric hash
bool alphanumeric_hash_add(uint16_t keycode) {
#if defined(ALPHANUMERIC_HASH_NO_TIMEOUT)
    if (alphanumeric_hash_index == 0) {
        alphanumeric_hash_reset_timer();
    }
#endif

    // Add the keycode and index to the hash
    alphanumeric_hash_digits = alphanumeric_hashing_function(keycode, alphanumeric_hash_index, alphanumeric_hash_digits);
    alphanumeric_hash_index++;

    return true;
}
