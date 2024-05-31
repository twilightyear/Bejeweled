#include "Puzzle_window.h"
#include "Puzzle.h"

namespace Graph_lib {

	Puzzle_window::Puzzle_window(Point xy, int w, int h, int num_rows, int num_columns, const string& title)
		: Window(xy, w, h, title)
	{
		this->num_rows = num_rows;			
		this->num_columns = num_columns;

		puzzle = new Puzzle(num_rows, num_columns);
		puzzle->randomize();

		double sx = (double)w / (double)num_columns;
		double sy = (double)h / (double)num_rows;
		double sz = (sx > sy ? sx : sy);

		for (int i = 0; i < num_rows; i++)
		{
			for (int j = 0; j < num_columns; j++)
			{
				int x = (int)(w/2 - (sz*num_columns) / 2 + j * sz);
				int y = (int)(i * sz);
				
				Jewel jewel = puzzle->getJewel(std::make_pair(i, j));
				std::string image_path = getImagePath(jewel);
				if (image_path != "")
				{
					ImageButton* button = new ImageButton(Point(x, y), image_path, cb_jewel);
					attach(*button);

					button_list.push_back(button);
				}
			}
		}

		setTimer();
	}

	Puzzle_window::~Puzzle_window()
	{
		for (ImageButton* button : button_list)
		{
			detach(*button);
			delete button;
		}
		delete puzzle;
	}

	void Puzzle_window::cb_jewel(Address button, Address window)
	{
		Puzzle_window* puzzle_window = static_cast<Puzzle_window*>(window);
		Fl_Widget* img_btn_widget = static_cast<Fl_Widget*>(button);

		puzzle_window->handleButtonPressed(img_btn_widget);
	}

	void Puzzle_window::cb_timer(Address window)
	{
		Puzzle_window* puzzle_window = static_cast<Puzzle_window*>(window);

		puzzle_window->handleTimer();
	}

	void Puzzle_window::setTimer()
	{
		Fl::add_timeout(0.5, cb_timer, (Address)this);
	}

	void Puzzle_window::resetTimer()
	{
		Fl::repeat_timeout(0.5, cb_timer, (Address)this);
	}

	void Puzzle_window::killTimer()
	{
		Fl::remove_timeout(cb_timer, (Address)this);
	}

	void Puzzle_window::handleTimer()
	{
		bool is_updated = puzzle->update();
		if (!is_updated)
		{
			killTimer();
		}
		else
		{
			updateButtonImages();
			Fl::redraw();

			resetTimer();
		}
	}

	void Puzzle_window::handleButtonPressed(Fl_Widget* img_btn_widget)
	{
		int index = getButtonIndex(img_btn_widget);
		pair<int, int> loc = getButtonLocation(index);

		pressed_locations.push_back(loc);
		if (pressed_locations.size() == 2)
		{
			pair<int, int> prev_loc = pressed_locations[0];
			pair<int, int> next_loc = pressed_locations[1];
			pressed_locations.clear();

			puzzle->swapJewels(prev_loc, next_loc);
			updateButtonImages();

			setTimer();
		}
	}

	void Puzzle_window::updateButtonImages()
	{
		int num_buttons = (int)button_list.size();
		for (int index = 0; index < num_buttons; index++)
		{
			ImageButton* button = button_list[index];

			pair<int,int> loc = getButtonLocation(index);
			Jewel jewel = puzzle->getJewel(loc);
			std::string path = getImagePath(jewel);

			button->updateImage(path);
		}
		Fl::redraw();
	}

	std::string Puzzle_window::getImagePath(Jewel jewel)
	{
		std::string path = "";

		switch (jewel) {
		case Jewel::RED:	path = "Bejeweled_Red_Gem.jpg";		break;
		case Jewel::ORANGE:	path = "Bejeweled_Orange_Gem.jpg";	break;
		case Jewel::YELLOW:	path = "Bejeweled_Yellow_Gem.jpg";	break;
		case Jewel::GREEN:	path = "Bejeweled_Green_Gem.jpg";	break;
		case Jewel::BLUE:	path = "Bejeweled_Blue_Gem.jpg";		break;
		case Jewel::PURPLE:	path = "Bejeweled_Purple_Gem.jpg";	break;
		case Jewel::WHITE:	path = "Bejeweled_White_Gem.jpg";	break;
		}

		return path;
	}

	int Puzzle_window::getButtonIndex(Fl_Widget* button_widget)
	{
		for (int i = 0; i < (int)button_list.size(); i++)
		{
			ImageButton* button = button_list[i];
			if (button->getFlWidget() == button_widget)
			{
				return i;
			}
		}
		return -1;
	}

	pair<int, int> Puzzle_window::getButtonLocation(int index)
	{
		int num_buttons = (int)button_list.size();
		if (index >= 0 && index < num_buttons)
		{
			int i = index / num_columns;
			int j = index % num_columns;

			return make_pair(i, j);
		}
		else
		{
			return make_pair(-1, -1);
		}
	}
};
