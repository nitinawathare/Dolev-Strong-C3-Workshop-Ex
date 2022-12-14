

sudo apt-get update

sudo apt-get install build-essential clang lld gdb bison flex perl python3 python3-pip qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
sudo apt-get install libqt5opengl5-dev libxml2-dev zlib1g-dev doxygen graphviz libwebkit2gtk-4.0-37

python3 -m pip install --user --upgrade numpy pandas matplotlib scipy seaborn posix_ipc

sudo apt-get install openscenegraph-plugin-osgearth libosgearth-dev

#This is optional package to leverage the parallel simulation support
sudo apt-get install mpi-default-dev


tar xvfz omnetpp-5.7-linux-x86_64.tgz

cd omnetpp-5.7
source setenv


./configure
make