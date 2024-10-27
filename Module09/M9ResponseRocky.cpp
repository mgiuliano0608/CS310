#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Computer {
    private:
        string cpuName;
        string gpuName;
        int ram;

    public:
        // set methods
        void setCpuName(string cpuName) {
            this->cpuName = cpuName;
        }
        void setGpuName(string gpuName) {
            this->gpuName = gpuName;
        }
        void setRam(int ram) {
            this->ram = ram;
        }

        // get methods
        string getCpuName() {
            return this->cpuName;
        }
        string getGpuName() {
            return this->gpuName;
        }
        int getRam() {
            return this->ram;
        }

    // Constructors
    Computer() {}
    Computer(string cpuName, string gpuName, int ram) {
        this->cpuName = cpuName;
        this->gpuName = gpuName;
        this->ram = ram;
    }

};

class Desktop : public Computer {
    private:
        int psuWattage;

    public:
        // set method
        void setPsuWattage(int psuWattage) {
            this->psuWattage = psuWattage;
        }

        // get method
        int getPsuWattage() {
            return this->psuWattage;
        }

    // Constructors
    using Computer::Computer;
    Desktop(string cpuName, string gpuName, int ram, int psuWattage) {
        setCpuName(cpuName);
        setGpuName(gpuName);
        setRam(ram);
        this->psuWattage = psuWattage;
    }

};

class Laptop : public Computer {
    private:
        int batteryLife;

    public:
        // set method
        void setBatteryLife(int batteryLife) {
            this->batteryLife = batteryLife;
        }

        // get method
        int getBatteryLife() {
            return this->batteryLife;
        }
    
    // Constructors
    using Computer::Computer;
    Laptop(string cpuName, string gpuName, int ram, int batteryLife) {
        setCpuName(cpuName);
        setGpuName(gpuName);
        setRam(ram);
        this->batteryLife = batteryLife;
    }

};


int main() {

    Desktop Threadripper("7960X", "RTX 4090", 128, 1000);
    Laptop Titan("14900HX", "RTX 4090", 128, 7);

    string desktopCPU = Threadripper.getCpuName();
    string laptopCPU = Titan.getCpuName();
    string desktopGPU = Threadripper.getGpuName();
    string laptopGPU = Titan.getGpuName();

    // Comparing CPUs
    if (desktopCPU == laptopCPU) 
        cout << "The Desktop and Laptop have the same CPU." << endl;
    else 
        cout << "The Desktop and Laptop have different CPUs." << endl;
    
    // Comparing GPUs
    if (desktopGPU == laptopGPU) 
        cout << "The Desktop and Laptop have the same GPU." << endl;
    else 
        cout << "The Desktop and Laptop have different GPUs." << endl;
    

    return 0;

}