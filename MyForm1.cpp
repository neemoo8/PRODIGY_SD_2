#include "MyForm1.h"
#include "MyForm.h"
#include <cstdlib>  
#include <ctime>

using namespace System;
using namespace System::Windows::Forms;

System::Void GuessGame3::MyForm1::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	std::srand(std::time(0));
    GuessGame3::MyForm::randomNumber = std::rand() % 100 + 1;
	MyForm^ newForm = gcnew MyForm();
	newForm->Show();
}
