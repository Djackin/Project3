#pragma once
#include "Folder.h"
class Application
{
public:
	Application();
	void run();
	int getCommand();
	void addFolderInterface();
	void deleteFolderInterface();
	void addPhotoInterface();
	void deletePhotoInterface();
	void displayFolderInfo();
	void moveDirectory();
private:
	Folder* root;
	Folder* pwd;
};

