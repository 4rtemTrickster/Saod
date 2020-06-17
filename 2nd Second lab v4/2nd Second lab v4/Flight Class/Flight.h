#pragma once
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <iostream>
#include <iterator>


namespace Flights
{
	class Flight
	{
	private:
		class Passenger
		{
		private:
			std::string Name;
			std::string SecondName;
			std::string Surname;
		public:
			Passenger(std::string Name, std::string SecondName, std::string Surname)
				:Name(Name), SecondName(SecondName), Surname(Surname) {}

			const std::string& GetName() const { return this->Name; }
			const std::string& GetSecondName() const { return this->SecondName; }
			const std::string& GetSurname() const { return this->Surname; }

			std::string& GetName() { return this->Name; }
			std::string& GetSecondName() { return this->SecondName; }
			std::string& GetSurname() { return this->Surname; }

			bool operator == (const Passenger& Other_Passenger) const;
			bool operator != (const Passenger& Other_Passenger) const;
			bool operator > (const Passenger& Other_Passenger) const;
			bool operator < (const Passenger& Other_Passenger) const;


		};

		std::vector<Passenger> Passengers_vector;
		unsigned int max_passangers_count;
		std::deque<Passenger> Passenger_deque;
		unsigned int FlightID;


	public:

		Flight(unsigned int max_passangers_count, unsigned int FlightID)
			:max_passangers_count(max_passangers_count), FlightID(FlightID) {};
		
		const unsigned int& GetMaxPassengersCount() const { return this->max_passangers_count; }
		unsigned int& GetMaxPassengersCount() { return this->max_passangers_count; }

		void addNewPassenger(std::string Name, std::string SecondName, std::string Surname);
		void ShowPassengers();
		void ShowDeque();
		unsigned int GetID() { return this->FlightID; }
		

	};
}