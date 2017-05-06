#ifndef OVEN_H_
#define OVEN_H_

class Oven {
public:
	Oven();
	bool start();
	bool stop();

	float getTemp();                    //
	void setTemp(int temp);             //
	bool isGrill();                     //
	void setGrill(bool grill);
	bool isMicrowave();                 //
	void setMicrowave(bool microwave);
	bool isOn();                        //
	bool isDoorOpen();                  //
	void setDoorOpen(bool doorOpen);    //
    void setOn(bool On);

private:
	int temp;
	bool on;
	bool grill;
	bool microwave;
	bool doorOpen;
};

#endif /* OVEN_H_ */
