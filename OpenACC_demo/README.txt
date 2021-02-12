First, SSH into the SCC

Get into queue and reserve a GPU in an interactive session
qrsh -l h_rt=01:45:00 -pe omp 1 -P paralg -l gpus=1.0 -l gpu_c=6.0

Change directory to get to demo code (This is where I put it)
cd /projectnb/paralg/brower/OpenACC_demo/OpenACCIntro


Load in PGI Compiler & gcc
module load pgi/19.4
module load gcc

Compile PGI code integrate.cpp
pgc++ -std=c++11 -Minfo=accel -acc -ta=tesla integrate.cpp -o integrate 

Run
./integrate

Compare with Serial

Compile
g++ -O2 serial_integrate.cpp -o serial

Run
./serial


Now we can go on to more NVIDIA demos at (where ever you put it)

cd /projectnb/paralg/brower/OpenACC_demo/Poisson2D

with details describe in the manual 

openACC_References/OpenACC_Programming_Guide_0.pdf

