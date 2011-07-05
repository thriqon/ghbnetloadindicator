#ifndef APPLET_GTK_H
#define APPLET_GTK_H

#include <gtk/gtk.h>

class PanelAppletGTK
{
	
	private:
		// these are in MiB
		double maxSumPerWeek;
		double curSumPerWeek;
		double sumThisDay;

		void redraw();

		GtkProgressBar* progressBar;

	public:
		PanelAppletGTK(GtkContainer* parent);
		virtual ~PanelAppletGTK();	
	

		void setMaxSum(double newVal) { maxSumPerWeek = newVal; redraw(); };
		double getMaxSum() { return maxSumPerWeek; };

		void setCurSum(double newVal) { curSumPerWeek = newVal; redraw(); };
		double getCurSum() { return curSumPerWeek; };

		void setSumThisDay(double newVal) { sumThisDay = newVal; redraw(); };
		double getSumThisDay() { return sumThisDay; };

};



#endif /*APPLET_GTK_H*/
