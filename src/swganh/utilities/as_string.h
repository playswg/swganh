#pragma once

template<typename T>
std::string AsString(T input)
{
	std::stringstream ss;
	ss << input;
	return ss.str();
}

template<typename T>
std::wstring AsWideString(T input)
{
	std::wstringstream wss;
	wss << input;
	return wss.str();
}
