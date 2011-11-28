// Singleton Pattern //
#include <iostream>
#include <time.h>
using namespace std;

class Singleton
{
private:
	// A Pointer To The Singleton Class //
	static Singleton* m_Single;

	// A Flag That We Can Check If The Class Has Been Instantiated Previously //
	// This Is Optional, As The Class Can Be Checked To Be Equal To NULL	  //
	static bool m_InstanceFlag;

	// A RandomNumber That Will Be Displayed To Prove This Class Has Become A Singleton //
	int m_RandomNumber;

	// A Private Constructor //
	// This Should Make One Wonder "How Do We Make This Class?" //
	// Since A Private Constructor Means Only A Member Of This  //
	// Class Can Instantiate This Class!						//
	Singleton()
	{
		// Set The Random Number To 0 //
		m_RandomNumber = 0;
		// We Initialize The Static Variables Differently From Normal Variables //
	}

public:
	// A Public Function That Will Create The Class Once, Then Always //
	// Return A Pointer Instead Of Creating The Object Again		  //
	// "static" Means This Method Is Unique To This Class And Must Be Called Using //
	// This Class's Name, Not An Instance Name. Example: Singleton.getInstance()   //
	// Would Not Work. This Must Be Called Using Singleton::getInstance()		   //
	static Singleton* getInstance();

	// A Prototype Of A Function To Call To Set The RandomNumber //
	void setRandomNumber(int Number);

	// A Prototype Of A Function To Return The Random Number //
	int getRandomNumber(void);

	// A Destructor //
	~Singleton()
	{
		// Set The Flag To False As Now This Object Has Been Destructed //
		m_InstanceFlag = false;
	}
};

//---Initialize The Static Variables---//
// Set The m_InstanceFlag To False //
// We Have To Put The Data Type Here (Like We're Declaring The Variable Again) //
// Because This Variable Exists At The Compiler's Level Or Something Like That //
bool Singleton::m_InstanceFlag = false;
// Set The m_Sinlge To NULL //
Singleton* Singleton::m_Single = NULL;
//-------------------------------------//

// Definition Of The getInstance Function In The Singleton Class //
Singleton* Singleton::getInstance()
{
	// Check If The Class Has Been Instantiated //
	// It Is Possible To Check Here If m_Single == NULL Instead Of Using A Flag //
	if(m_InstanceFlag == false)
	{
		//If Not, Set The Singleton Pointer To A New Instantiation Of The Class //
		m_Single = new Singleton();
		// Set The Instance Flag To True //
		m_InstanceFlag = true;
		// Return The Pointer //
		return m_Single;
	}
	else
	{
		// If InstanceFlag Has Been Set To True, Then We Simply Return The Pointer //
		// Because It Has Already Been Created									   //
		return m_Single;
	}
}

// Definition Of The setRandomNumber Function In The Singleton Class //
void Singleton::setRandomNumber(int Number)
{
	// Set The Passed In Number To The RandomNumber Variable In The Singleton Class //
	m_RandomNumber = Number;
}

// Definition Of The getRandomNumber Function In The Singleton Class //
int Singleton::getRandomNumber(void)
{
	// Return The RandomNumber From The Singleton Class //
	return m_RandomNumber;
}

int main()
{
	// Seed The Random Number Generator //
	srand(unsigned(time(NULL)));
	// Create A Pointer That Will Point To The Singleton Class //
	Singleton* ObjectPointer;
	// Set The ObjectPointer To The Same Location As The Internal Pointer //
	// Of The Singleton Class By Using The Class Name To Call getInstance //
	ObjectPointer = Singleton::getInstance();
	// The Singleton Is Now Complete! //
	// There Will Never Be Another Instantiation of The Singleton Class //

	// Now Time To Prove It Is A Singleton //

	//Set The RandomNumber In The Singleton //
	ObjectPointer->setRandomNumber(::rand());

	// Create Another ObjectPointer //
	Singleton *SecondPointer;
	// Try To Set This Pointer To Another Instaniation Of The Singleton Class //
	SecondPointer = Singleton::getInstance();

	// Print The RandomNumber Of The ObjectPointer (Should Be A Random Number) //
	printf("ObjectPointer's RandomNumber: %i\n", ObjectPointer->getRandomNumber());
	// Print The RandomNumber Of The SecondPointer (Should Be 0 If It Made A Second Object) //
	printf("SecondPointer's RandomNumber: %i\n\n", SecondPointer->getRandomNumber());

	printf("Both Of These Numbers Are The Same Because The SecondPointer Did Not Create\nAnother Instance, But Instead Was Set To The Same Object As The First Pointer\n\n");

	printf("ObjectPointer's Memory Address: %i\n", ObjectPointer);
	printf("SecondPointer's Memory Address: %i\n\n", SecondPointer);
	printf("As You Can See, They Both Point To The Same Location In Memory!\n");
	// Put A Break Point Here! //
	// End The Program //
	return 0;
}