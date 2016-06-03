#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <iomanip>
#include <ctime>
#include <stdexcept> // for illegal_argument exception class
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

Time::Time()
   : hour( 0 ), minute( 0 ), second( 0 )
{
	time_t initialTime = time(0);  //get computer time
	struct tm* currentTime = localtime(&initialTime);   //transfer computer time to local time

	int currentHour = currentTime->tm_hour;  //use arrow operator to access hour from currentTime pointer
	int currentMinute = currentTime->tm_min;  //use arrow operator to access minute from currentTime pointer
	int currentSecond = currentTime->tm_sec;  //use arrow operator to access second from currentTime pointer

	setTime(currentHour, currentMinute, currentSecond);  //set the time to the current local computer time
} // end Time constructor

// set new Time value using universal time
void Time::setTime( int h, int m, int s )
{
   // validate hour, minute and second
   if ( ( h >= 0 && h < 24 ) && ( m >= 0 && m < 60 ) && 
      ( s >= 0 && s < 60 ) ) 
   {
	   hour = h;  //set the hour
	   minute = m;  //set the minute
	   second = s;   //set the second
   } // end if
   else
      throw invalid_argument( 
         "hour, minute and/or second was out of range" );
} // end function setTime

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() const
{
   cout << setfill( '0' ) << setw( 2 ) << hour << ":" 
      << setw( 2 ) << minute << ":" << setw( 2 ) << second;
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard() const
{
   cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 ) << ":" 
      << setfill( '0' ) << setw( 2 ) << minute << ":" << setw( 2 )
      << second << ( hour < 12 ? " AM" : " PM" );
} // end function printStandard
