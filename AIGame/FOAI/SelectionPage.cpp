#include "SelectionPage.h"
#include<iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include<algorithm>

using namespace FOAI;



	int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		Application::Run(gcnew SelectionPage());
		return 0;
	}


