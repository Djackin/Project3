#pragma once
#include "DoublySortedLinkedList.h"
#include<string>
#include<ctime>
#include<iostream>
using namespace std;

class Photo
{
public:
	Photo(string name);
	void displayInfo();
	void operator = (Photo& data)
	{
		this->name = data.name;
		this->timedata = data.timedata;
	}
	bool operator == (Photo& data)
	{
		if (this->name == data.name)
			return true;
		else
			return false;
	};
	bool operator < (Photo& data)
	{
		if (this->name < data.name)
			return true;
		else
			return false;
	};
	bool operator < (Photo& data)
	{
		if (this->name < data.name)
			return true;
		else
			return false;
	}
private:
	string name;
	time_t timedata;
};

class Folder
{
public:
	Folder(string name);
	~Folder();
	int addFolder(Folder data);
	int deleteFolder(Folder data);
	int addPhoto(Photo data);
	int deletePhoto(Photo data);
	void displayFolderByName();
	void displayInfo();
	Folder* find(string name);
	Folder* getParent();
	void operator = (Folder& data)
	{
		this->name = data.name;
		this->timedata = data.timedata;
		this->fList = data.fList;
		this->pList = data.pList;
		this->num = data.num;
	}
	bool operator == (Folder& data)
	{
		if (this->name == data.name)
			return true;
		else
			return false;
	};
	bool operator < (Folder& data)
	{
		if (this->name < data.name)
			return true;
		else
			return false;
	};
	bool operator < (Folder& data)
	{
		if (this->name < data.name)
			return true;
		else
			return false;
	}
private:
	DoublySortedLinkedList<Folder> fList;
	DoublySortedLinkedList<Photo> pList;
	string name;
	time_t timedata;
	int num;
	Folder* parent;
};
