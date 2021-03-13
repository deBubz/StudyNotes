#include "RIMS.h"

/* 
    c code simulating SM
    refere to latch.png

    notice how all the variables are globally declared
*/

// SM states enum
enum LA_states
{
    LA_start,
    LA_s0 LA_s1
} LA_State;

void latch_tick();

void main()
{
    // good practice to init output
    B = 0x00;
    LA_State = LA_start;

    while (1)
    {
        latch_tick();
    }
}

void latch_tick()
{
    switch (LA_state) // transitions statements
    {
    case LA_start: // initial state
        LA_state = LA_s0;
        break;
    case LA_s0:
        if (A0)
            LA_State = LA_s1;
        else
            LA_State = LA_s0;
        break;
    case LA_s1:
        if (!A0)
            LA_State = LA_s0;
        else
            LA_State = LA_s1;
        break;
    default:
        LA_state = LA_start;
        break;
    }

    switch (LA_state) // state actions
    {
    case LA_s0:
        break;
    case LA_s1:
        B0 = A1;
        break;
    default:
        break;
    }
}