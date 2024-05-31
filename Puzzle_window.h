#pragma once

#include "GUI.h"
#include "Window.h"
#include "Puzzle.h"

#include <string>

namespace Graph_lib {

	struct Puzzle_window : Window
	{
		Puzzle_window(Point xy, int w, int h, int num_rows, int num_columns, const string& title);
		virtual ~Puzzle_window();

	private:
		void setTimer();
		void resetTimer();
		void killTimer();
		void handleTimer();

		void handleButtonPressed(Fl_Widget* button_widget);
		void updateButtonImages();

		std::string getImagePath(Jewel jewel);
		int getButtonIndex(Fl_Widget* button_widget);
		pair<int, int> getButtonLocation(int index);

		Puzzle* puzzle;

		vector<ImageButton*> button_list;
		vector<pair<int,int>> pressed_locations; 
			
		int num_columns;
		int num_rows;

		static void cb_jewel(Address widget, Address window);
		static void cb_timer(Address window);
	};
};
