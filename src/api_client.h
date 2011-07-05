#ifndef API_CLIENT_H
#define API_CLIENT_H

#define MAX_API_KEY_LENGTH 100

class ApiClient
{
	private:
		char mapikey[MAX_API_KEY_LENGTH+1];

		double weekSum; double thisDaySum;
		
	protected:
		void formatDate(char buf[11]);

	public:
		double getWeekSum() { return weekSum; };
		double getThisDaySum() { return thisDaySum; };

		void refresh();

		ApiClient(char* apikey, int length);
};



#endif
