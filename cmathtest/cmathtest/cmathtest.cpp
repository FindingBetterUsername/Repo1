// cmathtest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "cmathtest.h"

using namespace std;

static float nummerA = 3213.0f;
static float nummerB = 123.123f;


void S_init(struct posdata *pdat)
{
	pdat->day = -99;   /* Day of month (May 27 = 27, etc.) */
	pdat->daynum = -999;   /* Day number (day of year; Feb 1 = 32 ) */
	pdat->hour = -99;   /* Hour of day, 0 - 23 */
	pdat->minute = -99;   /* Minute of hour, 0 - 59 */
	pdat->month = -99;   /* Month number (Jan = 1, Feb = 2, etc.) */
	pdat->second = -99;   /* Second of minute, 0 - 59 */
	pdat->year = -99;   /* 4-digit year */
	pdat->interval = 0;   /* instantaneous measurement interval */
	pdat->aspect = 180.0;   /* Azimuth of panel surface (direction it
							faces) N=0, E=90, S=180, W=270 */
	pdat->latitude = -99.0;   /* Latitude, degrees north (south negative) */
	pdat->longitude = -999.0;   /* Longitude, degrees east (west negative) */
	pdat->press = 1013.0;   /* Surface pressure, millibars */
	pdat->solcon = 1367.0;   /* Solar constant, 1367 W/sq m */
	pdat->temp = 15.0;   /* Ambient dry-bulb temperature, degrees C */
	pdat->tilt = 0.0;   /* Degrees tilt from horizontal of panel */
	pdat->timezone = -99.0;   /* Time zone, east (west negative). */
	pdat->sbwid = 7.6;   /* Eppley shadow band width */
	pdat->sbrad = 31.7;   /* Eppley shadow band radius */
	pdat->sbsky = 0.04;   /* Drummond factor for partly cloudy skies */
	pdat->function = S_ALL;   /* compute all parameters */

}

int main()

{
	struct posdata possdata, *pdatapointer;

	pdatapointer = &possdata;
	S_init(pdatapointer);
	float wert = 20;
	float *zeiger;
	zeiger = &wert;
	//*zeiger = fabs(3213.32f);
	
	cout << "hello world" <<endl;
	cout << " pdatapointer:  " << &pdatapointer << endl;
	cout << " zeiger:  " << *zeiger << endl;
	cout << " wert:  0x" <<&wert << endl;

	cout << " structure elemts temp:  " << sin(pdatapointer->temp) << endl;

	getchar();
    return 0;
}

