/* Copyright 2021 Aristocratos (jakob@qvantnet.com)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

indent = tab
tab-size = 4
*/

#pragma once

#include <string>
#include <robin_hood.h>
#include <filesystem>

using std::string;

namespace Theme {
	extern std::filesystem::path theme_dir;
	extern std::filesystem::path user_theme_dir;

	extern vector<string> themes;

	//* Generate escape sequence for 24-bit or 256 color and return as a string
	//* Args	hexa: ["#000000"-"#ffffff"] for color, ["#00"-"#ff"] for greyscale
	//*			t_to_256: [true|false] convert 24bit value to 256 color value
	//* 		depth: ["fg"|"bg"] for either a foreground color or a background color
	string hex_to_color(string hexa, bool t_to_256=false, string depth="fg");

	//* Generate escape sequence for 24-bit or 256 color and return as a string
	//* Args	r: [0-255], g: [0-255], b: [0-255]
	//*			t_to_256: [true|false] convert 24bit value to 256 color value
	//* 		depth: ["fg"|"bg"] for either a foreground color or a background color
	string dec_to_color(int r, int g, int b, bool t_to_256=false, string depth="fg");

	//* Return an array of red, green and blue, 0-255 values for a 24-bit color escape string
	std::array<int, 3> esc_to_rgb(string c_string);

	//* Update list of available themes
	void updateThemes();

	//* Set current theme using <source> map
	void set(string theme);

	//* Return escape code for color <name>
	const string& c(string name);

	//* Return array of escape codes for color gradient <name>
	const std::array<string, 101>& g(string name);

	//* Return array of red, green and blue in decimal for color <name>
	const std::array<int, 3>& dec(string name);

	//? Testing
	robin_hood::unordered_flat_map<string, string>& test_colors();
	robin_hood::unordered_flat_map<string, std::array<string, 101>>& test_gradients();

}