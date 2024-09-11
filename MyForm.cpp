#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

static void StartApplication() {
	GuessGame3::MyForm form;
	Application::Run(% form);
}

int main(array<String^>^ args) {
	StartApplication();
	return 0;
}

System::Void GuessGame3::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		guess = Int32::Parse(textBox1->Text);  // Get the guess from the textbox
	}
	catch (FormatException^ ex) {
		// Show an error if the input is not a valid integer
		MessageBox::Show("Invalid input! Please enter a valid number between 1 and 100.");
		textBox1->Clear();  // Clear the textBox for the next input
		return;
	}

	// Check if the input is within the valid range (1 to 100)
	if (guess < 1 || guess > 100) {
		MessageBox::Show("Please enter a number between 1 and 100.");
		textBox1->Clear();  // Clear the textBox for the next input
		return;
	}

	attempts++;  // Increment the attempt count

	// Compare the guess with the random number
	if (guess > randomNumber) {
		MessageBox::Show("Too high! Try again.");
	}
	else if (guess < randomNumber) {
		MessageBox::Show("Too low! Try again.");
	}
	else {
		// Create and show MyForm1 with results in textBox1
		MyForm1^ resultWindow = gcnew MyForm1();
		resultWindow->textBox1->Text = "You've guessed the number in " + attempts.ToString() + " attempts!\n";
		resultWindow->ShowDialog();

		attempts = 0;  // Reset the attempt counter
	}

	// Clear the input field (textBox1) after each guess
	textBox1->Clear();
}
