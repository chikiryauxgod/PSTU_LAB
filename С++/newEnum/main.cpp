#include <iostream>
using namespace std;


class PC 
{
public: 

	enum PCState
	{
		OFF,
		ON,
		SLEEP
	};


	PCState GetState()
	{
		return State;
	}
	
	void SetState(PCState State)
	{
		this->State = State;
	}

private:
	PCState State;

};



int main()
{	
	PC pc;

	pc.SetState(PC::PCState::OFF);
	
	switch (pc.GetState())
	{
	case PC::PCState::OFF:
		{
		cout << "The PC is not running." << endl;
		break;
		}
	case PC::PCState::ON:
		{
		cout << "The PC is running." << endl;
		break;
		}
		
	case PCState::SLEEP:
	{
		cout << "THe PC is sleeping." << endl;
		break;
	}
	default:
		break;
	}

	return 0;
}