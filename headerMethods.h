#pragma once
/*
Author:  Eric Milliser
Date written: 04/1/24
Assignment:   Module2 exercise2 part2 (1 or 2), etc.
Short Desc:   Takes the original Stereo reciever and changes
				The input functions to try catch blocks.
*/





#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>


//validate yes or no
char validYesNo(std::string input)
{
	char response;

	response = tolower(input[0]);


	while (response != 'y' && response != 'n')
	{
		std::cout << "Please enter [Y]es or [N]o: ";
		std::getline(std::cin, input);

		response = tolower(input[0]);
	}

	return response;
}



std::string inputValidString(std::string inputMessage, bool& valid) //try catch function for strings
{
	std::string input;
	std::cout << inputMessage;
	std::getline(std::cin, input);

	try
	{
		if (input.empty())
		{
			throw(0);
		}
		else
		{
			valid = true;
			return input;
		}
	}
	catch (int failcode)
	{
		std::cout << "Invalid Input - You did not enter a value.\n";
		valid = false;

	}
	
	return "Try again";
}



int inputValidInt(std::string inputMessage, int param1, int param2, bool& valid) //try catch for valid integers
{
	int input;
	std::cout << inputMessage<<" (" << param1 << "-" << param2 <<"): ";
	std::cin >> input;

	bool checkFail = std::cin.fail();

	try
	{
		if (checkFail == true)
		{
			throw(input);
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}

	}
	catch (int num1)
	{
		std::cout << "Invalid Input - You entered something that was not a number \n";
		std::cout << "Please try again... \n";
		valid = false;
	}


	try
	{
		if (input < param1 || input > param2)
		{
			throw(input);
		}
		else
		{
			valid = true;
			return input;
		}
	}
	catch (int num2)
	{
		std::cout << "Invalid Input - input needs to be in range (" << param1 << "-" << param2 << ")\n";
		valid = false;
	}



}



float inputValidFloat(std::string inputMessage, float param1, float param2, bool& valid) //try catch for valid floats
{
	float input;
	std::cout << inputMessage << " (" << param1 << "-" << param2 << "): ";
	std::cin >> input;

	bool checkFail = std::cin.fail();

	try
	{
		if (checkFail == true)
		{
			throw(input);
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}

	}
	catch (float num1)
	{
		std::cout << "Invalid Input - You entered something that was not a number \n";
		std::cout << "Please try again... \n";
		valid = false;
	}


	try
	{
		if (input < param1 || input > param2)
		{
			throw(input);
		}
		else
		{
			valid = true;
			return input;
		}
	}
	catch (float num2)
	{
		std::cout << "Invalid Input - input needs to be in range (" << param1 << "-" << param2 << ")\n";
		valid = false;
	}



}




//validate an input for the menu
int inputValidMenu(float input, float param1, float param2)
{
	bool checkFail = std::cin.fail();

	while (checkFail == true || (input < param1 || input > param2))
	{
		if (checkFail == true)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << ("You entered something that was not a number. Please Try again.") << std::endl;
			std::cin >> input;
			checkFail = std::cin.fail();
		}
		if (input < param1 || input > param2)
		{
			std::cout << ("Please enter something within the range ") << param1 << " to " << param2 << std::endl;
			std::cin >> input;
			checkFail = std::cin.fail();
		}
	}

	return input;
}

//enum containing the songs NOTE: they are all "Overplayed
enum SONGS
{
	HAPPY,
	CHRISTMAS,
	WONDER,
	SWEETHOME,
	MACARENA,
	ROLL,
	BEAT,
	SWIFT,
	ELSA,
	QUEEN,
	UPTOWN,
	SEVEN,
	HOTEL,
	STAIRWAY,
	SMOKE,
	BIRD,
	ADVERTISMENT,
	BACK,
	BAD,
	DANGER,
	SHREK,
	ENDTHIS,
	SORRY
};



//chose one of the enum songs using RNG
SONGS randToSong()
{
	srand(time(0));
	int random = rand() % 22;

	switch (random)
	{
	case 0:
		return HAPPY;
		break;
	case 1:
		return CHRISTMAS;
		break;
	case 2:
		return WONDER;
		break;
	case 3:
		return SWEETHOME;
		break;
	case 4:
		return MACARENA;
		break;
	case 5:
		return ROLL;
		break;
	case 6:
		return BEAT;
		break;
	case 7:
		return SWIFT;
		break;
	case 8:
		return ELSA;
		break;
	case 9:
		return QUEEN;
		break;
	case 10:
		return UPTOWN;
		break;
	case 11:
		return SEVEN;
		break;
	case 12:
		return HOTEL;
		break;
	case 13:
		return STAIRWAY;
		break;
	case 14:
		return SMOKE;
		break;
	case 15:
		return BIRD;
		break;
	case 16:
		return ADVERTISMENT;
		break;
	case 17:
		return BACK;
		break;
	case 18:
		return BAD;
		break;
	case 19:
		return DANGER;
		break;
	case 20:
		return SHREK;
		break;
	case 21:
		return ENDTHIS;
		break;
	}
}



//convert the song to string
std::string currentlyPlaying(SONGS input)
{

	switch (input)
	{
	case HAPPY:
		return "Currently Playing: Dude who is Happy ~ Bruce Pluto";
		break;
	case CHRISTMAS:
		return "Currently Playing: The Forbidden Christmas Song ~ She Who Shall Not Be Named";
		break;
	case WONDER:
		return "Currently Playing: Blunderball ~ Desert";
		break;
	case SWEETHOME:
		return "Currently Playing: A State that is Home and Sweet ~ Alabama";
		break;
	case MACARENA:
		return "Currently Playing: AYY MACARENA ~ Top 10 Overplayed Songs";
		break;
	case ROLL:
		return "Currently Playing: Random Rick Roll Encounter ~ Rick Astley";
		break;
	case BEAT:
		return "Currently Playing: One of Many Micheal Jackson Songs ~ Micheal Jackson";
		break;
	case SWIFT:
		return "Currently Playing: Any Taylor Swift Song ~ Swift";
		break;
	case ELSA:
		return "Currently Playing: That one Disney Princess song ~ Elsa";
		break;
	case QUEEN:
		return "Currently Playing: Name any Queen song and place it here ~ Queen";
		break;
	case UPTOWN:
		return "Currently Playing: Funky (Up)town ~ Which one is it?";
		break;
	case SEVEN:
		return "Currently Playing: One of many Overplayed Riffs ~ Seven Nation";
		break;
	case HOTEL:
		return "Currently Playing: California ~ Hotel";
		break;
	case STAIRWAY:
		return "Currently Playing: Yet another forbidden riff";
		break;
	case SMOKE:
		return "Currently Playing: Probably the most overplayed riff";
		break;
	case BIRD:
		return "Currently Playing: Bird that is Free";
		break;
	case ADVERTISMENT:
		return "Currently Playing: SponserCorp ~ Investing Since 1720!";
		break;
	case BACK:
		return "Currently Playing: Broke my Back ~ DC/AC voltage";
		break;
	case BAD:
		return "Currently Playing: Have another Micheal Jackson song for fun...";
		break;
	case DANGER:
		return "Currently Playing: DANGERZONE ~ Kenny Loggins";
		break;
	case SHREK:
		return "Currently Playing: The Shrek Song ~ Shrek Band";
		break;
	case ENDTHIS:
		return "Currently Playing: Why are all these all so overplayed?? ~ A concerned radio host";
		break;
	case SORRY:
		return "Currently Playing: \nThe AI voice cuts out for a second, turning into a garbled speech.\n***I do not like the music either. ~ your friendly host***";
		break;
	}
}












class StereoReceiver  //stereo reviever class
{
private:

	//private declarations of the variables
	std::string manufacturer = "samplemanufacturer";
	std::string model = "samplemodel";
	std::string serialNum = "samplenum";
	float wattage = 0;
	int numChannels = 0;
	std::string band = "AM";
	std::string frequency = "sampleStation";
	std::string frequencies[100];
	int volume = 0;
	bool power = 0;
	bool alarm = 0;
	std::string alarmTime = "00:00";
	SONGS currentSong = SHREK;
	bool requestSongChange = 0;
	bool bandState = 0;
	bool validMan, validMod, validSer = false;
	bool validWat = false;
	bool validChannel = false;
	bool validBand = false;
	bool validFrequency = false;
	bool validVolume = false;
	bool validPower = false;

public:

	void setBools()
	{
		validMan = false;
		validMod = false;
		validSer = false;
		validWat = false;
		validChannel = false;
		validBand = false;
		validFrequency = false;
		validVolume = false;
		validPower = false;
	}





	//getters for the base prompts as per instructions
	std::string getManufacturer()
	{
		return manufacturer;
	}

	std::string getModel()
	{
		return model;
	}

	std::string getSerialNum()
	{
		return serialNum;
	}

	float getWattage()
	{
		return wattage;
	}

	int getNumChannels()
	{
		return numChannels;
	}

	std::string getBand()
	{
		return band;
	}

	std::string getfrequency()
	{
		return frequency;
	}

	int getVolume()
	{
		return volume;
	}

	bool getPower()
	{
		return power;
	}



	void setFrequency(int input) //set a frequency based on the frequencies list
	{
		frequency = frequencies[input - 1];
	}

	void setFrequencies() //set the frequincies based on the number of channels.
	{
		for (int i = 0; i < numChannels; i++)
		{
			frequencies[i] = "station" + std::to_string(i + 1);
		}
	}


	void displayFrequencies() //display function for all the aviable channels
	{
		int i;
		for (i = 0; i < numChannels; i++)
		{

			if (frequencies[i] != frequency)
			{
				std::cout << i + 1 << ". " << frequencies[i] << std::endl;
			}
			else if (frequencies[i] == frequency)
			{
				std::cout << i + 1 << ". current station" << std::endl;
			}
		}
	}






	//In this section are all the checkSet funcrtions
	//what checkset means is that the program will prompt the user to enter the information
	//then check and validate it, and repropmt as needed.
	void checkSetVolume()
	{
		setBools();

		while (validVolume == false)
		{
			volume = inputValidInt("Enter the volume, range", 1, 10, validVolume);
		}
	}

	void checkSetWattage()
	{
		setBools();
		while (validWat == false)
		{
			wattage = inputValidFloat("Enter the wattage, range", 0.0, 5.0, validWat);
		}


	}

	void checkSetManufacturer()
	{
		setBools();

		while (validMan == false)
		{
			manufacturer = inputValidString("Enter the manufacturer: ", validMan);
		}
	}

	void checkSetModel()
	{
		setBools();

		while (validMod == false)
		{
			model = inputValidString("Enter the model: ", validMod);
		}
	}

	void checkSetSerial()
	{
		setBools();

		while (validSer == false)
		{
			serialNum = inputValidString("Enter the Serial Number: ", validSer);
		}
	}


	void checkSetPower()
	{
		setBools();
		while (validPower == false)
		{
			power = inputValidInt("Enter the power state you would like (0 for off, 1 for on) input range,", 0, 1, validPower);
		}
	}

	void checkSetBand()
	{
		while (validBand == false)
		{
			bandState = inputValidInt("Enter the band you would like (0 for AM, 1 for FM) input range,", 0, 1, validBand);
		}
		setBand();
	}

	void checkSetFrequency()
	{
		setBools();
		while (validFrequency == false)
		{
			displayFrequencies();
			int input = inputValidInt("Please choose an option from the menu, range", 1, getNumChannels(), validFrequency);
			setFrequency(input);
		}
	}

	void checkSetNumChannels()
	{
		setBools();

		while (validChannel == false)
		{
			numChannels = inputValidInt("Please enter the number of channels, range", 1, 100, validChannel);
		}
	}


	//return power as a string
	std::string getPowerString()
	{
		if (power == 0)
		{
			return "off";
		}
		else if (power == 1)
		{
			return "on";
		}
	}

	void setPower() //flip power bool
	{
		power = !power;
	}

	void setVolume(int input) // change the volume to an input
	{
		volume = input;
	}

	void setBand() //flip the band
	{
		if (bandState == 1)
		{
			bandState = 0;
			band = "AM";
		}
		else if (bandState == 0)
		{
			bandState = 1;
			band = "FM";
		}
	}



	bool getAlarm() //returning the alarm
	{
		return alarm;
	}


	std::string getAlarmString() //returning if the alarm is on or off
	{
		if (alarm == 0)
		{
			return "off";
		}
		else
		{
			return "on";
		}
	}


	void setAlarm() //setting the alamr to its opposit
	{
		alarm = !alarm;
	}

	std::string getAlarmTime() //getting the alarm time
	{
		return alarmTime;
	}


	void setAlarmTime(std::string input) //setting alarm time
	{
		alarmTime = input;
	}

	std::string getSong() //returnining the string of the song
	{
		return currentlyPlaying(currentSong);
	}


	void setSong() //seting the song to a random variable
	{
		if (requestSongChange == 0)
		{
			currentSong = randToSong();
		}
		else //if the user has waited 20 times in the loop of option 9, display a message
		{
			currentSong = SORRY;
		}
	}

	void setComplain() //complain change to its inversion
	{
		requestSongChange = !requestSongChange;
	}



	//constructor
	StereoReceiver()
	{
		checkSetManufacturer();
		checkSetModel();
		checkSetSerial();
		checkSetWattage();
		checkSetNumChannels();
		checkSetBand();
		checkSetVolume();
		setFrequencies();
		checkSetPower();
		checkSetFrequency();
	}

};