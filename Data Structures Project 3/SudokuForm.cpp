/*
Christopher Robertson
Data Structures Project 3
*/

#include "SudokuForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	DataStructuresProject3::SudokuForm form;
	Application::Run(%form);
}