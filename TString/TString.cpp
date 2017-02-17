#include "TString.h"
TString::~TString()
{
	delete[] Data;
}
TString::TString()
{
	Data = nullptr;
	Data = new char[1];
	Data[0] = '\0';
}
TString::TString(const TString& rhs)
{
	int rhs_length = rhs.Size();
	Data = new char[rhs_length + 1];
	for (int i = 0; i < rhs_length + 1; i++){
		Data[i] = rhs.Data[i];
	}
}
TString::TString(const char * data)
{
	int i = 0;
	while (data[i])	i++;
	Data = new char[i+1];
	for (int j = 0; j < i + 1; j++){
		Data[j] = data[j];
	}
}
TString& TString::operator =(const TString& rhs)
{
	if (Data == rhs.Data) return *this;
	int rhs_length = rhs.Size();
	Data = new char[rhs_length + 1];
	for (int i = 0; i < rhs_length + 1; i++){
		Data[i] = rhs.Data[i];
	}
	return *this;
}
TString& TString::operator +=(const TString& rhs)
{
	int i = 0, length = Size(), length2 = rhs.Size();
	TString str;
	str = *this;
	Data = new char[length + length2 + 1];
	while (i < length){
		Data[i] = str.Data[i];
		i++;
	}
	i = 0;
	while (i <= length2){
		Data[length + i] = rhs.Data[i];
		i++;
	}
	return *this;
}
bool TString::operator ==(const TString& rhs) const
{
	int length = Size();
	int rhs_length = rhs.Size();
	if (length != rhs_length) return 0;
	else{
		for (int i = 0; i < length; i++){
			if (Data[i] != rhs.Data[i]) return 0;
		}
		return 1;
	}
}
bool TString::operator <(const TString& rhs) const
{
	int length = Size(), rhs_length = rhs.Size();
	if (length == rhs_length)  
	{
		for (int i = 0; i < length; i++){
			if (Data[i] > rhs.Data[i]) return 0;
			if (Data[i] < rhs.Data[i]) return 1;
		}
	}
	return 0;
}
size_t TString::Find(const TString& substr) const
{
	int length = Size(), sub_length = substr.Size();
	if (length <  sub_length)	return -1;
	for (int i = 0; i < length; i++){
		for (int j = 0; j < sub_length; j++){
			if (Data[i + j] != substr.Data[j]) break;
			if (j == sub_length - 1) return i;
		}
	}
	return -1;
}
void TString::Replace(char oldSymbol, char newSymbol){
	int lenght = Size();
	for (int i = 0; i < lenght; i++){
		if (Data[i] == oldSymbol) Data[i] = newSymbol;
	}
}
size_t TString::Size() const{
	int i = 0; 
	while (Data[i]) i++;
	return i;
}
bool TString::Empty() const{
	if (Data[0] == '\0') return 1;
	else return 0;
}
char TString::operator[](size_t index) const
{
	return Data[index];
}
char& TString::operator[](size_t index)
{
	return Data[index];
}
void TString::RTrim(char symbol){
	int length = Size();
	if (Data[length - 1] != symbol) std::cout << "ERROR!" << std::endl;
	else {
		length--;
		while (Data[length] == symbol){
			Data[length] = '\0';
			length--;
		}
	}
}
void TString::LTrim(char symbol){
		TString str;
		int i = 0, length = Size();
	if (Data[0] != symbol) std::cout << "ERROR!" << std::endl;
	else {
		while (Data[i] == symbol){
		i++;
	}
	str.Data = new char[length - i + 1];
	for (int j = 0; j < length - i + 1; j++)
	{
		str.Data[length - i - j] = Data[length - j];
	}
	*this = str;
	}
}
TString operator+(const TString & a, const TString & b){
	TString summa;
	summa = a;
	summa += b;
	return summa;
}
bool operator!=(const TString & a, const TString & b){
	bool i =  a < b;
	if (i == 1) return 0;
	else return 1;
}
bool operator>(const TString & a, const TString & b)
{
	bool c = a < b;
	if (a == b) return 0;
	if (c = 1) return 0;
	return 1;
}
std::ostream & operator<<(std::ostream &out, const TString &str)
{
	out
		<< str.Data;
	return out;
}
