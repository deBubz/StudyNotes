#include "RIMS.h"

enum light_states { st_start, st_unlit, st_lit } light_state;

void light_tick();

void main()
{
    B = 0x00;
    light_state = st_start;

    while(1) light_tick();
}

void light_tick()
{
    switch (light_state)
    {
    case st_start: st_state = st_unlit; break;
    case st_unlit: 
        if(!A0) st_state = st_unlit;
        else if(A0) st_state = st_lit;
        break;
    case st_lit: 
        if(!A1) light_state = st_lit;
        else if(A1) light_state = st_unlit;
        break;
    default: st_state = st_start; break;
    }

    switch (light_state)
        {
        case st_start: B = 0x00; break;
        case st_unlit: B0 = 1; break;
        case st_lit: B0 = 1; break;
        
        default:break;
    }
}