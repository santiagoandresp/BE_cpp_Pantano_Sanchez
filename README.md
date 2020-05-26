# F1 vehicule tracking

This is a simulation of tracking on a Formula One vehicule. Doing a &bash compile.sh will compile the program in Linux. It must be created the equivalent command file to compile it in Windows or MacOS. Similarly, to run, just execute $bash run.sh.

The program reads one two simulation files, in order to test every instance made, Overheat.txt or Puncture.txt. In the function readSim() in sketch_ino.cpp, the file read can be changed by rewriting the object as:

If we want to simulate a overheat in the engine we use
ifstream readFile("Sim/Overheat.txt");

Whereas if we want to simulate a puncture we use
ifstream readFile("Sim/Puncture.txt");

In the simulation we have three i2c connections that will be showed in the terminal:

1. LCDPits:

Writes in terminal "---Pits: [variable] [value]". It sends important information to the boxes.

2. LCDPilot:

Writes in terminal "---Pilot: [warning] [value]". It sends every warning to the pilot steering wheel screen.

3. CamTransmission:

writes in terminal "---TV Transmision: Onboard camera [R] [G] [B]". It sends a random color in RGB format, as there is no camera to get information.

There are also two indicator LEDs, an engine temperature LED and a fuel LED. They turn on if the corresponding variables are out of secure range in order to advise the pilot.

Finally, simulation finishes when the txt simulation file has no more values to read.
