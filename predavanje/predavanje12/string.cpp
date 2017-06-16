#include<iostream>
#include<string>
using namespace std;

struct String
{
	char * _text;

	void unos(char * tekst)
	{
		int vel = strlen(tekst) + 1;
		_text = new char[vel];
		strcpy_s(_text, vel, tekst);
	}

	void operator=(String & s)
	{
		int vel = strlen(s._text) + 1;
		_text = new char[vel];
		strcpy_s(_text, vel, s._text);
	}
	//stari tekst + novi tekst
	void dodajTekst(char * tekst)
	{
		int vel = strlen(_text) + strlen(tekst) + 1;
		char* noviTekst = new char[vel];
		strcpy_s(noviTekst, vel, _text);
		strcat_s(noviTekst,vel, tekst);
		delete[]_text;
		_text = noviTekst;
		noviTekst = nullptr;
	}
	void operator+=(String &s)
	{
		int vel = strlen(_text) + strlen(s._text) + 1;
		char* noviTekst = new char[vel];
		strcpy_s(noviTekst, vel, _text);
		strcat_s(noviTekst,vel, s._text);
		delete[]_text;
		_text = noviTekst;
		noviTekst = nullptr;
	}
	void ispis()
	{
		cout << _text << endl;
	}
	void dealociraj()
	{
		delete[]_text; _text = nullptr;
	}
};

struct ListaStringova
{
	String * _stringovi;
	int _trenutno;

	void unos()
	{
		_trenutno = 0;
		_stringovi = nullptr;
	}
	void ispis();
	void dealociraj();
	void dodajString(char * string)
	{
		String * noviStringovi = new String[_trenutno + 1];
		if (_stringovi == nullptr)
		{
			for (int i = 0; i < _trenutno; i++)
				noviStringovi[i].unos(_stringovi[i]._text);
			for (int i = 0; i < _trenutno; i++)
				_stringovi[i].dealociraj();
			delete[]_stringovi;
		}
		_stringovi = noviStringovi;
		noviStringovi = nullptr;
		_stringovi[_trenutno].unos(string);
		_trenutno++;
	}
	bool ukloniString(char * tekst)
	{

	}
};
void main()
{
	String s1, s2;
	s1.unos("test");
	s2 = s1;
	s1.dealociraj();
	s2.dealociraj();
}