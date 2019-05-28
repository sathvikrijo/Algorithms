#include<iostream>
#include<string.h>
#include<limits.h>
#include<conio.h>

using namespace std;

class Rides
{
    public:
        int pickup_time;
        int drop_time;
		int ride_amount;
        char drop_at;
        char pickup_at;
		int customer_id;
		int booking_id;
};

class Taxi
{
    public:
        Rides rides[100];
        static int idCounter;
        int taxi_id;
        int no_of_rides;
        int total_earnings;
		int freetime;
        char stationed_at;
        Taxi()
        {
			this->freetime = 0;
            this->stationed_at = 'A';
            this->total_earnings = 0;
            this->no_of_rides = 0;
			idCounter++;
            this->taxi_id = idCounter;
        }
};

int Taxi::idCounter = 0;

int main()
{
	int no_Taxi, no_Cust, pickTime, sId;
	char pickPoint, dropPoint;
	cout<<"Enter the number of taxi's available: ";
	cin>>no_Taxi;
	Taxi taxis[no_Taxi];
	cout<<"Enter the number of customers: ";
	cin>>no_Cust;
	for(int custIndex=0; custIndex<no_Cust; custIndex++)
	{
		cout<<"\nCustomer ID : "<<custIndex+1<<endl;
		cout<<"Pick up Point: ";
		cin>>pickPoint;
		cout<<"Drop Point: ";
		cin>>dropPoint;
		cout<<"Pick up time: ";
		cin>>pickTime;
		sId = 10;
		int mini = INT_MAX;
		for(int taxiId=0; taxiId<no_Taxi; taxiId++)
		{
			int diff = abs(taxis[taxiId].stationed_at - pickPoint);
			if(diff < sId && diff != 0 && taxis[taxiId].freetime < pickTime)
            {
				sId = taxiId;				
            }
			if(diff == 0 && taxis[taxiId].total_earnings<mini && taxis[taxiId].freetime < pickTime)
			{
				mini = taxis[taxiId].total_earnings;
				sId = taxiId;
			}
		}
		if(sId == 10)
		{
			cout<<"Booking is rejected\nNo taxis were free"<<endl;
			continue;
		}
		else
		{
			cout<<"Taxi can be alloted\n";
			cout<<"Taxi-"<<taxis[sId].taxi_id<<" is alloted"<<endl;
		}
		
		int distanceCCal = abs(pickPoint - dropPoint);
		int distanceTCal = abs(taxis[sId].stationed_at - pickPoint);
		int rideCount = taxis[sId].no_of_rides;

		taxis[sId].rides[rideCount].pickup_time = pickTime;
		taxis[sId].rides[rideCount].drop_at = dropPoint;
		taxis[sId].rides[rideCount].pickup_at = pickPoint;
		taxis[sId].rides[rideCount].drop_time = pickTime + distanceCCal;

		int kms = distanceCCal * 15;
		kms = kms - 5;

		int amount = 100 + (kms*10);
		taxis[sId].rides[rideCount].ride_amount = amount;
		taxis[sId].total_earnings += amount;

		taxis[sId].freetime = pickTime + distanceCCal + distanceTCal;

		taxis[sId].rides[rideCount].booking_id = custIndex+1;
		taxis[sId].rides[rideCount].customer_id = custIndex+1;

		taxis[sId].stationed_at = dropPoint;

		taxis[sId].no_of_rides++;		
	}

	getch();

	cout<<endl<<endl;

	for(int taxiIndex=0; taxiIndex<no_Taxi; taxiIndex++)
	{
		cout<<"Taxi No: "<<taxis[taxiIndex].taxi_id;
		cout<<"\t\tTotal Earnings: "<<taxis[taxiIndex].total_earnings<<endl;

		cout<<"Booking ID\tCustomerId\tFrom\t\tTo\t\tPickupTime\tDropTime\tAmount\n";
		for(int rideIndex=0; rideIndex<taxis[taxiIndex].no_of_rides; rideIndex++)
		{
			cout<<taxis[taxiIndex].rides[rideIndex].booking_id<<"\t\t"<<taxis[taxiIndex].rides[rideIndex].customer_id<<"\t\t"<<taxis[taxiIndex].rides[rideIndex].pickup_at<<"\t\t"<<taxis[taxiIndex].rides[rideIndex].drop_at<<"\t\t"<<taxis[taxiIndex].rides[rideIndex].pickup_time<<"\t\t"<<taxis[taxiIndex].rides[rideIndex].drop_time<<"\t\t"<<taxis[taxiIndex].rides[rideIndex].ride_amount<<"\n\n";
		}
	}

	return 0;
}
