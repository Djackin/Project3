#include "Application.h"

Application::Application()
{
	pwd = root;
};

void Application::run()
{
	int command;
	while (1)
	{
		command = getCommand();
		switch (command)
		{
		case 1:
			addFolderInterface();
			break;
		case 2:
			deleteFolderInterface();
			break;
		case 3:
			addPhotoInterface();
			break;
		case 4:
			deletePhotoInterface();
			break;
		case 5:
			displayFolderInfo();
			break;
		case 0:
			moveDirectory();
			break;
		}
	}
}

int Application::getCommand()
{
	int command;
	while (1)
	{
		cout << "Input Command :" << endl;
		cout << "1. Add Folder" << endl;
		cout << "2. Delete Folder" << endl;
		cout << "3. Add Photho" << endl;
		cout << "4. Delete Photo" << endl;
		cout << "5. Display All Item" << endl;
		cout << "0. Move Current Directory" << endl;
		cin >> command;
		if (command < 6 && command >= 0)
			return command;
		else
			cout << "Input right command" << endl;
	}
}

void Application::addFolderInterface()
{
	string name;
	cout << "type folder name: ";
	cin >> name;
	Folder temp(name);
	if (pwd->addFolder(temp))
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "fail" << endl;
	}
}

void Application::addPhotoInterface()
{
	string name;
	cout << "type photo name: ";
	cin >> name;
	Photo temp(name);
	if (pwd->addPhoto(temp))
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "fail" << endl;
	}
}

void Application::deleteFolderInterface()
{
	string name;
	cout << "type folder name: ";
	cin >> name;
	Folder temp(name);
	if (pwd->deleteFolder(temp))
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "fail" << endl;
	}
}

void Application::deletePhotoInterface()
{
	string name;
	cout << "type photo name: ";
	cin >> name;
	Photo temp(name);
	if (pwd->deletePhoto(temp))
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "fail" << endl;
	}
}

void Application::displayFolderInfo()
{
	pwd->displayFolderByName();
}

void Application::moveDirectory()
{
	string name;
	Folder* temp;
	cout << "where: ";
	cin >> name;
	if (name == "..")
		pwd = pwd->getParent;
	if ((temp = pwd->find(name))!=NULL)
	{
		pwd = temp;
		cout << "success" << endl;
	}
	else
		cout << "input right folder name" << endl;
}