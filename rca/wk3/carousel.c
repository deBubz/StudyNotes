#include "RIMS.h"

enum STATES { Start, Init, WaitRise, Increment, WaitFall } State;

void tick() {
    switch (State)
    {   // state management
    case Start: State = Init; break;
    case Init: State = WaitRise; break;
    case WaitRise: 
        if (!A1 && A0)
            State = Increment;
        else if (!A1 && !A0)
            State = WaitRise;
        else if (A1) State = Init;
        break;
    case Increment:
        State = WaitFall;
        break;
    case WaitFall: 
        if(A0) State = WaitFall;
        else if(!A0) State = WaitRise;
        break;
    default:
        break;
    }

    switch (State)
    {   // state actions
    case Init: B = 0; break;
    case WaitRise: break;
    case Increment: B = B + 1; break;
    case WaitFall: break;
    
    default:
        State = Init;
        break;
    }

}

int main()
{
    // initial output
    State = Start;
    B = 0x00;


    while(1)
    {
        tick();
    }
}

