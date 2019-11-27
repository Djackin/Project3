#include "Folder.h"


Folder::Folder(string name)
{
	this->name = name;
	time(&timedata);
	parent = NULL;
}

Folder::~Folder()
{

}

int Folder::addFolder(Folder data)
{
	if (fList.Add(data))
	{
		data.parent = this;
		num++;
		return 1;
	}
	return 0;
}

int Folder::deleteFolder(Folder data)
{
	if (fList.Delete(data))
	{
		num--;
		return 1;
	}
	return 0;
}

int Folder::addPhoto(Photo data)
{
	if (pList.Add(data))
	{
		num++;
		return 1;
	}
	return 0;
}

int Folder::deletePhoto(Photo data)
{
	if (pList.Delete(data))
	{
		num--;
		return 1;
	}
	return 0;
}

void Folder::displayFolderByName()
{
	DoublyIterator<Folder> fIter(this->fList);
	DoublyIterator<Photo> pIter(this->pList);
	while (fIter.NextNotNull())
	{
		fIter.GetCurrentNode().data.displayInfo();
		fIter.Next();
	}
	while (pIter.NextNotNull())
	{
		pIter.GetCurrentNode().data.displayInfo();
		pIter.Next();
	}
}

void Folder::displayInfo()
{
	cout << "name: " << name << endl;
	cout << "tiem: " << timedata << endl;
}

Photo::Photo(string name)
{
	this->name = name;
	time(&timedata);
}

void Photo::displayInfo()
{
	cout << "name: " << name << endl;
	cout << "time: " << timedata << endl;
}

Folder* Folder::find(string name)
{
	Folder temp(name);
	if (fList.Get(temp))
		return &temp;
	else
		return NULL;
}

Folder* Folder::getParent()
{
	return  parent;
}