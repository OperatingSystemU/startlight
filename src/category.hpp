// Copyright (C) 2013 Graeme Gott <graeme@gottcode.org>
//
// This library is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this library.  If not, see <http://www.gnu.org/licenses/>.


#ifndef WHISKERMENU_CATEGORY_HPP
#define WHISKERMENU_CATEGORY_HPP

#include <vector>

extern "C"
{
#include <garcon/garcon.h>
#include <gtk/gtk.h>
}

namespace WhiskerMenu
{

class Launcher;
class SectionButton;

class Category
{
public:
	explicit Category(GarconMenuDirectory* directory);
	~Category();

	GtkTreeModel* get_model();

	SectionButton* get_button() const
	{
		return m_button;
	}

	bool empty() const
	{
		return m_items.empty();
	}

	void push_back(Launcher* launcher)
	{
		m_items.push_back(launcher);
		unset_model();
	}

private:
	void unset_model();

private:
	std::vector<Launcher*> m_items;
	SectionButton* m_button;
	GtkTreeModel* m_model;
};

}

#endif // WHISKERMENU_CATEGORY_HPP