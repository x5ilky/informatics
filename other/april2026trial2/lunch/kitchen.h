// Provided functions:

// Sends a bit, either 0 or 1. Do not call more than 500000 times
void sendNextBit(int bit);

// Returns the next bit. Do not call more times than sendNextBit was called.
int getNextBit();

// returns next event as integer '1' = dish value 1, '2' = dish value 2,
// '0' = Jabba consumes a dish.
int nextEvent();

// accept the dish if the current event is a dish
void acceptDish();
// reject the dish if the current event is a dish
void discardDish();



// You must implement "void createAdvice(int N, int B)" which should call 'nextEvent()' N
// times, and 'sendNextBit(int bit)' some number of times to send bits of advice.
void createAdvice(int N, int B);

// You must implement "void receiveAdvice(int N, int B, int L)" which should call
// 'nextEvent()' N times and 'acceptDish' or 'discardDish' for each dish.
// It should also call 'getNextBit()' to get advice.
void receiveAdvice(int N, int B, int L);


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define _PAC_MAX_N 500500
#define _PAC_MAX_L 500500
#define _PAC_MAX_ALLOWED_BITS 500000

static int _pac_N, _pac_B;
static int _pac_dishValues[_PAC_MAX_N];
static int _pac_advice[_PAC_MAX_L];
static int _pac_adviceSize = 0, _pac_adviceCurrent = 0;
static int _pac_current = 0, _pac_total = 0;
static int _pac_part = 0;
static int _pac_queueSize = 0;

static int _pac_lastDishProcessed = 1;
int nextEvent(void) {
    if (_pac_current >= _pac_N) {
        fprintf(stderr, "Error:  Requested more events than there exist.\n");
        exit(0);
    }
    if(!_pac_lastDishProcessed) {
        fprintf(stderr, "Error:  Previous dish was not rejected or accepted.\n");
        exit(0);
    }
    if (_pac_current > 0 && _pac_dishValues[_pac_current-1] == 0) {
        if(_pac_queueSize > 0) {
            _pac_queueSize--;
        }
    }
    if(_pac_dishValues[_pac_current] != 0 && _pac_part == 1) {
        _pac_lastDishProcessed = 0;
    }
    return _pac_dishValues[_pac_current++];
}

void sendNextBit(int bit) {
    if (_pac_part == 1) {
        fprintf(stderr, "Error:  Tried to send a bit from 'receiveAdvice'.\n");
        exit(0);
    }
    if (bit != 0 && bit != 1) {
        fprintf(stderr, "Error:  Tried to send a bit with value '%d', which is not '0' or '1'.\n", bit);
        exit(0);
    }
    if (_pac_adviceSize == _PAC_MAX_ALLOWED_BITS) {
        fprintf(stderr, "Error:  Tried to send more than %d bits, which is the maximum allowed.\n", _PAC_MAX_ALLOWED_BITS);
        exit(0);
    }
    _pac_advice[_pac_adviceSize++] = bit;
}

int getNextBit(void) {
    if (_pac_part == 0) {
        fprintf(stderr, "Error:  Tried to receive a bit from 'createAdvice'.\n");
        exit(0);
    }
    if (_pac_adviceCurrent == _pac_adviceSize) {
        fprintf(stderr, "Error:  Tried to receive more bits than were sent.\n");
        exit(0);
    }
    return _pac_advice[_pac_adviceCurrent++];
}

//-----------------------

void acceptDish(void) {
    if (_pac_part == 0) {
        fprintf(stderr, "Error:  'acceptDish' called by 'createAdvice'.\n");
        exit(0);
    }
    if (_pac_current > _pac_N) {
        fprintf(stderr, "Error:  Tried to accept a dish after the last dish.\n");
        exit(0);
    }
    if (_pac_queueSize == _pac_B) {
        fprintf(stderr, "Error:  Tried to accept a dish, but the queue is full.\n");
        exit(0);
    }
    _pac_queueSize++;
    // Current is indexed one ahead of the dish under question
    
    _pac_lastDishProcessed = 1;
    _pac_total += _pac_dishValues[_pac_current-1];
}

void discardDish() {
    if (_pac_part == 0) {
        fprintf(stderr, "Error: 'rejectDish' called by 'receiveAdvice'.\n");
        exit(0);
    }
    if (_pac_current > _pac_N) {
        fprintf(stderr, "Tried to reject a dish after the last dish.\n");
        exit(0);
    }
    _pac_lastDishProcessed = 1;
}

int main() {
    
    int i;
    // Read from test data
    scanf("%d %d", &_pac_N, &_pac_B);
    for (i = 0; i < _pac_N; i++) {
        scanf("%d", _pac_dishValues+i);
    }
    createAdvice(_pac_N, _pac_B);

    // Reset dish index and queue size for partB
    _pac_current = 0;
    _pac_queueSize = 0;
    
    _pac_part = 1;

    receiveAdvice(_pac_N, _pac_B, _pac_adviceSize);

    fprintf(stderr, "You acheived a total score of:   %d\nThe number of bits you used was: %d\n", _pac_total, _pac_adviceSize);    

    // Hack for judging:
    printf("%d\n", _pac_total);

    return 0;
}
