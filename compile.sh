 #!/usr/bin/bash
cd src
g++ -Wall -std=c++11 -pthread board.cpp core_simulation.cpp mydevices.cpp sketch_ino.cpp -o arduino
