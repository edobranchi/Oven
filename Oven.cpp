#include "Oven.h"

Oven::Oven() {
	temp=0;
    on= false;
    grill= false;
    microwave= true;
    doorOpen= false;
}

void Oven::setDoorOpen(bool closeOpen){
if (closeOpen){
    doorOpen=true;
    on=false;
    grill=false;
    stop();
}else
    doorOpen= false;
    start();
}

bool Oven::isGrill(){
    return grill;
}

bool Oven::isMicrowave(){
    return microwave;
}

float Oven::getTemp(){
    return temp;
}

void Oven::setTemp(int temperature){
   if (temperature>0 && temperature<800){
       temp=temperature;
    }
    if (temperature<0){
        temp=0;
    }
    if (temperature>800){
        temp=800;
    }
}

bool Oven::isOn(){
    return on;
}

bool Oven::isDoorOpen(){
    return doorOpen;
}

void Oven::setGrill(bool changeGrill){
    grill=changeGrill;
}

void Oven::setMicrowave(bool changeMicro){
    microwave=changeMicro;
}

void Oven::setOn(bool OnOff) {
    on=OnOff;
}

bool Oven::start() {
    if ((isGrill() || isMicrowave())&& !isDoorOpen() && getTemp() > 0) {
            setOn(true);
            return true;
    } else return false;
}

bool Oven::stop() {
    if (isOn() == true) {
        setOn(false);
        return true;
    }
    return false;
}
