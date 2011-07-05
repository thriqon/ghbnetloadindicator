
#include <stdio.h>

#include "applet_gtk.h"

//add click handler to refresh NOW!

PanelAppletGTK::PanelAppletGTK(GtkContainer* parent)
{
	maxSumPerWeek = 0;
	curSumPerWeek = 0;
	sumThisDay    = 0;

	progressBar = GTK_PROGRESS_BAR(gtk_progress_bar_new());
	gtk_container_add(parent, GTK_WIDGET(progressBar));
	gtk_widget_show_all(GTK_WIDGET(parent));
	redraw();
}

PanelAppletGTK::~PanelAppletGTK()
{
	//TODO:deconstruct
}

void PanelAppletGTK::redraw()
{
	const int buflen = 15; // "1.1/4.7 (1024)"
	
	char buf[buflen];

	
	snprintf(buf, buflen, "%1.1f/%0.1f (%4.0f)", curSumPerWeek/1024, maxSumPerWeek/1024, sumThisDay);

	//printf("buf: %s\n", buf);
	gtk_progress_bar_set_text(progressBar, buf);
	if (curSumPerWeek * maxSumPerWeek != 0) 
		gtk_progress_bar_set_fraction(progressBar, curSumPerWeek / maxSumPerWeek);
}


