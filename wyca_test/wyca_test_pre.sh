#!/binsh

# Install the prerequisites for the wyca_test

echo "***************************update***************************"

sudo apt-get update
echo "***************************install ros-kinetic-audio-common***************************"

sudo apt-get install ros-kinetic-audio-common 
echo "***************************install libasound2***************************"

sudo apt-get install libasound2
