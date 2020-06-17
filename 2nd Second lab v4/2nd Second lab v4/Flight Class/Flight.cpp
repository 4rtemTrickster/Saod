#include "Flight.h"

namespace Flights
{
	bool Flight::Passenger::operator==(const Flight::Passenger& Other_Passenger) const
	{
		if (strcmp(this->Surname.c_str(), Other_Passenger.Surname.c_str()) == 0 &&
			strcmp(this->Name.c_str(), Other_Passenger.Name.c_str()) == 0 &&
			strcmp(this->SecondName.c_str(), Other_Passenger.SecondName.c_str()) == 0)
			return true;
		else
			return false;
	}

	bool Flight::Passenger::operator!=(const Flight::Passenger& Other_Passenger) const
	{
		if (strcmp(this->Surname.c_str(), Other_Passenger.Surname.c_str()) != 0 &&
			strcmp(this->Name.c_str(), Other_Passenger.Name.c_str()) != 0 &&
			strcmp(this->SecondName.c_str(), Other_Passenger.SecondName.c_str()) != 0)
			return true;
		else
			return false;
	}

	bool Flight::Passenger::operator > (const Flight::Passenger& Other_Passenger) const
	{
		int comp = strcmp(this->Surname.c_str(), Other_Passenger.Surname.c_str());
		int compN = strcmp(this->Name.c_str(), Other_Passenger.Name.c_str());

		if (comp > 0)
			return true;
		else if (comp == 0 && compN > 0)
			return true;
		else if (comp == 0 && compN == 0 && strcmp(this->SecondName.c_str(), Other_Passenger.SecondName.c_str()) > 0)
			return true;

		return false;
	}

	bool Flight::Passenger::operator < (const Flight::Passenger& Other_Passenger) const
	{
		int comp = strcmp(this->Surname.c_str(), Other_Passenger.Surname.c_str());
		int compN = strcmp(this->Name.c_str(), Other_Passenger.Name.c_str());

		if (comp < 0)
			return true;
		else if (comp == 0 && compN < 0)
			return true;
		else if (comp == 0 && compN == 0 && strcmp(this->SecondName.c_str(), Other_Passenger.SecondName.c_str()) < 0)
			return true;

		return false;
	}

	void Flight::addNewPassenger(std::string Name, std::string SecondName, std::string Surname)
	{
		Passenger NewPassenger(Name, SecondName, Surname);

		if (this->Passengers_vector.size() < this->max_passangers_count && (
			std::find(this->Passengers_vector.begin(), this->Passengers_vector.end(), NewPassenger) == this->Passengers_vector.end())
			)
		{
			this->Passengers_vector.emplace_back(NewPassenger);
			std::sort(this->Passengers_vector.begin(), this->Passengers_vector.end(), [](const Passenger& a, const Passenger& b) { return a < b; });
		}
		else if (this->Passenger_deque.size() < this->max_passangers_count && (
			std::find(this->Passenger_deque.begin(), this->Passenger_deque.end(), NewPassenger) == this->Passenger_deque.end()))
		{
			this->Passenger_deque.emplace_back(NewPassenger);
			std::sort(this->Passenger_deque.begin(), this->Passenger_deque.end(), [](const Passenger& a, const Passenger& b) { return a < b; });
		}
		else
			std::cout << "Already exist or all seats acupied" << std::endl;
	}

	void Flight::ShowPassengers()
	{
		for (auto i = this->Passengers_vector.begin(); i != this->Passengers_vector.end(); i++)
		{
			Passenger tmp = *i;
			std::cout << tmp.GetSurname() << " " << tmp.GetName() << " " << tmp.GetSecondName() << std::endl;
		}

	}
	void Flight::ShowDeque()
	{
		for (auto i = this->Passenger_deque.begin(); i != this->Passenger_deque.end(); i++)
		{
			Passenger tmp = *i;
			std::cout << tmp.GetSurname() << " " << tmp.GetName() << " " << tmp.GetSecondName() << std::endl;
		}
	}
}