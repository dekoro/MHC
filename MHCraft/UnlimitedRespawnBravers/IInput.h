#ifndef _DEVICE_INPUT_IINPUT_H_
#define _DEVICE_INPUT_IINPUT_H_

class IInput
{
public:
	IInput(){}
	~IInput(){}
	virtual void CheckInputStateRaw() = 0;

	unsigned int GetInputStateRaw(){ return inputStateRaw; }

protected:
	unsigned int inputStateRaw;

private:

};


#endif


