/*
Author:  Eric Milliser
Date written: 04/1/24
Assignment:   Module2 exercise2 part2 (1 or 2), etc.
Short Desc:   Takes the original Stereo reciever and changes
				The input functions to try catch blocks.
*/



//include statements
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include "headerMethods.h"




int main() //main program
{

	//declarations
	StereoReceiver newStereo; //utilizing the constructor.
	int input;
	bool valid;


	input = 0; //integer for input choices

	char yesNo = 'n'; //setting a sentinal variable
	std::string inputString; //input string varaiable


	do //do while yesNo == 'n"
	{

		//display input details
		std::cout << "Details of the Radio" << std::endl;
		std::cout << "Manufacturer: " << newStereo.getManufacturer() << std::endl;
		std::cout << "Model: " << newStereo.getModel() << std::endl;
		std::cout << "Serial Number: " << newStereo.getSerialNum() << std::endl;
		std::cout << "Wattage: " << newStereo.getWattage() << std::endl;
		std::cout << "Number of Channels: " << newStereo.getNumChannels() << std::endl;
		std::cout << "Band: " << newStereo.getBand() << std::endl;
		std::cout << "Frequency: " << newStereo.getfrequency() <<std::endl;
		std::cout << "Volume: " << newStereo.getVolume() << std::endl;


		//validate input
		std::cout << "Is this information correct? {Y}es or [N]o (make changes): ";
		std::getline(std::cin, inputString);
		yesNo = validYesNo(inputString);

		if (yesNo == 'y') //break if yes
		{
			break;
		}
		else
		{
			//prompt for details to change
			std::cout << "Please choose next the number next to the thing you wish to change. " << std::endl;
			std::cout << "1. Manufacturer" << std::endl;
			std::cout << "2. Model" << std::endl;
			std::cout << "3. Serial Number" << std::endl;
			std::cout << "4. Wattage" << std::endl;
			std::cout << "5. Number of channels" << std::endl;
			valid = false;
			while (valid == false)
			{
			input = inputValidInt("Please choose an option from the menu, range", 1, 5, valid);
		}
			switch (input)
			{
			case 1: //change manufacturer
				std::cin.ignore(100, '\n');
				newStereo.checkSetManufacturer();
				break;
			case 2: //change model
				std::cin.ignore(100, '\n');
				newStereo.checkSetModel();
				break;
			case 3: //change serialNum
				std::cin.ignore(100, '\n');
				newStereo.checkSetSerial();
				break;
			case 4: //change wattage
				newStereo.checkSetWattage();
				break;
			case 5: //change channels
				newStereo.checkSetNumChannels();
				break;

			}
		}


	} while (yesNo == 'n'); //while sentinal is not 'y'


	input = 0; //declare before while loop

	while (input < 6 || input == 9) //while the inputs are not the sentinel control;ers
	{
		//declare variables for what to display
		bool isOn = newStereo.getPower();
		bool alarmSet = newStereo.getAlarm();


		//display information
		std::cout << "Stereo Receiver" << std::endl;
		std::cout << newStereo.getManufacturer() << ": " << newStereo.getModel() << std::endl;
		std::cout << "Serial Number: " << newStereo.getSerialNum() << std::endl;
		std::cout << newStereo.getWattage() << " Watts" << std::endl;
		std::cout << "Number of Channels: " << newStereo.getNumChannels() << std::endl;
		std::cout << "Band: " << newStereo.getBand() << std::endl;
		std::cout << "Frequency: " << newStereo.getfrequency() << std::endl;
		std::cout << "Volume: " << newStereo.getVolume() << std::endl;


		//block to determine to show what displayed
		if (isOn == false)
		{
			//if the reciever is off, don't display the other information
			std::cout << "The reciever is " << newStereo.getPowerString() << std::endl;
		}
		else
		{
			//if the reciever is on, display song and alarm
			newStereo.setSong();

			std::cout << newStereo.getSong() << std::endl;


			if (alarmSet == true)
			{
				std::cout << "Alarm is " << newStereo.getAlarmString() << " and set for " << newStereo.getAlarmTime() << std::endl;
			}
			else
			{
				std::cout << "Alarm is " << newStereo.getAlarmString() << std::endl;
			}
		}


		///prompt choices based on the isOn varriable
		std::cout << "What would you like to do?" << std::endl;
		if (isOn == false)
		{
			std::cout << "1. Power on" << std::endl;
		}
		else if (isOn == true)
		{
			std::cout << "1. Power off" << std::endl;
		}

		std::cout << "2. Change band" << std::endl;
		std::cout << "3. Change Volume" << std::endl;
		std::cout << "4. Change Frequency" << std::endl;
		std::cout << "5. Set Alarm" << std::endl;
		std::cout << "6. Leave" << std::endl;
		if (isOn == true)
		{
			std::cout << "9. Complain about the music" << std::endl;
		}
		valid = false;
		while (valid == false)
		{
			input = inputValidInt("Please choose an option from the menu, range", 1, 6, valid);
		}

		if (input == 9 && isOn == true) //validatation of input if it is 9 and it is on
		{
			//This is the lengthy part of the program where it takes a look at the song
			//variables and plays on the fact the songs are all "overplayed" or annoying
			srand(time(0));
			int random = rand() % 11;

			//output
			std::cout << "You call the radio station to complain about the music..." << std::endl;
			std::cout << "Someone picks up.." << std::endl << std::endl;
			std::cout << "\'This is the automated call center for... " << newStereo.getfrequency() << "\"" << std::endl;
			std::cout << "\"We understand you may not like our music... Too bad!\"" << std::endl;
			std::cout << "\"Please wait while we reach out to the host...\"" << std::endl;


			int counter = 0;
			yesNo = 'y';

			//put on hold scenario, and loops while the user waits or until the counter hits 20 and the "phone hangs up"
			while (counter < 20 && yesNo == 'y')
			{
				newStereo.setSong();
				std::cout << "You hear the automated message after a brief hold..." << std::endl;
				std::cout << "\"" << newStereo.getSong() << "\"" << std::endl;
				std::cout << "The song starts to play over the phone." << std::endl;

				std::cout << "Do you wish to wait? [Y]es or [N]o? ";
				std::cin.ignore(100, '\n');
				std::cin >> inputString;
				yesNo = validYesNo(inputString);


				if (counter == 10 && alarmSet == true)
				{
					std::cout << std::endl;
					std::cout << "The radio starts blaring this current song. You check to find the alarm is going off." << std::endl;
					std::cout << "You have been waiting a long time." << std::endl;
					std::cout << std::endl;
				}



				if (counter >= 19)
				{
					newStereo.setComplain();
					newStereo.setSong();

					std::cout << std::endl;
					std::cout << "You hear the automated message once more." << std::endl;
					std::cout << newStereo.getSong() << std::endl;

					newStereo.setComplain();

					std::cout << "The phone hangs up." << std::endl << std::endl;
				}

				counter++;

			}


		}

		//any other choice goes here
		if (input != 9 || (input == 9 && isOn == false))
		{



			switch (input)
			{
			case 1: //flip power
				newStereo.checkSetPower();
				break;
			case 2: //flip band
				newStereo.checkSetBand();
				break;
			case 3: //change volume
				newStereo.checkSetVolume();
				break;
			case 4: //display channels
				newStereo.checkSetFrequency();
				break;
			case 5: //set alarm
				std::cout << "Set a time for the alarm: ";
				std::cin.ignore(100, '\n');
				std::getline(std::cin, inputString);
				newStereo.setAlarmTime(inputString);
				newStereo.setAlarm();
				std::cout << std::endl;
			default:
				break;
			}



		}

	}
}