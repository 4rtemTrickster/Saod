#include "Flight Class/Flight.h"

int mbsearch(std::vector<Flights::Flight> Flights, unsigned int key)
{
	unsigned int left = 0;
	unsigned int right = Flights.size() - 1;
	int search = -1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (key == Flights[mid].GetID())
		{
			search = mid;
			break;
		}
		
		if (key < Flights[mid].GetID())
			right = mid + 1;
		else
			left = mid + 1;

	}

	if (search == -1)
		return -1;
	else
		return search;
}

int main()
{
	std::vector<Flights::Flight> myFlights =
	{
		Flights::Flight(3,0),
		Flights::Flight(4,1),
		Flights::Flight(6,2),
		Flights::Flight(7,3),
		Flights::Flight(12,4),
		Flights::Flight(32,5),
		Flights::Flight(32,6)
	};

	std::cout << mbsearch(myFlights, 3);

	myFlights[0].addNewPassenger("Artem", "Sergeevich", "Korneev");
	myFlights[0].ShowPassengers();




	return 0;
}