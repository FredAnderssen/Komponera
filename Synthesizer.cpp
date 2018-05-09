#include "Synthesizer.h"
#include <cstdlib>
#include "RtMidi.h"
#ifndef __WINDOWS_MM__
#include <unistd.h>
#endif

Synthesizer::Synthesizer(int instrument):message(3)
{
     midiout = new RtMidiOut();

     // Check available ports.
     unsigned int nPorts = midiout->getPortCount();

     // Open last available port.
     midiout->openPort( nPorts-1 );

     // Set instrument
     message[0] = 192;
     message[1] = instrument;
     message[2] = 0;
     midiout->sendMessage( &message );


}

void Synthesizer::spela(int hoejd, int laengd, int volym)
{

    message[0] = 144;
    message[1] = hoejdtomidi(hoejd);
    message[2] = 90;
    midiout->sendMessage( &message );

#ifdef __WINDOWS_MM__
    std::chrono::milliseconds dur(laengd);
	std::this_thread::sleep_for(dur);
#endif
#ifndef __WINDOWS_MM__
    usleep(laengd*1000);
#endif

    message[0] = 128;
    message[1] = hoejdtomidi(hoejd);
    message[2] = 40;
    midiout->sendMessage( &message );
}
int Synthesizer::hoejdtomidi(int hoejd)
{
	int midinr = 60;
    switch (hoejd)
	{
	case 0: midinr = 60; break;
	case 1: midinr = 62; break;
	case 2: midinr = 64; break;
	case 3: midinr = 65; break;
	case 4: midinr = 67; break;
	case 5: midinr = 69; break;
	case 6: midinr = 71; break;
	case 7: midinr = 72; break;
	case 8: midinr = 74; break;
	case 9: midinr = 76; break;
	case 10: midinr = 77; break;
	case 11: midinr = 79; break;
	case 12: midinr = 81; break;
	};
	return midinr;
}

