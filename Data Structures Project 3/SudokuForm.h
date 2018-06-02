/*
Christopher Robertson
Data Structures Project 3
*/

#pragma once
#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <vcclr.h>
#include "STDLIB.h"

namespace DataStructuresProject3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class SudokuForm : public System::Windows::Forms::Form
	{
	public:
		SudokuForm(void)
		{
			InitializeComponent();
		}

	protected:
		~SudokuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnExit;

	private: System::Windows::Forms::GroupBox^  grpOptions;
	private: System::Windows::Forms::RadioButton^  radFast;
	private: System::Windows::Forms::RadioButton^  radSlow;
	private: System::Windows::Forms::Label^  lblReset;
	protected:

	protected:
	private: array<int, 2>^ grid = gcnew array<int, 2>(9, 9);
	private: Void setLbl(String^);
	private: Void setReset(String^);
	private: Void print();
	private: Boolean checkRow(int, int);
	private: Boolean checkCol(int, int);
	private: Boolean checkSquare(int, int);
	private: Boolean solveRecurF(int, int);
	private: Boolean solveRecurS(int, int);
	private: String^ printRecur(int, int);
	private: System::Windows::Forms::GroupBox^  ControlBox;
	private: System::Windows::Forms::Button^  btnSolve;

	private: System::Windows::Forms::Button^  btnLoad;
	private: System::Windows::Forms::Label^  lblOut;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->ControlBox = (gcnew System::Windows::Forms::GroupBox());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnLoad = (gcnew System::Windows::Forms::Button());
			this->btnSolve = (gcnew System::Windows::Forms::Button());
			this->lblOut = (gcnew System::Windows::Forms::Label());
			this->grpOptions = (gcnew System::Windows::Forms::GroupBox());
			this->radFast = (gcnew System::Windows::Forms::RadioButton());
			this->radSlow = (gcnew System::Windows::Forms::RadioButton());
			this->lblReset = (gcnew System::Windows::Forms::Label());
			this->ControlBox->SuspendLayout();
			this->grpOptions->SuspendLayout();
			this->SuspendLayout();
			// 
			// ControlBox
			// 
			this->ControlBox->Controls->Add(this->btnExit);
			this->ControlBox->Controls->Add(this->btnLoad);
			this->ControlBox->Controls->Add(this->btnSolve);
			this->ControlBox->Location = System::Drawing::Point(230, 12);
			this->ControlBox->Name = L"ControlBox";
			this->ControlBox->Size = System::Drawing::Size(166, 218);
			this->ControlBox->TabIndex = 1;
			this->ControlBox->TabStop = false;
			this->ControlBox->Text = L"Controls";
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(16, 149);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(135, 59);
			this->btnExit->TabIndex = 1;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &SudokuForm::btnExit_Click);
			// 
			// btnLoad
			// 
			this->btnLoad->Location = System::Drawing::Point(16, 19);
			this->btnLoad->Name = L"btnLoad";
			this->btnLoad->Size = System::Drawing::Size(135, 59);
			this->btnLoad->TabIndex = 0;
			this->btnLoad->Text = L"Load Sudoku";
			this->btnLoad->UseVisualStyleBackColor = false;
			this->btnLoad->Click += gcnew System::EventHandler(this, &SudokuForm::btnLoad_Click);
			// 
			// btnSolve
			// 
			this->btnSolve->Enabled = false;
			this->btnSolve->Location = System::Drawing::Point(16, 84);
			this->btnSolve->Name = L"btnSolve";
			this->btnSolve->Size = System::Drawing::Size(135, 59);
			this->btnSolve->TabIndex = 0;
			this->btnSolve->Text = L"Solve";
			this->btnSolve->UseVisualStyleBackColor = false;
			this->btnSolve->Click += gcnew System::EventHandler(this, &SudokuForm::btnSolve_Click);
			// 
			// lblOut
			// 
			this->lblOut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblOut->Location = System::Drawing::Point(9, 7);
			this->lblOut->Name = L"lblOut";
			this->lblOut->Size = System::Drawing::Size(221, 292);
			this->lblOut->TabIndex = 2;
			this->lblOut->Text = L"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
				L" 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
				L"";
			// 
			// grpOptions
			// 
			this->grpOptions->Controls->Add(this->radFast);
			this->grpOptions->Controls->Add(this->radSlow);
			this->grpOptions->Location = System::Drawing::Point(230, 240);
			this->grpOptions->Name = L"grpOptions";
			this->grpOptions->Size = System::Drawing::Size(166, 86);
			this->grpOptions->TabIndex = 4;
			this->grpOptions->TabStop = false;
			this->grpOptions->Text = L"Speed";
			// 
			// radFast
			// 
			this->radFast->AutoSize = true;
			this->radFast->Enabled = false;
			this->radFast->Location = System::Drawing::Point(14, 51);
			this->radFast->Name = L"radFast";
			this->radFast->Size = System::Drawing::Size(107, 17);
			this->radFast->TabIndex = 1;
			this->radFast->Text = L"Fast (no updates)";
			this->radFast->UseVisualStyleBackColor = true;
			this->radFast->CheckedChanged += gcnew System::EventHandler(this, &SudokuForm::radFast_CheckedChanged);
			// 
			// radSlow
			// 
			this->radSlow->AutoSize = true;
			this->radSlow->Checked = true;
			this->radSlow->Enabled = false;
			this->radSlow->Location = System::Drawing::Point(14, 22);
			this->radSlow->Name = L"radSlow";
			this->radSlow->Size = System::Drawing::Size(123, 17);
			this->radSlow->TabIndex = 0;
			this->radSlow->TabStop = true;
			this->radSlow->Text = L"Slow (show updates)";
			this->radSlow->UseVisualStyleBackColor = true;
			this->radSlow->CheckedChanged += gcnew System::EventHandler(this, &SudokuForm::radSlow_CheckedChanged);
			// 
			// lblReset
			// 
			this->lblReset->AutoSize = true;
			this->lblReset->Location = System::Drawing::Point(55, 305);
			this->lblReset->Name = L"lblReset";
			this->lblReset->Size = System::Drawing::Size(0, 13);
			this->lblReset->TabIndex = 5;
			this->lblReset->Visible = false;
			// 
			// SudokuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(405, 342);
			this->Controls->Add(this->lblReset);
			this->Controls->Add(this->grpOptions);
			this->Controls->Add(this->lblOut);
			this->Controls->Add(this->ControlBox);
			this->Name = L"SudokuForm";
			this->Text = L"SudokuForm";
			this->Load += gcnew System::EventHandler(this, &SudokuForm::SudokuForm_Load);
			this->ControlBox->ResumeLayout(false);
			this->grpOptions->ResumeLayout(false);
			this->grpOptions->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void SudokuForm_Load(System::Object^, System::EventArgs^);
private: System::Void btnLoad_Click(System::Object^, System::EventArgs^);
private: System::Void btnSolve_Click(System::Object^, System::EventArgs^);
private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) 
{
	exit(EXIT_SUCCESS);
}
private: System::Void radSlow_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	
}
private: System::Void radFast_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	
}
};

Void SudokuForm::SudokuForm_Load(System::Object^ sender, System::EventArgs^)
{
	setLbl((String^)"Click 'Load Sudoku' to read Sudoku.txt.");
}

Void SudokuForm::btnSolve_Click(Object^ sender, EventArgs^)
{
	using std::ifstream;
	radFast->Enabled = false;
	radSlow->Enabled = false;
	btnLoad->Enabled = false;
	btnSolve->Enabled = false;
	if (radFast->Checked == true)
	{
		if (solveRecurF(0, 0))
		{
			setReset((String^)"Click 'Load Sudoku' to reset.");
			/*
			ifstream infile;
			char temp;
			int in;
			char fileName[15] = "puzzle1.txt";
			int puzzNum = 1;
			for (; puzzNum <= 144; puzzNum++)
			{
				snprintf(fileName, 15, "puzzle%i.txt", puzzNum);
				infile.open(fileName);
				if (!infile)
				{
					setLbl((String^)"File not found. Please correct and try again.");
					return;
				}
				for (int ir = 0; ir < 9; ir++)
				{
					for (int ic = 0; ic < 9; ic++)
					{
						infile >> temp;
						in = (int)temp - '0';
						if (in < 0 || in > 9)
						{
							setLbl((String^)"Invalid sudoku contents. Please correct file. Use 0 for blanks.");
							return;
						}
						grid[ir, ic] = in;
					}
				}
				infile.close();
				lblReset->Visible = true;
				setReset(Convert::ToString(puzzNum));
				lblReset->Refresh();
				solveRecurF(0, 0);
			}
			setReset((String^)"Finished.");
			*/
		}
		else
		{
			setReset((String^)"Sudoku is unsolvable.");
		}
	}
	else
	{
		if (solveRecurS(0, 0))
		{
			setReset((String^)"Click 'Load Sudoku' to reset.");
		}
		else
		{
			setReset((String^)"Sudoku is unsolvable.");
		}
	}
	print();
	radFast->Enabled = true;
	radSlow->Enabled = true;
	btnLoad->Enabled = true;
	lblReset->Visible = true;
}

Boolean SudokuForm::checkRow(int r, int c)
{
	for (int i = 0; i < 9; i++)
	{
		if (grid[r, c] == grid[r, i] && i != c)
		{
			return false;
		}
	}
	return true;
}

Boolean SudokuForm::checkCol(int r, int c)
{
	for (int i = 0; i < 9; i++)
	{
		if (grid[r, c] == grid[i, c] && i != r)
		{
			return false;
		}
	}
	return true;
}

Boolean SudokuForm::checkSquare(int r, int c)
{
	int row = r % 3,
		col = c % 3;
	for (int ir = (r - row); ir <= r + (2 - row); ir++)
	{
		for (int ic = (c - col); ic <= c + (2 - col); ic++)
		{
			if (grid[r, c] == grid[ir, ic])
			{
				if (ir != r || ic != c)
				{
					return false;
				}
			}
		}
	}
	return true;
}

Boolean SudokuForm::solveRecurF(int r, int c)
{
	if (r >= 9)
	{
		return 1;
	}
	else if (c >= 9)
	{
		return solveRecurF(r + 1, 0);
	}
	else if (grid[r, c] != 0)
	{
		return solveRecurF(r, c + 1);
	}
	grid[r, c]++;
	while (!checkRow(r, c) || !checkCol(r, c) || !checkSquare(r, c) || !solveRecurF(r, c + 1))
	{
		grid[r, c]++;
		if (grid[r, c] > 9)
		{
			grid[r, c] = 0;
			return 0;
		}
	}
	return 1;
}

Boolean SudokuForm::solveRecurS(int r, int c)
{
	if (r >= 9)
	{
		return 1;
	}
	else if (c >= 9)
	{
		return solveRecurS(r + 1, 0);
	}
	else if (grid[r, c] != 0)
	{
		return solveRecurS(r, c + 1);
	}
	grid[r, c]++;
	while (!checkRow(r, c) || !checkCol(r, c) || !checkSquare(r, c) || !solveRecurS(r, c + 1))
	{
		grid[r, c]++;
		print();
		lblOut->Refresh();
		if (grid[r, c] > 9)
		{
			grid[r, c] = 0;
			return 0;
		}
	}
	return 1;
}

Void SudokuForm::btnLoad_Click(System::Object^ sender, System::EventArgs^ e)
{
	using std::ifstream;
	lblReset->Visible = false;
	ifstream infile;
	char temp;
	int in;
	infile.open("Sudoku.txt");
	//infile.open("puzzle0.txt");
	if (!infile)
	{
		setLbl((String^)"File not found. Please correct and try again.");
		return;
	}
	for (int ir = 0; ir < 9; ir++)
	{
		for (int ic = 0; ic < 9; ic++)
		{
			infile >> temp;
			in = (int)temp - '0';
			if (in < 0 || in > 9)
			{
				setLbl((String^)"Invalid sudoku contents. Please correct file. Use 0 for blanks.");
				return;
			}
			grid[ir, ic] = in;
		}
	}
	infile.close();
	print();
	radFast->Enabled = true;
	radSlow->Enabled = true;
	btnSolve->Enabled = true;
}

Void SudokuForm::print()
{
	setLbl(printRecur(0, 0));
}

String^ SudokuForm::printRecur(int r, int c)
{
	if (r >= 9)
		return "";
	else if (c >= 9)
	{
		return printRecur(r + 1, 0);
	}
	if (grid[r, c] == 0)
	{
		return "_|" + printRecur(r, c + 1);
	}
	else
	{
		return grid[r, c] + "|" + printRecur(r, c + 1);
	}
}

Void SudokuForm::setLbl(String^ str)
{
	this->lblOut->Text = str;
}

Void SudokuForm::setReset(String^ str)
{
	this->lblReset->Text = str;
}
}