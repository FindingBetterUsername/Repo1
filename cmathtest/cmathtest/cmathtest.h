#pragma once

#define L_ALL    0xFFFF

#define S_ALL    ( L_ALL                          )

struct posdata
{
	/***** ALPHABETICAL LIST OF COMMON VARIABLES *****/
	/* Each comment begins with a 1-column letter code:
	I:  INPUT variable
	O:  OUTPUT variable
	T:  TRANSITIONAL variable used in the algorithm,
	of interest only to the solar radiation
	modelers, and available to you because you
	may be one of them.

	The FUNCTION column indicates which sub-function
	within solpos must be switched on using the
	"function" parameter to calculate the desired
	output variable.  All function codes are
	defined in the solpos.h file.  The default
	S_ALL switch calculates all output variables.
	Multiple functions may be or'd to create a
	composite function switch.  For example,
	(S_TST | S_SBCF). Specifying only the functions
	for required output variables may allow solpos
	to execute more quickly.

	The S_DOY mask works as a toggle between the
	input date represented as a day number (daynum)
	or as month and day.  To set the switch (to
	use daynum input), the function is or'd; to
	clear the switch (to use month and day input),
	the function is inverted and and'd.

	For example:
	pdat->function |= S_DOY (sets daynum input)
	pdat->function &= ~S_DOY (sets month and day input)

	Whichever date form is used, S_solpos will
	calculate and return the variables(s) of the
	other form.  See the soltest.c program for
	other examples. */

	/* VARIABLE        I/O  Function    Description */
	/* -------------  ----  ----------  ---------------------------------------*/

	int   day;       /* I/O: S_DOY      Day of month (May 27 = 27, etc.)
					 solpos will CALCULATE this by default,
					 or will optionally require it as input
					 depending on the setting of the S_DOY
					 function switch. */
	int   daynum;    /* I/O: S_DOY      Day number (day of year; Feb 1 = 32 )
					 solpos REQUIRES this by default, but
					 will optionally calculate it from
					 month and day depending on the setting
					 of the S_DOY function switch. */
	int   function;  /* I:              Switch to choose functions for desired
					 output. */
	int   hour;      /* I:              Hour of day, 0 - 23, DEFAULT = 12 */
	int   interval;  /* I:              Interval of a measurement period in
					 seconds.  Forces solpos to use the
					 time and date from the interval
					 midpoint. The INPUT time (hour,
					 minute, and second) is assumed to
					 be the END of the measurement
					 interval. */
	int   minute;    /* I:              Minute of hour, 0 - 59, DEFAULT = 0 */
	int   month;     /* I/O: S_DOY      Month number (Jan = 1, Feb = 2, etc.)
					 solpos will CALCULATE this by default,
					 or will optionally require it as input
					 depending on the setting of the S_DOY
					 function switch. */
	int   second;    /* I:              Second of minute, 0 - 59, DEFAULT = 0 */
	int   year;      /* I:              4-digit year (2-digit year is NOT
					 allowed */

					 /***** FLOATS *****/

	float amass;      /* O:  S_AMASS    Relative optical airmass */
	float ampress;    /* O:  S_AMASS    Pressure-corrected airmass */
	float aspect;     /* I:             Azimuth of panel surface (direction it
					  faces) N=0, E=90, S=180, W=270,
					  DEFAULT = 180 */
	float azim;       /* O:  S_SOLAZM   Solar azimuth angle:  N=0, E=90, S=180,
					  W=270 */
	float cosinc;     /* O:  S_TILT     Cosine of solar incidence angle on
					  panel */
	float coszen;     /* O:  S_REFRAC   Cosine of refraction corrected solar
					  zenith angle */
	float dayang;     /* T:  S_GEOM     Day angle (daynum*360/year-length)
					  degrees */
	float declin;     /* T:  S_GEOM     Declination--zenith angle of solar noon
					  at equator, degrees NORTH */
	float eclong;     /* T:  S_GEOM     Ecliptic longitude, degrees */
	float ecobli;     /* T:  S_GEOM     Obliquity of ecliptic */
	float ectime;     /* T:  S_GEOM     Time of ecliptic calculations */
	float elevetr;    /* O:  S_ZENETR   Solar elevation, no atmospheric
					  correction (= ETR) */
	float elevref;    /* O:  S_REFRAC   Solar elevation angle,
					  deg. from horizon, refracted */
	float eqntim;     /* T:  S_TST      Equation of time (TST - LMT), minutes */
	float erv;        /* T:  S_GEOM     Earth radius vector
					  (multiplied to solar constant) */
	float etr;        /* O:  S_ETR      Extraterrestrial (top-of-atmosphere)
					  W/sq m global horizontal solar
					  irradiance */
	float etrn;       /* O:  S_ETR      Extraterrestrial (top-of-atmosphere)
					  W/sq m direct normal solar
					  irradiance */
	float etrtilt;    /* O:  S_TILT     Extraterrestrial (top-of-atmosphere)
					  W/sq m global irradiance on a tilted
					  surface */
	float gmst;       /* T:  S_GEOM     Greenwich mean sidereal time, hours */
	float hrang;      /* T:  S_GEOM     Hour angle--hour of sun from solar noon,
					  degrees WEST */
	float julday;     /* T:  S_GEOM     Julian Day of 1 JAN 2000 minus
					  2,400,000 days (in order to regain
					  single precision) */
	float latitude;   /* I:             Latitude, degrees north (south negative) */
	float longitude;  /* I:             Longitude, degrees east (west negative) */
	float lmst;       /* T:  S_GEOM     Local mean sidereal time, degrees */
	float mnanom;     /* T:  S_GEOM     Mean anomaly, degrees */
	float mnlong;     /* T:  S_GEOM     Mean longitude, degrees */
	float rascen;     /* T:  S_GEOM     Right ascension, degrees */
	float press;      /* I:             Surface pressure, millibars, used for
					  refraction correction and ampress */
	float prime;      /* O:  S_PRIME    Factor that normalizes Kt, Kn, etc. */
	float sbcf;       /* O:  S_SBCF     Shadow-band correction factor */
	float sbwid;      /* I:             Shadow-band width (cm) */
	float sbrad;      /* I:             Shadow-band radius (cm) */
	float sbsky;      /* I:             Shadow-band sky factor */
	float solcon;     /* I:             Solar constant (NREL uses 1367 W/sq m) */
	float ssha;       /* T:  S_SRHA     Sunset(/rise) hour angle, degrees */
	float sretr;      /* O:  S_SRSS     Sunrise time, minutes from midnight,
					  local, WITHOUT refraction */
	float ssetr;      /* O:  S_SRSS     Sunset time, minutes from midnight,
					  local, WITHOUT refraction */
	float temp;       /* I:             Ambient dry-bulb temperature, degrees C,
					  used for refraction correction */
	float tilt;       /* I:             Degrees tilt from horizontal of panel */
	float timezone;   /* I:             Time zone, east (west negative).
					  USA:  Mountain = -7, Central = -6, etc. */
	float tst;        /* T:  S_TST      True solar time, minutes from midnight */
	float tstfix;     /* T:  S_TST      True solar time - local standard time */
	float unprime;    /* O:  S_PRIME    Factor that denormalizes Kt', Kn', etc. */
	float utime;      /* T:  S_GEOM     Universal (Greenwich) standard time */
	float zenetr;     /* T:  S_ZENETR   Solar zenith angle, no atmospheric
					  correction (= ETR) */
	float zenref;     /* O:  S_REFRAC   Solar zenith angle, deg. from zenith,
					  refracted */
};
