#include "date.h"
#include <assert.h>
#include <exception>

extern char* weekdays[];

int main()
{
	GHB::Date firstof2011 (1,1,2011); // SATURDAY
	
	assert(firstof2011.getDay() == 1);
	assert(firstof2011.getMonth() == 1);
	assert(firstof2011.getYear() == 2011);

	assert(firstof2011.getDayOfWeek() == weekdays[6]);


	GHB::Date illegalDate (29, 2, 2011); // day after last day of februrary
	assert(illegalDate.getDay() == 1); // first of March
	assert(illegalDate.getMonth() == 3);
	assert(illegalDate.getYear() == 2011);	

}
